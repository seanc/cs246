#include <iostream>
#include <string>
#include "Node.h"
#include "Stack.h"
#include "Queue.h"
#include "BNode.h"
#include "Helper.h"

double Range(ds::sn::BNode<double>* root)
{
	ds::sn::BNode<double>* min = root;
	ds::sn::BNode<double>* max = root;

	while (min->left != NULL) {
		min = min->left;
	}
	
	while (max->right != NULL) {
		max = max->right;
	}

	return max->data - min->data;
}

template <typename T>
void BTRemove(ds::dn::BNode<T>* root,const T& value)
{
	ds::sn::Queue<ds::dn::BNode<T>*> nodes;
	ds::dn::BNode<T>* lastNode = root;
	ds::dn::BNode<T>* targetNode;
	nodes.Enqueue(root);

	while (!nodes.IsEmpty()) {
		ds::dn::BNode<T>* tmp = nodes.Peek();
		nodes.Dequeue();

		if (tmp->data == value) {
			targetNode = tmp;
		}

		if (tmp->left != NULL) {
			nodes.Enqueue(tmp->left);

			if (tmp->left->left == NULL && tmp->left->right == NULL) {
				lastNode = tmp->left;
			}

		}

		if (tmp->right != NULL) {
			nodes.Enqueue(tmp->right);

			if (tmp->right->left == NULL && tmp->right->right == NULL) {
				lastNode = tmp->right;
			}
		}
	}

	if (lastNode != NULL && targetNode != NULL) {
		ds::dn::BNode<T>* tmp = targetNode;
		targetNode->data = lastNode->data;
		lastNode->data = tmp->data;
		
		if (lastNode->p->left != NULL) {
			delete lastNode->p->left;
			lastNode->p->left = NULL;
		} else if (lastNode->p->right != NULL) {
			delete lastNode->p->right;
			lastNode->p->right = NULL;
		}
	}
}

template <typename T>
void BSTRemove(ds::dn::BNode<T>* root,const T& value)
{

}

int main()
{
	// Question 1
	ds::sn::BNode<double>* root = new ds::sn::BNode<double>(1);
	for (double i = 2; i < 10; i++) {
		BSTInsert(root, i);
	}

	std::cout << Range(root) << "\n";

	// Question 2
	ds::dn::BNode<int>* root2 = new ds::dn::BNode<int>(0);
	for (int i = 1; i < 10; i++) {
		BTInsert(root2, i);
	}
	BTRemove(root2, 3);
	// Without removal, should be 3; with removal, should be 9
	std::cout << root2->left->left->data << "\n";
	return 0;
}
