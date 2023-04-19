#include <stdio.h>
#include <math.h>
int main(void){
	int num, numN = 0,contador = 1;
	puts("introduce un numero");
	scanf("%d", &num);
	for (int i = 0; i < num; i++){
		int potencia = pow(10,contador);
		if ((num - (num-i )) % potencia== 0){
			numN += i * potencia;
		}
		if (i > potencia){
			contador++;
		}
	}
	printf("%d", numN);
	return 0;
}
