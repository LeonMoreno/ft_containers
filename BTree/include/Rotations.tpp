#ifndef ROTATIONS_HPP
# define ROTATIONS_HPP

#include "BTree.hpp"
#include <algorithm>

// template <class T>
// void swap(ft::BTree<T>* rh, ft::BTree<T>* lh) {


// }

template <class T>
void	rebalance_LL(ft::BTree<T>** root, ft::BTree<T>* node) {

	std::cout << "Rebalance node = " << node->pair->first << std::endl;
	std::cout << "Rebalance root = " << (*root)->pair->first << std::endl;

	ft::BTree<T>* temp = node->right;

	node->right = temp->left;
	if (temp->left != NULL) {
		temp->left->parent = node;
	}

	temp->left = node;

	if (node->parent == NULL)
		(*root) = temp;
	else if (node == node->parent->left)
		node->parent->left = temp;
	else if (node == node->parent->right)
		node->parent->right = temp;

	temp->parent = node->parent;
	node->parent = temp;


	// // update the balance factor
	node->bf = node->bf - 1 - std::max(0, temp->bf);
	temp->bf = temp->bf - 1 + std::min(0, node->bf);
}


#endif
