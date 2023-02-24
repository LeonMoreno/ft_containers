#ifndef TRAVERSETREE_TPP
# define TRAVERSETREE_TPP

#include "BTree.hpp"

template <class T>
void	BTree_TraversePreOrder(ft::BTree<T> *root) {

	if (!root)
		return ;
	if (!is_sentinel(root))
		std::cout << root->pair->first << ' ';
	BTree_TraversePreOrder(root->left);
	BTree_TraversePreOrder(root->right);
}

template <class T>
void	BTree_TraverseInOrder(ft::BTree<T> *root) {

	if (!root)
		return ;

	BTree_TraverseInOrder(root->left);
	if (!is_sentinel(root))
		std::cout << root->pair->first << " bf = " << root->bf << std::endl;
	BTree_TraverseInOrder(root->right);
}

template <class T>
ft::BTree<T>* help_begin(ft::BTree<T> *root)
{
	if (!(root->left) || is_sentinel(root->left))
		return (root);
	return (help_begin(root->left));
}

template <class T>
ft::BTree<T>* BTree_beginInOrder(ft::BTree<T> *root) {

	if (!root)
		return (NULL);
	return (help_begin(root));
}

template <class T>
ft::BTree<T>* help_end(ft::BTree<T> *root)
{
	if (!root->right || is_sentinel(root->right))
		return (root->right);
	return (help_end(root->right));
}


template <class T>
ft::BTree<T>* BTree_endInOrder(ft::BTree<T> *root) {

	if (!root)
		return (NULL);

	return (help_end(root));
}

template  <class T>
void	BTree_Print(ft::BTree<T>* root, std::string inde, bool last) {

	if (root != NULL) {
		std::cout << inde;
		if (last) {
			std::cout << "R----";
			inde += "     ";
		} else {
			std::cout << "L----";
			inde += "|    ";
		}

		if (!is_sentinel(root))
			std::cout << root->pair->first << "( BF = " << root->bf << ")" << std::endl;
		else
			std::cout << root << "( is_sentinel )" << std::endl;



		BTree_Print(root->left, inde, false);
		BTree_Print(root->right, inde, true);
	}
}

#endif
