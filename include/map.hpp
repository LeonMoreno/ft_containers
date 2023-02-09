#ifndef MAP_HPP
# define MAP_HPP

#include <functional>
#include "utils.hpp"
#include "../BTree/include/BTree.hpp"


namespace ft
{

//--------------------------Template parameters ---------------------------------------//
	template< class Key,
	 		class T,
			class Compare = std::less<Key>,
			// class Alloc = std::allocator< ft::pair<const Key, T> > >
			class Alloc = std::allocator< ft::BTree< ft::pair<const Key, T> > > >
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

		// typedef std::bidirectional_iterator_tag<value_type>		iterator;
		// typedef const std::bidirectional_iterator_tag	<const value_type>	const_iterator;

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

		// default constructor
		explicit map (	const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type()):
			_size(0), _compare(comp), _alloc(alloc), _root(NULL) { }



		~map() {  }//std::cout << "Destructor MAP " << std::endl; }

//---------------------------COPY ASSIGNMENT OPERATOR----------------------------------------//

//-------------------------------Getters and Setters-----------------------------------------------//

//---------------------------Iterator from MAP----------------------------------------//

//---------------------------CAPACITY----------------------------------------//

//---------------------------ELEMENT ACCESS----------------------------------------//

//---------------------------Modifiers----------------------------------------//

		// ft::pair<iterator,bool> insert (const value_type& val) {
		void	insert ( const value_type& val) {

			BTree_InsertNode(&_root, val, value_compare(_compare), _alloc);
		}

		void	TraverseTreePre() {
			BTree_TraversePreOrder(_root);
		}

		void	TraverseTreeIn() {
			BTree_TraverseInOrder(_root);
		}

		private:

		/* Si decido hacer allocation de pair */
		// value_type*	_alloc_pair (const value_type& val) {

		// 	value_type *new_pair = _alloc.allocate(1);
		// 	_alloc.construct(new_pair, val);
		// 	return (new_pair);
		// }

//---------------------------Observers----------------------------------------//

		key_compare key_comp() const {
			return (key_compare(key_compare()));
		}

		value_compare value_comp() const {

		}



/****************** 			MEMBER Attributes			******************/
			size_type				_size;
			key_compare				_compare;
			allocator_type			_alloc;
			ft::BTree<value_type>	*_root;
			// node_allocator_type		_node_alloc;

	};

} // namespace ft




#endif
