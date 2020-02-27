#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h"
#include "Iterator.h"

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
}

//GenerateList() - creates a linked list of random decimal numbers
ds::Node<double>* GenerateList(int n)
{
    int s = (n <= 0)?(10):(n);
    ds::Node<double>* root = new ds::Node<double>(0);

    for(int i = 1;i < s;i += 1)
    {
        ds::Node<double>* tmp = new ds::Node<double>(0,root);
        root = tmp;
    }

    ds::sn::Iterator<double>* iter = new ds::sn::Iterator<double>(root);
    
    while(iter->HasNext())
    {
        iter->Next() = (rand() % 10000) / 100.0;
    }
    return root;
} 

//Swap() - swaps the data of two nodes of a linked list
template <typename T>
void Swap(ds::Node<T>* a,ds::Node<T>* b)
{
    T t = a->GetData();
    a->SetData(b->GetData()); //alternate: a->GetData() = b->GetData();
    b->SetData(t);
}

/********************************
 * Helper Functions : End
 *******************************/

template <typename T>
ds::Node<T>* ReverseCopy(ds::Node<T>* root)
{
    // ds::Node<T>* rootCopy = root;
    if (root == NULL) {
        return NULL;
    }

    if (root->GetLink() == NULL) {
        return root;
    }

    ds::Node<T>* tmp = root;
    ds::Node<T>* prev;
    ds::Node<T>* next;

    while (tmp != NULL) {
        next = tmp->GetLink();
        tmp->SetLink(prev);
        prev = tmp;
        tmp = next;
    } 

    return prev;
}

void SelectionSort(ds::Node<double>* root)
{
    ds::Node<double>* tmp = root;


    while (tmp != NULL) {
        ds::Node<double>* min = tmp;
        ds::Node<double>* next = tmp->GetLink();

        while (next != NULL) {
            if (min->GetData() > next->GetData()) {
                min = next;
            }

            next = next->GetLink();
        }

        Swap(min, tmp);
        tmp = tmp->GetLink();
    }
    return;
}


int main()
{
    std::cout << "Tree: ";
    ds::Node<double>* tree = GenerateList(5);
    Print(tree);
    ds::Node<double>* reversedTree = ReverseCopy(tree);
    std::cout << "Reversed Tree: ";
    Print(reversedTree);

    SelectionSort(tree);
    std::cout << "Sorted Tree: ";
    Print(tree);
    return 0; 
}
