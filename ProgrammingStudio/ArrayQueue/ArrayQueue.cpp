// ArrayQueue.cpp
#include <iostream>
#include "ArrayQueue.h"
using namespace std;

// 생성자
ArrayQueue::ArrayQueue(int size) {
    maxsize = size;
    queue = new int[maxsize];

    front = 0;
    rear = 0;
}

// 소멸자
ArrayQueue::~ArrayQueue() {
    delete[] queue;
}

// 비었는지 확인
bool ArrayQueue::isEmpty() const {
    return front == rear;
}

// 가득 찼는지 확인
bool ArrayQueue::isFull() const {
    return rear == maxsize;
}

// 삽입
void ArrayQueue::enqueue(int value) {
    if (isFull()) {
        cerr << "Error: Full" << endl;
        return;
    }
    queue[rear++] = value;
}

// 삭제 및 반환
int ArrayQueue::dequeue() {
    if (isEmpty()) {
        cerr << "Empty!" << endl;
        return -1;
    }
    return queue[front++];
}

// front 값 확인
int ArrayQueue::peek() const {
    if (isEmpty()) {
        cerr << "Empty" << endl;
        return -1;
    }
    return queue[front];
}

// 출력
void ArrayQueue::print() const {
    for (int i = front; i < rear; i++) {
        cout << queue[i];
        if (i < rear - 1) cout << " <- ";
    }
}
