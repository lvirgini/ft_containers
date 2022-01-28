/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:42:51 by lvirgini          #+#    #+#             */
/*   Updated: 2022/01/29 00:00:38 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USEFULL_HPP
# define USEFULL_HPP

namespace ft 
{

/*
**	Lexicographical less-than comparison
**		Returns true if the range [first1,last1) compares lexicographically
**		less than the range [first2,last2).
*/
	template <typename InputIterator1, typename InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
									InputIterator2 first2, InputIterator2 last2)
	{
		while (first1!=last1)
		{
			if (first2 == last2 || *first2 < *first1) 
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

/*
**	equal
*/
	template < typename InputIterator1, typename InputIterator2>
	bool	equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		for(; first1 != last1; first1++, first2++)
		{
			if (*first1 != *first2)
				return false;
		}
		return (true);
	}

	// template <class InputIterator1, class InputIterator2, class BinaryPredicate>
//   bool equal (InputIterator1 first1, InputIterator1 last1,
            //   InputIterator2 first2, BinaryPredicate pred);


} // end namespace ft

#endif
