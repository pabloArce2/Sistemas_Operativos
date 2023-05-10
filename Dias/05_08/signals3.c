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

void sig_handler_padre (int signum)
{
	puts("Padre: recibida una señal de respuesta del chaval");
}

void sig_handler_hijo(int signum)
{
	puts("Hijo: recibida una señal del padre");
	sleep(1);
	kill(getppid(), SIGUSR1);
}

int main () 
{
	pid_t pid;
	if ((pid = fork())<0)
	{
		perror("El fork la ha liado");
		return -1;
	}
	else if (pid==0)
	{
		signal(SIGUSR1, sig_handler_hijo);
		puts ("Me quedo a la espera de una señal");
		pause();
	}
		
	else 
	{
		signal(SIGUSR1, sig_handler_padre);
		sleep(1);
		puts("Voy a enviar una señal para despertar al chaval");
		kill(pid, SIGUSR1);
		puts("Me quedo a la espera de la respuesta del hijo");
		pause();
	}
	return 0;
}

