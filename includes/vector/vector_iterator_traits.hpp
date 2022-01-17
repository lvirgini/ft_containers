/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator_traits.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:34:47 by lvirgini          #+#    #+#             */
/*   Updated: 2022/01/16 12:54:28 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_TRAIT_HPP
# define VECTOR_ITERATOR_TRAIT_HPP


namespace ft {

	template <typename T>
	struct remove_const
	{
		typedef T type;
	};

	template <typename T>
	struct remove_const<const T>
	{
		typedef T	type;
	};
	
template <typename Category, typename T>
struct iterator
{
	typedef Category						iterator_category;
	typedef T								value_type;
	typedef std::ptrdiff_t					difference_type;
	typedef T*								pointer;
	typedef T&								reference;
};



template <class _Iterator>
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
	//typedef typename remove_const<const T>::type		m_T;
	typedef std::random_access_iterator_tag	iterator_category;
	typedef T							  	value_type;
	typedef ptrdiff_t						difference_type;
	typedef const T*						pointer;
	typedef const T&						reference;
};

} // end namespace ft

 #endif
