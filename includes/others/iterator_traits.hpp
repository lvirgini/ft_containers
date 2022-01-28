/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:34:47 by lvirgini          #+#    #+#             */
/*   Updated: 2022/01/27 10:13:03 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAIT_HPP
# define ITERATOR_TRAIT_HPP


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

template <typename _Iterator>
struct iterator_traits
{
	typedef typename _Iterator::iterator_category iterator_category;
	typedef typename _Iterator::value_type        value_type;
	typedef typename _Iterator::difference_type   difference_type;
	typedef typename _Iterator::pointer           pointer;
	typedef typename _Iterator::reference         reference;
};

/*
** specialisation for pointer T* 
*/

template <typename T>
struct	iterator_traits<T*>
{
	typedef std::random_access_iterator_tag	iterator_category;
	typedef T								value_type;
	typedef ptrdiff_t						difference_type;
	typedef T*								pointer;
	typedef T&								reference;
};

/*
** specialisation for const pointer T* 	
*/

template <typename T>
struct	iterator_traits<const T*>
{
	typedef std::random_access_iterator_tag	iterator_category;
	typedef T							  	value_type;
	typedef ptrdiff_t						difference_type;
	typedef const T*						pointer;
	typedef const T&						reference;
};

} // end namespace ft

 #endif
