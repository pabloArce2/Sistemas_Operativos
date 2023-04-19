#include <stdio.h>
long int multiplica(int);
int main(void){
	int num;
	puts("Introduce un numero positivo;");
	scanf("%d",&num);
	printf("El factorial de %d es %ld\n",num, multiplica(num));
	return 0;
}

long int multiplica (int n)
{
	if (n>=1)
		return n*multiplica(n-1);
	else
		return 1;
}
