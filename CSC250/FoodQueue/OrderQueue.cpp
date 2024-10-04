// Implementation file for the OrderQueue
#include <iostream>
#include "OrderQueue.hpp"

//***************************************************************
// This constructor creates an empty queue of a specified size. *
//***************************************************************

template <typename T>
OrderQueue<T>::OrderQueue(int s) {
   queueArray = new T[s];
   queueSize = s;
   front = -1;
   rear = -1;
   numItems = 0;
}

//***************************************************************
// Copy constructor                                             *
//***************************************************************
template <typename T>
OrderQueue<T>::OrderQueue(const OrderQueue<T>& obj) {
   // Allocate the queue array.
   queueArray = new T[obj.queueSize];

   // Copy the other object's attributes.
   queueSize = obj.queueSize;
   front = obj.front;
   rear = obj.rear;
   numItems = obj.numItems;

   // Copy the other object's queue array.
   for (int count = 0; count < obj.queueSize; count++)
      queueArray[count] = obj.queueArray[count];
}

//***************************************************************
// Destructor                                                   *
//***************************************************************
template <typename T>
OrderQueue<T>::~OrderQueue() {
   delete[] queueArray;
}

//***************************************************************
// Function enqueue inserts a value at the rear of the queue.   *
//***************************************************************
template <typename T>
void OrderQueue<T>::enqueue(const T& num) {
   if (isFull())
      cout << "The queue is full.\n";
   else {
      // Calculate the new rear position
      rear = (rear + 1) % queueSize;
      // Insert new item
      queueArray[rear] = num;
      // Update item count
      numItems++;
   }
}

//***************************************************************
// Function dequeue removes the value at the front of the queue * 
// and copies t into num.                                       *
//***************************************************************
template <typename T>
void OrderQueue<T>::dequeue(T& num) {
   if (isEmpty())
      cout << "The queue is empty.\n";
   else {
      // Move front
      front = (front + 1) % queueSize;
      // Retrieve the front item
      num = queueArray[front];
      // Update item count
      numItems--;
   }
}

//***************************************************************
// isEmpty returns true if the queue is empty, otherwise false. *
//***************************************************************
template <typename T>
bool OrderQueue<T>::isEmpty() const {
   return numItems == 0;
}

//***************************************************************
// isFull returns true if the queue is full, otherwise false.   *
//***************************************************************
template <typename T>
bool OrderQueue<T>::isFull() const {
   return numItems >= queueSize;
}
