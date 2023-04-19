#include <string.h>
#include <stdio.h>
int main(void)
{
	char nombre[50];
	printf("Introduce tu nombre: ");
	scanf("%s", nombre);
	char apellido1[20];
	printf("Introduce tu apellido: ");
	scanf("%s", apellido1);
	char apellido2[20];
	printf("Introduce tu apellido: ");
	scanf("%s", apellido2);
	char space[2] = " ";
	strcat(nombre, space);
	strcat(nombre, apellido1);
	strcat(nombre, space);
	strcat(nombre, apellido2);
	printf("Te llamas %s ", nombre);
	return 0;
}
