/* Template (.tpp) file include guards or not ??*/
// https://stackoverflow.com/questions/54362798/template-tpp-file-include-guards

#ifndef INSERTNODE_TPP
# define INSERTNODE_TPP

#include "CreatNode.tpp"

template <class T, class Compare, class Alloc>
void	BTree_InsertNode(ft::BTree<T> **root, T *node, Compare compare, Alloc alloc) {

	if (*root == NULL) {
		*root = BTree_CreatNode_root(node, alloc);
		return ;
	}
	(void) compare;


}


#endif
