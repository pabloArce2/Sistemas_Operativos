#include <stdio.h>
#define MAX 100
int main(void)
{
	int var2[MAX], length, pos, val;
	int *p = NULL;
	printf("Dime el número de elementos ");
	scanf("%d",&length);
	printf("Introduce ahora los %d valores del array ", length);
	p = var2;
	for (int i = 0; i<length; i++, p++){
		int numActual;
		scanf("%d",&numActual);
		*p = numActual;
	}
	printf("Introduce la posición en la que quieres meter el número nuevo ");
	scanf("%d",&pos);
	pos--;
	printf("Introduce el valor a insertar ");
	scanf("%d",&val);
	
	int lastNumber, actualNumber = val;
	for (int i = 0; i<length+1; i++){
		if (i >= pos){
			lastNumber = var2[i];
			var2[i] = actualNumber;
			actualNumber = lastNumber;
		}
		printf("%d ", var2[i]);
	}
	return 0;
}
