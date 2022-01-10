/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:08:40 by lvirgini          #+#    #+#             */
/*   Updated: 2022/01/10 23:13:52 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include <iterator>


template <typename T>
class	vector;
template <typename T>
class	vector_iterator : public std::iterator<std::random_access_iterator_tag, T>
{

	public:
		typedef T				value_type;
		typedef T*				pointer;
		typedef T&				reference;
		typedef std::ptrdiff_t	difference_type;
		typedef std::random_access_iterator_tag	iterator_category;

	private:
		pointer		_ptr;


/* -------------------------------------------------------------------------- */
/*                     Constructor Destructor                                 */
/* -------------------------------------------------------------------------- */
	public:
	vector_iterator(void)
	: _ptr(NULL)
	{}

	vector_iterator(pointer ptr)
	: _ptr(ptr)
	{}

	vector_iterator(const vector_iterator & copy)
	{
		*this = copy;
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

	vector_iterator	&	operator-(difference_type n) const
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

	pointer			base(void)
	{
		return this->_ptr;
	}
};

# endif
