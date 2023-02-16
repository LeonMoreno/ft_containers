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

template <class T>
void	BTree_TraverseInOrder(ft::BTree<T> *root) {

	if (!root)
		return ;
	BTree_TraverseInOrder(root->left);
	std::cout << root->pair.first << ' ';
	BTree_TraverseInOrder(root->right);
}

template <class T>
ft::BTree<T>* help_begin(ft::BTree<T> *root)
{
	if (!(root->left))
		return (root);
	return (help_begin(root->left));
}

template <class T>
ft::BTree<T>* BTree_beginInOrder(ft::BTree<T> *root) {

	if (!root)
		return (NULL);
	return (help_begin(root->left));
}

template <class T>
ft::BTree<T>* help_end(ft::BTree<T> *root)
{
	if (!(root->left))
		return (root);
	return (help_end(root->right));
}


template <class T>
ft::BTree<T>* BTree_endInOrder(ft::BTree<T> *root) {
	if (!root)
		return (NULL);
	BTree_endInOrder(root->left);
	return (help_end(root->right));
}

#endif
