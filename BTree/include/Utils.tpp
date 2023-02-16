#ifndef UTILS_TPP
# define UTILS_TPP

#include "BTree.hpp"

template <class T, class Compare>
bool	is_equal(ft::BTree<T> *root, T pair, Compare compe) {

	if (!compe(root->pair, pair) && !compe(pair, root->pair))
		return (false);
	return (true);
}

template <class T>
// ft::BTree<T>* inorderSuccessor(ft::BTree<T> *root, ft::BTree<T> *p, Compare compe) {
ft::BTree<T>* inorderSuccessor(ft::BTree<T> *root, int p) {

	ft::BTree<T>* successor = NULL;

	while (root != NULL) {

		if (p >= root->pair.first)
			root = root->right;
		else {
			successor = root;
			root = root->left;
		}
	}
	return (successor);

}


#endif
