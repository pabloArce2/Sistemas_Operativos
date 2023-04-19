// Nos pide dos num, una vez se los damos, nos da 2 hijos, uno suma, y otro los resta, el padre espera

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <stdlib.h>

int main()
{
	int num1, num2;

	printf("Introduce un par de números\n");
	read(0, &num1, sizeof(num1));
	read(0, &num2, sizeof(num2));
	
	pid_t hijoSum = fork();
	pid_t hijoRes 

	if (hijoSum == 0){ 
		int suma = num1+num2;
		printf("La suma es %d\n", suma);
		exit(0);
	}
	else{hijoRes = fork();}
	
	if (hijoRes == 0){ 
		int resta = num1-num2;
		printf("La resta es %d\n", resta);
		exit(0);
	}
	
	else{
		printf("Goodbye my friends, nos vamos");
	}

	
	return 0;
}
