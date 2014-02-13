//  File Name         : threadqueue.h
//  Description       : Thread-safe queue definitions
//  Table of Contents : ThreadQueue class
//                      ThreadQueue::ThreadQueue()
//                      ThreadQueue::Push()
//                      ThreadQueue::Pop()
//                      ThreadQueue::Size()
//                      ThreadQueue::Empty()
//
//  Revision History  :
//      Albert Ng   Oct 03 2013     Initial Revision 
//      Albert Ng   Oct 07 2013     Added ThreadQueue::Size()
//      Albert Ng   Oct 10 2013     Added ThreadQueue::Empty()
//      Albert Ng   Jan 15 2014     Changed pthread_cond_signal() to
//                                    pthread_cond_broadcast()
//      Albert Ng   Feb 11 2014     Changed Empty() to call queue.empty()

#ifndef THREADQUEUE_H_
#define THREADQUEUE_H_

#include <queue>
#include <pthread.h>
#include <iostream>

// Simple thread-safe queue implementation using mutexes
//   and conditionals. Supports multiple producers and
//   multiple consumers.
// Bounded queue with a constant MAX_SIZE
template <typename T> 
class ThreadQueue {
  public:
    ThreadQueue();

    // Push onto queue, blocks (thread waits) until successful
    void Push(T data);

    // Pop from queue, blocks (thread waits) until successful
    T Pop();

    // Current number of enqueued values
    int Size();

    // Check if queue is empty
    bool Empty();
  
  private:
    std::queue<T> queue_;
    pthread_mutex_t mutex_;
    pthread_cond_t nonfull_cond_;
    pthread_cond_t nonempty_cond_;
    static const int MAX_Q_SIZE = 100000000;
};

// Simply initializes mutex and conditions
template <typename T> 
ThreadQueue<T>::ThreadQueue() {
  pthread_mutex_init(&mutex_, NULL);
  pthread_cond_init(&nonfull_cond_, NULL);
  pthread_cond_init(&nonempty_cond_, NULL);
}

// Waits using nonfull condition until queue is not full
template <typename T> 
void ThreadQueue<T>::Push(T data) {
  pthread_mutex_lock(&mutex_);
  
  while(queue_.size() == MAX_Q_SIZE) {
    //std::cout << "Full" << std::endl;
    pthread_cond_wait(&nonfull_cond_, &mutex_);
  }

  queue_.push(data);
  
  if (queue_.size() == 1) {
    pthread_cond_broadcast(&nonempty_cond_);
  }
  
  pthread_mutex_unlock(&mutex_);
}

// Waits using nonempty condition until queue is not empty
template <typename T> 
T ThreadQueue<T>::Pop() {
  pthread_mutex_lock(&mutex_);
  
  while(queue_.empty()) {
    pthread_cond_wait(&nonempty_cond_, &mutex_);
  }

  T ret = queue_.front();
  queue_.pop();
  
  if (queue_.size() == MAX_Q_SIZE-1) {
    pthread_cond_broadcast(&nonfull_cond_);
  }
  
  pthread_mutex_unlock(&mutex_);
  return ret;
}

template <typename T>
int ThreadQueue<T>::Size() {
  int size;
  pthread_mutex_lock(&mutex_);
  size = queue_.size();
  pthread_mutex_unlock(&mutex_);
  return size;
}

template <typename T>
bool ThreadQueue<T>::Empty() {
  bool empty;
  pthread_mutex_lock(&mutex_);
  empty = queue_.empty();
  pthread_mutex_unlock(&mutex_);
  return empty;
}
#endif // THREADQUEUE_H_
