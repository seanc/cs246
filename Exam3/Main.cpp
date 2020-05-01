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
	if (str.length() == 0) {
		return true;
	}

	ds::da::Stack<char> parens;

	// for (char l : str) {
	// 	if (l == '(') {
	// 		parens.Push(l);
	// 	} else if (l == ')') {
	// 		if (!parens.IsEmpty() && (parens.Top() == ')') && l != ')') {
	// 			return false;
	// 		}

	// 		if (!parens.IsEmpty()) {
	// 			parens.Pop();
	// 		}
	// 	}
	// }

	for (char l : str) {
		if (l == '(') {
			parens.Push('(');
		} else if (!parens.IsEmpty()) {
			if (l == parens.Top()) {
				return false;
			}
			parens.Pop();
		}
	}

	return parens.IsEmpty();
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

}

//Question 5

template <typename T>
bool IsProperSubSet(ds::da::Set<T>& A,ds::da::Set<T>& B)
{
	if (A.Size() >= B.Size()) {
		return false;
	}

	ds::da::Iterator<int>* it = A.ToIterator();
	int i = 0;
	while (it->HasNext()) {
		int data = it->Next();
		if (!B.Contains(data)) {
			return false;
		}
	}

	if (i < B.Size()) {
		return true;
	}

	return false;
}

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

ds::da::Set<int> GenerateSet(int n)
{
    int s = (n <= 0)?(10):(n);
    ds::da::Set<int> S;

    while(S.Size() < s)
    {
        S.Insert((rand() % 1000 + 1));
    }
    return S;
} 

template<typename T>
void PrintList(ds::dn::Node<T>* list) {
	std::cout << "[";
	while (list != NULL) {
		std::cout << list->GetData() << (list->GetNext() ? ", " : "");
		list = list->GetNext();
	}
	std::cout << "]\n";
}

int main()
{
	srand(time(NULL));
	// Question 1
	int nums[] = { 7,2,4,3,2,8,3,9,3,2,9,4,2,5,3 };
	int numsSize = sizeof(nums) / sizeof(int);
	ds::da::Vector<int> data;
	for (int i = 0; i < numsSize; i++) {
		data.Insert(nums[i]);
	}
	std::cout << "Bound Mode: " << BoundMode(data, 9) << "\n";

	// Question 3
	std::cout << "Valid Parens: " << IsValidParentheses("()()") << "\n";

	// Question 5
	ds::da::Set<int> A = GenerateSet(5);
	ds::da::Set<int> B = A;
	B.Insert(10);
	std::cout << "Proper Subset: " << IsProperSubSet(A, B) << "\n";

	return 0;
}