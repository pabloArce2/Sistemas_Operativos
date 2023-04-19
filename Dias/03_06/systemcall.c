#include <stdio.h>
#include <unistd.h>

int main()
{
	// Standar out salida estandar por pantalla 
	write (1, "Hola mundo\n", sizeof("Hola mundo\n"));
	
	return 0;
}
