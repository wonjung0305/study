/*
revise a text file with a given map file
=> print the revised text

Input: text file name, map file name
Output: the revised text

format
SOURCE_WORD: TARGET_Word

make BST with the mapfile
key = source word
data = target word

Case, puncuation marks

==> find source word and change into target word
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "BST.h"

using namespace std;

int main(){
  BST manager;

  // open map.txt (read)
  ifstream inFile("map.txt");
  if(!inFile){  // can't open map.txt
    cout << "Error: map.txt" << endl;
    return 1;
  }

  // set source word and target word
  string line;
  while(getline(inFile, line)){ // read line
    if(line.empty()){ // empty line
      continue; // skip
    }

    int index = line.find(": ");  // find : 
    if(index == string::npos){  // can't find ": "
      continue; // next line
    }

    string sourceWord = line.substr(0, index);  // source word(key) before :
    string targetWord = line.substr(index+2); // target word(data) after :

    manager.change(sourceWord, targetWord ); // set the node(data)

  }

  // open input.txt
  ifstream modifyFile("input.txt");
  if(!modifyFile){  // can't open
    cout << "Error: input.txt" << endl; // error message
    return 1;
  }

  while(getline(modifyFile,line)){
    stringstream sstm(line);  // get word from line (one line)
    string word;  // division word
    bool first = true;  // first word of the line

    // skip empty line
    if(line.empty()){
      continue;
    }

    while(sstm >> word){  // set word from line(one line)
      string result = manager.find(word); // if find key, set data(target)
      if(result == ""){  // No key
        result = word;  // return word(as it)
      }

      if(!first){ // not first word in the line
        cout << " ";  // write blank before print word
      }

      cout << result; // print word
      first = false;  // not first word
    }
    cout << endl;
  }



  return 0;
}