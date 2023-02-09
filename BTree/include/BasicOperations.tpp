/* Template (.tpp) file include guards or not ??*/
// https://stackoverflow.com/questions/54362798/template-tpp-file-include-guards
#ifndef BASICS_TPP
# define BASICS_TPP

#include "BTree.hpp"

template <class T, class Alloc>
ft::BTree<T>	*BTree_CreatNode(T pair, Alloc alloc) {

	ft::BTree<T> *new_node = alloc.allocate(1);
	alloc.construct(new_node, ft::BTree<T>(pair));
	return (new_node);
}

template <class T, class Compare, class Alloc>
void	InsertHelp(ft::BTree<T> *root, T pair, Compare compare, Alloc alloc) {


	if(!root)
		return ;
	if (compare(root->pair, pair)) {
		std::cout << "Es menor y Pair es " << pair.first << std::endl;
		InsertHelp((root->right), pair, compare, alloc);
		if (root->right == NULL)
			(root->right = BTree_CreatNode(pair, alloc));
	}
	else {
		std::cout << "Es Mayor y Pair es " << pair.first << std::endl;
		InsertHelp((root->left), pair, compare, alloc);
		if (root->left == NULL)
			root->left = BTree_CreatNode(pair, alloc);
	}
}

template <class T, class Compare, class Alloc>
void	BTree_InsertNode(ft::BTree<T> **root, T pair, Compare compare, Alloc alloc) {

	if (*root == NULL) {
		*root = BTree_CreatNode(pair, alloc);
		return ;
	}

	InsertHelp(*root, pair, compare, alloc);
}


#endif
