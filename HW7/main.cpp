/*
1. Read a file
  // input file name by keyboard input
2. print the lines in the reverse order

!. use a linked list(not array)

- format of input file
name, id, email. ( ==> name, id email )

- Output format 
id, name, email. ( ==> name, id email )
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "Stack.h"

using namespace std;

int main(){
  // input filename
  string filename;
  cin >> filename;

  // open file
  ifstream file(filename);

  // fail to open => exit the program
  if(!file){
    cout << "Error";
    return 1;
  }

  Stack stack;
  string line;

  // read a file, line by line
  while(getline(file, line)){
    // empty line => skip
    if(line.empty()){
      continue;
    }

    string stringId = "";
    string name = "";
    string email = "";
  
    // stringstream to divide the line by ','
    stringstream division(line);

    getline(division, name, ',');
    getline(division, stringId, ',');
    getline(division, email);

    // string to int
    int id = 0;
    id = stoi(stringId);

    // push
    stack.push(id, name, email);
  }

  file.close();

  stack.print();

  return 0;

}