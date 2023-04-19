//convertir,anterior y siguiente
// lee una letra, y luego crea los procesos
// siguiente, letra nueva en ascii
// anterior, letra anterior

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <stdlib.h>

int main()
{
	pid_t convertidor, anterior, siguiente;
	char c, nueva;
	printf("Dime una letra\n");
	scanf("%c", &c);
	
	convertidor = fork();
	if(convertidor){
		anterior = fork();
	}
	if(anterior && convertidor){
		siguiente = fork();
	}
	if(siguiente && anterior && convertidor){		
		puts("Soy el padre, y espero a que acaben los hijos");
		while(wait(NULL)>0); // El while se pone porque esta esperando a mas de uno
		puts("Los hijos ya han terminado, adios");
		}
	
	if (convertidor == 0 ){
		if (c >= 'a' && c<='z'){
			nueva=c-'a'+'A';}
		else if (c >= 'A' && c<='Z'){
			nueva=c-'A'+'a';}
		exit(0);
	}
	if (anterior == 0)
	{
		sleep(1);
		printf("La letra anterior es %c\n",c);
		exit(0);
	}
	if (siguiente == 0)
	{
		if (c >= 'a' && c<='z'){
			nueva=c-'a'+'A';}
		else if (c >= 'A' && c<='Z'){
			nueva=c-'A'+'a';}
		sleep(2);
		printf("La letra nueva es %c\n",nueva);
		exit(0);
	}
	return 0;
}
