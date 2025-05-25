#include "Node.h"

// Constructor
Node::Node(int id, string name, string email){
  this->id = id;
  this->name = name;
  this->email = email;

  this->next = nullptr; 
}

// getter
int Node::getId() const{
  return id;
}
string Node::getName() const{
  return name;
}
string Node::getEmail() const{
  return email;
}

// set nextnode, and get node
void Node::setNext(Node* nextNode){
  next = nextNode;
}
Node* Node::getNext() const{
  return next;
}