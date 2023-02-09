#ifndef TRAVERSETREE_TPP
# define TRAVERSETREE_TPP

#include "BTree.hpp"

template <class T>
void	BTree_TraversePreOrder(ft::BTree<T> *root) {

	if (!root)
		return ;
	std::cout << root->pair.first << ' ';
	BTree_TraversePreOrder(root->left);
	BTree_TraversePreOrder(root->right);
}

#endif
