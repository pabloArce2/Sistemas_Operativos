#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <stdlib.h>

int main()
{
	pid_t suma, resta;
	int num1=6, num2=5;
	
	suma = fork();
	if(suma){
		resta = fork();
	}
	if (suma!=0 && resta!=0)
	{
		puts("Soy el padre, y espero a que acaben los hijos");
		while(wait(NULL)>0); // El while se pone porque esta esperando a mas de uno
		puts("Los hijos ya han terminado, adios");
	}
	else if (suma == 0 && resta != 0)
	{
		sleep(1);
		printf("La suma es %d\n",num1+num2);
		exit(0);
	}
	else if (suma != 0 && resta == 0)
	{
		sleep(3);
		printf("La resta es %d\n",num1-num2);
		exit(0);
	}
	return 0;
}
