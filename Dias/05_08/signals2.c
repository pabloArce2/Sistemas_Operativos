#include <sys/mman.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <sys/types.h>
#include <string.h>
#include <semaphore.h>
#include <fcntl.h>
#include <pthread.h>
#include <signal.h>


void manejador (int signum)
{
	puts("Ahora estamos dentro de una funcion manejadora");
}


int main () 
{
	signal(SIGUSR1, manejador);
	puts("Dentro de la funcion main");
	raise(SIGUSR1);
	puts("Dentro de la función main");
	return 0;
}
