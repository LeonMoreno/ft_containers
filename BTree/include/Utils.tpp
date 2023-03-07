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

// Funcion para operator overload ++
template <class T>
ft::BTree<T>* BTree_minNode(ft::BTree<T> *root) {

	while (root->left != NULL && !is_sentinel(root->left)) {
		root = root->left;
	}
	return (root);
}

template <class T>
ft::BTree<T>* BTree_NodeSuccessor(ft::BTree<T>* root) {

	if (root->right != NULL && !is_sentinel(root->right))
		return (BTree_minNode(root->right));

	ft::BTree<T>* tmp = root->parent;

	while (tmp != NULL && root == tmp->right) {
		root = tmp;
		tmp = tmp->parent;
	}
	return (tmp);
}

// Funcion para operator overload --
template <class T>
ft::BTree<T>* BTree_maxNode(ft::BTree<T> *root) {

	while (root->right != NULL && !is_sentinel(root->right)) {
		root = root->right;
	}
	return (root);
}

template <class T>
ft::BTree<T>* BTree_NodePrev(ft::BTree<T>* root) {

	if (root->left != NULL && !is_sentinel(root->left))
		return (BTree_maxNode(root->left));

	ft::BTree<T>* tmp = root->parent;

	while (tmp != NULL && root == tmp->left) {
		root = tmp;
		tmp = tmp->parent;
	}
	return (tmp);
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
	// std::cout << " Deallocat node " << root->pair << std::endl;
}

template <class T, class Alloc1, class Alloc2>
void	free_Node_OneSentinel(ft::BTree<T>* node, ft::BTree<T>* senti, Alloc1 node_alloc, Alloc2 pair_alloc) {

	free_sentinel(senti, node_alloc);
	pair_alloc.destroy(node->pair);
	pair_alloc.deallocate(node->pair, 1);
	node_alloc.destroy(node);
	node_alloc.deallocate(node, 1);
}

template <class T, class Alloc1>
void	free_Node_OneSentinel_A(ft::BTree<T>* node, ft::BTree<T>* senti, Alloc1 node_alloc) {

	free_sentinel(senti, node_alloc);
	// pair_alloc.destroy(node->pair);
	// pair_alloc.deallocate(node->pair, 1);
	node_alloc.destroy(node);
	node_alloc.deallocate(node, 1);
}


#endif
