#include <string.h>
#include <stdio.h>
int main(void)
{
	char comando[30];
	scanf("%s", comando);
	//
	char prueba[30] = "hola buenos dias";
	comando[4] = '\0';
	puts(prueba);
	printf("\n %c\n", prueba[10]);
	//
	char cadena[50]="/bin/";
	strcat(cadena, comando);
	puts(cadena);
	printf("La longitud de la cadena \"%s\" es %zu\n", cadena, strlen(cadena));
	return 0;
}
