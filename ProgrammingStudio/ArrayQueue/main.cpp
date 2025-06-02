// main.cpp
#include <iostream>
#include "ArrayQueue.h"
using namespace std;

int main() {
    ArrayQueue manager(5);  // 크기 5짜리 큐

    manager.enqueue(10);
    manager.enqueue(20);
    manager.enqueue(30);

    manager.print();  // 10 <- 20 <- 30

    cout << "peek(): " << manager.peek() << endl;

    manager.dequeue();
    manager.print();  //  20 <- 30 

    return 0;
}
