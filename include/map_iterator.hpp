#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

#include "itetator_traits.hpp"
#include "../BTree/include/BTree.hpp"
#include "map.hpp"


namespace ft {

	template <typename T>
	class map_iterator {
		public:


			/*---------------VECTOR ITERATOR TYPEDEFS (iterator traits - las propiedades del iterator)-------- */

			typedef		map_iterator<T>					iterator;
			typedef		std::bidirectional_iterator_tag	iterator_category;
			typedef		T								value_type;
			typedef		T*								pointer;
			typedef		T&								reference;

			typedef 	ft::BTree<T>*					node_pointer;
			// typedef ft::btree<T>&					node_reference;
			// typedef std::ptrdiff_t					difference_type;

			//---------------MAP ITERATOR CONSTRUCTORS-----------------------------------------------
			map_iterator() : _node_ptr(NULL) {  }// std::cout << "ITE_MAP def constr\n"; }
			explicit map_iterator (node_pointer ptr) : _node_ptr(ptr) {
				// std::cout << "ITE_MAP INI constr ptr = " << ptr << std::endl;
				}

			~map_iterator () { }

			//relational operators overload
			bool operator==(const iterator& right_hand_side)
			{
				return this->_node_ptr == right_hand_side._node_ptr;
			}
			bool operator!=(const iterator& right_hand_side)
			{
				return this->_node_ptr != right_hand_side._node_ptr;
			}


			//---------------MAP ITERATOR OPERATOR OVERLOADS----------------------------------------

			// map_iterator operator--(void) {
			// 	node_pointer precedent;

			// 	precedent = ()
			// 	return(*this);
			// }


			//---------------PRIVATE HELPER FUNCIONS----------------------------------------

			node_pointer base() const {return (_node_ptr); }
			node_pointer get_node(void) { return (this->_node_ptr); }


			//---------------MAP ITERATOR OPERATOR OVERLOADS (NON-MEMBER) -> DIFFERENT ITERATOR TYPE----------------------------------------




			//---------------PRIVATE MEBER FUNCTION------------------------------------------------
		private:
			node_pointer	_node_ptr;


	};


} // end namespace ft



#endif
