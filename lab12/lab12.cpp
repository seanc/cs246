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
    ds::sn::Set<T>* tmp;
    
    return ds::sn::Set<T>();
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
    
    std::cout << tree << std::endl;
    std::cout << teaTree << std::endl;
    std::cout << Intersection(tree, teaTree) << std::endl;
    std::cout << Intersection(tree, tree) << std::endl;

    return 0; 
}
