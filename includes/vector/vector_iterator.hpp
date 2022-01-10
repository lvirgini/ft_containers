/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:08:40 by lvirgini          #+#    #+#             */
/*   Updated: 2022/01/10 18:04:10 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include <iterator>

template <typename T>
class	vector_iterator
{

	public:
		typedef T				value_type;
		typedef T*				pointer;
		typedef T&				reference;
		typedef std::ptrdiff_t	difference_type;
		typedef std::random_access_iterator_tag	iterator_category;

	private:
		pointer		_ptr;

	public:
	vector_iterator(void)
	: _ptr(NULL)
	{}

};

# endif
