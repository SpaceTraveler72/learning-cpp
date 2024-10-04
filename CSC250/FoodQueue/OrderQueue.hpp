// Specification file for the OrderQueue class
#ifndef ORDERQUEUE_H
#define ORDERQUEUE_H

#include <string>
using namespace std;


template <typename T>
class OrderQueue {
private:
   T* queueArray;  // Points to the queue array
   int queueSize;    // The queue size
   int front;        // Subscript of the queue front
   int rear;         // Subscript of the queue rear
   int numItems;     // Number of items in the queue
public:
   // Constructor
   OrderQueue(int);

   // Copy constructor
   OrderQueue(const OrderQueue<T>&);

   // Destructor
   ~OrderQueue();

   // Adds a new object at the end of queue
   void enqueue(const T&);
   // removes the object at the start of the queue and returns it thought the parameter passed in
   void dequeue(T&);
   // Queue operations
   bool isEmpty() const;
   bool isFull() const;
};

#endif