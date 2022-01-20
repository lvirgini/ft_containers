/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:34:47 by lvirgini          #+#    #+#             */
/*   Updated: 2022/01/19 11:04:42 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAIT_HPP
# define ITERATOR_TRAIT_HPP


namespace ft {

/*
** define empy struct for iterator_tags :
** only used to distinguish different iterator category
*/

struct input_iterator_tag
{};

struct output_iterator_tag
{};

struct forward_iterator_tag : public input_iterator_tag
{};

struct bidirectional_iterator_tag : public forward_iterator_tag
{};

struct random_access_iterator_tag : public bidirectional_iterator_tag
{};


/*
** standard declaration of iterator
*/

template <typename Category, typename T> // no need more ?
struct iterator
{
	typedef Category						iterator_category;
	typedef T								value_type;
	typedef std::ptrdiff_t					difference_type;
	typedef T*								pointer;
	typedef T&								reference;
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
