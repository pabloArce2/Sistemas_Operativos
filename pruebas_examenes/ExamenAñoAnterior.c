#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <stdlib.h>
#include <ctype.h> 
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <pthread.h>

#define SIZE 3

pthread_t master, par, impar;

int matriz[SIZE][SIZE];

void* masterWork();
void* parWork();
void* imparWork();

void mataALosHilos();
void pintaMatriz();

int numeroIntroducido=0;
int posicionArray=0;
int programaAcabado=0; //1 para matar el par, 2 para matar el impar
int i, j;

void manejador(int signum){}


int main (void) {
	
	signal(SIGUSR1, manejador);
	
	pthread_create(&master, NULL, &masterWork, NULL);
	pthread_create(&par, NULL, &parWork, NULL);
	pthread_create(&impar, NULL, &imparWork, NULL);
	
	pthread_join(impar, NULL);
	pthread_join(par, NULL);
	pthread_join(master, NULL);
	
	
	return 0;
	
}

void *masterWork(){
	usleep(2);
	
	for (i=0; i<SIZE;i++){
		for (j=0; j<SIZE;j++){

			if ( (i+j) % 2 == 0 || (i==0 && j==0)){
				
				pthread_kill(par,SIGUSR1);
				
			} else {
				
				pthread_kill(impar,SIGUSR1);
				
			}
			pause();
		}
	}
	
	printf("\n\n");
	
	// funcion para recorrer la matriz llena y pintarla
	pintaMatriz();
	
	// funcion para matar los hilos en orden, cuando muera el par nos envia un kill
	mataALosHilos();
	pause();

	return 0;
}

void *parWork(){
	
	while (programaAcabado != 1){
		pause();
		
		if (i==SIZE && j==SIZE){} //cuando llegamos al final de la matriz, saltamos la recogida de datos
		else {
			printf("Soy hilo par, introduce un valor para la posicion [%d][%d]: ",i,j);
			scanf("%d", &numeroIntroducido);
			matriz[i][j]=numeroIntroducido;
			pthread_kill(master,SIGUSR1);
		}
	}
	
	puts("hilo par, dispuesto a morir");
	
	pthread_kill(master,SIGUSR1);
	
	return 0;
}

void *imparWork(){
	
	while (programaAcabado != 2){
		pause();
		
		if (i==SIZE && j==SIZE){}//cuando llegamos al final de la matriz, saltamos la recogida de datos
		else {
			printf("Soy hilo impar, introduce un valor para la posicion [%d][%d]: ",i,j);
			scanf("%d", &numeroIntroducido);
			matriz[i][j]=numeroIntroducido;
			pthread_kill(master,SIGUSR1);
		}
	}
	
	puts("hilo impar, dispuesto a morir");

	return 0;
}


void mataALosHilos(){
	programaAcabado=2;
	pthread_kill(impar,SIGUSR1);
	
	usleep(2);
	
	programaAcabado=1;
	pthread_kill(par,SIGUSR1);
}


void pintaMatriz(){
	for (i=0; i<SIZE;i++){
		for (j=0; j<SIZE;j++){
			printf("%d ",matriz[i][j]);	
		}
	printf("\n");
	}
}
