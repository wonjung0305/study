#ifndef BST_H
#define BST_H

#include <string>

using namespace std;

struct Node{
  string value; // string value (user input)
  int key;  // number

  Node* left; // left node
  Node* right;  // right node
};

class BST{
private:
  Node* root; // root Node

public:
  BST();  //Constructor
  ~BST();  // Destructor

  void clear(Node* node); // delete all node

  bool isEmpty(); // check whether it is empty
  void addNode(int key, string value); // add the node
  void deleteNode(int key); // delete the node

  void checkOrder(Node* node);  // check the order(in inorder)
  void printNode();  // print the node(in inorder)
  void quit();  // end the program;


};

#endif 