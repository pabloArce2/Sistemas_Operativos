#include <stdio.h>
#include <math.h>
int main(void)
{
	int c, val = 0;
	puts("introduce un número");
	scanf("%d", &c);
	for (int i = 2; i < sqrt(c); i++)
	{
		if (c%i == 0) 
		{
			val = 1;
			break;
		}
	}
	if (val == 1){printf("El numero %d no es primo",c);}
	else{printf("El numero %d es primo",c);}
	return 0;
}

