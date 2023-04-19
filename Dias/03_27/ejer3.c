#include <sys/mman.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <sys/types.h>
#include <string.h>

static int *variable_compartida;

int main(void){
	
	pid_t hijo;
	variable_compartida=mmap(NULL, sizeof *variable_compartida, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS,  -1, 0);
	*variable_compartida = 0;
	hijo = fork();
	if (hijo == 0)
	{
		puts("Soy el hijo, dame el valor de la variable compartida");
		scanf("%d", *&variable_compartida);
		exit(0);
	}
	else if (hijo>0)
	{
		printf("Soy el padre, la variable vale %d y quedo a la espera\n", *variable_compartida);
		wait(NULL);
		printf("Soy el padre y el hijo ha cambiado el valor de la variable a %d\n", *variable_compartida);
	}
return 0;	
}
