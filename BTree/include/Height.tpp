#ifndef HEIGHT_TPP
# define HEIGHT_TPP

#include "BTree.hpp"
#include "Rotations.tpp"

template <class T>
void	CheckRebalance(ft::BTree<T>** root, ft::BTree<T>* node) {
	// std::cout << "check Balc node = " << node->pair->first << std::endl;
	if (node->bf > 0) {
		if (node->right->bf < 0) {
			rotation_Right(root, node->right);
			rotation_Left(root, node);
		}
		else
			rotation_Left(root, node);
	}
	else if (node->bf < 0) {
		if (node->left->bf > 0) {
			rotation_Left(root, node->left);
			rotation_Right(root, node);
		}
		else
			rotation_Right(root, node);
	}
}

template <class T>
void	updateBalance(ft::BTree<T> **root ,ft::BTree<T>* node) {


	if (!node)
		return ;

	if (node->bf < -1 || node->bf > 1) {
		CheckRebalance(root, node);
		return ;
	}

	if (node->parent != NULL) {

		if (node == node->parent->left)
			node->parent->bf -= 1;
		else if (node == node->parent->right)
			node->parent->bf += 1;
		if (node->parent->bf != 0)
			updateBalance(root, node->parent);
	}
}

// Para revisar atentamente apenas tenga todo listo
/**
 * @brief  Actualizo todo los Balance factor de los parent.
 *	A la inversa del otro Balance.
 * @tparam T
 * @param root
 * @param node
 */
template <class T>
void	updateBalance_Del(ft::BTree<T> **root ,ft::BTree<T>* node) {
// std::cout << "Update Balc node = " << node->pair->first << std::endl;
// std::cout << " node par = " << node->parent->pair->first << std::endl;
	if (!node)
		return ;

	if (node->bf < -1 || node->bf > 1) {
		CheckRebalance(root, node);
		return ;
	}

	if (node->parent != NULL) {

		if (node == node->parent->left)
			node->parent->bf += 1;
		else if (node == node->parent->right)
			node->parent->bf -= 1;
		// if (node->parent->bf != 0)
		updateBalance_Del(root, node->parent);
	}
}

#endif
