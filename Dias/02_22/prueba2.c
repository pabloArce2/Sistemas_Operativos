#include <stdio.h>

int main(void)
{
	int a, b;
	puts("introduce un número por teclado");
	scanf("%d", &a);
	puts("Introduce una segunda variable");
	scanf("%d", &b);
	printf("La suma de %d, y %d, es %d\n",a,b,a+b);
	return 0;
}

