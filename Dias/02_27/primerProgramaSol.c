#include <stdio.h>
int sum=0, resto;
int funcion_inversa(int);
int main(){
	int num,inverso;
	printf("Introduce un numero;");
	scanf("%d",&num);
	inverso = funcion_inversa(num);
	printf("El inverso del numero es: %d",inverso);
	return 0;
}
int funcion_inversa(int num){
	if(num){
		resto=num%10;
		sum=sum*10+resto;
		funcion_inversa(num/10);
	}
	else
		return sum;
	return sum;
}
