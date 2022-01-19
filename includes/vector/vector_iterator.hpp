/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:08:40 by lvirgini          #+#    #+#             */
/*   Updated: 2022/01/19 11:02:42 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include "vector_iterator_traits.hpp"
# include "type_traits.hpp"
# include <iostream>


namespace ft 
{

// defined for double_inclusion
template <typename, class>
class	vector;

template <typename Iterator, typename Container>
class	vector_iterator 
{
	private:
		typedef ft::iterator_traits<Iterator>			__trait_type;
		Iterator										_ptr;
	
	
	public:
		typedef typename __trait_type::value_type			value_type;
		typedef typename __trait_type::pointer				pointer;
		typedef typename __trait_type::reference			reference;
		typedef typename __trait_type::difference_type		difference_type;
		typedef typename __trait_type::iterator_category	iterator_category;


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

/*
**	Check if Iterator and container pointer are same (value == true or false)
**	ft::are_same<Iter, typename Container::pointer>::value)
**
**	enable if (if value ==true):
**	get Containrer
**	if same type between container pointer and Iterator :  (are same value == true)
**	return container

** ex for int : 
** 	typedef vector_iterator<const int *, ft::vector<int>> ft::vector<int>::const_iterator
**	typedef vector_iterator<int *, ft::vector<int>> ft::vector<int>::iterator
*/

	/*template <typename Iter>
	vector_iterator(const vector_iterator <Iter, 
		typename ft::enable_if<
			(ft::are_same<Iter, typename Container::pointer>::value), Container>::type> & i)
	: _ptr(i.base())
	{}*/
	

/*
**	if const_iter : Iterator != Iter (like int and const int)
*/
	template <typename __Iter>
	vector_iterator(const vector_iterator <__Iter,typename ft::remove_const<Container>::type> & i)
	: _ptr(i.base())
	{}

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

	bool				operator==(const vector_iterator & other) const
	{
		return (this->_ptr == other._ptr);
	}

	bool				operator!=(const vector_iterator & other) const
	{
		return (this->_ptr != other._ptr);
	}

	bool				operator<(const vector_iterator & other) const
	{
		return (this->_ptr < other._ptr);
	}

	bool				operator<=(const vector_iterator & other) const
	{
		return (this->_ptr <= other._ptr);
	}

	bool				operator>(const vector_iterator & other) const
	{
		return (this->_ptr > other._ptr);
	}	

	bool				operator>=(const vector_iterator & other) const
	{
		return (this->_ptr >= other._ptr);
	}

	Iterator		base(void) const
	{
		return this->_ptr;
	}
};

// random access iterator requirements:
// for operator with no instanciation (ex: vector.begin() == vector.end())


	template < typename IteratorL, typename IteratorR, typename Container>
	inline bool		operator==(const vector_iterator<IteratorL, Container> & lhs,
								const vector_iterator<IteratorR, Container> & rhs)
	{
		return lhs.base() == rhs.base();
	}

	template <typename Iterator, typename Container>
	inline bool		operator==(const vector_iterator<Iterator, Container> & lhs,
								const vector_iterator<Iterator, Container> & rhs)
	{
		return lhs.base() == rhs.base();
	}


	template <typename IteratorL, typename IteratorR, typename Container>
	inline bool		operator!= (const vector_iterator<IteratorL, Container> & lhs,
								const vector_iterator<IteratorR, Container> & rhs)
	{
		return lhs.base() != rhs.base();
	}

	template <typename Iterator, typename Container>
	inline bool		operator!= (const vector_iterator<Iterator, Container> & lhs,
								const vector_iterator<Iterator, Container> & rhs)
	{
		return lhs.base() != rhs.base();
	}


	template <typename IteratorL, typename IteratorR, typename Container>
	inline bool		operator< (const vector_iterator<IteratorL, Container> & lhs,
								const vector_iterator<IteratorR, Container> & rhs)
	{
		return lhs.base() < rhs.base();
	}

	template <typename Iterator, typename Container>
	inline bool		operator<(const vector_iterator<Iterator, Container> & lhs,
								const vector_iterator<Iterator, Container> & rhs)
	{
		return lhs.base() < rhs.base();
	}


		template <typename IteratorL, typename IteratorR, typename Container>
	inline bool		operator> (const vector_iterator<IteratorL, Container> & lhs,
								const vector_iterator<IteratorR, Container> & rhs)
	{
		return lhs.base() > rhs.base();
	}

	template <typename Iterator, typename Container>
	inline bool		operator>(const vector_iterator<Iterator, Container> & lhs,
								const vector_iterator<Iterator, Container> & rhs)
	{
		return lhs.base() > rhs.base();
	}


	template <typename IteratorL, typename IteratorR, typename Container>
	inline bool		operator<= (const vector_iterator<IteratorL, Container> & lhs,
								const vector_iterator<IteratorR, Container> & rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template <typename Iterator, typename Container>
	inline bool		operator<=(const vector_iterator<Iterator, Container> & lhs,
								const vector_iterator<Iterator, Container> & rhs)
	{
		return lhs.base() <= rhs.base();
	}


		template <typename IteratorL, typename IteratorR, typename Container>
	inline bool		operator>= (const vector_iterator<IteratorL, Container> & lhs,
								const vector_iterator<IteratorR, Container> & rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template <typename Iterator, typename Container>
	inline bool		operator>=(const vector_iterator<Iterator, Container> & lhs,
								const vector_iterator<Iterator, Container> & rhs)
	{
		return lhs.base() >= rhs.base();
	}


	template <typename IteratorL, typename IteratorR, typename Container>
	inline typename vector_iterator<IteratorL, Container>::difference_type
					operator- (const vector_iterator<IteratorL, Container> & lhs,
								const vector_iterator<IteratorR, Container> & rhs)
	{
		return lhs.base() - rhs.base();
	}

	template <typename Iterator, typename Container>
	inline typename vector_iterator<Iterator, Container>::difference_type
					operator- (const vector_iterator<Iterator, Container> & lhs,
								const vector_iterator<Iterator, Container> & rhs)
	{
		return lhs.base() - rhs.base();
	}

	template <typename Iterator, typename Container>
	inline vector_iterator<Iterator, Container>
					operator+(typename vector_iterator<Iterator, Container>::difference_type n,
							const vector_iterator<Iterator, Container> & i)
	{
		return (vector_iterator<Iterator, Container>(i.base() + n));
	}


} // end of namespace ft
# endif
