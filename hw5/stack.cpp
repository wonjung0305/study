/*
Implement the stack.h
Constructor, destructor, isfullS, IsEmptyS, push, pop
Especially Print

! (I don't know how to set value of the default constructor)
*/

#include <iostream>
#include "stack.h"

using namespace std;

// Default Constructor
Stack::Stack(){
  top = -1;
  max_size = 0;
  stack = new Element[10];
}

// Constructor
Stack::Stack(int num){
  top = -1;
  max_size = num;
  stack = new Element[max_size];
}

// Destructor
Stack::~Stack(){
  delete[] stack;
}

// Check whether it is full 
bool Stack::IsFullS(){
  return (top == max_size -1);

}

// check whether it is empty
bool Stack::IsEmptyS(){
  return (top == -1);
}

// add item
void Stack::Push(Element item){
  if(IsFullS()){
    cout << "Full";
  }
  else{
    stack[++top] = item;
  }
}

// return item
Element Stack::Pop(){
  if(IsEmptyS()){
    cout << "Empty" << endl;
    return 0;
  }
  else{
    return stack[top--]; // return the value 
  }
}

// !!!!! print out the stack
void Stack::Print() const {
  for(int i = 0; i <= top; i++){
    cout << stack[i] << " "; // print the value of stack
  }
  cout << endl;
}

