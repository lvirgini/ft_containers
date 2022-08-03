/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:02:08 by lvirgini          #+#    #+#             */
/*   Updated: 2022/05/02 12:26:18 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include <deque>
#include "vector.hpp"
namespace ft
{
	template <typename T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef typename Container::value_type		value_type;
			typedef typename Container::reference		reference;
			typedef typename Container::const_reference const_reference;
			typedef typename Container::size_type		size_type;
			typedef Container							container_type;

		protected:
			Container c;


	/* -------------------------------------------------------------------------- */
	/*                     Constructor Destructor                                 */
	/* -------------------------------------------------------------------------- */

		public :

		explicit stack (const Container & _c = Container())
		: c(_c)
		{}


	/* -------------------------------------------------------------------------- */
	/*                                Functions                                   */
	/* -------------------------------------------------------------------------- */

	/*
	**	empty()
	**		Return true if stack is empty
	*/

		bool	empty() const
		{
			return c.empty();
		}

	/*
	**	size()
	**		Return the number of element in the stack
	*/

		size_type	size() const
		{
			return c.size();
		}

	/*
	**	top()
	**		1 - Return a read/write reference top the data at the first element of the stack.
	**		2 - Return a read-only reference.
	*/

		reference	top()
		{
			return c.back();
		}


		const_reference top() const 
		{
			return c.back();
		}

	/*
	**	pop()
	**		Remove first element in the stack
	*/

		void	pop()
		{
			c.pop_back();
		}

	
	/*
	**	push()
	**		Add data to the top of the stack
	*/

	void	push(const value_type & data)
	{
		c.push_back(data);
	}


	template < typename T2, typename Container2>
	friend inline bool		operator==(const stack<T2, Container2> & lhs, const stack <T2, Container2> & rhs);

	template < typename T2, typename Container2>
	friend	inline bool		operator<(const stack<T2, Container2> & lhs, const stack <T2, Container2> & rhs);

};


	template < typename T, typename Container>
	inline bool		operator==(const stack<T, Container> & lhs, const stack <T, Container> & rhs)
	{
		return lhs.c == rhs.c;
	}

	template < typename T, typename Container>
	inline bool		operator!=(const stack<T, Container> & lhs, const stack <T, Container> & rhs)
	{
		return !(lhs == rhs);
	}

	template < typename T, typename Container>
	inline bool		operator<(const stack<T, Container> & lhs, const stack <T, Container> & rhs)
	{
		return lhs.c < rhs.c;
	}

	template < typename T, typename Container>
	inline bool		operator>(const stack<T, Container> & lhs, const stack <T, Container> & rhs)
	{
		return rhs < lhs;
	}

	template < typename T, typename Container>
	inline bool		operator<=(const stack<T, Container> & lhs, const stack <T, Container> & rhs)
	{
		return !(rhs < lhs);
	}

		template < typename T, typename Container>
	inline bool		operator>=(const stack<T, Container> & lhs, const stack <T, Container> & rhs)
	{
		return !(lhs < rhs);
	}


	// ! a < b	==	a >= b
	// ! b < a	==  a <= b
	// b < a 	==  a > b

	
} // end namespace


#endif
