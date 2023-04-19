#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <sys/types.h>
#include <string.h>

// Pablo Arce de Aldecoa, 22 / 03 / 2023

int main(void) {
    pid_t pid;
    printf("Bienvenido a la MiniShell, escribe un comando:\n");
    char comando[20];
    char salir[20] = "exit";

    while(1) {
		printf("Introduce un comando: ");
        scanf("%s", comando);
        if (strcmp(comando, salir) == 0) {
            break;
        }
        if ((pid = fork()) == 0) {
            execlp(comando, comando, NULL); 
            exit(0); // Exit para el proceso hijo
        }
        else {
            wait(NULL); // Wait para esperar al proceso hijo
        }
    }
    return 0;
}

