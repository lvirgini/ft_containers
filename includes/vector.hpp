/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 14:52:37 by lvirgini          #+#    #+#             */
/*   Updated: 2022/05/03 12:46:19 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <cstddef>
# include <memory>
# include <stdexcept>
# include <sstream>

# include "normal_iterator.hpp"
# include "reverse_iterator.hpp"
# include "usefull.hpp"

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
/* -------------------------------------------------------------------------- */
	public:		

		typedef T										value_type;
		typedef Allocator				 				allocator_type;
		typedef size_t									size_type;
		typedef ptrdiff_t								difference_type;

		typedef T*										pointer;
		typedef const T*								const_pointer;
		typedef T &										reference;
		typedef const T &								const_reference;

		typedef ft::normal_iterator<pointer, vector>		iterator;
		typedef ft::normal_iterator<const_pointer, vector>	const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

	private:
		size_type		_size;		// taille réelle (demandée) du vector
		size_type		_capacity; 	// capacité totale allouée (peut etre + que la size)
		pointer			_first;		// pointeur sur le premier element.
		pointer			_last;		// NOPE ?
		Allocator		_allocator; // type d'allocateur (std::allocator<T>::allocator_type)
		
/* -------------------------------------------------------------------------- */

	public:

/* -------------------------------------------------------------------------- */
/*                     Constructor Destructor                                 */
/* -------------------------------------------------------------------------- */

	/*
	** empty container constructor (default constructor)
	**		construct an empty container with no elements.
	*/

		explicit vector(const Allocator & alloc = Allocator())
		: _size(0), _capacity(0), _first(NULL), _last(NULL), _allocator(alloc)
		{}

	/*
	**	fill constructor
	**		construct a container with n elements.
	**		Each element is copy of (val).
	*/

		explicit vector(size_type n, const value_type & val = value_type(), const Allocator & alloc = Allocator())
		: _size(n), _capacity(n), _allocator(alloc)
		{
			this->_first = _m_allocate(n);
			_m_fill(this->_first, n, val);
		}

	/*
	**	copy constructor
	**		constructs a container with a copy of each of the elements in (copy)
	**		in the same order.
	*/

		vector(const vector & copy)
		: _size(0), _capacity(0), _first(pointer()), _allocator(Allocator()) 
		{
			this->insert(this->begin(), copy.begin(), copy.end());
		}

	/*
	** range constructor
	**		constructs a container with as many element as the range [first - last]
	**		with each element constructed from its corresponding element in that range
	**		in the same order.
	*/

		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const Allocator & alloc = Allocator(), 
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = NULL)
		: _size(0), _capacity(0), _first(pointer()), _allocator(alloc)
		{
			this->insert(this->begin(), first, last);
		}

	/*
	** destructor
	**		destroys all container elements and deallocates all the storage capacity allocated.
	*/
		~vector(void)
		{
			this->clear();
			this->_allocator.deallocate(this->_first, this->capacity());
		};

/* -------------------------------------------------------------------------- */
/*                                Assignation                                 */
/* -------------------------------------------------------------------------- */

	/*
	**	operator=
	**		assigns new contents to the conaitner, replacing its current contents and size.
	**		the allocator is not modified.
	*/

		vector	&	operator=( const vector & copy)
		{
			if (this != &copy)
			{
				this->assign(copy.begin(), copy.end());
			}
			return (*this);
		}


	/* Assign() : 
	** any elements held in the container before the call are destroyed and replaced by newly constructed elements */

	/*
	**	Assigns (range version)
	**		the new contents are elements constructed from each of the elements
	**		in the range [first - last] in the same order.
	**	replacing its current contents and modifying its size accordingly.
	*/

		template <class InputIterator>
		void 			assign(InputIterator first, InputIterator last, 
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = NULL)
		{
			_check_new_size(std::distance(first, last));
			this->clear();
			this->insert(this->begin(), first, last);
		}

	/*
	**	Assign (fill version)
	**		the new contents are (n) elements, each initialized to a copy of (val)
	*/

		void 			assign(size_type n, const value_type & val)
		{
			_check_new_size(n);
			this->clear();
			this->insert(this->begin(), n, val);
		}

	/*
	**	get_allocator()
	**		returns a copy of the allocator associated with the vector.
	*/

		allocator_type	get_allocator(void) const
		{
			return (this->_allocator);
		}

/* -------------------------------------------------------------------------- */
/*                                Iterator                                    */
/* -------------------------------------------------------------------------- */

	/*
	** begin()
	**		return an iterator pointing to the first element in the vector.
	*/

		iterator				begin(void)
		{
			return iterator(this->_first);
		}
		
		const_iterator			begin(void) const
		{
			return const_iterator(this->_first);
		}

	/*
	**	rbegin()
	**		return reverse iterator pointing to the last element in the vector.
	**		for iterate backwards
	*/

		reverse_iterator		rbegin(void)
		{
			return reverse_iterator(this->_first + this->_size);
		}

		const_reverse_iterator	rbegin() const
		{
			return const_reverse_iterator(this->_first + this->_size);
		}
	
	/*
	**	end()
	**		Return an iterator reffering to the past-the_end element in the vector.
	**		past-the-end is last element + 1 theorical element.
	**		that means it shall not be be dereferenced.
	*/

		iterator				end(void)
		{
			return iterator( this->_first + this->size() );
		}
		
		const_iterator			end(void) const
		{
			return const_iterator(this->_first + this->size() );
		}

	/*
	**	rend()
	**		Return reverse iterator pointing to the theorical element preceding the first element.
	**		it's considered its reverse end
	*/

		reverse_iterator		rend(void)
		{
			return reverse_iterator(this->_first);
		}
	
		const_reverse_iterator	rend(void) const
		{
			return const_reverse_iterator(this->_first);
		}

/* -------------------------------------------------------------------------- */
/*                                Capacity                                    */
/* -------------------------------------------------------------------------- */

	/*
	**	size()
	**		Return current size : the number of elements in the vector.
	*/

		size_type	size(void) const
		{
			return (this->_size);
		}

	/*
	**	max_size()
	**		Returns the maximum number of elements that the vector can hold.
	*/

		size_type	max_size(void) const
		{
			return (this->_allocator.max_size());
		}

	/*
	**	capacity()
	**		Returns the size of the current allocated storage capacity.
	**		corresponding to total number of elements that the vector can
	**		hold before needing to allocate more memory.
	*/

		size_type	capacity(void) const
		{
			return (this->_capacity);
		}

	/*
	**	empty()
	**		Returns true if the vector is empty. (size == 0)
	*/

		bool		empty(void) const
		{
			return ( this->_size == 0 );
		}

	/*
	**	resize()
	**		Resizes the container so that it contains n elements.
	**		if (new_size == size) do nothing;
	**		if (new_size < size) : erase all after new_size;
	**		if (new_size > size) : insert from this->end() : (val) until new_size();
	*/

		void		resize(size_type new_size, value_type val = value_type()) 
		{
			if (new_size > this->size())
				this->insert(this->end(), new_size - this->size(), val);
			else if (new_size < this->size())
				this->erase(this->_first + new_size, this->end());
		}

	/*
	**	reserve()
	**		Request a change in capacity
	**		only if capacity < n : reallocate the storage and increase capacity to n
	*/

		void		reserve(size_type	n)
		{
			pointer		new_ptr;

			if (_check_new_size(n))
				return ;
			new_ptr = _m_allocate(n);
			for (size_type i = 0; i < this->size(); i++)
			{
				this->_allocator.construct(new_ptr + i, this->_first[i]);
				this->_allocator.destroy(this->_first + i);
			}
			this->_allocator.deallocate(this->_first, this->size());
			this->_first = new_ptr;
			this->_capacity = n;
		}	

/* -------------------------------------------------------------------------- */
/*                                 Element access                             */
/* -------------------------------------------------------------------------- */
	
	/*
	**	operator[]
	*		Returns a reference to the element at position (n) in the vector.
	*		This operator allows for easy, array-style, data access.
	*		Note that data access with this operator is unchecked and
	*		out_of_range lookups are not defined.
	*/

		reference		operator[](size_type n)
		{
			return *(this->_first + n);
		}

		const_reference	operator[](size_type n) const
		{
			return *(this->_first + n);
		}

	/*
	**	front()
	*		Returns a reference to the first element in the vector
	*/
		reference		front()
		{
			return *this->_first;
		}

		const_reference	front() const
		{
			return *this->_first;
		}

	/*
	**	back()
	*		returns a reference to the last element in the vector.
	*/

		reference		back()
		{
			return *(end() - 1);
		}

		const_reference	back() const
		{
			return *(end() - 1);
		}

	/*
	** at()
	*		Return a reference to the element at position (n) in the vector.
	*		a range checks throw a exception if (n) is out of range.
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

	/*
	**	push_back()
	**		add a new element at the end of the vector.
	*/

		void		push_back(const value_type & val)
		{
			this->insert(this->end(), val);
		}

	/*
	**	pop_back()
	**		destroys the last element in the vector.
	**		normaly not protected in stl
	*/

		void		pop_back(void)
		{
			if (this->_size > 0)
			{
				this->_allocator.destroy(this->_first + this->_size - 1);
				this->_size--;
			}
		}

	/*
	**	Insert()
	**		the vecotr is extended by inserting new elements before the element at the (position).
	**		increase the container size by the number of elements inserted.
	**		this causes an automatic reallocation of the allocated storage (capacity)
	**		if and only if the new vector size > current vector capacity.
	**		
	**		-	check capacity and grow her if needed
	**		-	move all after pos to the end
	** 		-	insert at pos
	*/

		iterator	insert(iterator position, const value_type & val)
		{
			difference_type	pos_index = std::distance(this->begin(), position);
			
			this->insert(position, 1, val);
			return (this->begin() + pos_index);
		}
		
		void		insert(iterator position, size_type n, const value_type & val)
		{
			difference_type pos_index = std::distance(this->begin(), position);
			size_type		old_size = this->_size;
			bool			is_in_the_end = position == this->end();
			
			if (n == 0)
				return ;
			_check_capacity_for_insert(this->_size + n);
			position = this->begin() + pos_index;
			if (old_size > 0 && is_in_the_end == false)
				_move_elements_to_the_end(this->_first + this->_size - 1, n, this->_first + pos_index);
			_m_fill(this->begin() + pos_index, n, val);
		}

		template<class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last, 
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = NULL)
		{
			difference_type pos_index = std::distance(this->begin(), position);
			difference_type size_insert = std::distance(first, last);
			size_type		old_size = this->_size;
			bool			is_in_the_end = position == this->end();

			if (first == last)
				return ;
			_check_capacity_for_insert(size_insert + this->_size);
			position = this->begin() + pos_index;
			if (old_size > 0 && is_in_the_end == false)
				_move_elements_to_the_end(this->_first + this->_size - 1, size_insert, this->_first + pos_index + 1);
			 for(;first != last; first++, position++)
			 	this->_allocator.construct(position.base(), *first);
		}

	/*
	**	erase()
	**		removes from the vector either a single position or a range of elements [first - last]
	**		the size is reduces by the number of elements removed, wich are destroyed.
	**		move all elements after to keep a valid array.
	**
	**		this->-first	...		(first)  ... (last) 	(last) + 1 .... end
	**
	**		destroy all element inside [first - last] 
	**		move last + 1 to first;
	*/

		iterator	erase(iterator first, iterator last)
		{
			iterator 	position = first;
			size_type	size_erased = 0;
	
			if (first != last)
			{
				for (;first != last; size_erased++, first++)
					this->_allocator.destroy(first.base());
				first = position;
				for (iterator end = this->end(); last != end; last++, first++)
				{
					this->_allocator.construct(first.base(), *last);
					this->_allocator.destroy(last.base());
				}
				this->_size -= size_erased;
			}
			return (position);
		}

		iterator	erase(iterator position)
		{
			if (position + 1 != this->end())
				return (this->erase(position, position + 1));
			this->_allocator.destroy(position.base());
			this->_size--;
			return this->end();
		}

	/*
	**	swap()
	**		exchanges the content of the container by the content of x 
	**		which is another vector object of the same type. 
	*/

		void		swap(vector & x)
		{
			pointer tmp_first = this->_first;
			pointer tmp_last = this->_last;
			allocator_type tmp_allocator = this->_allocator;
			size_type tmp_size = this->_size;
			size_type tmp_capacity = this->_capacity;

			_first = x._first;
			_last = x._last;
			_allocator = x._allocator;
			_size = x._size;
			_capacity = x._capacity;

			x._first = tmp_first;
			x._last = tmp_last;
			x._allocator = tmp_allocator;
			x._size = tmp_size;
			x._capacity = tmp_capacity;
		}

	/*
	**	clear()
	**		removes all elements wich are destroyed, leaving the container empty.
	*/

		void		clear(void)
		{
			if (this->size() > 0)
			{
				for (size_type	i = 0; i < this->size(); i++)
					this->_allocator.destroy(this->_first + i);
				this->_size = 0;
			}
		}

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

	
		bool	_check_new_size(size_type new_size) const
		{
			if (new_size > this->max_size())
			{
				std::ostringstream msg;
				msg << "ft::vector::check_size: n (which is " << new_size << ") > std::allocator.max_size() (which is " << this->_allocator.max_size() << ")";
				throw std::length_error(msg.str());
			}
			if (new_size <= this->capacity())
				return true;
			return false;
		}

		size_type	_get_len(size_type n, const char * msg) const
		{
			size_type	len;

			if (this->max_size() - this->size() < n)
				throw std::length_error(msg);
			len = this->size() + std::max(this->size(), n);
			if (len > this->max_size())
				return (this->max_size());
			return (len);
		}

		void		_m_fill(iterator first, size_type n, const value_type & val)
		{
			for (size_type i = 0; i < n; i++, first++)
				this->_allocator.construct(first.base(), val);
		}

		pointer		_m_allocate(size_type n)
		{
			if (n != 0)
				return (this->_allocator.allocate(n));
			return (pointer());
		}

		void		_check_capacity_for_insert(size_type new_size)
		{
			if ( new_size > this->capacity())
				this->reserve(_get_len(new_size - this->size(), "_check_capacity_for_insert"));				// maybe can be more optimize without copiing all decaled value. good innegliche
			this->_size = new_size;
		}

		void	_move_elements_to_the_end(pointer end, size_type size_insert, pointer position)
		{
			if (size_insert == this->_size)
				return ;
			for (size_type i = 0; (end - i) > position; i++)
			{
				this->_allocator.construct(end - i, *(end - i - size_insert));
				this->_allocator.destroy(end - i - size_insert);
			}
		}
};

/*
**	Comparaison : 
*/

template <class T, class Allocator>
inline bool operator==(const ft::vector<T,Allocator>& x, const ft::vector<T,Allocator>& y)
{
	return (x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin()));
}

template <class T, class Allocator>
inline bool operator!=(const ft::vector<T,Allocator>& x, const ft::vector<T,Allocator>& y)
{
	return !(x == y);
}

template <class T, class Allocator>
inline bool operator< (const ft::vector<T,Allocator>& x, const ft::vector<T,Allocator>& y)
{
	return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
}

template <class T, class Allocator>
inline bool operator> (const ft::vector<T,Allocator>& x,const ft::vector<T,Allocator>& y)
{
	return y < x;
}

template <class T, class Allocator>
inline bool operator>=(const ft::vector<T,Allocator>& x,const ft::vector<T,Allocator>& y)
{
	return !(x < y);
}

template <class T, class Allocator>
bool operator<=(const ft::vector<T,Allocator>& x,const ft::vector<T,Allocator>& y)
{
	return !(y < x);
}

// specialized algorithms:
template <class T, class Allocator>
inline void swap(vector<T,Allocator>& x, vector<T,Allocator>& y)
{
	x.swap(y);
}

} // end of namespace ft

#endif
