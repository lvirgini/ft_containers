/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rb_tree_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:55:34 by lvirgini          #+#    #+#             */
/*   Updated: 2022/05/03 12:42:53 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKTREE_ITERATOR_HPP
# define REDBLACKTREE_ITERATOR_HPP

# include "iterators_traits.hpp"

namespace ft 
{

template <typename Value, typename Node >
class Rb_tree_iterator
{
	public:
		typedef Value				value_type;
		typedef Value &				reference;
		typedef Value *				pointer;
		typedef std::ptrdiff_t		difference_type;

		typedef Rb_tree_iterator<Value, Node>			self;
		typedef std::bidirectional_iterator_tag	iterator_category;
		
		typedef  Node *			node_pointer;
		typedef  Node &			node_reference;
		typedef  const Node &	node_const_reference;

		node_pointer	_node;


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

		pointer		operator->() const
		{
			return _node->operator->();
		}

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

		self & operator--()
		{
			_node = _node->decrement();
			return *this;
		}

		self	operator--(int)
		{
			self	tmp = *this;

			_node = _node->decrement();
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

template <typename Val, typename Node>
inline bool		operator==(const Rb_tree_iterator<Val, Node> & x, const Rb_tree_iterator<Val, Node> & y)
{
	return x._node == y._node;
}

template <typename Val, typename Node>
inline bool		operator!=(const Rb_tree_iterator<Val, Node> & x, const Rb_tree_iterator<Val, Node> & y)
{
	return x._node != y._node;
}




template <typename Value, typename Node>
class Rb_tree_const_iterator
{
	public:
		typedef Value				value_type;
		typedef const Value &		reference;
		typedef const Value *		pointer;
		typedef std::ptrdiff_t		difference_type;

		typedef Rb_tree_iterator<Value, Node>		iterator;
		typedef Rb_tree_const_iterator<Value, Node>	self;
		typedef std::bidirectional_iterator_tag	iterator_category;
		
		typedef  Node *		node_pointer;
		typedef  Node &		node_reference;

		node_pointer	_node;


		Rb_tree_const_iterator()
		: _node()
		{}

		explicit	Rb_tree_const_iterator(node_pointer ptr)
		: _node(ptr)
		{}

		Rb_tree_const_iterator(const iterator & other)
		: _node(other._node)
		{}

		iterator	M_const_cast() const
		{
			return iterator(const_cast<typename iterator::node_pointer>(_node));
		}

		self &		operator=(const self & other)
		{
			if (this != &other)
				_node = other._node;
			return *this;
		}

		reference	operator*() const
		{
			return _node->operator*();
		}

		pointer		operator->() const
		{
			return &(operator*());
		}

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

		self & operator--()
		{
			_node = _node->decrement();
			return *this;
		}

		self	operator--(int)
		{
			self	tmp = *this;

			_node = _node->decrement();
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

  template<typename Value, typename Node>
    inline bool
    operator==(const Rb_tree_iterator<Value, Node>& __x, const Rb_tree_const_iterator<Value, Node>& __y) 
    { return __x._node == __y._node; }

  template<typename Value, typename Node>
    inline bool
    operator!=(const Rb_tree_iterator<Value, Node>& __x, const Rb_tree_const_iterator<Value, Node>& __y) 
    { return __x._node != __y._node; }

}// end namespace ft

# endif
