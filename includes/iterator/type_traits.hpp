/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:23:15 by lvirgini          #+#    #+#             */
/*   Updated: 2022/01/24 23:52:40 by lvirgini         ###   ########.fr       */
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
	// struct		true_type
	// {};

	// struct		false_type
	// {}; 

	template <typename T, T v>
	struct integral_constant
	{
		static const T						value = v;
		typedef T						value_type;
		typedef integral_constant<T, v>	type;
	};

	struct true_type : ft::integral_constant<bool, true>
	{};
	

	struct false_type : ft::integral_constant<bool, false>
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
	struct are_same : ft::false_type
	{};
	// 	enum	val
	// ;	{
	// 		value = 0
	// 	};
	// 	typedef	false_type	type
	// };


	template<typename T>
	struct are_same<T, T> : ft::true_type
	{};
	// {
	// 	enum val
	// 	{
	// 		value = 1
	// 	};
	// 	typedef true_type	type;
	// };
	

/*
**	Is something
*/

	// template<typename T, typename = void>
	// struct is_iterator
	// {
	// 	enum val
	// 	{
	// 		value = 0
	// 	};
	// 	typedef false_type		type;
	// };

	// template <typename T> 
	// struct is_iterator<T, typename ft::iterator_traits<T>::value_type>
	// {
	// 	enum val
	// 	{
	// 		value = 1
	// 	};
	// 	typedef true_type		type;
	// };


	//CppCon Metaprogramming: type traits
	template<typename T>
	struct is_void : ft::false_type
	{};

	template<>
	struct is_void<void> : ft::true_type
	{};



	template <typename T>
	struct is_integer : ft::false_type
	{};

	template <>
	struct is_integer<int> : true_type
	{};




	

	

} // end namespace ft

#endif
