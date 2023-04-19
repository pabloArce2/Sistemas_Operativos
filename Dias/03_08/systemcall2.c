#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

int main()
{
	register int syscall_no asm("rax") = 1;
	register int arg1 asm("rdi") = 1;
	register char* arg2 asm ("rsi") = "Hola mundo\n";
	register int arg3 asm ("rdx")=sizeof("Hola mundo");
	asm("syscall");
	return 0;
}

