#ifndef UTILS_TPP
# define UTILS_TPP

#include "BTree.hpp"

template <class T, class Compare>
bool	IsAlready(ft::BTree<T> *root, T pair, Compare compe) {

	if (!compe(root->pair, pair) && !compe(pair, root->pair))
		return (false);
	return (true);
}


#endif
