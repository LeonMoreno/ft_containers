#include <iostream>

template <class T>
struct key_compare {

	std::less<int> comp;

	key_compare() : comp(std::less<int>()) { }

	bool operator() (T& x, T& y) {
		return comp(x.first, y.first);
	}
};

std::pair<int, int>	*new_pair(int x, int y) {

	std::pair<int, int> *a = new std::pair<int, int>(x, y);

	return (a);
}


namespace ft {

	template <typename T>
	struct BTree
	{
		BTree	*parent;
		BTree	*left;
		BTree	*right;

		T		*pair;
		int		bf; // balance factor

		BTree() : parent(NULL), left(NULL), right(NULL), pair(NULL), bf(0) {    } // std::cout << "BTree Constr Def " << std::endl; }
		BTree(T *new_pair) : parent(NULL), left(NULL), right(NULL), pair(new_pair), bf(0) { } // std::cout << "BTree Constr INT " << std::endl; }
		~BTree() {  }// std::cout <<  "BTree Destructor " << std::endl; }
	};
}


template <class T>
void	rebalance_LL(ft::BTree<T>* node) {

	ft::BTree<T>* temp;
	temp = node->right;

	node->right = temp->left;
	if (temp->left != NULL) {
		temp->left->parent = node;
	}
	temp->parent = node->parent;

	if (node->parent == NULL)
		;
	else if (node == node->parent->left)
		node->parent->left = temp;
	else if (node == node->parent->right)
		node->parent->right = temp;

	temp->left = node;
	node->parent = temp;

	// // update the balance factor
	node->bf = node->bf - 1 - std::max(0, temp->bf);
	temp->bf = temp->bf - 1 + std::min(0, node->bf);
}

template <class T>
void	CheckRebalance(ft::BTree<T>* node) {

	if (node->bf > 0) {
		if (node->right->bf < 0)
			std::cout << " por aca me fui node" << node->pair->first << std::endl;
		else
			rebalance_LL(node);
	} else if (node->bf < 0) {
		std::cout << "BF es menor" << std::endl;
	}

}


// Update balance factor node recursive --
template <class T>
void	updateBalance(ft::BTree<T>* node) {

	if (node->bf < -1 || node->bf > 1) {
		CheckRebalance(node);
		return ;
	}

	if (node->parent != NULL) {
		if (node == node->parent->left)
			node->parent->bf -= 1;
		if (node == node->parent->right)
			node->parent->bf += 1;
		if (node->parent->bf != 0)
			updateBalance(node->parent);
	}
}

template <class T, class Compare>
bool	is_equal(ft::BTree<T> *root, T pair, Compare compe) {

	if ((compe(*root->pair, pair) == false) && (compe(pair, *root->pair) == false))
		return (true);
	return (false);
}

template <class T, class Alloc>
void	free_sentinel(ft::BTree<T>* sentinel, Alloc alloc) {

	alloc.destroy(sentinel);
	alloc.deallocate(sentinel, 1);
}

template <class T>
bool	is_sentinel(ft::BTree<T>* root) {

	if (!root)
		return (false);
	if (!root->pair && !root->left && !root->right)
		return (true);
	return (false);
}

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
ft::BTree<T>	*BTree_CreatNode(ft::BTree<T>* root, T *pair, Alloc alloc) {

	ft::BTree<T> *new_node = alloc.allocate(1);
	alloc.construct(new_node, ft::BTree<T>(pair));
	new_node->parent = root;
	new_node->left = Creat_SentinelNode<T>(new_node, alloc);
	new_node->right = Creat_SentinelNode<T>(new_node, alloc);
	return (new_node);
}

template <class T>
void	updateRoot(ft::BTree<T>** root) {

	if ((*root)->parent == NULL) {
		return ;
	}
	*root = (*root)->parent;
}

template <class T, class Compare, class Alloc>
void	InsertHelp(ft::BTree<T> *root, T* pair, Compare compare, Alloc alloc) {

	if(!root || is_sentinel(root))
		return ;

	if (is_equal(root, *pair, compare))
		return ;
	if (compare(*root->pair, *pair)) {
		// std::cout << "root = " << root->pair->first << " Es menor y Pair es " << pair->first << std::endl;
		InsertHelp((root->right), pair, compare, alloc);
		if (is_sentinel(root->right)) {
			free_sentinel(root->right, alloc);
			root->right = BTree_CreatNode(root, pair, alloc);
			updateBalance(root->right);
			return ;
		}
	}
	else {
		// std::cout << "Es Mayor y Pair es " << pair->first << std::endl;
		InsertHelp((root->left), pair, compare, alloc);
		if (is_sentinel(root->left)) {
			free_sentinel(root->left, alloc);
			root->left = BTree_CreatNode(root, pair, alloc);
			updateBalance(root->left);
			return ;
		}
	}
}

template <class T, class Compare, class Alloc>
void	BTree_InsertNode(ft::BTree<T> **root, T* pair, Compare compare, Alloc alloc) {

	if (*root == NULL) {
		*root = BTree_CreatRoot(pair, alloc);
		return ;
	}
	InsertHelp(*root, pair, compare, alloc);
	updateRoot(root);
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

int main (void) {

	key_compare<std::pair<int, int> > compare;
	std::allocator< ft::BTree<std::pair<int, int> > > alloc;
	ft::BTree<std::pair<int, int> > *root = NULL;

	BTree_InsertNode(&root, new_pair(30, 100), compare, alloc);
	BTree_InsertNode(&root, new_pair(60, 100), compare, alloc);
	BTree_InsertNode(&root, new_pair(90, 100), compare, alloc);

	BTree_TraverseInOrder(root);
	std::cout << std::endl;


	return (0);
}
