#include <stdio.h>

void saca_char(char);

int main(void)
{
	char c;
	puts("introduce un caracter");
	scanf("%c", &c);
	saca_char(c);
	return 0;
}

void saca_char(char c)
{
	printf("El código ASCII de %c es %d\n",c,c);
}
