/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:23:15 by lvirgini          #+#    #+#             */
/*   Updated: 2022/01/15 14:28:56 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAIT_HPP
# define TYPE_TRAIT_HPP


namespace ft
{


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
	
	struct		true_type
	{};

	struct		false_type
	{}; 


/*		ARE_SAME : compare for equality of types
**		if template have only one parameters typename (T) it use the second
**		struct are same and get true_type. else get false_type;
**/

	template <typename T, typename U >
	struct are_same
	{
		bool	value = false;
		typedef	false_type	type;
	};


	template<typename T>
	struct are_same<T, T>
	{
		bool	value = true;
		typedef true_type	type;
	};





template <bool B, typename T >
struct	enable_if
{};

template<typename T>
struct enable_if<true, T>
{
	typedef T		type;
};
/*

template <class T, T v>
struct integral_constant
{
	static T value = v;

	typedef T							value_type;
	typedef integral_constant<T, v>		type;
	typedef bool_constant<false>		false_type;
};

typedef integral_constant<bool, B>	bool_constant;*/
//template <>
//typedef bool_constant<true>			true_type;

/*

template <bool B>
struct bool_constant
{
	typedef
}
using	bool_constant = integral_constant<bool, B>;
using	true_type = bool_constant<true>;
using	false_type = bool_constant<false>
*/
/*
template<typename T>
struct false_type
{};

template <typename T>
struct true_type
{};
*/

	
} // end namespace ft

#endif
