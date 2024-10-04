// Specification file for the BinaryTree class
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <string>
#include <iostream>
using namespace std;

class BinaryTree {
private:
   struct TreeNode
   {
      int quantity;         // The value in the node
      string name;
      TreeNode* left;    // Pointer to left child node
      TreeNode* right;   // Pointer to right child node
   };

   TreeNode* root;       // Pointer to the root node

   // Private member functions
   void insert(TreeNode*&, TreeNode*&);
   void destroySubTree(TreeNode*);
   void deleteNode(string, TreeNode*&);
   void makeDeletion(TreeNode*&);
   void displayInOrder(TreeNode*) const;
   void displayPreOrder(TreeNode*) const;
   void displayPostOrder(TreeNode*) const;
   int getTreeHeight(TreeNode*) const;
   int getTotalQuantity(TreeNode* nodePtr) const;

public:
   // Constructor
   BinaryTree() {
      root = nullptr;
   }

   // Destructor
   ~BinaryTree() {
      destroySubTree(root);
   }

   // Binary tree operations
   void insertNode(string, int);
   bool searchNode(string searchName, string& name, int& quantity);
   void remove(string);

   bool compareAlphabeticalOrder(string, string);

   //Gets the height of the longest branch of the tree
   int getTreeHeight() const {return getTreeHeight(root);}

   // Display operations
   void displayRoot() const {
      cout << root->quantity << " " << root->name << endl;
   }

   void displayInOrder() const {
      displayInOrder(root);
   }

   void displayPreOrder() const {
      displayPreOrder(root);
   }

   void displayPostOrder() const {
      displayPostOrder(root);
   }

   int getTotalQuantity() const {return getTotalQuantity(root);}
};
#endif