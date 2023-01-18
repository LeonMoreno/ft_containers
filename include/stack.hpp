#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace ft {

	/**
	 * @brief A standard container giving FILO behavior.
	 *
	 * @tparam T  Type of element.
	 * @tparam Container  Type of underlying sequence, defaults to deque<T>.
	 *
	 * This is not a true container, but an @e adaptor.  It holds
	 * another container, and provides a wrapper interface to that
	 * container.  The wrapper is what enforces strict
	 * first-in-last-out %stack behavior. -- FILO
	 */

//-------------------------- Template parameters ---------------------------------------//
	template<typename T, typename Container = ft::vector<T> >
	class stack {

		public:
//--------------------------Member types ---------------------------------------//

			typedef Container									container_type;
			typedef typename Container::value_type				value_type;
			typedef typename Container::size_type				size_type;
			typedef typename Container::reference				reference;
			typedef typename Container::const_reference			const_reference;

//--------------------------- constructor & Destructor ---------------------------------------//-

			// default - 	(since C++11)

			// until C++11
			/**
			 * @brief Construct a new stack object
			 * Copy-constructs the underlying container with the contents of cont.
			 * This is also the default constructor. (until C++11)
			 * @param ctnr -- Container
			 */
			explicit stack (const container_type& ctnr = container_type()) : c(ctnr) { }

			stack( const stack& other ) : c(other.c) { }

			~stack(void) { }

			stack& operator=( const stack& rhs ) {

				c = rhs.c;
				return (*this);
			}


//--------------------------- Member functions ---------------------------------------//-

			// true if the underlying container's size is 0, false otherwise.
			bool empty() const { return (c.empty); }

			// The number of elements in the underlying container.
			size_type size() const { return (c.size() ); }

			// Since stacks are last-in first-out containers,
			// the top element is the last element inserted into the stack.
			reference top() { return (c.back()); }

			const_reference top() const { return (c.back()); }

			// Inserts a new element at the top of the stack,
			// above its current top element.
			void push (const value_type& val) {
				c.push_back(val);
			}

			// Removes the element on top of the stack,
			// effectively reducing its size by one.
			void pop() {
				c.pop_back();
			}

			// template< class _T, class _Container >
			// friend bool operator==( const ft::stack<_T,_Container>& lhs, const ft::stack<_T,_Container>& rhs );

		protected:
				container_type	c;
	};

	template < class T, class Container >
	bool operator==(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) {

		return (lhs.c == rhs.c);
	}


} // end ft


#endif
