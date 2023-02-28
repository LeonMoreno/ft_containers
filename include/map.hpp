#ifndef MAP_HPP
# define MAP_HPP

#include <functional>
#include "utils.hpp"
#include "map_iterator.hpp"
#include "../BTree/include/BTree.hpp"
#include "reverse_vector_iterator.hpp"


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
		typedef Key												key_type;

		/* Each element in a map stores some data as its mapped value.
		 Aliased as member type map::mapped_type.*/
		typedef T												mapped_type;

		// typedef ft::pair<const Key, T>						value_type;
		typedef ft::pair<const key_type, mapped_type>			value_type;
		typedef Compare											key_compare;
		typedef Alloc											allocator_type;

		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;

		typedef typename Alloc::pointer							pointer;
		typedef typename Alloc::const_pointer					const_pointer;

		typedef ft::map_iterator<value_type>					iterator;
		typedef ft::map_iterator<value_type>					const_iterator;

		typedef std::size_t										size_type;
		typedef std::ptrdiff_t									difference_type;

		typedef	ft::reverse_vector_iterator<iterator>			reverse_iterator;
		typedef	ft::reverse_vector_iterator<const_iterator>		const_reverse_iterator;

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
			_size(0), _compare(comp), _alloc(alloc), _root(NULL),  _node_alloc(node_alloc_type()) { }

		//  -- range
		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()):
			_size(0), _compare(comp), _alloc(alloc), _root(NULL),
			_node_alloc(node_alloc_type()) {
				// std::cout << " construct range inssert" << std::endl;
				this->insert(first, last);
			}

		// -- copy constructor
		map (const map& x) : _size(0), _compare(x.key_comp()), _alloc(x.get_allocator()), _root(NULL) {
			// std::cout << " construct copy" << std::endl;

			*this = x;
		}

		~map() {

			this->clear();


		}//std::cout << "Destructor MAP " << std::endl; }

//---------------------------COPY ASSIGNMENT OPERATOR Overload----------------------------------------//
		// Assigns new contents to the container, replacing its current content.
		map& operator= (const map& other)
			{
				// std::cout << " ASSIGNMENT copy" << std::endl;
				this->clear();
				this->insert(other.begin(), other.end());
				return (*this);
			}

//-------------------------------Getters and Setters-----------------------------------------------//

//---------------------------Iterator----------------------------------------//
		iterator begin() {
			return (iterator(BTree_beginInOrder(_root)));
		}

		const_iterator begin() const {
			return (const_iterator(BTree_beginInOrder(_root)));
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

		const_iterator end() const {
			return (const_iterator(BTree_endInOrder(_root)));
		 }

		reverse_iterator rbegin() {
			return reverse_iterator(--this->end());
		}

		reverse_iterator rend(void) {
				return reverse_iterator(--this->begin());
		}

		const_reverse_iterator rbegin(void) const
		{
			return const_reverse_iterator(--this->end());
		}

		const_reverse_iterator rend(void) const
		{
			return const_reverse_iterator(--this->begin());
		}

// }


//---------------------------CAPACITY----------------------------------------//

		size_type size(void) const {
			return (this->_size);
		}

		bool empty() const {
			if (_size == 0)
				return (true);
			return (false);
		}

		size_type max_size() const {
			return (_alloc.max_size());
		}




//---------------------------ELEMENT ACCESS----------------------------------------//

		mapped_type& operator[] (const key_type& key)
		{
			iterator					pair_iterator;
			ft::pair<iterator, bool>	insert_return;

			insert_return = insert(ft::make_pair(key, mapped_type()));
			pair_iterator = insert_return.first;
			// std::cout << "pair first  = " << pair_iterator->second << std::endl;
			return (pair_iterator->second);
		}

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
			it = this->find(val.first);
			this->_size++;
			return (ft::make_pair(it, true));
		}

		// with hint (2)
		iterator insert (iterator position, const value_type& val) {
			iterator it = this->find(val.first);
			(void) position;

			if (it != this->end())
				return(it);
			BTree_InsertNode(&_root, _alloc_pair(val), value_compare(_compare), _node_alloc);
			it = this->find(val.first);
			this->_size++;
			return (it);
		}

		// range
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last) {

			while (first != last) {
				this->insert(*first);
				++first;
			}
		}

		void clear() {
			BTree_PostOrder_free(_root, _node_alloc, _alloc);
			_size = 0;
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

//---------------------------Observers----------------------------------------//

		key_compare key_comp() const {
			return (key_compare(key_compare()));
		}

		// value_compare value_comp() const {

		// }

		void prinBTree() {
			BTree_Print(_root, "", false);
		}

//---------------------------Operations----------------------------------------//

		 iterator find (const key_type& k) {

			ft::BTree<value_type>* ptr_to_find = NULL;

			ptr_to_find = BTree_find<value_type>(_root, ft::make_pair(k, mapped_type()), value_compare(_compare));

			if (ptr_to_find)
				return (iterator(ptr_to_find));
			return(iterator(this->end()));
		 }

		 iterator upper_bound (const key_type& key)
			{
				iterator node;

				node = find(key);

				ft::BTree<value_type>* suce = node.get_node();
				ft::BTree<value_type>* suce2 = node.get_node();

				suce2 = BTree_NodeSuccessor(suce);


				return (iterator(suce2));
			}



//---------------------------Allocator----------------------------------------//

		allocator_type get_allocator() const {
			return (_alloc);
		}



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

	/* *******************************************************************************/
	/* 								Non-member function 							 */
	/* *******************************************************************************/

//---------------------------relational operators (vector (overloads)----------------//

	template <class Key, class T, class Compare, class Alloc>
	bool operator== ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {

		if (lhs.size() != rhs.size())
			return (false);

		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {

		return (!(lhs == rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator< ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {

		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
		return (rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
		return (!(rhs < lhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
		return (!(lhs < rhs));
	}








} // namespace ft




#endif
