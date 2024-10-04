#include <iostream>
#include "RobotNodes.h"
using namespace std;

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************

RobotNodes::~RobotNodes()
{
   StackNode *nodePtr = nullptr, *nextNode = nullptr;

   // Position nodePtr at the top of the stack.
   nodePtr = top;

   // Traverse the list deleting each node.
   while (nodePtr != nullptr)
   {
      nextNode = nodePtr->next;
      delete nodePtr;
      nodePtr = nextNode;
   }
}

//************************************************
// Member function push pushes the argument onto *
// the stack.                                    *
//************************************************

void RobotNodes::push(float distance, float angle, bool clockwise)
{
   StackNode *newNode = nullptr; // Pointer to a new node

   // Allocate a new node and store num there.
   newNode = new StackNode;
   newNode->distance = distance;
   newNode->angle = angle;
   newNode->clockwise = clockwise;

   // If there are no nodes in the list
   // make newNode the first node.
   if (isEmpty())
   {
      top = newNode;
      newNode->next = nullptr;
   }
   else  // Otherwise, insert NewNode before top.
   {
      newNode->next = top;
      top = newNode;
   }
}

//****************************************************
// Member function pop pops the value at the top     *
// of the stack off, and copies it into the variable *
// passed as an argument.                            *
//****************************************************

void RobotNodes::pop(float & distance, float & angle, bool & clockwise)
{
   StackNode *temp = nullptr; // Temporary pointer

   // First make sure the stack isn't empty.
   if (isEmpty())
   {
      cout << "The stack is empty.\n";
   }
   else  // pop value off top of stack
   {
      distance = top->distance;
      angle = top->angle;
      clockwise = top->clockwise;

      temp = top->next;
      delete top;
      top = temp;
   }
}

//****************************************************
// Member function isEmpty returns true if the stack *
// is empty, or false otherwise.                     *
//****************************************************

bool RobotNodes::isEmpty() {
   return top == nullptr;
}