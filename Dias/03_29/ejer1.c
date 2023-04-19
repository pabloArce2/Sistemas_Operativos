#include <sys/mman.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <sys/types.h>
#include <string.h>

static int *variable_compartida;

int main(void) {
    pid_t lee, escribe;
    variable_compartida = mmap(NULL, sizeof *variable_compartida, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS,  -1, 0);
    *variable_compartida = 0;
    lee = fork();
    if (lee == 0) {
        printf("Soy el hijo que lee, dame el valor de la variable compartida: \n");
        scanf("%d", variable_compartida);
        exit(0);
    }
    else if (lee > 0) {
        escribe = fork();
        if (escribe == 0) {
            printf("Soy el hijo que escribe, introduce un número por teclado: \n");
            scanf("%d", variable_compartida);
            exit(0);
        }
        else if (escribe > 0) {
            printf("Soy el padre, la variable vale %d y quedo a la espera\n", *variable_compartida);
            wait(NULL);
            printf("Soy el padre y el hijo ha cambiado el valor de la variable a %d\n", *variable_compartida);
        }
    }

    return 0;
}
