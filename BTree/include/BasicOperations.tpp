/* Template (.tpp) file include guards or not ??*/
// https://stackoverflow.com/questions/54362798/template-tpp-file-include-guards
#ifndef BASICS_TPP
# define BASICS_TPP

#include "BTree.hpp"
#include "Height.tpp"

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
	new_node->bf = 0;
	new_node->left = Creat_SentinelNode<T>(new_node, alloc);
	new_node->right = Creat_SentinelNode<T>(new_node, alloc);
	return (new_node);
}

template <class T, class Alloc>
ft::BTree<T>	*BTree_CreatNode(T *pair, Alloc alloc) {

	ft::BTree<T> *new_node = alloc.allocate(1);
	alloc.construct(new_node, ft::BTree<T>(pair));
	new_node->left = Creat_SentinelNode<T>(new_node, alloc);
	new_node->right = Creat_SentinelNode<T>(new_node, alloc);
	return (new_node);
}

template <class T, class Compare, class Alloc>
void	InsertHelp(ft::BTree<T>** _root, ft::BTree<T> **root,
	ft::BTree<T>* parent, T* pair, Compare compare, Alloc alloc) {

	if(is_sentinel(*root)) {
		free_sentinel(*root, alloc);
		*root = BTree_CreatNode(pair, alloc);
		(*root)->parent = parent;
		updateBalance(_root, *root);
		return ;
	}
	// if (is_equal(*root, *pair, compare)) // solo un ensayo ;)
	// 	return ;
	// if (compare(*(*root)->pair, *pair)) // -- Aqui estaba el problema de Compare 
	if (compare(*pair, *(*root)->pair))
		return (InsertHelp(_root, &(*root)->left, *root, pair, compare, alloc));
	return (InsertHelp(_root, &(*root)->right, *root, pair, compare, alloc));
}

template <class T, class Compare, class Alloc>
void	BTree_InsertNode(ft::BTree<T> **root, T* pair, Compare compare, Alloc alloc) {

	if (*root == NULL) {
		*root = BTree_CreatRoot(pair, alloc);

		return ;
	}
	InsertHelp(root, root, *root, pair, compare, alloc);
}

template <class T, class Alloc1, class Alloc2>
void	BTree_deleteNode_A(ft::BTree<T> **_root, ft::BTree<T> *root,
		int key, Alloc1 node_alloc, Alloc2 pair_alloc) {

	// std::cout << "O SORPRESA ENTRO ACA = " << std::endl;


	if (!root || is_sentinel(root))
		return ;
	if (key == root->pair->first) {
		// case 1
		if (is_sentinel(root->left) && is_sentinel(root->right)) {

			ft::BTree<T>* tmp_setinel = root->right;
			ft::BTree<T>* papa= root->parent;

			if (root->parent == NULL) {
				BTree_PostOrder_free(root, node_alloc, pair_alloc);
				(*_root) = NULL;
				return ;
			}
			if (root == root->parent->left)
				root->parent->left = tmp_setinel;
			else if (root == root->parent->right)
				root->parent->right = tmp_setinel;
			tmp_setinel->parent = papa;
			free_Node_OneSentinel_A(root, root->left, node_alloc);
			updateBalance_Del(_root, papa);
			return ;
		}
		// Case 2
		else if (is_sentinel(root->left)){

			ft::BTree<T>* papa= root->parent;

			if (root == root->parent->left)
				root->parent->left = root->right;
			else if (root == root->parent->right)
				root->parent->right = root->right;
			root->right->parent = papa;
			free_Node_OneSentinel_A(root, root->left, node_alloc);
			updateBalance_Del(_root, papa);
			return ;
		}
		else if (is_sentinel(root->right)){

			ft::BTree<T>* papa= root->parent;

			if (root == root->parent->left)
				root->parent->left = root->left;
			else if (root == root->parent->right)
				root->parent->right = root->left;
			root->left->parent = papa;
			free_Node_OneSentinel_A(root, root->right, node_alloc);
			updateBalance_Del(_root, papa);
			return ;
		}
		// case 3 // Hijos a ambos lados
		else {
			// std::cout << "voy por aca AMBPS\n";


			ft::BTree<T>* tmp = BTree_minNode(root->right);

			pair_alloc.destroy(root->pair);
			pair_alloc.deallocate(root->pair, 1);

			root->pair = tmp->pair;

			BTree_deleteNode_A(_root, root->right, tmp->pair->first, node_alloc, pair_alloc);
			return ;
		}

	}
	else if (key > root->pair->first)
		return (BTree_deleteNode_A(_root, root->right, key, node_alloc, pair_alloc));
	return (BTree_deleteNode_A(_root, root->left, key, node_alloc, pair_alloc));
}





template <class T, class Alloc1, class Alloc2, class Compare>
void	BTree_deleteNode(ft::BTree<T> **_root, ft::BTree<T> *root,
		T key, Alloc1 node_alloc, Alloc2 pair_alloc, Compare compe) {

	if (!root || is_sentinel(root))
		return ;
	// if (key == root->pair->first) {
	if (is_equal(root, key, compe)) {
		// case 1
		if (is_sentinel(root->left) && is_sentinel(root->right)) {

		// std::cout << "case_1 = " << root->pair->first << std::endl;


			ft::BTree<T>* tmp_setinel = root->right;
			ft::BTree<T>* papa= root->parent;

			if (root->parent == NULL) {
				BTree_PostOrder_free(root, node_alloc, pair_alloc);
				(*_root) = NULL;
				return ;
			}
			if (root == root->parent->left) {
				// std::cout << "root = root->papa->left bf = " <<  papa->bf << std::endl;
				papa->bf += 1;
				root->parent->left = tmp_setinel;
				// std::cout << "root = root->papa->left bf = " <<  papa->bf << std::endl;

			}
			else if (root == root->parent->right) {
				papa->bf -= 1;
				root->parent->right = tmp_setinel;
			}
			tmp_setinel->parent = papa;
			free_Node_OneSentinel(root, root->left, node_alloc, pair_alloc);
			updateBalance_Del(_root, papa);
			return ;
		}
		// Case 2
		else if (is_sentinel(root->left)){

		// std::cout << "case_2 = " << root->pair->first << std::endl;


			ft::BTree<T>* papa= root->parent;

			if (root->parent == NULL)
				(*_root) = root->right;
			else if (root == root->parent->left) {
				papa->bf += 1;
				root->parent->left = root->right;
			}
			else if (root == root->parent->right) {
				papa->bf += 1;
				root->parent->right = root->right;
			}
			root->right->parent = papa;
			free_Node_OneSentinel(root, root->left, node_alloc, pair_alloc);
			updateBalance_Del(_root, papa);
			return ;
		}
		else if (is_sentinel(root->right)){

			ft::BTree<T>* papa= root->parent;

			if (root->parent == NULL)
				(*_root) = root->left;
			else if (root == root->parent->left) {
				papa->bf += 1;
				papa->left = root->left;
			}
			else if (root == root->parent->right) {
				papa->bf -= 1;
				root->parent->right = root->left;
			}
			root->left->parent = papa;
			free_Node_OneSentinel(root, root->right, node_alloc, pair_alloc);
			updateBalance_Del(_root, papa);
			return ;
		}
		// case 3 // Hijos a ambos lados
		else {
			// std::cout << "case 3 Pares " << root->pair->first << std::endl;

			ft::BTree<T>* tmp = BTree_minNode(root->right);

			pair_alloc.destroy(root->pair);
			pair_alloc.deallocate(root->pair, 1);

			root->pair = tmp->pair;

			BTree_deleteNode_A(_root, root->right, tmp->pair->first, node_alloc, pair_alloc);
			return ;
		}

	}
	// else if (key > root->pair->first)
	else if (compe(*root->pair, key))
		return (BTree_deleteNode(_root, root->right, key, node_alloc, pair_alloc, compe));
	return (BTree_deleteNode(_root, root->left, key, node_alloc, pair_alloc, compe));
}


#endif
