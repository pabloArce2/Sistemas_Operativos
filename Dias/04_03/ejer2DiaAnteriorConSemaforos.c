#include <sys/mman.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <sys/types.h>
#include <string.h>
#include <semaphore.h>
#include <fcntl.h>

static int *variable_compartida;
sem_t *semaforo;

int main(void) 
{
	semaforo = sem_open("/miSemaforo2", O_CREAT, S_IRUSR | S_IWUSR,  1);
    pid_t lee, escribe;
    variable_compartida = mmap(NULL, sizeof *variable_compartida, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS,  -1, 0);
    lee = fork();
    if (lee>0)
    {
		escribe = fork();
	}
	if (lee == 0){
		printf("Soy el proceso %d, introduce un número: ", getpid());
		scanf("%d", *&variable_compartida);
		sem_post(semaforo);
		exit(0);
	}
	if (escribe == 0){
		sem_wait(semaforo);
		printf("Soy el proceso %d y el número tecleado es %d\n", getpid(),  *variable_compartida);
		exit(0);
	}
	while (wait (NULL) > 0);
	puts("Soy el padre");
	sem_close(semaforo);
	sem_unlink("/miSemaforo2");

    return 0;
}
