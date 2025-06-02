// ArrayQueue.h
#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

class ArrayQueue {
private:
    int* queue;       // 큐 배열
    int maxsize;     // 큐 최대 크기

    int front;        // 삭제 위치
    int rear;         // 삽입 위치

public:
    ArrayQueue(int size = 100);  // 생성자 (기본 크기 100)
    ~ArrayQueue();               // 소멸자

    bool isEmpty() const;        // 비어있는지 확인
    bool isFull() const;         // 가득 찼는지 확인

    void enqueue(int value);     // 삽입
    int dequeue();               // 삭제 및 반환
    int peek() const;            // front 값 확인

    void print() const;          // 큐 전체 출력
};

#endif  //ARRAYQUEUE_H
