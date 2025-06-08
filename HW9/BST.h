#ifndef BST_H
#define BST_H

#include <string>
using namespace std;

struct Node{
  string key;   // source word
  string data;  // target word

  Node* left;
  Node* right;

  Node(string original, string target);
};

class BST{
private:
  Node* root;


public:
  BST();  // constructor
  ~BST(); // destructor

  void clear(Node* ptr);
  void change(Node*& ptr, string key, string data);  // change source word->keyword
  void change(string key, string data);
  string find(Node* ptr,string key);  // find source word
  string find( string key);

};

#endif  //BST_H