/*
* a program that demonstrate race condition.
*/
#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITERATION 1000000

size_t counter = 0;

void *increment_counter(void *args)
{
	pthread_t id = pthread_self();
	printf("thread %lu started incrementing the counter...\n", id);
	for (size_t i = 0; i < MAX_ITERATION; i++)
		counter++;
}

int main(void)
{
	pthread_t t1, t2;

	if (pthread_create(&t1, NULL, increment_counter, NULL) != 0)
		return EXIT_FAILURE;
	if (pthread_create(&t2, NULL, increment_counter, NULL) != 0)
		return EXIT_FAILURE;

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	printf("total counter after both thread exit: %ld\n", counter);

	return 0;
}