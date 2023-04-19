
// Papa crea un hijo, el hijo espera, papa lee por teclado dos números enteros, 
// le pasa los dos numeros enteros al hijo, este una vez recibidos, 
// calcula la suma y devuelve el valor al padre, que lo presenta por pantalla

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <sys/types.h>
#include <string.h>

int main(void){
	int tuberia_hijo[2], tuberia_padre[2], num1, num2, suma;
	pid_t hijo;

	
	if (pipe(tuberia_hijo)<0 || pipe(tuberia_padre)<0){
	perror("Error al crear el pipe\n");
	return -1;
	}	
	hijo = fork();
	if (hijo < 0)
	{
		perror("Se ha producido un error al crear el hijo\n");
		return -1;
	}
	else if (hijo>0) // proceso padre
	{
		close (tuberia_padre[0]);
		close (tuberia_hijo[1]);
		printf("Escribe el primer número: ");
		scanf("%d", &num1);
		while (num1 != -1){
			printf("Escribe el segundo número: ");
			scanf("%d", &num2);
			write(tuberia_padre[1], &num1, sizeof(num1));
			write(tuberia_padre[1], &num2, sizeof(num2));
			read(tuberia_hijo[0], &suma, sizeof(suma));
			printf("La suma es %d\n", suma);
			printf("Escribe el primer número: ");
			scanf("%d", &num1);
		}
		puts("");
		kill(hijo,SIGKILL);
	}
	
	else if (hijo == 0)
	{
		close (tuberia_padre[1]);
		close (tuberia_hijo[0]);
		while(1){
			read(tuberia_padre[0], &num1, sizeof(num1));
			read(tuberia_padre[0], &num2, sizeof(num2));
			suma = num1 + num2;
			write(tuberia_hijo[1], &suma, sizeof(suma));
		}	
	}
	return 0;
}

