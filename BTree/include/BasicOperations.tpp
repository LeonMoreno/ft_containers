/* Template (.tpp) file include guards or not ??*/
// https://stackoverflow.com/questions/54362798/template-tpp-file-include-guards
#ifndef BASICS_TPP
# define BASICS_TPP

#include "BTree.hpp"

template <class T, class Alloc>
ft::BTree<T>	*Creat_SentinelNode(ft::BTree<T>* root, Alloc alloc) {

	ft::BTree<T> *sentinel_node = alloc.allocate(1);
	alloc.construct(sentinel_node, ft::BTree<T>());
	sentinel_node->parent = root;
	return (sentinel_node);
}

template <class T, class Alloc>
ft::BTree<T>	*BTree_CreatRoot(T *pair, Alloc alloc) {

	ft::BTree<T> *new_node = alloc.allocate(1);
	alloc.construct(new_node, ft::BTree<T>(pair));
	new_node->parent = NULL;
	new_node->left = Creat_SentinelNode<T>(new_node, alloc);
	new_node->right = Creat_SentinelNode<T>(new_node, alloc);

	return (new_node);
}

template <class T, class Alloc>
ft::BTree<T>	*BTree_CreatNode(ft::BTree<T>* root, T *pair, Alloc alloc) {

	ft::BTree<T> *new_node = alloc.allocate(1);
	alloc.construct(new_node, ft::BTree<T>(pair));
	new_node->parent = root;
	new_node->left = Creat_SentinelNode<T>(new_node, alloc);
	new_node->right = Creat_SentinelNode<T>(new_node, alloc);
	return (new_node);
}

template <class T, class Compare, class Alloc>
void	InsertHelp(ft::BTree<T> *root, T* pair, Compare compare, Alloc alloc) {

	if(!root || is_sentinel(root))
		return ;

	if (is_equal(root, *pair, compare))
		return ;
	if (compare(*root->pair, *pair)) {
		// std::cout << "Es menor y Pair es " << pair->first << std::endl;
		InsertHelp((root->right), pair, compare, alloc);
		if (is_sentinel(root->right)) {
			(root->right = BTree_CreatNode(root, pair, alloc));

		}
	}
	else {
		// std::cout << "Es Mayor y Pair es " << pair->first << std::endl;
		InsertHelp((root->left), pair, compare, alloc);
		if (is_sentinel(root->left))
			root->left = BTree_CreatNode(root, pair, alloc);
	}
}

template <class T, class Compare, class Alloc>
void	BTree_InsertNode(ft::BTree<T> **root, T* pair, Compare compare, Alloc alloc) {

	if (*root == NULL) {
		*root = BTree_CreatRoot(pair, alloc);
		return ;
	}

	InsertHelp(*root, pair, compare, alloc);
}

template <class T, class Alloc>
ft::BTree<T>*	BTree_deleteNode(ft::BTree<T> *root, int key, Alloc alloc) {

	if (!root)
		return (root);
	if (key == root->pair.first) {
		if (!root->left) {
			if (!root->right) {
				alloc.destroy(root);
				alloc.deallocate(root, 1);
			}
			return (root->right);
		}
		else if (!root->right)
			return (root->left);
		else {
			ft::BTree<T>* p = inorderSuccessor(root, root->pair.first);

			root->pair = p->pair;
			root->right = BTree_deleteNode(root->right, p->pair.first, alloc);
			return (root);
		}
	}
	else if (key > root->pair.first)
		root->right = BTree_deleteNode(root->right, key, alloc);
	else
		root->left = BTree_deleteNode(root->left, key, alloc);
	return (root);
}


#endif
