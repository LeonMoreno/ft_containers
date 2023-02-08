#ifndef CREATNODE_TPP
# define CREATNODE_TPP

#include "BTree.hpp"

template <class T, class Alloc>
ft::BTree<T>	*BTree_CreatNode_root(T *node, Alloc alloc) {

	ft::BTree<T> *new_node = alloc.allocate(1);
	alloc.construct(new_node, ft::BTree<T>(node));
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);

}


#endif
