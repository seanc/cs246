#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.h"
#include "Node.h"
#include "Iterator.h"
#include "List.h"
#include "Stack.h"
#include "Queue.h"
#include "Set.h"
#include "Deque.h"
#include "Helper.h" //Helper Functions for Testing Your Functions

template <typename T>
int LastOccurrence(ds::da::Vector<T>& data,const T& value)
{
    if (!data.Contains(value)) {
        return -1;
    }
    
    int idx = data.Size() - 1;
    T k;

    for (int i = data.Size() - 1; i >= 0; i--) {
        k = data[i];

        if (k == value) {
            return i;
        }
    }
    

    //Rewrite Definition of LastOccurrence() Here
    return -1;
}

template <typename T>
void BubbleSort(ds::dn::Node<T>* root)
{
    ds::dn::Node<T>* tmp;
    ds::dn::Node<T>* tmp1;
    bool swapped = false;

    while (swapped) {
        tmp = root;

        while (tmp->GetNext() != tmp1) {
            if (tmp->GetData() > tmp->GetNext()->GetData()) {
                T tmpData = tmp->GetData();
                tmp->SetData(tmp->GetNext()->GetData());
                tmp->GetNext()->SetData(tmpData);
            }

            tmp = tmp->GetNext();
        }


    }
    return;
}

template <typename T>
bool HasCycle(ds::sn::Node<T>* root)
{
    //Rewrite Definition of HasCycle() Here 
    return false;
}

std::string AdjacentDuplicatesRemoval(std::string str)
{
    //Rewrite Definition of AdjacentDuplicatesRemoval() Here
    return "";
}

int MaxKSum(ds::da::Vector<int>& data,int k)
{
    //Rewrite Definition of MaxKSum() Here
    return 0;
}

int main()
{
    srand(time(NULL));
    ds::da::Vector<int> list = GenerateRepeatingList();
    std::cout << list << std::endl;
    std::cout << LastOccurrence(list, 2);
    //Test Your Functions Here

    return 0;
}
