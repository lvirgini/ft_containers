/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rb_tree_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:55:34 by lvirgini          #+#    #+#             */
/*   Updated: 2022/04/13 17:42:38 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKTREE_ITERATOR_HPP
# define REDBLACKTREE_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft 
{

	// IMPLEMENTATION ITERATORS

template <typename Value, typename Node >
class Rb_tree_iterator
{
	public:
		typedef Value			value_type;
		typedef Value &			reference;
		typedef Value *			pointer;
		typedef ptrdiff_t		difference_type;

		typedef Rb_tree_iterator<Value, Node>			self;
		typedef std::bidirectional_iterator_tag	iterator_category;
		
		typedef  Node *		node_pointer;
		typedef  Node &		node_reference;
		typedef  const Node &	node_const_reference;

		
	private:
		node_pointer	_node;


	public:

		Rb_tree_iterator()
		: _node()
		{}

		explicit	Rb_tree_iterator(node_pointer ptr)
		: _node(ptr)
		{}

		Rb_tree_iterator(const self & other)
		{
			*this = other;
		}

		self &		operator=(const self & other)
		{
			if (this != &other)
				_node = other._node;
			return *this;
		}

		reference	operator*()
		{
			return _node->operator*();
		}

		pointer		operator->()
		{
			return _node->operator->();
		}

		// self & operator[](difference_type n)
		// {

		// }


		self &	operator++()
		{
			_node = _node->increment();
			return *this;
		}

		self	operator++(int)
		{
			self	tmp = *this;
			
			_node = _node->increment();
			return tmp;
		}


		bool	operator==( const self & other) const
		{
			return (_node == other._node);
		}

		bool	operator !=(const self & other) const
		{
			return (_node != other._node);
		}


};


}// end namespace ft


# endif
