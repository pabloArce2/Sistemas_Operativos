#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <stdlib.h>
#include <ctype.h> 
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <pthread.h>

pthread_t hiloCreaMatrices;
pthread_t hiloPreguntaDimensiones;
pthread_t hiloPreguntaNumeros;

pthread_mutex_t lock;

void *preguntaDimensiones();
void *preguntaNumeros();
void *creaMatrices();

int dim1;
int dim2;

int main ()
{
	pthread_mutex_init(&lock, NULL);
	
	pthread_create(&hiloPreguntaDimensiones, NULL,preguntaDimensiones, NULL);
	pthread_join(hiloPreguntaDimensiones, NULL);
	
	pthread_mutex_destroy(&lock);
	return 1;
}

void *preguntaDimensiones()
{
	printf("Dime las dimensiones de la matriz:\n");
	printf("Primera dimensión: ");
	scanf("%d", &dim1);
	printf("Segunda dimensión: ");
	scanf("%d", &dim2);
	
	pthread_create(&hiloPreguntaNumeros, NULL,preguntaNum, NULL);
	pthread_exit(NULL);
}

void *preguntaNumeros()
{
	pthread_exit(NULL);
}

void *creaMatrices()
{
	pthread_exit(NULL);
}


