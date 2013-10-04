//  File Name        : threadqueue_test.cpp
//  Description      : Thread-safe queue test
//
//  Revision History :
//      Albert Ng   Oct 03 2013     Initial Revision 
//

#include "threadqueue.h"
#include <iostream>
#include <pthread.h>

ThreadQueue<int> tqueue;
pthread_mutex_t cout_mutex;

void* producer_fn(void* id) {
  int i = 0;
  while (true) {
    tqueue.push(i);
    pthread_mutex_lock(&cout_mutex);
    std::cout << "Producer: " << i << std::endl;
    pthread_mutex_unlock(&cout_mutex);
    i++;
  }
}

void* consumer_fn(void* id) {
  while(true) {
    int i = tqueue.pop();
    pthread_mutex_lock(&cout_mutex);
    std::cout << "Consumer " << *((int*) id) << ": " << i << std::endl;
    pthread_mutex_unlock(&cout_mutex);
    
    sleep(1);
  }
}

int main() {
  pthread_t producer;
  pthread_t consumer1;
  pthread_t consumer2;
  
  int prod_id = 0;
  int cons1_id = 1;
  int cons2_id = 2;
  
  pthread_mutex_init(&cout_mutex, NULL);

  pthread_create(&producer, NULL, &producer_fn, (void *) &prod_id);
  pthread_create(&consumer1, NULL, &consumer_fn, (void *) &cons1_id);
  pthread_create(&consumer2, NULL, &consumer_fn, (void *) &cons2_id);
  
  pthread_join(producer, NULL);
  pthread_join(consumer1, NULL);
  pthread_join(consumer2, NULL);

  return 0;
}
