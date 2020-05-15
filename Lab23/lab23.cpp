#include <iostream>
#include <string>
#include "BNode.h" 

bool HasPathSum(ds::sn::BNode<int>* root,int value)
{
	if (root == NULL) {
		return (value == 0);
	}
	return (HasPathSum(root->left, value - root->data) || HasPathSum(root->right, value - root->data));
}

template <typename T>
int TreeDepth(ds::dn::BNode<T>* root)
{
	if (root == NULL) {
		return 0;
	} else {
		int ld = TreeDepth(root->left);
		int rd = TreeDepth(root->right);

		return (ld < rd ? rd : ld) + 1;
	}
}

template <typename T>
bool IsFull(ds::sn::BNode<T>* root)
{
	if (root == NULL) {
		return true;
	}

	if ((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL)) {
		return false;
	}

	return IsFull(root->left) || IsFull(root->right);
}

int main()
{
	ds::sn::BNode<int>* root = new ds::sn::BNode<int>(1);
	root->left = new ds::sn::BNode<int>(2);
	root->left->left = new ds::sn::BNode<int>(2);
	root->left->right = new ds::sn::BNode<int>(4);
	root->right = new ds::sn::BNode<int>(3);
	root->right->right = new ds::sn::BNode<int>(2);
	root->right->left = new ds::sn::BNode<int>(5);

	std::cout << HasPathSum(root, 5) << "\n";

	ds::dn::BNode<int>* root1 = new ds::dn::BNode<int>(1);
	root1->left = new ds::dn::BNode<int>(2);
	root1->right = new ds::dn::BNode<int>(3);
	root1->left->left = new ds::dn::BNode<int>(4);

	std::cout << TreeDepth(root1) << "\n";

	ds::sn::BNode<int>* root3 = new ds::sn::BNode<int>(1);
	root3->left = new ds::sn::BNode<int>(2);
	root3->right = new ds::sn::BNode<int>(3);
	std::cout << IsFull(root3);
	return 0;
}
