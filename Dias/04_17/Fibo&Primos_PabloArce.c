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


long int global_var = 0; // variable global inicializada a cero
sem_t semaforo; // Inicializamos el semáforo

void *fibonacci(); // Dejamos cada una de las funciones inicializadas
void *primo();

int main() {
    pthread_t hiloFibo, hiloPrimo; // Creamos los dos hilos
    
    sem_init(&semaforo, 0, 0); // Inicializamos el semáforo
    
    pthread_create(&hiloFibo, NULL, fibonacci, NULL);
    pthread_create(&hiloPrimo, NULL, primo, NULL);
    
    pthread_join(hiloFibo, NULL);
    pthread_join(hiloPrimo, NULL);
    
    sem_destroy(&semaforo); // Destruimos el semáforo
    
    return 0;
}

void *fibonacci() {
    long num;
    printf("Introduce un número: ");
    scanf("%ld", &num); // pedimos el numero por pantalla
    
    long fib1 = 0, fib2 = 1, fib3;
    printf("Sucesión de Fibonacci de los primeros %ld numeros: ", num);
    for (int i = 1; i <= num; i++) { //Aqui resolvemos el logaritmo de fibonacci para un numero limite (num)
        printf("%ld ", fib1);
        fib3 = fib1 + fib2;
        fib1 = fib2;
        fib2 = fib3;
    }
    printf("\n");
    global_var = fib2 - fib1; // El ultimo numero es la resta de fib2 y fib1
    sem_post(&semaforo); // Desbloqueamos el semáforo
    pthread_exit(NULL);
}

void *primo() {
    sem_wait(&semaforo); // Esperamos a que se desbloquee el semáforo
    long num = global_var; // num es el numero que recibimos de la función de fibonacci
    printf("El último número de la sucesión de Fibonacci es %ld\n", num);
    num --;
    int i, flag = 0; // flag, hace de booleano 
    for (i = 2; i <= num / 2; ++i) { // busca si el numero es primo
        if (num % i == 0) { // si numero no es primo, flag = 1
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        printf("%ld es un número primo\n", num);
    else
        printf("%ld no es un número primo\n", num);
    pthread_exit(NULL);
}
