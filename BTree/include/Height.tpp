#ifndef HEIGHT_TPP
# define HEIGHT_TPP

#include "BTree.hpp"
#include "Rotations.tpp"

template <class T>
void	CheckRebalance(ft::BTree<T>* node) {
	std::cout << "Pa rebalanceo" << node->pair->first << std::endl;

	// if (node->bf > 1 && node->right->bf > 0)
	// 	rebalance_LL(node);
}


// Update balance factor node recursive --
template <class T>
void	updateBalance(ft::BTree<T>* node) {

	if (node->bf < -1 || node->bf > 1) {
		CheckRebalance(node);
		return ;
	}

	if (node->parent != NULL) {
		// std::cout << "Entre parent = " << node->parent->pair->first << std::endl;

		if (node == node->parent->left)
			node->parent->bf -= 1;
		else if (node == node->parent->right)
			node->parent->bf += 1;
		if (node->parent->bf != 0)
			updateBalance(node->parent);
	}
}

#endif
