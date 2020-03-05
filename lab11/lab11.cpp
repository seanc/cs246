#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h"
#include "Iterator.h"
#include "Point.h"
#include "Vector.h"

bool IsLine(ds::Vector<Point>& coors)
{
    bool sameX = true;
    bool sameY = true;

    if (coors.Length() == 1) {
        return true;
    }

    int initX = coors[0].x;
    int initY = coors[0].y;

    for (int i = 1; i < coors.Length(); i++) {
        if (coors[i].x != initX) {
            sameX = false;
        }

        if (coors[i].y != initY) {
            sameY = false;
        }
    }

    if ((!sameX && sameY) || (!sameY && sameX) || (initX == initY)) {
        return true;
    } else {
        return false;
    }

    return false;
}

template<typename T>
ds::Node<T>* MiddleNode(ds::Node<T>* head)
{
    ds::Node<T>* tmp = head;
    ds::Vector<ds::Node<T>*> nodes;
    ds::Node<T>* middle;

    while (tmp != NULL) {
        nodes.Insert(tmp);
        tmp = tmp->GetLink();
    }

    int even = (nodes.Length() % 2) == 0;
    if (even) {
        middle = nodes[(nodes.Length() - 1 )/ 2];
    } else {
        middle = nodes[(nodes.Length()) / 2];
    }

    return middle;
}

/********************************
 * Helper Functions : Begin
 *******************************/

//Print() - prints elements of a linked list in a line
template <typename T>
void Print(ds::Node<T>* root)
{
    ds::sn::Iterator<T>* iter = new ds::sn::Iterator<T>(root);

    while(iter->HasNext())
    {
        std::cout << iter->Next() << " ";
    }
    std::cout << "\n"; 
    delete iter;
}

//Print() - prints elements of vector in a line
template <typename T>
void Print(ds::Vector<T> data)
{
    ds::da::Iterator<T>* iter = data.ToIterator();

    while(iter->HasNext())
    {
        std::cout << iter->Next() << " ";
    }
    std::cout << "\n"; 
    delete iter;
}

//GenerateList() - creates a linked list of random decimal numbers
ds::Node<int>* GenerateList(int n)
{
    int s = (n <= 0)?(10):(n);
    ds::Node<int>* root = new ds::Node<int>(0);

    for(int i = 1;i < s;i += 1)
    {
        ds::Node<int>* tmp = new ds::Node<int>(0,root);
        root = tmp;
    }

    ds::sn::Iterator<int>* iter = new ds::sn::Iterator<int>(root);
    
    while(iter->HasNext())
    {
        iter->Next() = (rand() % 100) + 1;
    }
    return root;
} 

/********************************
 * Helper Functions : End
 *******************************/

int main()
{
    srand(time(NULL));
    ds::Node<int>* oddLengthLine = GenerateList(7);
    ds::Node<int>* evenLengthLine = GenerateList(6);
    std::cout << "Odd Length Line: ";
    Print(oddLengthLine);

    std::cout << "Even Length Line:";
    Print(evenLengthLine);
    
    std::cout << MiddleNode(evenLengthLine)->GetData() << " | " << MiddleNode(oddLengthLine)->GetData() << std::endl;
    return 0; 
}
