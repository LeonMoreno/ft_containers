#ifndef UTILS_TPP
# define UTILS_TPP

#include "BTree.hpp"

template <class T>
bool	is_sentinel(ft::BTree<T>* root) {

	if (!root)
		return (false);
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
ft::BTree<T>*	findRoot(ft::BTree<T>* node) {

	if (!node)
		return (NULL);
	if (!node->parent)
		return (node);
	ft::BTree<T>* root = node->parent;

	while (root->parent != NULL) {
		// std::cout << "root = " << root->pair->first << std::endl;
		root = root->parent;
	}
	return (root);
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

/* Esta mal, no mira hacia la IZ
   encuentra es nodo, no numero o ref.
   Ademas necesito el root para que funcione. */
template <class T>
ft::BTree<T>* precedenteNode(ft::BTree<T>* root, ft::BTree<T>* node) {
	std::cout << "root parente = " << root->parent << std::endl;

	std::cout << "node parente = " << node->parent->pair->first << std::endl;

	ft::BTree<T>* node_per = node->parent;

	std::cout << "padre node per = " << node_per->parent->pair->first << std::endl;


	// while(root != NULL && !is_sentinel(root)) {

	// 	if (root->right == node)
	// 		return (root);
	// 	root = root->right;
	// }

	return (node->parent);
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

template <class T, class Alloc>
void	free_sentinel(ft::BTree<T>* sentinel, Alloc alloc) {

	alloc.destroy(sentinel);
	alloc.deallocate(sentinel, 1);
	// std::cout << "dealloc sentinel = " << sentinel << std::endl;
}

template <class T, class Alloc1, class Alloc2>
void	BTree_PostOrder_free(ft::BTree<T>* root, Alloc1 node_alloc, Alloc2 pair_alloc) {

	if (!root)
		return ;
	BTree_PostOrder_free(root->left, node_alloc, pair_alloc);
	BTree_PostOrder_free(root->right, node_alloc, pair_alloc);
	if (root->pair) {
		pair_alloc.destroy(root->pair);
		pair_alloc.deallocate(root->pair, 1);
	}
	node_alloc.destroy(root);
	node_alloc.deallocate(root, 1);
	// std::cout << " Deallocat node " << root << std::endl;
}

#endif
