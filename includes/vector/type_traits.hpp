/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:23:15 by lvirgini          #+#    #+#             */
/*   Updated: 2022/01/19 10:56:38 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAIT_HPP
# define TYPE_TRAIT_HPP


namespace ft
{
	/* Remove Const for const_iterator */
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

	/* Struct true_type and false_type */	
	struct		true_type
	{};

	struct		false_type
	{}; 

/*
template<typename T>
struct false_type
{};

template <typename T>
struct true_type
{};
*/

/*
** ENABLE IF:
**		enable typedef type only (condition bool) is true.
*/

	template <bool B, typename T>
	struct enable_if
	{};

	template <typename T>
	struct enable_if<true, T>
	{
		typedef	T	type;
	};



/*		ARE_SAME : compare for equality of types
**		if template have only one parameters typename (T) it use the second
**		struct are same and get true_type. else get false_type;
**/

	template <typename , typename >
	struct are_same
	{
		enum	val
		{
			value = 0
		};
		typedef	false_type	type;
	};


	template<typename T>
	struct are_same<T, T>
	{
		enum val
		{
			value = 1
		};
		typedef true_type	type;
	};
	
} // end namespace ft

#endif
