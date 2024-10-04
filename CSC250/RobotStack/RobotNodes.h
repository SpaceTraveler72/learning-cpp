// Specification file for the DynIntStack class
#ifndef ROBOTNODES_H
#define ROBOTNODES_H

class RobotNodes {
private:
   // Structure for stack nodes
   struct StackNode
   {
      float distance, angle;
      bool clockwise; // true for clockwise and false for counterclockwise
      StackNode *next;  // Pointer to the next node
   };

   StackNode *top;      // Pointer to the stack top

public:
   // Constructor
   RobotNodes()
      {  top = nullptr; }

   // Destructor
   ~RobotNodes();

   // Stack operations
   void push(float, float, bool);
   void pop(float &, float &, bool &);
   bool isEmpty();
}; 
#endif