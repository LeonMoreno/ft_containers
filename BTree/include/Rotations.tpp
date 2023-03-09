#ifndef ROTATIONS_HPP
# define ROTATIONS_HPP

#include "BTree.hpp"
#include <algorithm>

template <class T>
void	rotation_Left(ft::BTree<T>** root, ft::BTree<T>* node) {
	// std::cout << "RotaLeft nodo = " << node->pair->first << " bf = " << node->bf << std::endl;

	ft::BTree<T>* temp = node->right;

	// Movimientos
	node->right = temp->left;
	if (temp->left != NULL)
		temp->left->parent = node;
	temp->left = node;
	// conexion al arbol
	if (node->parent == NULL)
		(*root) = temp;
	else if (node == node->parent->left)
		node->parent->left = temp;
	else if (node == node->parent->right)
		node->parent->right = temp;
	// Quien es papa de quien
	temp->parent = node->parent;
	node->parent = temp;
	// // update the balance factor
	node->bf = node->bf - 1 - std::max(0, temp->bf);
	temp->bf = temp->bf - 1 + std::min(0, node->bf);
}

template <class T>
void	rotation_Right(ft::BTree<T>** root, ft::BTree<T>* node) {
	// std::cout << "RotaRigth nodo = " << node->pair->first << " bf = " << node->bf << std::endl;

	ft::BTree<T>* temp = node->left;

	//Movimientos
	node->left = temp->right;
	if (temp->right != NULL)
		temp->right->parent = node;
	temp->right = node;
	// Conexion al Arbol
	if (node->parent == NULL)
		(*root) = temp;
	else if (node == node->parent->left)
		node->parent->left = temp;
	else if (node == node->parent->right)
		node->parent->right = temp;
	// quin es el papa de quien
	temp->parent = node->parent;
	node->parent = temp;
	// update balance factor
	node->bf = node->bf + 1 - std::min(0, temp->bf);
	temp->bf = temp->bf + 1 - std::max(0, node->bf);
}

#endif
