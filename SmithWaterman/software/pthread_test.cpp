#include <iostream>
#include <pthread.h>
#include <string>

void* thread_worker(void* s) {
	for (int i = 0; i < 100; i++) {
		std::cout << *((std::string *) s) << " " << i << "\n";
	}
}

int main() {
	pthread_t thread1, thread2;
	std::string str1 = "From thread 1";
	std::string str2 = "From thread 2";

	int iret1 = pthread_create( &thread1, NULL, &thread_worker, (void*) &str1);
	int iret2 = pthread_create( &thread2, NULL, &thread_worker, (void*) &str2);
	
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	std::cout << "Thread 1 returns: " << iret1 << std::endl;
	std::cout << "Thread 2 returns: " << iret2 << std::endl;

	return 0;
}
