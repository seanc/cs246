#include <iostream>
#include <string>
#include "BNode.h" 
#include "Helper.h"

// Get the left-most node
template <typename T>
ds::dn::BNode<T>* TreeMinimum(ds::dn::BNode<T>* root)
{
	ds::dn::BNode<T>* tmp = root;
	while (tmp->left != NULL) {
		tmp = tmp->left;
	}

	return tmp;
}

// Get the right-most node
template <typename T>
ds::dn::BNode<T>* TreeMaximum(ds::dn::BNode<T>* root)
{
	ds::dn::BNode<T>* tmp = root;
	while (tmp->right != NULL) {
		tmp = tmp->right;
	}

	return tmp;
}

template <typename T>
ds::dn::BNode<T>* TreeSuccessor(ds::dn::BNode<T>* x)
{
	if (x == NULL) {
		return NULL;
	}

	
	return NULL;
}

template <typename T>
ds::dn::BNode<T>* TreePredecessor(ds::dn::BNode<T>* x)
{
	if (x == NULL) {
		return NULL;
	}

	if (x->left != NULL) {
		return TreeMaximum(x->left);
	} else {
		ds::dn::BNode<T>* tmp = x;
		ds::dn::BNode<T>* tmpParent = x->p;
		while (tmpParent != NULL && tmp->data == tmpParent->left->data) {
			tmp = tmpParent;
			tmpParent = x->p;
		}

		if (tmpParent != NULL) {
			return tmpParent;
		}
	}
	return NULL;
}


int main()
{
	srand(time(NULL));
	ds::dn::BNode<int>* tree = new ds::dn::BNode<int>(2);
	ds::dn::BNode<int>* tmp;
	
	for (int i = 0; i < 10; i++) {
		if (i == 5) {
			ds::dn::BSTInsert(tree, 8);
		}
		ds::dn::BSTInsert(tree, rand() % 17);
	}

	ds::dn::InOrderPrint(tree);

	ds::dn::BNode<int>* min = TreeMinimum(tree);
	std::cout << "\nmin: " << min->data << "\n";

	ds::dn::BNode<int>* max = TreeMaximum(tree);
	std::cout << "\nmax: " << max->data << "\n";

	ds::dn::BNode<int>* target = ds::dn::BSTSearch(tree, 8);
	ds::dn::BNode<int>* successor = TreePredecessor(target);
	std::cout << target->data << "\n";
	std::cout << (successor != NULL ? std::to_string(successor->data) : " ");
	return 0;
}
