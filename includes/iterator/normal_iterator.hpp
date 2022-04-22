/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:08:40 by lvirgini          #+#    #+#             */
/*   Updated: 2022/04/22 13:55:29 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include "iterator_traits.hpp"
# include "type_traits.hpp"
# include <iostream>


namespace ft 
{

// defined for double_inclusion
// template <typename, class>
// class	vector;

template <typename Iterator, typename Container>
class	normal_iterator
{
	private:
		typedef ft::iterator_traits<Iterator>			__trait_type;
		Iterator										_current;
	
	
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

	normal_iterator(void)
	: _current(Iterator())
	{}

	normal_iterator(Iterator ptr)
	: _current(ptr)
	{}

	normal_iterator(const normal_iterator & copy)
	: _current(copy._current)
	{}

/*
**	Check if Iterator and container pointer are same (value == true or false)
**	ft::are_same<Iter, typename Container::pointer>::value)
**
**	enable if (if value ==true):
**	get Containrer
**	if same type between container pointer and Iterator :  (are same value == true)
**	return container

** ex for int : 
** 	typedef normal_iterator<const int *, ft::vector<int>> ft::vector<int>::const_iterator
**	typedef normal_iterator<int *, ft::vector<int>> ft::vector<int>::iterator
*/

	/*template <typename Iter>
	normal_iterator(const normal_iterator <Iter, 
		typename ft::enable_if<
			(ft::are_same<Iter, typename Container::pointer>::value), Container>::type> & i)
	: _current(i.base())
	{}*/
	

/*
**	if const_iter : Iterator != Iter (like int and const int)
*/
	template <typename __Iter>
	normal_iterator(const normal_iterator <__Iter, Container> & i)
	: _current(i.base())
	{}

	// template <typename __Iter>
	// normal_iterator(const normal_iterator <__Iter, typename ft::remove_const<Container>::type> & i)
	// : _current(i.base())
	// {}

	~normal_iterator(void)
	{}

/* -------------------------------------------------------------------------- */
/*                                Operator                                    */
/* -------------------------------------------------------------------------- */

	normal_iterator &	operator=(const normal_iterator & copy)
	{
		if (this != &copy)
			this->_current = copy._current;
		return (*this);
	}
	
	reference			operator*(void) const
	{
		return *_current;
	}

	pointer				operator->(void)
	{
		return _current;
	}

	reference			operator[](difference_type	n)
	{
		return *(this->_current + n);
	}


	normal_iterator &	operator++(void)
	{
		_current++;
		return *this;
	}

	normal_iterator		operator++(int)
	{
		normal_iterator it = *this;
		_current++;
		return (it);
	}

	normal_iterator &	operator--(void)
	{
		_current--;
		return (*this);
	}

	normal_iterator		operator--(int)
	{
		normal_iterator it = *this;
		_current--;
		return (it);
	}	

	normal_iterator		operator+(difference_type n) const
	{
		return (normal_iterator(_current + n));
	}

	normal_iterator		operator-(difference_type n) const
	{
		return (normal_iterator(_current - n));
	}

	normal_iterator	&	operator-=(difference_type n)
	{
		_current -= n;
		return (*this);
	}

	normal_iterator	&	operator+=(difference_type n)
	{
		_current += n;
		return (*this);
	}

	bool				operator==(const normal_iterator & other) const
	{
		return (this->_current == other._current);
	}

	bool				operator!=(const normal_iterator & other) const
	{
		return (this->_current != other._current);
	}

	bool				operator<(const normal_iterator & other) const
	{
		return (this->_current < other._current);
	}

	bool				operator<=(const normal_iterator & other) const
	{
		return (this->_current <= other._current);
	}

	bool				operator>(const normal_iterator & other) const
	{
		return (this->_current > other._current);
	}	

	bool				operator>=(const normal_iterator & other) const
	{
		return (this->_current >= other._current);
	}

	Iterator		base(void) const
	{
		return this->_current;
	}
};

// random access iterator requirements:
// for operator with no instanciation (ex: vector.begin() == vector.end())


	template < typename IteratorL, typename IteratorR, typename Container>
	inline bool		operator==(const normal_iterator<IteratorL, Container> & lhs,
								const normal_iterator<IteratorR, Container> & rhs)
	{
		return lhs.base() == rhs.base();
	}

	template <typename Iterator, typename Container>
	inline bool		operator==(const normal_iterator<Iterator, Container> & lhs,
								const normal_iterator<Iterator, Container> & rhs)
	{
		return lhs.base() == rhs.base();
	}


	template <typename IteratorL, typename IteratorR, typename Container>
	inline bool		operator!= (const normal_iterator<IteratorL, Container> & lhs,
								const normal_iterator<IteratorR, Container> & rhs)
	{
		return lhs.base() != rhs.base();
	}

	template <typename Iterator, typename Container>
	inline bool		operator!= (const normal_iterator<Iterator, Container> & lhs,
								const normal_iterator<Iterator, Container> & rhs)
	{
		return lhs.base() != rhs.base();
	}


	template <typename IteratorL, typename IteratorR, typename Container>
	inline bool		operator< (const normal_iterator<IteratorL, Container> & lhs,
								const normal_iterator<IteratorR, Container> & rhs)
	{
		return lhs.base() < rhs.base();
	}

	template <typename Iterator, typename Container>
	inline bool		operator<(const normal_iterator<Iterator, Container> & lhs,
								const normal_iterator<Iterator, Container> & rhs)
	{
		return lhs.base() < rhs.base();
	}


		template <typename IteratorL, typename IteratorR, typename Container>
	inline bool		operator> (const normal_iterator<IteratorL, Container> & lhs,
								const normal_iterator<IteratorR, Container> & rhs)
	{
		return lhs.base() > rhs.base();
	}

	template <typename Iterator, typename Container>
	inline bool		operator>(const normal_iterator<Iterator, Container> & lhs,
								const normal_iterator<Iterator, Container> & rhs)
	{
		return lhs.base() > rhs.base();
	}


	template <typename IteratorL, typename IteratorR, typename Container>
	inline bool		operator<= (const normal_iterator<IteratorL, Container> & lhs,
								const normal_iterator<IteratorR, Container> & rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template <typename Iterator, typename Container>
	inline bool		operator<=(const normal_iterator<Iterator, Container> & lhs,
								const normal_iterator<Iterator, Container> & rhs)
	{
		return lhs.base() <= rhs.base();
	}


		template <typename IteratorL, typename IteratorR, typename Container>
	inline bool		operator>= (const normal_iterator<IteratorL, Container> & lhs,
								const normal_iterator<IteratorR, Container> & rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template <typename Iterator, typename Container>
	inline bool		operator>=(const normal_iterator<Iterator, Container> & lhs,
								const normal_iterator<Iterator, Container> & rhs)
	{
		return lhs.base() >= rhs.base();
	}


	template <typename IteratorL, typename IteratorR, typename Container>
	inline typename normal_iterator<IteratorL, Container>::difference_type
					operator- (const normal_iterator<IteratorL, Container> & lhs,
								const normal_iterator<IteratorR, Container> & rhs)
	{
		return lhs.base() - rhs.base();
	}

	template <typename Iterator, typename Container>
	inline typename normal_iterator<Iterator, Container>::difference_type
					operator- (const normal_iterator<Iterator, Container> & lhs,
								const normal_iterator<Iterator, Container> & rhs)
	{
		return lhs.base() - rhs.base();
	}

	template <typename Iterator, typename Container>
	inline normal_iterator<Iterator, Container>
					operator+(typename normal_iterator<Iterator, Container>::difference_type n,
							const normal_iterator<Iterator, Container> & i)
	{
		return (normal_iterator<Iterator, Container>(i.base() + n));
	}


} // end of namespace ft

# endif
