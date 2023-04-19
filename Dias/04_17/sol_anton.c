#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int num_iterations;
int *fibonacci_sequence;
pthread_mutex_t mutex;

void *fibonacci(void *arg) {
	int i;
	fibonacci_sequence[0] = 0;
	fibonacci_sequence[1] = 1;
	printf("%d\n%d\n", fibonacci_sequence[0], fibonacci_sequence[1]);
	for (i = 2; i < num_iterations; i++) {
    	fibonacci_sequence[i] = fibonacci_sequence[i-1] + fibonacci_sequence[i-2];
    	printf("%d\n", fibonacci_sequence[i]);
	}
	pthread_exit(NULL);
}


void *is_prime(void *arg) {
	int i, last_num;
	last_num = fibonacci_sequence[num_iterations-1];
	for (i = 2; i < last_num; i++) {
    	if (last_num % i == 0) {
        	pthread_exit(NULL);
    	}
	}
	printf("%d is prime!\n", last_num);
	pthread_exit(NULL);
}

int main() {
	pthread_t fib_tid, prime_tid;
	int i;

	printf("Enter the number of iterations for the Fibonacci sequence: ");
	scanf("%d", &num_iterations);

	fibonacci_sequence = (int *) malloc(num_iterations * sizeof(int));

	pthread_mutex_init(&mutex, NULL);

	pthread_create(&fib_tid, NULL, fibonacci, NULL);
	pthread_create(&prime_tid, NULL, is_prime, NULL);

	pthread_join(fib_tid, NULL);
	pthread_join(prime_tid, NULL);

	pthread_mutex_destroy(&mutex);

	free(fibonacci_sequence);

	return 0;
}
