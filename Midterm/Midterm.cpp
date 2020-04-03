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
    if (root == NULL) return;
    ds::dn::Node<T>* tmp = root;
    ds::dn::Node<T>* next;

    while (tmp && tmp->GetNext()) {
        next = tmp->GetNext();

        while (next) {
            if (tmp->GetData() > next->GetData()) {
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

template <typename T>
bool HasCycle(ds::sn::Node<T>* root)
{
    if (root == NULL) return false;

    ds::sn::Node<T>* tmp = root;
    ds::sn::Node<T>* tmp1 = root;
    while (tmp && tmp1 && tmp1->GetLink()) {
        tmp = tmp->GetLink();
        tmp1 = tmp1->GetLink()->GetLink();

        if (tmp == tmp1) {
            return true;
        }
    }
    // while (tmp != prev) {
    //     // std::cout << tmp->GetData() << " " << prev->GetData();
    //     if (tmp->GetData() = prev->GetData()) {
    //         return true;
    //     } else {
    //         prev = tmp;
    //         tmp = tmp->GetLink();
    //     }
    // }

    return false;
}

std::string AdjacentDuplicatesRemoval(std::string str)
{
	int index = 0;
	int occurences = 0;
	int firstOccurenceIndex = 0;
	char lastLtr;
    std::string newStr;

	while (index < str.length())
	{
		char ltr = str[index];
		int nextLtrIndex = index + 1;

		if (nextLtrIndex < str.length()) {
			if (ltr == str[nextLtrIndex] || ltr == lastLtr) {
				occurences++;
				lastLtr = str[index];

				if (occurences == 1) {
					firstOccurenceIndex = index;
				}

				if (occurences > 1) {
					// Restart parsing from initial detection of sequence
					index = firstOccurenceIndex;
					occurences = 0;
				}
			} else {
				occurences = 0;
                newStr += str[index];
			}
		}

		index++;
	}
	
    return newStr;
}

int MaxKSum(ds::da::Vector<int>& data,int k)
{
    if (data.IsEmpty()) return 0;

    if (k < 0 || data.Size() < k) {
        int sum = 0;
        for (int i = 0; i < data.Size(); i++) {
            sum += data[i];
        }
        return sum;
    }

    int subSum = 0;
    for (int i = 0; i < k; i++) {
        subSum += data[i];
    }

    int remSum = subSum;
    for (int i = k; i < data.Size(); i++) {
        remSum += data[i] - data[i - k];
        subSum = subSum > remSum ? subSum : remSum;
    }
    
    return subSum;
}

int main()
{
    srand(time(NULL));

    // Question 1
    ds::da::Vector<int> list = GenerateRepeatingList();
    std::cout << list << std::endl;
    std::cout << LastOccurrence(list, 2) << std::endl << std::endl;

    // Question 2
    ds::dn::Node<int>* dnList = GenerateUnsortedList();
    PrintList(dnList);
    BubbleSort(dnList);
    PrintList(dnList);

    // Question 3
    ds::sn::Node<int>* infiniteList = GenerateInfiniteList();
    std::cout << HasCycle(infiniteList) << std::endl << std::endl; // Always returns true?

    // Question 4
    std::string repetitiveString = RepeatingValues();
    std::cout << repetitiveString << std::endl;
    std::cout << AdjacentDuplicatesRemoval(repetitiveString) << std::endl << std::endl;
    
    // Question 5
    ds::da::Vector<int> longList = GenerateLengthyList();
    std::cout << longList << std::endl;
    std::cout << MaxKSum(longList, 3) << std::endl;

    // HOORAY
    return 0;
}
