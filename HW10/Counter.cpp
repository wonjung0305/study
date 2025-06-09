#include "Counter.h"

#include <iostream>
#include <fstream>
#include  <sstream>
#include <cctype>

using namespace std;

// Constructor
Counter::Counter(){
  words = new Word[MAX];  // allocate dynamic array
  wordCount = 0;  // initialize
}

// Destructor
Counter::~Counter(){
  delete[] words; // deallocate array
}

// read lines from file
bool Counter::readFile(const string& filename){
  ifstream inFile(filename);  // open file

  if(!inFile){  // check
    cerr << "Error: readfile()" << endl;
    return false; // fail
  }

  string line;
  while(getline(inFile, line)){ // read line
    readWord(line); // read word (change into lowercase or change into whitespace)
  }

  inFile.close(); // file close
  return true;  // success

}

// read word from line(divde line)
void Counter::readWord(const string& line){
  string modified;  // modified line

  // remove punctuations and change into lowercase
  for(char c : line){
    if(isalpha(c) || isdigit(c)){
      modified += tolower(c); // if alphabet and number => change to lowercase
    }
    else{
      modified += ' ';  // punctuations => whitespace
    }
  }

  stringstream sstm(modified);
  string word;

  while(sstm >> word){  // insert word or increase count
    insertWord(word);
  }

}

// insert word or count
void Counter::insertWord(const string& w){
  // if the word already exist, count
  for(int i = 0; i < wordCount; i++){
    if(w == words[i].word){
      words[i].count++; // already exist ==> count
      return;
    }
  }

  // doesn't exist ==> insert word
  words[wordCount].word = w;  // add new word
  words[wordCount].count = 1; // set 1 (count)
  wordCount++;

}

// Heap Sort
void Counter::sort(){

  // make MinHeap
  for(int i = (wordCount-1)/2; i >= 0; i--){    // leaf -> root
    heapify(wordCount, i);  // MinHeap
  }

  // Sort
  for(int i = wordCount - 1; i > 0; i--){ // sort array
    swap(words[0], words[i]); // move smallest word at the end(sorted position, descending)
    heapify(i,0); // sort again(make MinHeap)
  }

}

// make Heap
void Counter::heapify(int size, int index){
  int parent = index;
  int left = index*2 + 1; // left child
  int right = index*2 + 2;  // right child

  // check left child
  if(left < size && !compare(words[parent], words[left])){
    parent = left;  // left child < parent ==> change
  }

  // check right child
  if(right < size && !compare(words[parent], words[right])){
    parent = right; // change
  }

  // if parent is changed
  if(parent != index){
    swap(words[index], words[parent]);  // chanage the location
    heapify(size, parent);  // check with new child
  }
}

// compare two words frequency for minHeap
bool Counter::compare(const Word& a, const Word& b){
  if(a.count < b.count) return true;  // frequency a < b
  
  if(a.count == b.count){ // if the same frequency
    if(a.word > b.word){  // reverse alphabetical order
      return true;
    }
  }

  return false; 
  
}

// print 5 words
void Counter::print(){

  for(int i = 0; i <5; i++){  // print 5 words
    string upper = words[i].word;  // change into uppercase
    for(char& c : upper){
      c = toupper(c);
    }

    cout << upper << ": " << words[i].count << endl;
  }
}