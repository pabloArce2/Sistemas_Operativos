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


void *thread_creation() {
    pthread_t thread_id = pthread_self();
    printf("Hilo %ld creado.\n", thread_id);
	return 0;
}

int main() {
    int i;
    pthread_t threads[LIMITE];

    for (i = 0; i < LIMITE; i++) {
		pthread_create(&threads[i], NULL, thread_creation, NULL);
		sleep(1);
    }

    char num;
    printf("Introduce un carácter: ");
    scanf(" %c", &num);

    for (i = LIMITE - 1; i >= 0; i--) {
        pthread_join(threads[i], NULL);
        printf("Hilo %ld cerrado.\n", threads[i]);
        sleep(1);
    }

    return 0;
}

