// Una calculadora que vaya leyendo numeros hasta que uno de ellos sea x/0
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

 

//Salida esperada:
//primer numero: A la espera 
//8
//segundo número:
//2
//El resultado es 4
//primer numero: 8
//segundo numero: 0
//Vamos a resetear el hilo divisor
//Vamos a resetear el hilo divisor
//primer numero:
