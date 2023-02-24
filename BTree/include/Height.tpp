#ifndef HEIGHT_TPP
# define HEIGHT_TPP

#include "BTree.hpp"
#include "Rotations.tpp"

template <class T>
void	CheckRebalance(ft::BTree<T>** root, ft::BTree<T>* node) {
	if (node->bf > 1 && node->right->bf > 0)
		rebalance_LL(root, node);
}

template <class T>
void	updateBalance(ft::BTree<T> **root ,ft::BTree<T>* node) {

	// if (!node->parent)
	// 	return ;
	std::cout << "UpdateBalance nodo = " << node->pair->first << " bf = " << node->bf << std::endl;

	if (node->bf < -1 || node->bf > 1) {
		CheckRebalance(root, node);
		return ;
	}

	if (node->parent != NULL) {
		std::cout << "2do if nodo = " << node->pair->first << " bf = " << node->bf << std::endl;

		if (node == node->parent->left)
			node->parent->bf -= 1;
		else if (node == node->parent->right)
			node->parent->bf += 1;
		if (node->parent->bf != 0)
			updateBalance(root, node->parent);
	}
}

#endif
