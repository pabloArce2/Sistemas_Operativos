#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <stdlib.h>

int main()
{
	int i;
	fork();
	for (i=0; i<1000; i++){
			printf("Proceso %zu - Valor de i: %d\n", (long)getpid(), i);  // Se van intercalando, a tiempos distintos
	}
}
