#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h"
#include "Iterator.h"
#include "Set.h"

template <typename T>
ds::sn::Set<T> Intersection(const ds::sn::Set<T>& A,const ds::sn::Set<T>& B)
{   
    ds::sn::Iterator<T>* iterA = A.ToIterator();
    ds::sn::Set<T> inters;

    while (iterA->HasNext()) {
        T val = iterA->Next();
        if (B.Contains(val)) {
            inters.Insert(val);
        }
    }

    return inters;
}

template <typename T>
ds::sn::Set<T> Union(const ds::sn::Set<T>& A,const ds::sn::Set<T>& B)
{
    ds::sn::Iterator<T>* iterB = B.ToIterator();
    ds::sn::Set<T> C = A;
    while (iterB->HasNext()) {
        T bVal = iterB->Next();
        C.Insert(bVal);
    }
    
    return C;
}

/********************************
 * Helper Functions : Begin
 *******************************/

//GenerateList() - creates a linked list of random decimal numbers
ds::sn::Set<int> GenerateSet(int n)
{
    int s = (n <= 0)?(10):(n);
    ds::sn::Set<int> S;

    while(S.Size() < s)
    {
        S.Insert((rand() % 1000 + 1));
    }
    return S;
} 

/********************************
 * Helper Functions : End
 *******************************/

int main()
{
    ds::sn::Set<int> tree = GenerateSet(5);
    ds::sn::Set<int> teaTree = GenerateSet(5);

    std::cout << "A: " << tree << std::endl;
    std::cout << "B: " << teaTree << std::endl;

    std::cout << "--- INTERSECTION ---" << std::endl;
    
    std::cout << "A: " << Intersection(tree, teaTree) << std::endl;
    std::cout << "B: " << Intersection(tree, tree) << std::endl;

    std::cout << "--- UNION ---" << std::endl;
    std::cout << "A: " << Union(tree, teaTree) << std::endl;
    std::cout << "B: " << Union(teaTree, tree) << std::endl; 

    return 0; 
}
