#include "BST.h"

#include <iostream>
#include <string>

using namespace std;

//Constructor
BST::BST(){
  root = nullptr; // initialize root
}
// Destructor
BST::~BST(){
  // dellocate root ==> left-> right -> root
  clear(root);
}

// delete all node
void BST::clear(Node* node){
  // If there is no more node(or empty), return
  if(node == nullptr){
    return;
  }

  // left -> right, recursive
  clear(node->left);  
  clear(node->right);

  delete node;  // delete node(current/now)
}

// check the tree whether it is empty
bool BST::isEmpty(){
  return root == nullptr;
}

 // add the node
void BST::addNode(int key, string value){
  // make a new node
  Node* newNode = new Node;

  // initialize
  newNode-> key = key;
  newNode-> value = value;
  newNode->left = nullptr;
  newNode->right = nullptr;

  // if ther is no node => newnode is root
  if(isEmpty()){
    root = newNode;
    return;
  }

  // root -> left -> right
  Node* cur = root;
  Node* parent = nullptr; // parent node

  // check the node until leaf
  while(cur != nullptr){
    parent = cur; // set parent node

    if(key == cur->key){  // check if there is same node
      cout << key << " is already in the tree" << endl;
      delete newNode;
      return;
    }

    // key > cur->key go right, key < cur->key go left
    if(key < cur->key) cur = cur->left;
    else cur = cur->right;
  }

  // set the newNode
  if(key < parent -> key) parent->left = newNode;
  else parent->right = newNode;

}

// delete the node
void BST::deleteNode(int key){
  // initialize the node
  Node* cur = root; // root -> left -> right
  Node* parent = nullptr;

  // until the end && until find the key
  while(cur != nullptr && cur->key != key){
    parent = cur;

    if(key < cur->key) cur = cur->left; // key < cur->key, go left
    else cur = cur-> right; // key > cur->right, go right
  }

  // no key
  if(cur == nullptr){
    cout << key << " is not in the tree" << endl;
    return;
  }

// if it is leaf node
  if(cur->left == nullptr && cur->right == nullptr){ // no left child, right child
    if(cur== root){ // if it is root
      delete cur; // delete root
      root = nullptr; // initialize root
    }
    else{
      if(parent->left == cur) parent->left = nullptr; // if cur is left child of parent, disconnect
      else parent->right = nullptr; // right child of parent
      delete cur; // delete cur
    }
    return;
  }

  // one child(only left child)
  if(cur->left != nullptr && cur->right == nullptr ){ 
    if(cur == root) root = cur->left;
    else {
      if(parent->left == cur) parent->left = cur->left; // connect path (left)
      else parent->right = cur->left; // connect path(right)
    } 
    delete cur; // delete node
    return;
  }
  // onc child(only right child)
  if(cur->right != nullptr && cur->left == nullptr){
    if(cur == root) root = cur->right;
    else{
      if(parent->left ==  cur ) parent->left = cur->right;  
      else parent->right = cur->right;
    }
    delete cur;
    return;
  }

  // two child (minimu at the right subtree )
  Node* minimum = cur->right;
  Node* minimumParent = cur;

  // in the right subtree, find the minimum value(find minimum leaf node)
  while(minimum->left != nullptr){
    minimumParent = minimum;
    minimum = minimum->left;
  }

  // copy the data (set cur)
  cur->key = minimum->key;  // set key
  cur->value = minimum->value;  // set value

  //  minimum == left child of parent
  if(minimumParent->left == minimum){
    minimumParent->left = minimum->right; // connect left node to right node
  }
  else{ // if minimum is right child
    minimumParent->right = minimum->right;  // connect right node to left node
  }

  // delete minimum node
  delete minimum;

}

// check the order(in inorder), print format (key,value)
void BST::checkOrder(Node* node){
  // If there is no more node(or empty), return
  if(node == nullptr){
    return;
  }

  // check left subtree
  checkOrder(node-> left);

  // print
  cout << "(" << node->key << ", " << node->value << ")" << endl;

  // check right subtree
  checkOrder(node->right);

}

// print the node(in inorder) <= use check order
void BST::printNode(){

  if(isEmpty()){
    cout << "Error: Empty" << endl;
    return;
  }

  // check root -> left -> right
  checkOrder(root);
}

// end the program;
void BST::quit(){
  exit(0);  
}