#include <sys/mman.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <sys/types.h>
#include <string.h>

static int *variable_compartida, *global_flag;

int main(void) 
{
    pid_t lee, escribe;
    variable_compartida = mmap(NULL, sizeof *variable_compartida, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS,  -1, 0);
    global_flag= mmap(NULL, sizeof *global_flag, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS,  -1, 0);
    *global_flag = -1;
    lee = fork();
    if (lee>0)
    {
		escribe = fork();
	}
	if (lee == 0){
		printf("Soy el proceso %d, introduce un número: ", getpid());
		scanf("%d", *&variable_compartida);
		*global_flag = 1;
		exit(0);
	}
	if (escribe == 0){
		while (*global_flag==-1) usleep(1); // con el usleep dejamos descanso de micras al programa
		printf("Soy el proceso %d y el número tecleado es %d\n", getpid(),  *variable_compartida);
		exit(0);
	}
	while (wait (NULL) > 0);
	puts("Soy el padre");

    return 0;
}

