// si pasas de un número grande, no responde

#include <sys/mman.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <sys/types.h>
#include <string.h>

#define limite 25000

static int *variable_compartida;


int main(void) 
{
	int i;
	variable_compartida = mmap(NULL, sizeof *variable_compartida, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS,  -1, 0);
	*variable_compartida = 0;
	
	pid_t suma, resta;
	suma = fork();
	if (suma > 0)
	{resta = fork();
	}
	
	if (suma == 0){
		for (i=0; i<=limite;i++){
					*variable_compartida = *variable_compartida+1;
			}
		exit(0);
	}
	else if (resta == 0){
			for (i=0; i<=limite;i++){
					*variable_compartida = *variable_compartida-1;
			}
	}
	else if (resta >0 && suma >0){
		while (wait(NULL)>0);
		printf("La variable compartida toma el valor final %d\n", *variable_compartida);
		munmap(variable_compartida, sizeof *variable_compartida);
	}
	
    return 0;
}

