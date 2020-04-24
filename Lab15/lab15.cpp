#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h"
#include "Queue.h"
#include "Stack.h"
#include "lab15.h"

bool TestStackClass()
{
    ds::sn::Stack<int> a;
    MyStack<int> b;
    int value;
    int n = rand() % 41 + 10;

    for(int i = 0;i < n;i += 1)
    {
        value = rand() % 100 + 1;
        a.Push(value);
        b.Push(value);
    }

    while(!a.IsEmpty() && !b.IsEmpty())
    {
        if(a.Top() != b.Top())
        {
            std::cout << "MyStack is invalid\n\n";
            return false;
        }
        a.Pop();
        b.Pop();
    }
    
    if(a.IsEmpty() == b.IsEmpty())
    {
        std::cout << "MyStack is valid\n\n";
        return true;
    }
    else
    {
        std::cout << "MyStack is invalid\n\n";
        return false;
    }
}

bool TestQueueClass()
{
    ds::sn::Queue<int> a;
    MyQueue<int> b;
    int value;
    int n = rand() % 41 + 10;

    for(int i = 0;i < n;i += 1)
    {
        value = rand() % 100 + 1;
        a.Enqueue(value);
        b.Enqueue(value);
    }

    while(!a.IsEmpty() && !b.IsEmpty())
    {
        if(a.Peek() != b.Peek())
        {
            std::cout << "MyQueue is invalid\n\n";
            return false;
        }
        a.Dequeue();
        b.Dequeue();
    }
    
    if(a.IsEmpty() == b.IsEmpty())
    {
        std::cout << "MyQueue is valid\n\n";
        return true;
    }
    else
    {
        std::cout << "MyQueue is invalid\n\n";
        return false;
    }
}


int main()
{
    srand(time(NULL));
    TestStackClass();
    TestQueueClass();
    return 0; 
}
