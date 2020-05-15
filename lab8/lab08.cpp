#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h"
#include "Iterator.h"

/**
 * NOTE:
 * RemoveAll1 is setting the head to 0 instead of completely removing it.
 * Why?
 **/

/**
 * Swap Nodes
 * Know the previous nodes to the nodes that you want to swap
 * 
 **/
template <typename T>
void SwapNodes(ds::Node<T>* root,ds::Node<T>* nptr1,ds::Node<T>* nptr2)
{
    ds::Node<T>* prev1, *prev2;
    ds::Node<T>* tmp1 = root, *tmp2 = root;

    while (tmp1 != NULL && tmp1->GetData() != nptr1->GetData()) {
        prev1 = tmp1;
        prev1 = prev1->GetLink();
    }

    while (tmp2 != NULL && tmp2->GetData() != nptr2->GetData()) {
        prev2 = tmp2;
        prev2 = prev2->GetLink();
    }

    if (prev1 == NULL || prev2 == NULL) {
        return;
    }

    if (prev1 != NULL) {
        prev1->SetLink(tmp2);
    } else {
        root = tmp2;
    }

    if (prev2 != NULL) {
        prev2->SetLink(tmp1);
    } else {
        root = tmp1;
    }

    ds::Node<T>* tmp = tmp2->GetLink();
    tmp2->SetLink(tmp1->GetLink());
    tmp1->SetLink(tmp);
}

// double SecondLargest(ds::Node<double>* root)
// {
//     return 0.0;
// }

template <typename T>
void RemoveAll(ds::Node<T>*& root, const T& target) {
    if (root == NULL) return;

    // if (root->GetData() == target) {
    //     ds::Node<T> *remove_ptr = root;
    //     root = root->GetLink();
    //     delete remove_ptr;
    //     remove_ptr = NULL;
    // }

    ds::Node<T> *tmp = root;
    ds::Node<T> *prev;

    while (tmp != NULL && tmp->GetData() == target) {
        root = tmp->GetLink();
        delete tmp;
        tmp = root;
    }

    while (tmp != NULL) {
        if (tmp->GetData() == target) {
            while (tmp != NULL && tmp->GetData() == target) {
                ds::Node<T>* tmp2 = tmp->GetLink();
                delete tmp;
                tmp = tmp2;
            }

            prev->SetLink(tmp);
        }

        if (tmp != NULL) {
            prev = tmp;
            tmp = tmp->GetLink();
        }
    }
}

template <class T>
void Print(ds::Node<T>* root)
{
    for(ds::Node<T>* t = root;t != NULL;t = t->GetLink())
    {
        std::cout << t->GetData() << " ";
    }
}

ds::Node<int>* GenerateList(int n)
{
    int s = (n <= 0)?(10):(n);
    ds::Node<int>* root = new ds::Node<int>(0);

    for(int i = 1;i < s;i += 1)
    {
        ds::Node<int>* tmp = new ds::Node<int>((rand() % 2) * (3 - 1) + 1,root);
        root = tmp;
    }

    return root;
} 

int main()
{
    srand(time(NULL));
    ds::Node<int>* node = GenerateList(24);
    ds::Node<int>* tmp;
    for (int i = 24; i > 0; i--) {
        int value = (rand() % 2) * (3 - 1) + 1;
        tmp = new ds::Node<int>(value, node);
        node = tmp;
    }

    Print(node);
    std::cout << std::endl;
    RemoveAll(node, 1);
    Print(node);
    std::cout << std::endl;
    // RemoveAll(node, 3);
    // Print(node);
    // std::cout << std::endl;

    return 0; 
}
