#include "Stack.h"

#include <iostream>
#include <string>

using namespace std;

// Constructor
Stack::Stack(){
  top = nullptr;

}
// Destructor
Stack::~Stack(){
  while(!isEmpty()){
    Node* temp = top; // store current top
    top = top -> getNext(); // link next node
    delete temp; //
  }
}

// check if the stack is empty
bool Stack::isEmpty(){
  return top == nullptr;
}

// add a new node
void Stack:: push(int id, string name, string email){
  Node* newNode = new Node(id, name, email); // make new node

  newNode->setNext(top); // set next node
  top = newNode;
}

// print stack
void Stack:: print(){
  Node* cur = top;

  while(cur != nullptr){
    cout << cur-> getId() << ", ";
    cout << cur-> getName() << ", ";
    cout << cur->getEmail() << endl;

    cur = cur->getNext(); // move to next node;
  }
}


void Stack::printReverse(Node* node){
  if(node == nullptr){
    return;
  }

  printReverse(node-> getNext());
  cout << node-> getId() << ", ";
  cout << node-> getName() << ", ";
  cout << node->getEmail() << endl;
}

void Stack::printReverse(){
  printReverse(top);
}