#ifndef ROTATIONS_HPP
# define ROTATIONS_HPP

#include "BTree.hpp"
#include <algorithm>

// template <class T>
// void swap(ft::BTree<T>* rh, ft::BTree<T>* lh) {


// }

template <class T>
void	rebalance_LL(ft::BTree<T>* node) {

	std::cout << "Rebalance node = " << node->pair->first << std::endl;

	// ft::BTree<T>* temp;

	// temp = node->right;

	// node->right = temp->left;

	// temp->left = node;


	// if (temp->left != NULL) {
	// 	temp->left->parent = node;
	// }

	// if (node->parent == NULL)
	// 	std::cout << "aqui fue\n";
	// else if (node == node->parent->left) {
	// 	std::cout << "por este else\n";
	// 	node->parent->left = temp;
	// }
	// else if (node == node->parent->right) {
	// 	std::cout << "por este OTRO\n";

	// 	node->parent->right = temp;
	// }

	// temp->parent = node->parent;
	// node->parent = temp;


	// // update the balance factor
	// node->bf = node->bf - 1 - std::max(0, temp->bf);
	// temp->bf = temp->bf - 1 + std::min(0, node->bf);
}


#endif
