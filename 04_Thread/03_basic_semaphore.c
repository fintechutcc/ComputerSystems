/*
 * How to compile: gcc 03_basic_semaphore.c -o 03_basic_semaphore.c -lpthread -lrt
 */

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;

void* thread(void* arg)
{
    char *tid = (char*)arg;

	//wait
	sem_wait(&mutex);
	printf("\nEntered...tid(%s).\n", tid);

	//critical section
	printf("tid(%s) is in critical section.\n", tid);
	
	//signal
	printf("Just Exiting...tid(%s).\n", tid);
	sem_post(&mutex);
}


int main()
{
	sem_init(&mutex, 0, 1);
	pthread_t t1,t2;
	pthread_create(&t1,NULL,thread,"1");
	pthread_create(&t2,NULL,thread,"2");
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	sem_destroy(&mutex);
	return 0;
}
