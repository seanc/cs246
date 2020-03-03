#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.h"

void RandInts(ds::Array<int>& arr,int lo,int hi)
{
    int mx = (hi >= lo)?(hi):(lo);
    int mn = (lo <= hi)?(lo):(hi);
    ds::it::Iterator<int>* iter = arr.ToIterator();

    while(iter->HasNext())
    {
        iter->Next() = rand() % (mx - mn + 1) + mn;
    }

    delete iter;
} 

void SortedInts(ds::Array<int>& arr,int start,bool dup)
{
    int prev = start;
    int c = (dup)?(0):(1);
    ds::it::Iterator<int>* iter = arr.ToIterator();

    while(iter->HasNext())
    {
        prev = prev + rand() % 10 + c;
        iter->Next() = prev; 
    }

    delete iter;
}

int MaxOccurence(ds::Array<int>& data) {
    int maxOccurences = 0;
    int lastMaxIdx = 0;
    for (int i = 0; i < data.Length(); i++) {
        int occurences = 0;
        for (int j = 0; j < data.Length(); j++) {
            if (data[j] == data[i]) {
                occurences++;
            }
        }

        if (occurences == maxOccurences) {
            lastMaxIdx = data[i] < data[lastMaxIdx] ? i : lastMaxIdx; 
        }

        if (occurences > maxOccurences) {
            lastMaxIdx = i;
            maxOccurences = occurences;
        }
    }

    return data[lastMaxIdx];
}

template <typename T>
int CommonValues(ds::Array<T>& arr1, ds::Array<T>& arr2) {
    int commonCount = 0;

    for (int i = 0; i < arr1.Length(); i++) {
        for (int j = 0; j < arr2.Length(); j++) {
            if (arr1[i] == arr2[j]) {
                commonCount++;
            }
        }
    }

    return commonCount;
}

int FindPair(ds::Array<int>& arr, int target) {
    int pairCount = 0;
    for (int i = 0; i < arr.Length(); i++) {

        int diff = arr[i] - target;
        for (int j = 0; j < arr.Length(); j++) {
            if ((diff == arr[j]) && diff != arr[i]) {
                pairCount++;
            } 
        }

    }

    return pairCount;
}

int main()
{
    srand(time(NULL));
    ds::Array<int> nums(10);
    ds::Array<int> nums2(5);
    ds::Array<int> nums3(5);
    nums3[0] = 1;
    nums3[1] = 3;
    nums3[2] = 2;
    nums3[3] = 4;
    nums3[4] = 6;
    RandInts(nums, 2, 20);
    RandInts(nums2, 2, 20);

    std::cout << "Nums 1: " << nums << std::endl;
    std::cout << "Nums 2: " << nums2 << std::endl;
    std::cout << "Nums 3: " << nums3 << std::endl;

    std::cout << "Max Occurence Nums 1: " << MaxOccurence(nums) << std::endl;
    std::cout << "Common Values Count: " << CommonValues(nums, nums2) << std::endl;
    std::cout << "Pair Nums 3: " << FindPair(nums3, 1) << std::endl;
    return 0; 
}
