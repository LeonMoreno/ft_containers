#ifndef ROTATIONS_HPP
# define ROTATIONS_HPP

#include "BTree.hpp"
#include <algorithm>

// template <class T>
// void swap(ft::BTree<T>* rh, ft::BTree<T>* lh) {


// }

template <class T, class Alloc>
void	rebalance_LL(ft::BTree<T>* node, Alloc alloc) {
	(void) alloc;

	std::cout << "Rotacion Para node " << node->pair->first << std::endl;

	std::cout << "node rig = " << node->right << std::endl;

	// ft::BTree<T>* temp;

	// temp = node->right;

	// std::cout << "temp left = " << temp->left << std::endl;

	

	alloc.destroy(node->right);
	alloc.deallocate(node->right, 1);
	node->right = NULL;

	// std::cout << "node rig = " << node->right << std::endl;


	// std::cout << "Despues node rig = " << node->right << std::endl;

	// if (temp->left != NULL) {
	// 	temp->left->parent = node;
	// }


	// temp->parent = node->parent;

	// if (node->parent == NULL)
	// 	std::cout << "aqui fue\n";
	// else if (node == node->parent->left)
	// 	node->parent->left = temp;
	// else if (node == node->parent->right)
	// 	node->parent->right = temp;
	// // free_sentinel(temp->left, alloc);
	// temp->left = node;
	// node->parent = temp;
	// std::cout << "Termine"<< std::endl;

	// // update the balance factor
	// node->bf = node->bf - 1 - std::max(0, temp->bf);
	// temp->bf = temp->bf - 1 + std::min(0, node->bf);
}


#endif
