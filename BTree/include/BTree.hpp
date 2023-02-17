#ifndef BST_HPP
# define BST_HPP

namespace ft {

	template <typename T>
	struct BTree
	{
		BTree	*left;
		BTree	*right;

		T		*pair;

		BTree() : left(NULL), right(NULL), pair(NULL) {    } // std::cout << "BTree Constr Def " << std::endl; }
		BTree(T *new_pair) : left(NULL), right(NULL), pair(new_pair) { } // std::cout << "BTree Constr INT " << std::endl; }
		~BTree() {  }// std::cout <<  "BTree Destructor " << std::endl; }
	};
}

#include	"Utils.tpp"
#include	"BasicOperations.tpp"
#include	"TraverseTree.tpp"

#endif
