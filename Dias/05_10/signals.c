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

int contador = 1;

void manejador (int signum)
{
	char comando[4];
	while(1){
		puts("  END? S/N");
		fgets(comando, sizeof(comando), stdin);
		if (strcmp(comando, "S") == 0) {exit(0);}
		else if (strcmp(comando, "N") == 0) {break;}
	}
}

int main () 
{
	signal(SIGINT, manejador);
	while(1)
	{
		printf("%d - programa en funcionamiento...\n", contador);
		sleep(1);
		contador++;
	}
	return 0;
}
