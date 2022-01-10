/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 14:52:37 by lvirgini          #+#    #+#             */
/*   Updated: 2022/01/10 20:49:17 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <cstddef>
# include <memory>
# include <stdexcept>
# include <sstream>
# include <iterator>
# include "vector_iterator.hpp"

/*
** ISO : class vector p.508
**		member functions p 483
**		container requirement p.486
*/


/*
** T:		type of the elements 
**			Aliased as member type vector::value_type.
**
** Alloc:	type of the allocator object used to define the storage allocation model.
**			Aliased as member type vector::allocator_type.
*/

namespace	ft
{
	template < typename T, class Allocator = std::allocator<T> >
	class vector
	{
		public:		

			typedef T										value_type;
			typedef Allocator				 				allocator_type;
			typedef size_t									size_type;
			typedef ptrdiff_t								difference_type;

			typedef typename Allocator::pointer				pointer;
			// typedef T * pointer ?
			typedef typename Allocator::const_pointer		const_pointer;
			// typedef const T * pointer ?

		
			// NOPE ? 
			typedef vector_iterator<T>						iterator;
			//typedef	std::iterator<std::bidirectional_iterator_tag, T>				iterator;
		//	typedef std::bidirectional_iterator_tag		iterator;
		//	typedef std::iterator<std::iterator::random_access_iterator_tag<T>, T>		iterator;
		//	typedef typename std::iterator<random_access_iterator_tag, const T>	const_iterator;
		
			// typedef std::iterator<pointer, vector>			iterator;
		//	 typedef std::iterator<T>						iterator;
			// typedef std::iterator<const T>					const_iterator;
			
			// OK
			typedef std::reverse_iterator<iterator>			reverse_iterator;
		//	typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;

			// ISO et A VOIR
			typedef T &										reference;
			//typedef Allocator::reference					reference;			// ISO
			typedef const T &								const_reference;
			//typedef Allocator::const_reference			const_reference; // ISO


		private:
			size_type		_size;		// taille réelle (demandée) du vector
			size_type		_capacity; 	// capacité totale allouée (peut etre + que la size)
			pointer			_first;		// pointeur sur le premier element.
			pointer			_last;		// NOPE ?
			Allocator		_allocator; // type d'allocateur (std::allocator<T>::allocator_type)

	


		public:


/* -------------------------------------------------------------------------- */
/*                     Constructor Destructor                                 */
/* -------------------------------------------------------------------------- */

		// constructor
			explicit vector(const Allocator & alloc = Allocator())
			: _size(0), _capacity(0), _first(NULL), _last(NULL), _allocator(alloc)
			{}

			
			explicit vector(size_type n, const value_type & val = value_type(), const Allocator & alloc = Allocator())
			: _size(n), _capacity(n), _allocator(alloc)
			{
				this->_first = _allocator.allocate(n);
				_allocator.construct(this->_first, val); // for ALL ( VOIR ITERATOR)
		//		this->_last = this->start + n; //
			}
			
/*			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const Allocator & alloc = Allocator())
			: _allocator(alloc)
			{}

			vector(const vector<T, Allocator >& x);
*/
			
		// destructor	
			~vector(void) {};


/* -------------------------------------------------------------------------- */
/*                                Assignation                                 */
/* -------------------------------------------------------------------------- */

// Assign : reallocation complete
/*			
			vector<T, Allocator> &	operator=(const vector<T, Allocator> & x);
		
			template <class InputIterator>
			void 			assign(InputIterator first, InputIterator last);

			void 			assign(size_type n, const T & u);
			allocator_type	get_allocator() const;
*/



/* -------------------------------------------------------------------------- */
/*                                Iterator                                    */
/* -------------------------------------------------------------------------- */

		 iterator				begin(void)
		 {
			 return iterator(this->_first);
		 }
		// const_iterator			begin() const ;

		 iterator				end()
		 {
			 return iterator( this->_first + this->size() );
		 }
		// const iterator			end() const ;

		// reverse_iterator		rbegin();
		// const reverse_iterator	rbegin() const ;

		// reverse_iterator		rend();
		// const reverse_iterator	rend() const ;


/* -------------------------------------------------------------------------- */
/*                                Capacity                                    */
/* -------------------------------------------------------------------------- */

			size_type	size(void) const
			{
				return (this->_size);
			}


			size_type	max_size(void) const
			{
				return (this->_allocator.max_size());
			}

			/**		
			*	Returns the total number of elements that the %vector can
			*	hold before needing to allocate more memory.	*/
			size_type	capacity(void) const
			{
				return (this->_capacity);
			}

			/**
			*	Returns true if the vector is empty.*/
			bool		empty(void) const
			{
				return ( this->begin() == this->end() );
			}


/*
void		resize(size_type sz, T c = T()) ;
void		reserve(size_type	n) ;
*/



/* -------------------------------------------------------------------------- */
/*                                 Element access                             */
/* -------------------------------------------------------------------------- */
		
			/**
			*	This operator allows for easy, array-style, data access.
			*	Note that data access with this operator is unchecked and
			*	out_of_range lookups are not defined. */
			reference		operator[](size_type n)
			{
				return *(this->_first + n);
			}

			const_reference	operator[](size_type n) const
			{
				return *(this->_first + n);
			}


/*
reference		front()
{
	return *begin();
}
const_reference	front() const
{
	return *begin();
}
reference		back()
{
	return *(end() - 1);
}
const_reference	back() const
{
	return *(end() - 1);
}	
*/

			const_reference	at(size_type n) const
			{
				_range_check(n);
				return *(this->_first + n);
			}

			reference		at(size_type n)
			{
				_range_check(n);
				return *(this->_first + n);
			}


/* -------------------------------------------------------------------------- */
/*                                Modifiers                                   */
/* -------------------------------------------------------------------------- */




void		push_back(const T & x)
{
	if (this->_size < this->_capacity)
	{
		this->_allocator.construct(this->_first, this->_first + this->_size, x);
		this->_size++;
	}	
}


/*1void		pop_back(void) ;

iterator	insert(iterator position, const T & x);
void		insert(iterator position, size_type n, const T & x);
template <class InputIterator>
void		insert(iterator position, InputIterator first, InputIterator last);

iterator	erase(iterator position);
iterator	erase (iterator first, iterator last);

void		swap(vector<T, Allocator> &); // ??
void		clear(void);
*/


/* -------------------------------------------------------------------------- */
/*                               Private Functions                            */
/* -------------------------------------------------------------------------- */

		private : 

			/* Check only for at() if out of range : throw exception */
			void	_range_check(size_type n) const
			{
				if (n >= this->size())
				{
					std::ostringstream msg;
					msg << "ft::vector::_range_check: n (which is " << n << ") >= this->size() (which is " << this->size() << ")";

					throw std::out_of_range(msg.str());
				}
			}


	

};	
}


#endif
