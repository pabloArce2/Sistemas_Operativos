#include <stdio.h>
#define MAX 10
int main(void)
{
	int var2[MAX] = {0,1,2,3,4,5,6,7,8,9};
	int *p = NULL;
	for (int i = 0; i<MAX; i++){
		printf("%d ", var2[i]);
	}
	printf ("\n");
	
															
	// CON PUNTEROS
	//int var = 10000;
	//printf("%zu",sizeof(var));
	
	p=var2;
	for (int i=0; i<MAX; i++, p++){
		printf("%d ", *p);
	}
	return 0;
}

