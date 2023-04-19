#include <sys/mman.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <sys/types.h>
#include <string.h>

void* crear_memoria_compartida(size_t size){
		int protection = PROT_READ | PROT_WRITE;
		int visibility = 	MAP_SHARED | MAP_ANONYMOUS;
		return mmap(NULL, size, protection, visibility, -1, 0);
	}

int main(void) 
{
	char mensaje_padre[] = "Hola buenos dias";
	char mensaje_hijo []= "Adios viejo de los cojones";
	void* shmem = crear_memoria_compartida(128);
	memcpy(shmem, mensaje_padre, sizeof(mensaje_padre));
	pid_t hijo = fork();
	if (hijo == 0)
	{
		printf("Soy el hijo y leo %s\n", (char*)shmem);
		memcpy(shmem, mensaje_hijo, sizeof(mensaje_hijo));
		printf("Soy el hijo y he cambiado la memoria a: %s\n", (char*)shmem);
	}
	else
	{
		printf("Soy el padre y leo: %s\n", (char*)shmem);
		sleep(2);
		printf("Soy el padre y despues de 2 seg leo: %s\n", (char*)shmem);
	}
	
    return 0;
}

