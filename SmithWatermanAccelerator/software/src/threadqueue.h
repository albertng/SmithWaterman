//  File Name        : threadqueue.h
//  Description      : Thread-safe queue definitions
//
//  Revision History :
//      Albert Ng   Oct 03 2013     Initial Revision 
//

#ifndef THREADQUEUE_H_
#define THREADQUEUE_H_

#include <queue>
#include <pthread.h>

template <typename T> 
class ThreadQueue {
  public:
    ThreadQueue();
    void push(T data);
    T pop();
    
  private:
    std::queue<T> queue_;
    pthread_mutex_t mutex_;
    pthread_cond_t nonfull_cond_;
    pthread_cond_t nonempty_cond_;
    static const int MAX_SIZE = 100;
};

template <typename T> 
ThreadQueue<T>::ThreadQueue() {
  pthread_mutex_init(&mutex_, NULL);
  pthread_cond_init(&nonfull_cond_, NULL);
  pthread_cond_init(&nonempty_cond_, NULL);
}

template <typename T> 
void ThreadQueue<T>::push(T data) {
  pthread_mutex_lock(&mutex_);
  
  if (queue_.size() == MAX_SIZE) {
    pthread_cond_wait(&nonfull_cond_, &mutex_);
  }

  queue_.push(data);
  
  if (queue_.size() == 1) {
    pthread_cond_signal(&nonempty_cond_);
  }
  
  pthread_mutex_unlock(&mutex_);
}

template <typename T> 
T ThreadQueue<T>::pop() {
  pthread_mutex_lock(&mutex_);
  
  if (queue_.empty()) {
    pthread_cond_wait(&nonempty_cond_, &mutex_);
  }

  T ret = queue_.front();
  queue_.pop();
  
  if (queue_.size() == MAX_SIZE-1) {
    pthread_cond_signal(&nonfull_cond_);
  }
  
  pthread_mutex_unlock(&mutex_);
  return ret;
}

#endif // THREADQUEUE_H_
