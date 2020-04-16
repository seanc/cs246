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
// template <typename T>
// void SwapNodes(ds::Node<T>* root,ds::Node<T>* nptr1,ds::Node<T>* nptr2)
// {
//     ds::Node<int>* tmp = nptr1;

//     return;
// }

// double SecondLargest(ds::Node<double>* root)
// {
//     return 0.0;
// }

template <typename T>
void RemoveAll(ds::Node<T>*& root, const T& target) {
    if (root == NULL) return;

    if (root->GetData() == target) {
        ds::Node<T> *remove_ptr = root;
        root = root->GetLink();
        delete remove_ptr;
        remove_ptr = NULL;
    }

    ds::Node<T> *tmp = root;
    ds::Node<T> *prev = root;

    while (tmp != NULL) {
        if (tmp->GetData() == target) {
            if (prev != NULL) {
                prev->SetLink(tmp->GetLink());
            } else {
                prev = tmp->GetLink();
                tmp = prev->GetLink();
            }
        } else {
            prev = tmp;
            tmp = tmp->GetLink();
        }
    }

    // while (tmp->GetLink() != NULL) {
    //     if (tmp->GetLink()->GetData() == target) {
    //         tmp->SetLink(tmp->GetLink()->GetLink());
    //     } else {
    //         tmp = tmp->GetLink();
    //     }
    // }

    return;
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
