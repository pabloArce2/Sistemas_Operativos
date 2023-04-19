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

#define LIMITE 100000
pthread_mutex_t lock;

void *incrementa();
void *decrementa();
static long int global_var=0;
int main ()
{
	pthread_mutex_init(&lock, NULL);
	pthread_t suma, resta;
	pthread_create(&suma, NULL, &incrementa, NULL);
	pthread_create(&resta, NULL, &decrementa, NULL);
	pthread_join(resta, NULL);
	pthread_join(suma, NULL);
	printf("El valor final de la variable es %ld\n", global_var);
	
	return 0;
}
void *incrementa()
{
	long int i;
	for (i=0;i<LIMITE; i++)
	{
		pthread_mutex_lock(&lock);
		global_var=global_var+1;
		pthread_mutex_unlock(&lock);
	}
	printf("Suma: El valor final de la variable es %ld\n", global_var);
	return 0;
}

void *decrementa()
{
	long int j;
	for (j=0;j<LIMITE;j++)
	{
		pthread_mutex_lock(&lock);
		global_var=global_var-1;
		pthread_mutex_unlock(&lock);
	}
	printf("Resta: El valor final de la variable es %ld\n", global_var);
	return 0;
}
