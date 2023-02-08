#ifndef BST_HPP
# define BST_HPP

namespace ft {

	template <typename T>
	struct BTree
	{
		BTree	*left;
		BTree	*right;

		T		*node;

		BTree() : left(NULL), right(NULL), node(NULL) { std::cout << "Constr Def " << std::endl; }
		BTree(T *new_node) : left(NULL), right(NULL), node(new_node) { std::cout << "Constr Def " << std::endl; }
		~BTree() { std::cout <<  "Destructor " << std::endl; }
	};
} 

#include "InsertNode.tpp"
#include "CreatNode.tpp"


#endif
