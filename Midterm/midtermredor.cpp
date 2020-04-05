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
int LastOccurrence(ds::da::Vector<T> &data, const T &value)
{
    if (!data.Contains(value))
    {
        return -1;
    }

    int idx = data.Size() - 1;
    T k;

    for (int i = data.Size() - 1; i >= 0; i--)
    {
        k = data[i];

        if (k == value)
        {
            return i;
        }
    }

    return -1;
}

template <typename T>
void BubbleSort(ds::dn::Node<T> *root)
{
    if (root == NULL)
        return;
    ds::dn::Node<T> *tmp = root;
    ds::dn::Node<T> *next;

    while (tmp && tmp->GetNext())
    {
        next = tmp->GetNext();

        while (next)
        {
            if (tmp->GetData() > next->GetData())
            {
                T tmpData = tmp->GetData();
                tmp->SetData(next->GetData());
                next->SetData(tmpData);
            }

            next = next->GetNext();
        }

        tmp = tmp->GetNext();
    }
    return;
}

// FIXED
template <typename T>
bool HasCycle(ds::sn::Node<T> *root)
{
    if (root == NULL)
        return false;

    ds::sn::Node<T> *tmp = root;
    ds::sn::Set<ds::sn::Node<T>*> previousNodes;

    while (tmp)
    {
        if (previousNodes.Contains(tmp)) {
            return true;
        } else {
            previousNodes.Insert(tmp);
            tmp = tmp->GetLink();
        }
    }

    return false;
}

// FIXED
std::string AdjacentDuplicatesRemoval(std::string str)
{
    std::string newStr;

    for (int i = 0; i < str.length(); i++) {
        char ltr = str[i];
        if (ltr == str[i - 1] || ltr == str[i + 1]) {
            continue;
        } else {
            newStr += ltr;
        }
    }

    return newStr;
}

int MaxKSum(ds::da::Vector<int> &data, int k)
{
    if (data.IsEmpty())
        return 0;

    if (k < 0 || data.Size() < k)
    {
        int sum = 0;
        for (int i = 0; i < data.Size(); i++)
        {
            sum += data[i];
        }
        return sum;
    }

    int subSum = 0;
    for (int i = 0; i < k; i++)
    {
        subSum += data[i];
    }

    int remSum = subSum;
    for (int i = k; i < data.Size(); i++)
    {
        remSum += data[i] - data[i - k];
        subSum = subSum > remSum ? subSum : remSum;
    }

    return subSum;
}

void DenoteQuestion (int num, bool end = false) {
    if (end) {
        std::cout << "--- END Question " << num << " ---\n\n";
    } else {
        std::cout << "--- Question " << num << " ---\n";
    }
} 

int main()
{
    srand(time(NULL));

    DenoteQuestion(1);
    // Question 1
    ds::da::Vector<int> list = GenerateRepeatingList();
    std::cout << list << std::endl;
    std::cout << LastOccurrence(list, 2) << std::endl;
    DenoteQuestion(1, true);

    DenoteQuestion(2);
    // Question 2
    ds::dn::Node<int> *dnList = GenerateUnsortedList();
    PrintList(dnList);
    BubbleSort(dnList);
    PrintList(dnList);
    DenoteQuestion(2, true);

    DenoteQuestion(3);
    // Question 3
    ds::sn::Node<int> *infiniteList = GenerateInfiniteList();
    std::cout << HasCycle(infiniteList) << std::endl;

    ds::sn::Node<int> *finiteList = GenerateInfiniteList();
    finiteList->SetLink(NULL);
    std::cout << HasCycle(finiteList) << std::endl;
    DenoteQuestion(3, true);



    DenoteQuestion(4);
    // Question 4
    std::string repetitiveString = RepeatingValues();
    std::cout << repetitiveString << std::endl;
    std::cout << AdjacentDuplicatesRemoval(repetitiveString) << std::endl;
    DenoteQuestion(4, true);


    DenoteQuestion(5);
    // Question 5
    ds::da::Vector<int> longList = GenerateLengthyList();
    ds::da::Vector<int> shortList(6);
    int nums[] = { 3,9,1,8,2,7 };
    for (int num : nums) shortList.Insert(num);

    std::cout << longList << std::endl;
    std::cout << MaxKSum(longList, 3) << std::endl;
    std::cout << shortList << std::endl;
    std::cout << MaxKSum(shortList, 3) << std::endl;
    DenoteQuestion(5, true);

    // HOORAY
    return 0;
}
