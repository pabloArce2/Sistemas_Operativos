#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>

int main()
{
	
	printf("Soy el proceso padre con PID %ld\n", (long)getpid());
	pid_t hijo = fork(); // para el padre, hijo vale un numero positivo, para el hijo, siempre va a ser 0
	if (hijo == 0){ 
		
		sleep(2);
		printf ("Hola, soy el proceso hijo con PID %ld\n", (long)getpid());
		printf("Mi padre tiene PID %ld\n", (long)getppid());
	}
	
	else{
		//wait(NULL); espera al hijo
		while(wait(NULL)>0);
		printf("Hola soy el proceso padre, mi hijo tiene PID %ld\n", (long)hijo);
	}
	
	
	
	//fork();  hay dos procesos que se estan ejecutando
	//write (1, "Escribe un num\n", sizeof("Escribe un num\n"));
	//read(0, &n, sizeof(n));
	//write(1, &n, sizeof(n));
	
	return 0;
}
