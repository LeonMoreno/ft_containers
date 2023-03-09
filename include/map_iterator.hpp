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

			typedef	map_iterator<T>					iterator;
			typedef	std::bidirectional_iterator_tag	iterator_category;
			typedef	T								value_type;
			typedef	T*								pointer;
			typedef	T&								reference;
			typedef ft::BTree<T>*					node_pointer;
			typedef	ft::BTree<T>&					node_reference;
			typedef	std::ptrdiff_t					difference_type;

			//---------------MAP ITERATOR CONSTRUCTORS-----------------------------------------------
			map_iterator() : _node_ptr(NULL) {  }// std::cout << "ITE_MAP def constr\n"; }
			explicit map_iterator (node_pointer ptr) : _node_ptr(ptr) {
				// std::cout << "ITE_MAP INI constr ptr = " << ptr << std::endl;
				}

			~map_iterator () { }

			//---------------------------COPY ASSIGNMENT OPERATOR----------------------------------------//

			map_iterator& operator=(const map_iterator& rhs)
			{
				this->_node_ptr = rhs._node_ptr;
				return *this;
			}

			//---------------MAP ITERATOR OPERATOR OVERLOADS----------------------------------------

			//relational operators overload
			bool operator==(const iterator& rhs)
			{
				return this->_node_ptr == rhs._node_ptr;
			}

			bool operator!=(const iterator& rhs) {
				return this->_node_ptr != rhs._node_ptr;
			}


			// increment and decrement operators overload
			/**
			 * @brief pre-increment operator ++
			 * Lo primero es encontrar el root.
			 * Si estamos en el ultimo nodo enInOrder,
			 * No buscamos sucesor y retorno sentinela de la derecha osea end();
			 * @return map_iterator
			 */
			map_iterator operator++(void) {

				node_pointer root = findRoot(_node_ptr);

				if (BTree_endInOrder(root) == _node_ptr->right) {
					_node_ptr = _node_ptr->right;
					return (*this);
				}
				// _node_ptr = inorderSuccessor(root, _node_ptr->pair->first);
				_node_ptr = BTree_NodeSuccessor(_node_ptr);
				return(*this);
			}


			/**
			 * @brief post-increment operator ++
			 * Lo primero es encontrar el root.
			 * Si estamos en el ultimo nodo enInOrder,
			 * No buscamos sucesor y retorno sentinela de la derecha osea end();
			 * @return map_iterator //  returned value should be a copy of the object before increment
			 */
			map_iterator operator++(int) {

				node_pointer root = findRoot(_node_ptr);
				map_iterator temp = *this;

				if (BTree_endInOrder(root) == _node_ptr->right) {
					_node_ptr = _node_ptr->right;
					return (*this);
				}
				// _node_ptr = inorderSuccessor(root, _node_ptr->pair->first);
				_node_ptr = BTree_NodeSuccessor(_node_ptr);
				return(temp);
			}

			map_iterator operator--(void) {

				node_pointer root = findRoot(_node_ptr);

				if (BTree_beginInOrder(root) == _node_ptr) {
					_node_ptr = _node_ptr->left;
					return (*this);
				}

				_node_ptr = BTree_NodePrev(_node_ptr);
				return (*this);
			}

			map_iterator operator--(int) {

				node_pointer root = findRoot(_node_ptr);

				if (BTree_beginInOrder(root) == _node_ptr) {
					_node_ptr = _node_ptr->left;
					return (*this);
				}

				map_iterator temp = *this;
				_node_ptr = BTree_NodePrev(_node_ptr);
				return (temp);
			}

			//dereference operator
			reference operator*(void) const {
				return *(this->_node_ptr->pair);
			}

			pointer operator->(void) {
				return (this->_node_ptr->pair);
			}

			pointer operator->(void) const {
				return (this->_node_ptr->pair);
			}


			//--------------- HELPER FUNCIONS----------------------------------------

			node_pointer get_node(void) { return (this->_node_ptr); }


			//---------------MAP ITERATOR OPERATOR OVERLOADS (NON-MEMBER) -> DIFFERENT ITERATOR TYPE----------------------------------------




			//---------------PRIVATE MEBER FUNCTION------------------------------------------------
		private:
			node_pointer	_node_ptr;

	};


} // end namespace ft



#endif
