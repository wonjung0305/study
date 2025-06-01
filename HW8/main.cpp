/*
Implement an interactive BST(Binary Search Tree)

user input -> tree = insert/ delete/ print/ end

input format command key value
command = 'a' , 'd', 'p' 'q' (add, delete, print, quit)

==> p , q => no key, value

inoder traversal (left -> data -> right)

add => if the key is already exist, printout "(key) is already in the tree"
delete => if the key is not exist, printout "<key> is not in the tree"
*/
#include <iostream>
#include <string>

#include "BST.h"

using namespace std;

int main(){
  BST manager;


  while(true){  // enter the character
      char command = ' ';
      int userKey = 0;
      string input = "";


      cin >> command;

      switch(command){
        case 'a':
          cin >> userKey; // enter the key
          cin.ignore(); // delete buffer

          getline(cin, input);

          manager.addNode(userKey, input); // add node
          break;
        case 'd':
          cin >> userKey; // enter the key
          cin.ignore(); // delete buffer

          manager.deleteNode(userKey);  // delete the node that user input (key)
          break;
        case 'p': 
          manager.printNode();  // print all node
          break;
        case 'q':
          manager.quit();
          break;
      }

  }


  return 0;
}