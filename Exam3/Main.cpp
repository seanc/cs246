#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Array.h"
#include "Node.h"
#include "Pair.h"
#include "Iterator.h"
#include "List.h"
#include "Set.h"
#include "Stack.h"
#include "Queue.h"
#include "Deque.h"
#include "Map.h"
#include "HashTable.h"

//Question 1

ds::da::Vector<int> BoundMode(ds::da::Vector<int>& data,int upb)
{
	ds::da::Vector<int> modes; 
	ds::da::Map<int, int> freq;
	
	int largestMode = data[0];
	freq.Put(data[0], 1);

	if (upb < 1 || data.Size() <= 1) {
		return modes;
	}

	for (int i = 1; i < data.Size(); i++) {
		if (freq.Contains(data[i])) {
			freq.Get(data[i])++;
			if (freq.Get(largestMode) < freq.Get(data[i])) {
				largestMode = data[i];
			}
		} else {
			freq.Put(data[i], 1);
		}
	}

	int maxFreq = freq.Get(largestMode);
	ds::da::PairIterator<int, int>* it = freq.ToIterator();
	ds::Pair<int, int> tmp;
	while (it->HasNext()) {
		tmp = it->Next();
		if (tmp.GetValue() == maxFreq) {
			modes.Insert(tmp.GetKey());
		}
	}

	return modes;
}

//Question 2

struct Point
{
	int x;
	int y;
};

int PointToIndex(Point& p)
{
	return (p.x - 1) * 8 + (p.y - 1);
}

bool RookMove(ds::da::Vector<int>& bd,Point& s,Point& e)
{
	return false;
}

//Question 3

bool IsValidParentheses(std::string str)
{
	return false;
}

//Question 4

template <typename T>
void Swap(ds::dn::Node<T>* a,ds::dn::Node<T>* b)
{
	if(a != NULL && b != NULL)
	{
		T t = a->GetData();
		a->SetData(b->GetData());
		b->SetData(t);
	}
}

template <typename T>
void InsertionSort(ds::dn::Node<T>* root)
{
	
	return;
}

//Question 5

template <typename T>
bool IsProperSubSet(ds::da::Set<T>& A,ds::da::Set<T>& B)
{
	return false;
}

int main()
{
	int nums[] = { 7,2,4,3,2,8,3,9,3,2,9,4,2,5,3 };
	int numsSize = sizeof(nums) / sizeof(int);
	ds::da::Vector<int> data;
	for (int i = 0; i < numsSize; i++) {
		data.Insert(nums[i]);
	}
	std::cout << BoundMode(data, 9) << "\n";
	return 0;
}
