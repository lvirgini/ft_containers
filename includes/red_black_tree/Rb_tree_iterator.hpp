/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rb_tree_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:55:34 by lvirgini          #+#    #+#             */
/*   Updated: 2022/04/13 13:52:45 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKTREE_ITERATOR_HPP
# define REDBLACKTREE_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft 
{

	// IMPLEMENTATION ITERATORS

template <typename Value>
class Rb_tree_iterator
{
	private:
		typedef ft::iterator_traits<Value>	__trait_type;

	public:
		typedef typename __trait_type::value_type			value_type;
		typedef typename __trait_type::pointer				pointer;
		typedef typename __trait_type::const_pointer		const_pointer;
		typedef typename __trait_type::reference			reference;
		typedef typename __trait_type::const_reference		const_reference;
		typedef typename __trait_type::difference_type		difference_type;
		typedef typename __trait_type::iterator_category	iterator_category;

		typedef typename Node<Value>::pointer		node_pointer;
		typedef Rb_tree_iterator<Value>				self;
		
	private:
		node_pointer						_node;


	public:

		Rb_tree_iterator()
		: _node()
		{}

		explicit	Rb_tree_iterator(node_pointer ptr)
		: _node(ptr)
		{}

		Rb_tree_iterator(const_reference other)
		{
			this = other;
		}

		reference		operator=(const_reference other)
		{
			if (this != &other)
				_node = other._node;
			return *this;
		}

		reference	operator*() const
		{
			return *_node;
		}

		pointer		operator->()
		{
			return _node;
		}

		// self & operator[](difference_type n)
		// {

		// }


		reference	operator++()
		{
			_node.increment;
			return *this;
		}

		// reference	operator++(int)
		// {
		// 	self	tmp = *this;
		// 	_node = 
		// }



};


}// end namespace ft


# endif
