// Un programa que cree dos hilos, el hilo padre lee un número por teclado, el primero de los hilos va a calcular la sucesión de fibonacci
// hasta ese numero. El segundo hilo, coge el ultimo numero de esos, le resta 1, y mira si es primo o no es primo

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

void *buscaNumeros();
void *esPrimo();
pthread_mutex_t lock;
static long int global_var=0;

int main ()
{
	pthread_mutex_init(&lock, NULL);
	pthread_t hiloFibo, hiloPrimos;
	pthread_create(&hiloFibo, NULL, &buscaNumeros, NULL);
	pthread_create(&hiloPrimos, NULL, &esPrimo, NULL);
	pthread_join(buscaNumeros, NULL);
	pthread_join(esPrimo, NULL);
	printf("El numero %ld es \n", global_var);
	
	return 0;
}
