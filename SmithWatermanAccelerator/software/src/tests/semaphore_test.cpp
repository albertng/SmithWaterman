#include <iostream>
#include <pthread.h>
#include <semaphore.h>

void* consume(void* args) {
	sem_t* semaphore = (sem_t*) args;
	int val;

	while(true) {
		sem_wait(semaphore);
		sem_getvalue(semaphore, &val);
		std::cout<<val<<std::endl;
	}
}
	
void* produce(void* args) {
	sem_t* semaphore = (sem_t*) args;

	while(true) {
		sem_post(semaphore);
		sleep(1);
	}
}

int main (void) {
	pthread_t producer;
	pthread_t consumer;
	
	sem_t semaphore;
	sem_init(&semaphore, 0, 5);

	pthread_create(&producer, NULL, &produce, &semaphore);
	pthread_create(&consumer, NULL, &consume, &semaphore);

	pthread_join(producer, NULL);
	pthread_join(consumer, NULL);	
	
	return 0;
}
