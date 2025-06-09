/*
If text file is given, print 5 most frequently words and frequencies.

1. user input-> filename of the text file(input1.txt or input2.txt)
2. Read lines
3. read each line
  : change all punctuation -> space
  : divide the words with space
  : consider alphabet, number
4. regardless of case, count words

5. sort descending order
  : if frequency is same, sort ascending alphabet order

6. choose a sorting algorithm
  : explain the reasion by comment
7. change the most 5 words to uppercase and print with their frequencies

maximum number of words 2048
*/

#include <iostream>

#include "Counter.h"

int main(){

  string file;
  cin >> file;

  Counter manager;
  if(manager.readFile(file)){
    // use MinHeap ==> make a MinHeap 
      // to make smaller frequency moves to the end
      // so most frequency words move to the front
    manager.sort(); 
    manager.print();
  }

  return 0;
}