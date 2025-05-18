/*
Complete the Stack::Print()

by Kim, Wonjung (22200145)
*/

#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    Stack *stack = new Stack(5);

    stack->Push(1); // [0] = 1
    stack->Push(3); // [1] = 3
    stack->Print(); // print out 1 3

    cout << "Pop: " << stack->Pop() << endl; // Pop: 3
    stack->Print(); // 1

    delete stack; 

    return 0;
}