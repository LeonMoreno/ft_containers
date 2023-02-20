#ifndef MAP_HPP
# define MAP_HPP

#include <functional>
#include "utils.hpp"
#include "map_iterator.hpp"
#include "../BTree/include/BTree.hpp"


namespace ft
{

//--------------------------Template parameters ---------------------------------------//
	template< class Key,
	 		class T,
			class Compare = std::less<Key>,
			class Alloc = std::allocator< ft::pair<const Key, T> > >
			// class Alloc = std::allocator< ft::BTree< ft::pair<const Key, T> > > >
	class map
	{
		public:
//---------------------------member types -- Definitions---------------------------------//


		/*  Each element in a map is uniquely identified by its key value.
		 Each element in a map is uniquely identified by its key value. */
		typedef Key											key_type;

		/* Each element in a map stores some data as its mapped value.
		 Aliased as member type map::mapped_type.*/
		typedef T											mapped_type;

		typedef ft::pair<const Key, T>						value_type;
		typedef std::size_t									size_type;
		typedef std::ptrdiff_t								difference_type;
		typedef Compare										key_compare;
		typedef Alloc										allocator_type;

		typedef value_type&									reference;
		typedef const value_type&							const_reference;

		typedef typename Alloc::pointer						pointer;
		typedef typename Alloc::const_pointer				const_pointer;

		typedef ft::map_iterator<value_type>				iterator;
		typedef ft::map_iterator<value_type>				const_iterator;

		// typedef	reverse_vector_iterator <iterator>				reverse_iterator;
		// typedef	reverse_vector_iterator <const_iterator>		const_reverse_iterator;

		class value_compare
			{
				friend class map;

				protected:
				Compare comp;
				value_compare (Compare c) : comp(c) {}

				public:

				bool operator() (const value_type& x, const value_type& y) const
				{
					return comp(x.first, y.first);
				}
			};



//---------------------------constructor & Destructor---------------------------------------//

		// default constructor -- Constructs an empty container, with no elements.
		explicit map (const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type()):
			_size(0), _compare(comp), _alloc(alloc), _root(NULL) { }

		//  -- range
		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()):
			_size(0), _compare(comp), _alloc(alloc), _root(NULL) {
				std::cout << " construct range inssert" << std::endl;
				this->insert(first, last);
			}



		~map() {  }//std::cout << "Destructor MAP " << std::endl; }

//---------------------------COPY ASSIGNMENT OPERATOR----------------------------------------//

//-------------------------------Getters and Setters-----------------------------------------------//

//---------------------------Iterator----------------------------------------//
		iterator begin() {
			return (iterator(BTree_beginInOrder(_root)));
		}

		iterator prcedente(ft::BTree<value_type>* node) {
			return (iterator(precedenteNode(_root, node)));
		}

		/**
		 * @brief  Returns an iterator referring to
		 * the past-the-end element in the map container.
		 *	ENvio al constructor de Iterator un ptr a ft::BTree<T>
		 *	Dejo asi en tres pasos para acordarme bien que es un PTR.
		 * @return iterator
		 */
		iterator end() {

			ft::BTree<value_type>* ptr = NULL;

			ptr = BTree_endInOrder(_root);

			return (iterator(ptr));
		}


// }


//---------------------------CAPACITY----------------------------------------//

//---------------------------ELEMENT ACCESS----------------------------------------//

//---------------------------Modifiers----------------------------------------//



		/**
		 * @brief  single element (1)
		 *
		 * @param val
		 * @return ft::pair<iterator,bool>
		 */
		ft::pair<iterator, bool> insert (const value_type& val) {

			iterator it = this->find(val.first);
			if (it != this->end())
				return(ft::make_pair(it, false));
			BTree_InsertNode(&_root, _alloc_pair(val), value_compare(_compare), _node_alloc);
			_size++;
			return (make_pair(it, true));
		}

		// with hint (2)
		// iterator insert (iterator position, const value_type& val);

		// range
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last) {

			while (first != last) {
				this->insert(*first);
				++first;
			}
		}

		size_type erase (const key_type& k) {
			BTree_deleteNode<value_type>(_root, k, _alloc);
			_size--;
			return(1);
		}

		void	TraverseTreePre() {
			BTree_TraversePreOrder(_root);
		}

		void	TraverseTreeIn() {
			BTree_TraverseInOrder(_root);
		}

//---------------------------Operations----------------------------------------//

		 iterator find (const key_type& k) {

			ft::BTree<value_type>* ptr_to_find = NULL;

			ptr_to_find = BTree_find<value_type>(_root, ft::make_pair(k, 1), value_compare(_compare));

			if (ptr_to_find)
				return (iterator(ptr_to_find));
			return(iterator(this->end()));
		 }

		 iterator upper_bound (const key_type& key)
			{
				ft::BTree<value_type>* upper;

				upper = inorderSuccessor(_root, key);
				// ft::btree<value_type> *node = btree_begin(this->_root);
				// value_type boundary_pair = ft::make_pair(key, mapped_type());

				// while(node != end_node)
				// {
				// 	if (this->value_comp()(boundary_pair, *node->item))
				// 		return iterator(node);
				// 	else
				// 		node = btree_next(node);
				// }
				return (iterator(upper));
			}

//---------------------------Observers----------------------------------------//

		key_compare key_comp() const {
			return (key_compare(key_compare()));
		}

		// value_compare value_comp() const {

		// }

		private:

		typedef typename Alloc::template rebind< ft::BTree<value_type> >::other		node_alloc_type;


		/* Si decido hacer allocation de pair */
		value_type*	_alloc_pair (const value_type& val) {

			value_type *new_pair = _alloc.allocate(1);
			_alloc.construct(new_pair, val);
			return (new_pair);
		}

/****************** 			MEMBER Attributes			******************/
			size_type				_size;
			key_compare				_compare;
			allocator_type			_alloc;
			ft::BTree<value_type>	*_root;
			node_alloc_type			_node_alloc;

	};

} // namespace ft




#endif
