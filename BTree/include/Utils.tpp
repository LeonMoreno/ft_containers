#ifndef UTILS_TPP
# define UTILS_TPP

#include "BTree.hpp"

template <class T>
bool	is_sentinel(ft::BTree<T>* root) {

	if (!root->pair && !root->left && !root->right)
		return (true);
	return (false);
}

template <class T, class Compare>
bool	is_equal(ft::BTree<T> *root, T pair, Compare compe) {

	if ((compe(*root->pair, pair) == false) && (compe(pair, *root->pair) == false))
		return (true);
	return (false);
}

template <class T>
// ft::BTree<T>* inorderSuccessor(ft::BTree<T> *root, ft::BTree<T> *p, Compare compe) {
ft::BTree<T>* inorderSuccessor(ft::BTree<T> *root, int p) {

	ft::BTree<T>* successor = NULL;

	while (root != NULL && !is_sentinel(root)) {
		if (p >= root->pair->first)
			root = root->right;
		else {
			successor = root;
			root = root->left;
		}
	}
	return (successor);
}

template <class T>
ft::BTree<T>* precedenteNode(ft::BTree<T>* root, ft::BTree<T>* node) {

	while(root != NULL && !is_sentinel(root)) {

		if (root->right == node)
			return (root);
		root = root->right;
	}
	return (NULL);
}

template <class T, class Compare>
ft::BTree<T>* BTree_find(ft::BTree<T>* root, T to_find, Compare compe) {

	while (root != NULL && !is_sentinel(root)) {
	if (is_equal(root, to_find, compe))
		return (root);
	else if (compe(to_find, *root->pair))
		root = root->left;
	else
		root = root->right;
	}
	return (NULL);
}



#endif
