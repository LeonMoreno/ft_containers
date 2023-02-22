#ifndef ROTATIONS_HPP
# define ROTATIONS_HPP

#include "BTree.hpp"
#include <algorithm>

// template <class T>
// void swap(ft::BTree<T>* rh, ft::BTree<T>* lh) {


// }

template <class T>
void	rebalance_LL(ft::BTree<T>* node) {
	std::cout << "Aqwui toy" << node->pair->first << std::endl;

	ft::BTree<T>* temp;

	temp = node->right;
	node->right = temp->left;
	if (temp->left != NULL) {
		temp->left->parent = node;
	}


	temp->parent = node->parent;

	if (node->parent == NULL)
		std::cout << "aqui fue\n";
	else if (node == node->parent->left)
		node->parent->left = temp;
	else if (node == node->parent->right)
		node->parent->right = temp;
	temp->left = node;
	node->parent = temp;
	std::cout << "Termine"<< std::endl;

	// update the balance factor
	node->bf = node->bf - 1 - std::max(0, temp->bf);
	temp->bf = temp->bf - 1 + std::min(0, node->bf);
}


#endif
