// si pasas de un número grande, no responde
// Aqui se va a solucionar el problema, con semaforos


#include <sys/mman.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <sys/types.h>
#include <string.h>
#include <semaphore.h>
#include <fcntl.h>

#define limite 100000000

static int *variable_compartida;
sem_t *semaforo;

int main(void) 
{
	int i;
	variable_compartida = mmap(NULL, sizeof *variable_compartida, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS,  -1, 0);
	*variable_compartida = 0;
	
	semaforo = sem_open("/miSemaforo2", O_CREAT, S_IRUSR | S_IWUSR,  1);
	
	pid_t suma, resta;
	suma = fork();
	if (suma > 0)
	{resta = fork();
	}
	
	if (suma == 0){
		for (i=0; i<=limite;i++){
				sem_wait(semaforo);
				*variable_compartida = *variable_compartida+1;
				sem_post(semaforo);
			}
		exit(0);
	}
	else if (resta == 0){
			for (i=0; i<=limite;i++){
				sem_wait(semaforo);
				*variable_compartida = *variable_compartida-1;
				sem_post(semaforo);
			}
	}
	else if (resta >0 && suma >0){
		while (wait(NULL)>0);
		printf("La variable compartida toma el valor final %d\n", *variable_compartida);
		munmap(variable_compartida, sizeof *variable_compartida);
		sem_close(semaforo);
		sem_unlink("/miSemaforo2");
	}
	
    return 0;
}

