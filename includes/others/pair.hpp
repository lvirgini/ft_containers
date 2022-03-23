/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 21:47:59 by lvirgini          #+#    #+#             */
/*   Updated: 2022/03/22 09:48:38 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

/*
** Pair class
**		this class couples together a pair of values, which may be different types
**		(T1 ans T2), The individual values can be accessed through its public members
**		(first) and (second).
*/

namespace ft
{

	template <typename T1, typename T2> 
	struct pair
	{
		typedef  T1	first_type;
		typedef  T2	second_type;

		T1		first;
		T2		second;


	/*
	** Constructor
	*/

		pair() :first(), second()
		{};

		pair(const first_type & _first, const second_type & _second)
		: first(_first), second(_second)
		{}

		template <typename U, typename V>
		pair (const pair< U, V > & copy)
		: first(copy.first), second(copy.second)
		{}

		~pair()
		{}

		pair & operator= (const pair & other)
		{
			if (this != &other)
			{
				this->first = other.first;
				this->second = other.second;
			}
			return *this;
		}
};


template < typename T1, typename T2>
pair<T1, T2> make_pair( T1 first, T2 second)
{
	return (pair<T1, T2>(first, second));
}

template <typename T1, typename T2>
bool	operator== (const pair<T1,T2> & lhs, const pair<T1,T2> & rhs)
{
	return(lhs.first == rhs.first && lhs.second == rhs.second);
}

template <typename T1, typename T2>
bool operator!= (const pair<T1,T2> & lhs, const pair<T1,T2> & rhs)
{
	return !(lhs==rhs);
}

template <typename T1, typename T2>
bool operator<  (const pair<T1,T2> & lhs, const pair<T1,T2> & rhs)
{
	return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
}

template <typename T1, typename T2>
bool operator<= (const pair<T1,T2> & lhs, const pair<T1,T2> & rhs)
{
	return !(rhs < lhs);
}

template <typename T1, typename T2>
bool operator>  (const pair<T1,T2> & lhs, const pair<T1,T2> & rhs)
{
	return rhs < lhs;
}

template <typename T1, typename T2>
bool operator>= (const pair<T1,T2> & lhs, const pair<T1,T2> & rhs)
{
	return !(lhs < rhs);
}


}// end namespace ft

#endif
