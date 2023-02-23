#ifndef HEIGHT_TPP
# define HEIGHT_TPP

#include "BTree.hpp"
#include "Rotations.tpp"

template <class T, class Alloc>
void	CheckRebalance(ft::BTree<T>* node, Alloc alloc) {
	std::cout << "Pa rebalanceo" << node->pair->first << std::endl;
	// std::cout << "Antes Rebalance = " << node->right << std::endl;
	(void) alloc;

	if (node->bf > 1 && node->right->bf > 0)
		rebalance_LL(node, alloc);
	std::cout << "Despues Rebalance = " << node->right << std::endl;

}


// Update balance factor node recursive --
template <class T, class Alloc>
void	updateBalance(ft::BTree<T>* node, Alloc alloc) {

	if (node->bf < -1 || node->bf > 1) {
		CheckRebalance(node, alloc);
	std::cout << "After UpdateBalnce Rebalance node Rigt= " << node->right << std::endl;
	return ;
	// std::cout << "RETURN DESPUES" << node->right << std::endl;

	}

	// std::cout << "Arriba UpdateRebalance Entre parent = " << node->parent << std::endl;
	if (node->parent != NULL) {
	// std::cout << "node " << node->pair->first <<  " parent = " << node->parent->pair->first << std::endl;

		if (node == node->parent->left)
			node->parent->bf -= 1;
		else if (node == node->parent->right)
			node->parent->bf += 1;
		if (node->parent->bf != 0)
			updateBalance(node->parent, alloc);
		// std::cout << "VUELVO AQUI ?? NOde " << node << std::endl;

	}
}

#endif
