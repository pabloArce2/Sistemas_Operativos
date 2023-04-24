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
#define LIMITE 3

int n=0;
pthread_t array[LIMITE];
void *creaThread();

int main (void){
	pthread_create(&array[0],NULL,&creaThread, NULL);
	pthread_join(array[n], NULL);
	}

void *creaThread(){
	
	printf("He nacido, soy el hilo con ID %lu\n", pthread_self());
	n++;
	sleep(1);
	if (n < LIMITE){
		pthread_create(&array[n], NULL, &creaThread, NULL);
		pthread_join(array[n], NULL);
		}
	else{
		char g[10];
		fgets(g, sizeof(g), stdin);
		}
	printf("Soy el hilo con ID %lu y acabo mi ejecución\n", pthread_self());
	return 0;
}
