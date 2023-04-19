#include <stdio.h>

int main(void)
{
	int n=7; 
	int *punt=NULL;
	punt = &n;
	printf("El valor es: %d, y esta colocada en la direccion de memoria: %p", n, &n);
	printf("La direccion de p es %p y su valor %d\n", punt, &punt);
	return 0;
}
