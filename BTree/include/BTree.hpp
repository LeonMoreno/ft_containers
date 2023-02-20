#ifndef BST_HPP
# define BST_HPP

namespace ft {

	template <typename T>
	struct BTree
	{
		BTree	*parent;
		BTree	*left;
		BTree	*right;

		T		*pair;

		BTree() : parent(NULL), left(NULL), right(NULL), pair(NULL) {    } // std::cout << "BTree Constr Def " << std::endl; }
		BTree(T *new_pair) : parent(NULL), left(NULL), right(NULL), pair(new_pair) { } // std::cout << "BTree Constr INT " << std::endl; }
		~BTree() {  }// std::cout <<  "BTree Destructor " << std::endl; }
	};
}

#include	"Utils.tpp"
#include	"BasicOperations.tpp"
#include	"TraverseTree.tpp"

#endif
