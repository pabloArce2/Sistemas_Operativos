#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int num = 10;
long int factorial;
int flag = 1;

pthread_t preguntaNum;
pthread_t muestraFact;

pthread_mutex_t lock;

void *preguntaNumero(void *arg);
void *muestraFactorial(void *arg);

int main() 
{
    pthread_mutex_init(&lock, NULL);
    pthread_create(&preguntaNum, NULL, preguntaNumero, NULL);
    pthread_join(preguntaNum, NULL);
    pthread_mutex_destroy(&lock);
    return 0;
}

void *preguntaNumero(void *arg)
{
    while (flag) {
        pthread_mutex_lock(&lock);
        printf("Soy el hilo %lu, introduce un numero: ", pthread_self());
        scanf("%d", &num);
        pthread_mutex_unlock(&lock);
        if (num == -1) {
            flag = 0;
            pthread_exit(NULL);
        }
        pthread_create(&muestraFact, NULL, muestraFactorial, NULL);
        pthread_join(muestraFact, NULL);
    }
}

void *muestraFactorial(void *arg)
{
    pthread_mutex_lock(&lock);
    factorial = 1;
    for (int i = 1; i <= num; i++) {
        factorial = factorial * i;
    }
    printf("Soy el hilo %lu, el factorial es: %ld\n", pthread_self(), factorial);
    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
}

