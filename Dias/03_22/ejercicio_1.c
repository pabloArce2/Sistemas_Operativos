#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <sys/types.h>
#include <string.h>
int main(void){
	pid_t hijo;
	int tuberia[2];
	
	if (pipe(tuberia)<0){
	perror("Error al crear el pipe\n");
	return -1;
	}	
	if ((hijo = fork())<0)
	{
		perror("Se ha producido un error al crear el hijo\n");
		return -1;
	}
	else if (hijo>0)
	{
		close (tuberia[0]);
		char mensaje[] = "Hola buenos dias hijo";
		write(tuberia[1], mensaje, sizeof(mensaje));
		wait(NULL);
	}
	else{
		close(tuberia[1]);
		char buffer[100];
		read(tuberia[0], buffer, sizeof(buffer));
		printf("Mi padre me ha escrito \"%s\"\n", buffer);
		exit(0);
	}
	puts("Mi hijo ha muerto");
	return 0;
}
	



