// Implementation file for the BinaryTree class
#include <algorithm>
#include "BST.h"
using namespace std;

//*************************************************************
// insert accepts a TreeNode pointer and a pointer to a node. *
// The function inserts the node into the tree pointed to by  *
// the TreeNode pointer. This function is called recursively. *
//*************************************************************

void BinaryTree::insert(TreeNode*& nodePtr, TreeNode*& newNode) {
   if (nodePtr == nullptr)
      nodePtr = newNode;                  // Insert the node.
   else if (compareAlphabeticalOrder(newNode->name, nodePtr->name))
      insert(nodePtr->left, newNode);     // Search the left branch
   else
      insert(nodePtr->right, newNode);    // Search the right branch
}

//**********************************************************
// insertNode creates a new node to hold num as its value, *
// and passes it to the insert function.                   *
//**********************************************************

void BinaryTree::insertNode(string name, int quantity) {
   TreeNode* newNode;	// Pointer to a new node.

   // Create a new node and store num in it.
   newNode = new TreeNode;
   newNode->name = name;
   newNode->quantity = quantity;
   newNode->left = newNode->right = nullptr;

   // Insert the node.
   insert(root, newNode);
}

//***************************************************
// destroySubTree is called by the destructor. It   *
// deletes all nodes in the tree.                   *
//***************************************************

void BinaryTree::destroySubTree(TreeNode* nodePtr) {
   if (nodePtr) {
      if (nodePtr->left)
         destroySubTree(nodePtr->left);
      if (nodePtr->right)
         destroySubTree(nodePtr->right);
      delete nodePtr;
   }
}

//***************************************************
// searchNode determines if a value is present in   *
// the tree. If so, the function returns true.      *
// Otherwise, it returns false.                     *
//***************************************************

bool BinaryTree::searchNode(string searchName, string& name, int& quantity) {
   TreeNode* nodePtr = root;

   while (nodePtr) {
      if (nodePtr->name.find(searchName) == 0) {
         name = nodePtr->name;
         quantity = nodePtr->quantity;
         return true;
      }
      else if (compareAlphabeticalOrder(searchName, nodePtr->name))
         nodePtr = nodePtr->left;
      else
         nodePtr = nodePtr->right;
   }
   return false;
}

//**********************************************
// remove calls deleteNode to delete the       *
// node whose value member is the same as num. *
//**********************************************

void BinaryTree::remove(string name) {
   deleteNode(name, root);
}


//********************************************
// deleteNode deletes the node whose value   *
// member is the same as num.                *
//********************************************

void BinaryTree::deleteNode(string name, TreeNode*& nodePtr) {
   if (name.compare(nodePtr->name) == 0)
      makeDeletion(nodePtr);
   else if (compareAlphabeticalOrder(name, nodePtr->name))
      deleteNode(name, nodePtr->left);
   else
      deleteNode(name, nodePtr->right);
}


//***********************************************************
// makeDeletion takes a reference to a pointer to the node  *
// that is to be deleted. The node is removed and the       *
// branches of the tree below the node are reattached.      *
//***********************************************************

void BinaryTree::makeDeletion(TreeNode*& nodePtr) {
   // Define a temporary pointer to use in reattaching
   // the left subtree.
   TreeNode* tempNodePtr = nullptr;

   if (nodePtr == nullptr)
      cout << "Cannot delete empty node.\n";
   else if (nodePtr->right == nullptr) {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->left;   // Reattach the left child
      delete tempNodePtr;
   }
   else if (nodePtr->left == nullptr) {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->right;  // Reattach the right child
      delete tempNodePtr;
   }
   // If the node has two children.
   else {
      // Move one node the right.
      tempNodePtr = nodePtr->right;
      // Go to the end left node.
      while (tempNodePtr->left != nullptr)
         tempNodePtr = tempNodePtr->left;
      // Reattach the left subtree.
      tempNodePtr->left = nodePtr->left;
      tempNodePtr = nodePtr;
      // Reattach the right subtree.
      nodePtr = nodePtr->right;
      delete tempNodePtr;
   }
}

//Gets the height of the longest branch of the tree
int BinaryTree::getTreeHeight(TreeNode* root) const {
   if (root == nullptr) return -1; // Height of an empty tree is -1

   // Recursively find the height of the left and right subtrees
   int left_height = getTreeHeight(root->left);
   int right_height = getTreeHeight(root->right);

   // Height of the tree is the maximum height of the left and right subtrees plus 1 for the current node
   return 1 + max(left_height, right_height);
}

// Compares two strings and returns true if the first string should come before the second
bool BinaryTree::compareAlphabeticalOrder(string first, string second) {
   for (int i = 0; i < first.length(); i++) {
      if (i >= second.length()) return false; // this return is in case both strings are the same but second is shorter
      if (tolower(first[i]) < tolower(second[i])) return true;
      if (tolower(first[i]) > tolower(second[i])) return false;
   }

   // this return is in case both strings are the same but first is shorter
   return true;
}

//****************************************************************
// The displayInOrder member function displays the values        *
// in the subtree pointed to by nodePtr, via inorder traversal.  *
//****************************************************************

void BinaryTree::displayInOrder(TreeNode* nodePtr) const {
   if (nodePtr) {
      displayInOrder(nodePtr->left);
      cout << nodePtr->quantity << " " << nodePtr->name << endl;
      displayInOrder(nodePtr->right);
   }
}

//****************************************************************
// The displayPreOrder member function displays the values       *
// in the subtree pointed to by nodePtr, via preorder traversal. *
//****************************************************************

void BinaryTree::displayPreOrder(TreeNode* nodePtr) const {
   if (nodePtr) {
      cout << nodePtr->quantity << " " << nodePtr->name << endl;
      displayPreOrder(nodePtr->left);
      displayPreOrder(nodePtr->right);
   }
}

//****************************************************************
// The displayPostOrder member function displays the values      *
// in the subtree pointed to by nodePtr, via postorder traversal.*
//****************************************************************

void BinaryTree::displayPostOrder(TreeNode* nodePtr) const {
   if (nodePtr) {
      displayPostOrder(nodePtr->left);
      displayPostOrder(nodePtr->right);
      cout << nodePtr->quantity << " " << nodePtr->name << endl;
   }
}

// Returns the total quantity of prizes
int BinaryTree::getTotalQuantity(TreeNode* nodePtr) const {
   int sum = 0;
   if (nodePtr) {
      sum += getTotalQuantity(nodePtr->left);
      sum += getTotalQuantity(nodePtr->right);
      return sum + nodePtr->quantity;
   }
   return 0;
}