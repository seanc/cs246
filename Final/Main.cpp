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
#include "BNode.h"
using namespace ds;


template <typename T>
void Print(sn::Node<T>* root)
{
    ds::sn::Iterator<T>* iter = new sn::Iterator<T>(root);

    while(iter->HasNext())
    {
        std::cout << iter->Next() << " ";
    }
    std::cout << "\n"; 
}
//Question 1

template <typename T>
bool IsBST(sn::BNode<T>* root)
{
	if (root == NULL) {
		return true;
	}

	ds::dn::Stack<sn::BNode<T>*> stack;
	sn::BNode<T>* tmp = root;
	int prev = 0;
	int current;

	while (true) {
		if (tmp != NULL) {
			stack.Push(tmp);
			tmp = tmp->left;
		} else {
			if (stack.IsEmpty()) {
				break;
			}

			tmp = stack.Top();
			stack.Pop();
			current = tmp->data;

			if (current < prev) {
				return false;
			}

			prev = current;
			tmp = tmp->right;
		}
	}

	return true;
}

//Question 2

sn::Node<int>* MergeSortedLists(sn::Node<int>* a,sn::Node<int>* b)
{
	sn::Node<int>* tmp;
	sn::Node<int>* tail = tmp;

	while (a != NULL & b != NULL) {
		if (a->GetData() < b->GetData()) {
			tail->SetLink(a);
			tail = a;
			a = a->GetLink();
		} else {
			tail->SetLink(b);
			tail = b;
			b = b->GetLink();
		}
	}

	if (a != NULL) {
		tail->SetLink(a);
	} else if (b != NULL) {
		tail->SetLink(b);
	}

	return tmp;
}

//Question 3

bool IsValidWord(std::string wrd)
{
	return false;
}

//Question 4
/******************************************************************************************
InFix: 2, 40, 13, 23, 11, 39, 38, 47, 36, 26, 5, 3, 43, 21, 14

Postfix:
 
Prefix:

******************************************************************************************/


int main()
{

	sn::BNode<int> root(6);
	root.right = new sn::BNode<int>(4); 
	root.left = new sn::BNode<int>(1); 
	root.left->right = new sn::BNode<int>(3); 
	std::cout << IsBST(&root);

	sn::Node<int> a(1);
	a.SetLink(new sn::Node<int>(3));
	a.GetLink()->SetLink(new sn::Node<int>(5));
	sn::Node<int> b(2);
	b.SetLink(new sn::Node<int>(4));
	b.GetLink()->SetLink(new sn::Node<int>(6));

	MergeSortedLists(&a, &b);
	return 0;
}
