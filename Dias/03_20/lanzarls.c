// sacrificamos al hijo para mantener al padre vivo
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <sys/types.h>
int main(void){
	pid_t pid;
	if ((pid = fork())== 0){
		printf("Mi id como hijo es %d\n", getpid());
		puts("Banzaiiii");
		execl("/bin/ls", "ls", "-l", NULL);
		puts("Si lees esto todos los alumnos de SO sacan un 10 en la asignatura");
	}

	wait(NULL);
	printf("Sigo vivo perras\n");
	printf("El id de mi hijo es %d\n", getpid());

	return 0;
}
