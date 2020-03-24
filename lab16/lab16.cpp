#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h"

template <class T>
void ReverseTraverse(ds::dn::Node<T>* root)
{
    if (root != NULL) {
        while (root->GetNext() != NULL) {
            root = root->GetNext();
        }

        while (root != NULL) {
            std::cout << root->GetData() << " ";
            root = root->GetPrev();
        }
    }
    return;
}

template <class T>
void InsertionSort(ds::dn::Node<T>* root)
{
    return;
}

/********************************
 * Helper Functions : Begin
 *******************************/

//GenerateList() - converts Point object to a one dimension chess board index
ds::dn::Node<int>* GenerateList(int n)
{
    int nc = (n <= 0)?(10):(n);
    ds::dn::Node<int>* root = new ds::dn::Node<int>(rand() % 99 + 1);
    ds::dn::Node<int>* tmp = root;
    for(int i = 1;i < nc;i += 1)
    {
        tmp->SetNext(new ds::dn::Node<int>(rand() % 99 + 1));
        tmp->GetNext()->SetPrev(tmp);
        tmp = tmp->GetNext();
    }

    return root;
}

template <class T>
void Print(ds::dn::Node<T>* root)
{
    for(ds::dn::Node<T>* t = root;t != NULL;t = t->GetNext())
    {
        std::cout << t->GetData() << " ";
    }
}

/********************************
 * Helper Functions : End
 *******************************/

int main()
{
    srand(time(NULL));
    ds::dn::Node<int>* root = GenerateList(15);
    Print(root);
    std::cout << "\n";
    ReverseTraverse(root);
    // ds::dn::Clear(root);
        
    return 0; 
}
