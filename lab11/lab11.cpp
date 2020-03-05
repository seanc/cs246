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

    return NULL;
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
    ds::Vector<Point> line;
    return 0; 
}
