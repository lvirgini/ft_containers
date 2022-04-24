/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:17:18 by lvirgini          #+#    #+#             */
/*   Updated: 2022/04/24 12:11:48 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "normal_iterator.hpp"

namespace ft {


template < typename Iterator>
class reverse_iterator
	: public ft::iterator < 
		typename ft::iterator_traits<Iterator>::iterator_category,
		typename ft::iterator_traits<Iterator>::value_type,
		typename ft::iterator_traits<Iterator>::difference_type,
		typename ft::iterator_traits<Iterator>::pointer,
		typename ft::iterator_traits<Iterator>::reference >
{

	private:
		typedef ft::iterator_traits<Iterator>				_traits_type;
		Iterator	_current;

	public:
		typedef Iterator									iterator_type;
		typedef typename _traits_type::value_type			value_type;
		typedef typename _traits_type::pointer				pointer;
		typedef typename _traits_type::reference			reference;
		typedef typename _traits_type::difference_type		difference_type;
		typedef typename _traits_type::iterator_category	iterator_category;

/* -------------------------------------------------------------------------- */
/*                     Constructor Destructor                                 */
/* -------------------------------------------------------------------------- */

	reverse_iterator(void)
	: _current()
	{}

	explicit	reverse_iterator(iterator_type x)
	: _current(x)
	{}


	reverse_iterator(const reverse_iterator & copy)
	:_current(copy._current)
	{}

	template <typename _Iter>
	reverse_iterator(const reverse_iterator <_Iter> & x)
	: _current(x.base())
	{}

	~reverse_iterator(void)
	{}

	iterator_type	base(void) const
	{
		return this->_current;
	}

/* -------------------------------------------------------------------------- */
/*                                Operator                                    */
/* -------------------------------------------------------------------------- */

	reference			operator*() const
	{
		Iterator	ref = _current;
		return *(--ref);
	}


	pointer operator->() const
	{
		return &(operator*());
	}

	reference			operator[](difference_type	n) const
	{
		return *(this->_current - n - 1);
	}

	reverse_iterator &	operator++(void)
	{
		--_current;
		return *this;
	}

	reverse_iterator		operator++(int)
	{
		reverse_iterator it = *this;
		--_current;
		return (it);
	}

	reverse_iterator &	operator--(void)
	{
		++_current;
		return *this;
	}

	reverse_iterator		operator--(int)
	{
		reverse_iterator it = *this;
		++_current;
		return (it);
	}	

	reverse_iterator		operator+(difference_type n) const
	{
		return (reverse_iterator(_current - n));
	}

	reverse_iterator		operator-(difference_type n) const
	{
		return (reverse_iterator(_current + n));
	}

	reverse_iterator	&	operator-=(difference_type n)
	{
		_current += n;
		return (*this);
	}

	reverse_iterator	&	operator+=(difference_type n)
	{
		_current -= n;
		return (*this);
	}

};

	template <typename Iterator>
	inline reverse_iterator<Iterator>
					operator+(typename reverse_iterator<Iterator>::difference_type n,
							const reverse_iterator<Iterator> & i)
	{
		return (reverse_iterator<Iterator>(i.base() - n));
	}


	template<typename Iterator>
	bool	operator==(const reverse_iterator<Iterator>& lhs,
						const reverse_iterator<Iterator>& rhs)
    {
		return lhs.base() == rhs.base();
	}

  template<typename Iterator>
	bool	operator<(const reverse_iterator<Iterator>& lhs, 
						const reverse_iterator<Iterator>& rhs)
    { 
		return rhs.base() < lhs.base(); 
	}

  template<typename Iterator>
	bool	operator!=(const reverse_iterator<Iterator>& lhs,
						const reverse_iterator<Iterator>& rhs)
    { 
		return !(lhs == rhs);
	}

  template<typename Iterator>
	bool	operator>(const reverse_iterator<Iterator>& lhs,
						const reverse_iterator<Iterator>& rhs)
    { 
		return rhs < lhs;
	}

  template<typename Iterator>
	bool	operator<=(const reverse_iterator<Iterator>& lhs,
						const reverse_iterator<Iterator>& rhs)
    { 
		return !(rhs < lhs); 
	}

  template<typename Iterator>
	bool	operator>=(const reverse_iterator<Iterator>& lhs,
						const reverse_iterator<Iterator>& rhs)
    { 
		return !(lhs < rhs); 
	}


/*
**	Comparison of reverse_iterator to const reverse_iterator.
*/

  template<typename _IteratorL, typename _IteratorR>
	bool			operator==(const reverse_iterator<_IteratorL>& lhs,
	       const reverse_iterator<_IteratorR>& rhs)
    {
		return lhs.base() == rhs.base();
	}

  template<typename _IteratorL, typename _IteratorR>
	bool			operator<(const reverse_iterator<_IteratorL>& lhs,
	      const reverse_iterator<_IteratorR>& rhs)
    {
		return rhs.base() < lhs.base();
	}

  template<typename _IteratorL, typename _IteratorR>
	bool			operator!=(const reverse_iterator<_IteratorL>& lhs,
	       const reverse_iterator<_IteratorR>& rhs)
    { 
		return !(lhs == rhs);
	}

  template<typename _IteratorL, typename _IteratorR>
	bool			operator>(const reverse_iterator<_IteratorL>& lhs,
	      const reverse_iterator<_IteratorR>& rhs)
    {
		return rhs < lhs;
	}

  template<typename _IteratorL, typename _IteratorR>
	bool			operator<=(const reverse_iterator<_IteratorL>& lhs,
	       const reverse_iterator<_IteratorR>& rhs)
    {
		return !(rhs < lhs);
	}

  template<typename _IteratorL, typename _IteratorR>
	bool			operator>=(const reverse_iterator<_IteratorL>& lhs,
	       const reverse_iterator<_IteratorR>& rhs)
    {
		return !(lhs < rhs);
	}

  template<typename Iterator>
    inline typename reverse_iterator<Iterator>::difference_type
	operator-(const reverse_iterator<Iterator>& lhs,
	      const reverse_iterator<Iterator>& rhs)
    {
		return rhs.base() - lhs.base();
	}

  template<typename _IteratorL, typename _IteratorR>
    inline typename reverse_iterator<_IteratorL>::difference_type
    operator-(const reverse_iterator<_IteratorL>& lhs,
	      const reverse_iterator<_IteratorR>& rhs)
    {
		return rhs.base() - lhs.base();
	}


} // end namespace ft

#endif

