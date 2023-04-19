#include <sys/mman.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <sys/types.h>
#include <string.h>
#include <semaphore.h>
#include <fcntl.h>

static int *numero;
sem_t *semaforo;

int main(void) 
{
	semaforo = sem_open("/miSemaforo2", O_CREAT, S_IRUSR | S_IWUSR,  1);
    pid_t lee, escribe;
    numero= mmap(NULL, sizeof *numero, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS,  -1, 0);
    lee = fork();
    if (lee>0)
    {
		escribe = fork();
	}
	if (lee == 0){
		sem_wait(semaforo);
		printf("Introduce un número: ");
		scanf("%d", *&numero);
		sem_post(semaforo);
		exit(0);
	}
	if (escribe == 0){
		usleep(10);
		sem_wait(semaforo);
		printf("El número tecleado es %d\n", *numero);
		exit(0);
	}
	while (wait (NULL) > 0);
	sem_close(semaforo);
	sem_unlink("/miSemaforo2");

    return 0;
}
