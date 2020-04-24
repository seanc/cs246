#ifndef LAB15_H
#define LAB15_H

#include <iostream>
#include <sstream>
#include <string>
#include "Node.h"
#include "Queue.h"
#include "Stack.h"

template <class T>
class MyStack  
{
private:
    //Create your queue field here     
    T* data;
    int capacity;
    int front;
    int back;

    void Resize(int ncp) {
        if(ncp <= 0)
        {
            ncp = 2 * capacity;
        }

        int tcp = (ncp > capacity)?(ncp):(capacity);
        T* tmp = new T[tcp];

        for(int i = 0;i < tcp;i += 1)
        {
            tmp[i] = data[i];
        }
        delete[] data;
        data = new T[ncp];
        capacity = ncp;

        for(int i = 0;i < tcp;i += 1)
        {
            data[i] = tmp[i];
        }
        delete[] tmp;

    }

public:
    MyStack() : MyStack(10) {};
    //Initialize your stack
    MyStack(int capacity) : capacity(10), front(0) {
        data = new T[capacity];
    }

    //adds element to the stack
    void Push(const T& value) {
        if (front == capacity) {
            Resize(2 * capacity);
        }

        data[front] = value;
        front++;
    }

    //removes top element from the stack        
    void Pop() {
        if (front > 0) {
            front--;
        }
    }

    //retrieves but does not remove the top element of the stack 
    const T& Top() const {
        if (front == 0) {
            throw "Empty stack";
        }
        return data[front - 1];
    }

    //states if the stack is empty
    bool IsEmpty() const {
        return front == 0;
    }

    void Print() {
        std::cout << "[";
        for (int i = 0; i < front; i++) {
            std::cout << data[i] << ((i + 1 < front) ? ", " : "");
        }
        std::cout << "]\n";
    }
};


template <class T>
class MyQueue  
{
private:
    //Create your stack field here 
    T* data;
    int size;
    int capacity;    
public:
    //Initialize your queue
    MyQueue() : MyQueue(10) {};

    MyQueue(int capacity) : capacity(capacity), size(0) {
        data = new T[capacity];
    }

    void Resize(int ncp)
    {
        if(ncp <= 0)
        {
            ncp = 2 * capacity;
        }

        int tcp = (ncp > capacity)?(ncp):(capacity);
        T* tmp = new T[tcp];

        for(int i = 0;i < tcp;i += 1)
        {
            tmp[i] = data[i];
        }
        delete[] data;
        data = new T[ncp];
        capacity = ncp;

        for(int i = 0;i < tcp;i += 1)
        {
            data[i] = tmp[i];
        }
        delete[] tmp;
    }

    void Enqueue(const T& value) {
        if (size == capacity) {
            Resize(2 * capacity);
        }
        
        data[size] = value;
        size++;
    }

    //removes front element from the queue        
    void Dequeue() {
        if (size > 0) {
           for (int i = 0; i < size; i++) {
               data[i] = data[i + 1];
           }
           size--;
        }
    }

    //retrieves but does not remove the front element of the queue 
    const T& Peek() const {
        if (size == 0) {
            throw "Empty queue";
        }

        return data[0];
    }

    //states if the queue is empty
    bool IsEmpty() const {
        return size == 0;
    }
};

#endif