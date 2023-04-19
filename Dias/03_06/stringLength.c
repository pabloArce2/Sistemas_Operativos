#include <string.h>
#include <stdio.h>

int stringLength (char*);

int main(void)
{
	// fgets == scanf con espacios
	char cadena[125];
	printf("Introduce una cadena: ");
	fgets(cadena,sizeof(cadena),stdin);
	printf("La longitud de \"%s\" es %d\n", cadena, stringLength(cadena));
}

int stringLength (char *str){
		int contador = 0;
		while (1){
			if (*str == '\0'){return contador;}
			contador++;
			str++;
		}
	}
