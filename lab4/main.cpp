#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.h"

/**
 * Student work
 **/

void InitializeArray(ds::Array<int>& arr, int target) {
    int n = arr.Length() - 1;
    while (n > 0) {
        arr[n] = target;
        n--;
    }
}

int ArrayMax(ds::Array<int>& arr) {
    int max = 0;
    int n = arr.Length() - 1;
    while (n > 0) {
        if (arr[n] > max) max = arr[n];
        n--;
    }
    return max;
}

bool FindPair(ds::Array<int>& arr, int target) {
    for (int i = 0; i < arr.Length() - 1; i++) {

        int diff = target - arr[i];

        for (int j = 0; j < arr.Length() - 1; j++) {
            if ((diff == arr[j]) && diff != arr[i]) {
                std::cout << "Pair: " << i << ", " << j << std::endl;
                return true;
            } 
        }

        return false;

    }
}

int RemoveAllOccurrences(ds::Array<int>& arr, int target) {
    int removed = 0;
    for (int i = 0; i < arr.Length(); i++) {
        std::cout << arr[i] << "target" << target << std::endl;
        if (arr[i] == target) {
            removed++;
            for (int j = i; j < arr.Length(); j++) {
                if ((j + 1) < arr.Length()) {
                    arr[j] = arr[j + 1];
                } else {
                    arr[j] = 0;
                }
            }
        }
    }
    return arr.Length() - removed;
}

int IndexOf(ds::Array<int>& arr, int target) {
    int sortedInsertIdx = 0;
    for (int i = 0; i < arr.Length(); i++) {
        if (arr[i] == target) {
            return i;
        }

        if (target < arr[i]) {
            sortedInsertIdx = i;
            break;
        }

        if (target > arr[i]) {
            sortedInsertIdx = i;
        }
    }

    return sortedInsertIdx;
}

// End student work

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

int main()
{
    ds::Array<int> a(10), b(20), c(4);
    for (int i = 0; i <= c.Length() - 1; i++) {
        c[i] = i+1;
    }

    srand(time(NULL));

    RandInts(a,1,50);
    SortedInts(b,8,false);

    std::cout << a << "\n";
    std::cout << b << "\n";
    std::cout << c << "\n";
    std::cout << ArrayMax(a) << "\n";
    FindPair(c, 4);
    std::cout << RemoveAllOccurrences(c, 2) << " | " << c << "\n";
    std::cout << IndexOf(b, 60) << "\n";

    return 0; 
}