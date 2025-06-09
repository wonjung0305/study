#ifndef COUNTER_H
#define COUNTER_H

#include <string>

const int MAX = 2048; // maximum number of words

using namespace std;

// word + frequency
struct Word{
  string word;
  int count;
};

class Counter{
private:
  Word* words;  // array
  int wordCount;  // total word number

public:
  Counter();  // Constructor
  ~Counter(); // Destructor

  bool readFile(const string& filename);  // read lines from file
  void readWord(const string& line);  // read word from line(divde line)

  void insertWord(const string& word);  // insert word

  void sort();  // Heap Sort
  void heapify(int size, int index); // function for sort

  bool compare(const Word& a, const Word& b);  // compare word

  void print(); // print 5 words
};


#endif