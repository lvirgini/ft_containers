/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:41:43 by lvirgini          #+#    #+#             */
/*   Updated: 2022/05/03 12:41:50 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

# include <iterator>

namespace ft {

/*
** standard declaration of iterator
*/

template <typename T,typename Category = std::random_access_iterator_tag, typename Distance = std::ptrdiff_t, typename Pointer = T*, typename Reference = T&>
struct iterator
{
	typedef Category		iterator_category;
	typedef T				value_type;
	typedef Distance		difference_type;
	typedef Pointer			pointer;
	typedef Reference		reference;
};


/*
** Iterator_traits : nested typedef of iterator
** usefull for correct semantics for pointer and const_pointer
*/
template <typename Iterator>
struct iterators_traits
{
	typedef typename Iterator::iterator_category iterator_category;
	typedef typename Iterator::value_type        value_type;
	typedef typename Iterator::difference_type   difference_type;
	typedef typename Iterator::pointer           pointer;
	typedef typename Iterator::reference         reference;
};

/*
** specialisation for pointer T* 
*/

template <typename T>
struct	iterators_traits<T*>
{
	typedef std::random_access_iterator_tag	iterator_category;
	typedef T								value_type;
	typedef std::ptrdiff_t						difference_type;
	typedef T*								pointer;
	typedef T&								reference;
};

/*
** specialisation for const pointer T* 	
*/

template <typename T>
struct	iterators_traits<const T*>
{
	typedef std::random_access_iterator_tag	iterator_category;
	typedef T							  	value_type;
	typedef std::ptrdiff_t						difference_type;
	typedef const T*						pointer;
	typedef const T&						reference;
};

} // end namespace ft

 #endif
