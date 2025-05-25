#ifndef STACK_H
#define STACK_H

#include "Node.h"

#include <string>
using namespace std;

class Stack{
private:
  Node* top;

public:
  Stack(); // Constructor
  ~Stack(); // Destructor

  bool isEmpty();

  void push(int id, string name, string email);
  void print();
  void printReverse(Node* node);
  void printReverse();
  
};


#endif