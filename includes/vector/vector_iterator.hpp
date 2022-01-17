/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:08:40 by lvirgini          #+#    #+#             */
/*   Updated: 2022/01/17 09:36:40 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include "vector_iterator_traits.hpp"
# include <iostream>
template <typename T>
class	vector;





template <typename Iterator, typename Container>
class	vector_iterator 
{
	private:
		typedef ft::iterator_traits<Iterator>			_trait_type;
	//	typedef typename ft::remove_const<Container>::type				_type;
		Iterator		_ptr;
	
	
	public:
		typedef typename _trait_type::value_type		value_type;
		typedef typename _trait_type::pointer			pointer;
		typedef typename _trait_type::reference			reference;
		typedef typename _trait_type::difference_type	difference_type;
		typedef typename _trait_type::iterator_category	iterator_category;



/*template<class T> struct iterator_traits<T*> {
typedef ptrdiff_t difference_type;
typedef T value_type;
typedef T* pointer;
typedef T& reference;
typedef random_access_iterator_tag iterator_category;
};
and for pointers to const as
template<class T> struct iterator_traits<const T*> {
typedef ptrdiff_t difference_type;
typedef T value_type;
typedef const T* pointer;
typedef const T& reference;
typedef random_access_iterator_tag iterator_category;
};*/


/* -------------------------------------------------------------------------- */
/*                     Constructor Destructor                                 */
/* -------------------------------------------------------------------------- */
	public:

	vector_iterator(void)
	: _ptr(Iterator())
	{}

	vector_iterator(pointer ptr)
	: _ptr(ptr)
	{}

	vector_iterator(const vector_iterator & copy)
	{
		*this = copy;
	}

	/*vector_iterator(const Iterator & i)
	: _ptr(i.base())
	{}
	*/
	/*explicit vector_iterator(vector_iterator & Iter)
	: _ptr(vector_iterator<Iterator, ft::remove_const<vector_iterator>::type)

	{}*/


	/*template <typename pointer, typename  = typename ft::remove_const<pointer>::type>
	vector_iterator(typename ft::remove_const<pointer>::type	ptr)
	: _ptr( ptr)
	{}*/


/*
	template <typename Iter>
	vector_iterator(const vector_iterator <Iter, typename ft::enable_if<ft::are_same(Iter, typename Container::pointer::__value), Container>::type & _i)
	: _ptr(i.base())
	{}*/
	




// Allow iterator to const_iterator conversion
      template<typename _Iter>
    vector_iterator(const vector_iterator<_Iter,
			  typename __gnu_cxx::__enable_if<
      	       (std::__are_same<_Iter, typename Container::pointer>::__value), Container>::__type>& __i) _GLIBCXX_NOEXCEPT
        : _ptr(__i.base()) {
		 }


	~vector_iterator(void)
	{}

/* -------------------------------------------------------------------------- */
/*                                Operator                                    */
/* -------------------------------------------------------------------------- */

	vector_iterator &	operator=(const vector_iterator & copy)
	{
		if (this != &copy)
			this->_ptr = copy._ptr;
		return (*this);
	}
	
	reference			operator*(void) const
	{
		return *_ptr;
	}

	pointer				operator->(void)
	{
		return _ptr;
	}

	reference			operator[](difference_type	n)
	{
		return *(this->_ptr + n);
	}


	vector_iterator &	operator++(void)
	{
		_ptr++;
		return *this;
	}

	vector_iterator		operator++(int)
	{
		vector_iterator it = *this;
		_ptr++;
		return (it);
	}

	vector_iterator &	operator--(void)
	{
		_ptr--;
		return (*this);
	}

	vector_iterator		operator--(int)
	{
		vector_iterator it = *this;
		_ptr--;
		return (it);
	}	

	vector_iterator		operator+(difference_type n) const
	{
		return (vector_iterator(_ptr + n));
	}

	vector_iterator		operator-(difference_type n) const
	{
		return (vector_iterator(_ptr - n));
	}

	vector_iterator	&	operator-=(difference_type n)
	{
		_ptr -= n;
		return (*this);
	}

	vector_iterator	&	operator+=(difference_type n)
	{
		_ptr += n;
		return (*this);
	}

	bool				operator==(const vector_iterator & other)
	{
		return (this->_ptr == other._ptr);
	}

	bool				operator!=(const vector_iterator & other)
	{
		return (this->_ptr != other._ptr);
	}

	bool				operator<(const vector_iterator & other)
	{
		return (this->_ptr < other._ptr);
	}

	bool				operator<=(const vector_iterator & other)
	{
		return (this->_ptr <= other._ptr);
	}

	bool				operator>(const vector_iterator & other)
	{
		return (this->_ptr > other._ptr);
	}	

	bool				operator>=(const vector_iterator & other)
	{
		return (this->_ptr >= other._ptr);
	}

	Iterator		base(void) const
	{
		return this->_ptr;
	}
};

# endif
