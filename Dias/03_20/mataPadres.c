#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <sys/types.h>
int main(void){
	printf("Soy el proceso padre con PID, %ld\n", (long)getpid());
	pid_t hijo;
	if ((hijo = fork())<0){
		printf("Error al crear el proceso");
		exit(-1);
	}
	else if (hijo>0){
		sleep(1);
		printf("Soy el padre y me despido\n");
		exit(0);
	}
	else{
		printf("Hola soy el hijo %ld\n",(long)getpid());
		sleep(3);
		printf("Hola soy el hijo, y mi padre muerto es %ld\n",(long)getppid());
		sleep(200);
	}
	return 0;
}
