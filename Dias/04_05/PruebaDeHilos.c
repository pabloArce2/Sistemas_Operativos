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

pthread_t ntid;

void printids(const char* s){
	pid_t pid;
	pthread_t tid;
	pid = getpid();
	tid = pthread_self();
	printf("%s pid %u tid %u\n", s, (unsigned int)pid, (unsigned int) tid);
	return;
}

void* thr_fn(void *arg)
{
	printids("Nuevo hilo: ");
	return NULL;
}

int main (void)
{
	int error;
	error=pthread_create(&ntid, NULL, &thr_fn, NULL);
	if (error != 0)
	{
		perror("No se puede crear el hilo");
	}
	printids("Hilo principal: ");
	usleep(100);
	return 0;
}

