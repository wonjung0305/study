#ifndef NODE_H
#define NODE_H

#include <string>

using namespace std;

// store name, id, email
class Node{
private:
  int id; // student id
  string name;  // student name
  string email; // student email
  Node* next; // point next node

public:
// constructor
  Node(int id, string name, string email);

  // getter
  int getId() const;
  string getName() const;
  string getEmail() const;

  // set nextnode, and get node
  void setNext(Node* nextNode);
  Node* getNext() const;
};

#endif