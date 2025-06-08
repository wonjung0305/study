
#include <iostream>
#include <string>

#include "BST.h"

using namespace std;

// constructor
Node::Node(string original, string target){
    key = original; // key is original word
    data = target;  // data is target word
    
    left = nullptr; // initialize
    right = nullptr;
  }

// constructor
BST::BST(){
  root = nullptr; // initialize root
}

// destructor
BST::~BST(){
  clear(root);  // delete all node
}

void BST::clear(Node* ptr){
  // base
  if(ptr == nullptr){
    return;
  }

  clear(ptr->left); // delete left
  clear(ptr->right);  // delete right

  delete ptr; //delete node
}

// change source word->keyword
void BST::change(Node*& ptr, string key, string data){
  // if there is no key
  if(ptr == nullptr){ // 
    ptr = new Node(key, data); // make a new node
    return;
  }

  if(key == ptr->key){  //if the key is already exist
    ptr->data = data; // update data
  }
  else if(key < ptr-> key){ // recursion left
    change(ptr->left, key, data);
  }
  else{ // recursion right
    change(ptr->right, key, data);
  }
}

// call from main (main can't acces Node)
void BST::change(string key, string data){
  change(root, key, data);
}

// find source word
string BST::find(Node* ptr, string key){

  // find key
  while(ptr != nullptr){
    if(key == ptr->key){  // if find key
      return ptr->data; // return the data(Target)
    }
    else if(key < ptr->key){  // if key < ptr-> key
      ptr = ptr->left;  // go left
    }
    else{ // if key > ptr-> key
      ptr = ptr->right; // go right
    }
  }

  return "";  // not found
}

// call from main (main can't acces Node)
string BST::find( string key){
  return find(root, key);
}