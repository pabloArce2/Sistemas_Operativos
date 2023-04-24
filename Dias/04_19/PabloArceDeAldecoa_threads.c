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

#define LIMITE 5

pthread_t threads[LIMITE]; // array de threads, dependiendo del limite
int flags[LIMITE]; // un array de flags que guarda un numero aleatorio por cada thread
int contador = 0;

void *thread_function(void *arg) {
    pthread_t thread_id = pthread_self(); // almaceno el thread actual en thread_id
    printf("Hilo %ld creado.\n", thread_id); // imprimo el id del thread
    int contador_actual = contador;
    contador++; 
    while (flags[contador_actual] != 1){} // En cuanto pase a ser 1, sale del while, y se muere 
	pthread_exit(NULL);
}

int main() {
    int i;
    for (i = 0; i < LIMITE; i++) {
        pthread_create(&threads[i], NULL, thread_function, NULL); //se crea cada hilo con un for
        sleep(1);
    }
    
    char c;
    printf("Introduce un carácter: ");
    scanf(" %c", &c);

    for (i = LIMITE - 1; i >= 0; i--) {
        flags[contador] = 1;
        printf("Hilo %ld cerrado.\n", threads[i]); //se cierra cada hilo con un for
    }


    return 0;
}
