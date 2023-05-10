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
	if (signum == SIGINT)
	{puts(" Paso de tu culo :P");}
}


int main () 
{
	signal(SIGINT, manejador);
	for (int i = 1; ; i++)
	{
		printf("%d: Estoy haciendo el gamba\n", i);
		sleep(5);
	}
	
	
	return 0;
}
