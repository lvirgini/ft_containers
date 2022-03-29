/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 10:13:38 by lvirgini          #+#    #+#             */
/*   Updated: 2022/03/29 19:22:21 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

# include <memory>
# include "TreeNode.hpp"
# include "pair.hpp"

/*
**	Rules :
**		All nodes are RED or BLACK
**		Root and external NULLs are BLACK
**		new insertions are RED
**		no path can have 2 consecutives RED nodes
**		children of RED are BLACK
**		Every path from root-leaf has the same number of BLACK nodes
*/


/*
**	Rebalance : 
**		BLACK aunts rotate : after rotate : parent is BLACK and son are RED
**		RED aunts colorflip : after : parent is RED and sons are BLACK
**
*/


namespace ft 
{


  // Helper type offering value initialization guarantee on the compare functor.
//   template<typename _Key_compare>
//     struct _Rb_tree_key_compare
//     {
//       _Key_compare		_M_key_compare;

//       _Rb_tree_key_compare()
//       _GLIBCXX_NOEXCEPT_IF(
// 	is_nothrow_default_constructible<_Key_compare>::value)
//       : _M_key_compare()
//       { }

//       _Rb_tree_key_compare(const _Key_compare& __comp)
//       : _M_key_compare(__comp)
//       { }



	// IMPLEMENTATION ITERATORS


	// template <typename Key, typename Value, typename Compare = ft::less<Key>, typename Node_Alloc = std::allocator < ft::Node < ft::pair<Key, Value> > > >
template <typename Value, typename Compare = ft::less<Value>, typename Node_Alloc = std::allocator < ft::Node < Value > > >
class Rb_tree
{
	public:

		// typedef	Key								key_type;
		// typedef	Value							key_value_type;

		// typedef	ft::pair< value >	value_type;

		typedef	Value					value_type;
		typedef ft::Node<value_type >			node_type;

		typedef	node_type *			node_pointer;
		typedef	const node_type *	const_node_pointer;
		typedef	node_type &			node_reference;
		typedef	const node_type &	const_node_reference;

		typedef	size_t				size_type;
		typedef	ptrdiff_t			difference_type;
		typedef	Node_Alloc			node_allocator;

	private:

		node_pointer		_root;
		// node_pointer		_null_node;
		node_pointer		_first;
		node_pointer		_last;
		size_type			_tree_size;
		node_allocator		_allocator;
		Compare				_comp;

	/* -------------------------------------------------------------------------- */
	/*                     Constructor Destructor                                 */
	/* -------------------------------------------------------------------------- */

	public:

		Rb_tree(const node_allocator & alloc = node_allocator(), const Compare & comp = Compare())
		: _root(NULL), _first(NULL), _last(NULL), _tree_size(0), _allocator(alloc), _comp(comp)
		{};

		Rb_tree(node_pointer first, const node_allocator & alloc = node_allocator(), const Compare & comp = Compare())
		: _tree_size(1), _allocator(alloc), _comp(comp)
		{
			_root = m_allocate_node(first);
			_first = _root;
			_last = _root;
		}

		// Rb_tree(const Rb_tree & copy) ;

		// operator=

		~Rb_tree()
		{
			// destroy and deallocate
		}


		void	insert(const value_type & value)
		{
			node_pointer	to_insert = _m_allocate_node(value);

			insert(to_insert);
		}


		void	insert(node_pointer	to_add)
		{
			if (_root == NULL)
			{
				_root = to_add;
				to_add->color = BLACK;
			}
			else
				_insert_not_empty(to_add);
		}



	//private:

		// INSERT FROM introduction to Algorithms:

		void	_insert_not_empty(node_pointer to_add)
		{
			node_pointer	parent = NULL;
			node_pointer	current = _root;

			while (current != NULL)
			{
				parent = current;
				if (_compare(to_add, current) == true)
					current = current->left;
				else
					current = current->right;
			}
			to_add->parent = parent;
			if (_compare(to_add, parent) == true)
				parent->left = to_add;
			else
				parent->right = to_add;
			_insert_fixup(to_add);
		}





		// if node and parent are red : 
		//CAS1:		if aunt of node is red : push black to grandparent
		// 		else
		// CAS2			// if node is left : left_rotate
		// CAS3			// else right rotate


		// Case 2: z ́’s uncle y is black and  ́z is a right child
		// Case 3: z ́’s uncle y is black and  ́z is a left child


		bool	_insert_fixup(node_pointer current)
		{
			node_pointer aunt;
			
			while (current != NULL && current->parent != NULL && current->parent->color == RED)
			{
				aunt = current->get_aunt();
				if (current->parent->is_left())
				{
					if (aunt && aunt->color == RED)
					{
						current->parent->color = BLACK;
						aunt->color = BLACK;
						current = current->get_grand_parent();
						if (current)
							current->color = RED;
					}
					else if (current->is_right())
					{
						current = current->parent;
						_left_rotate(current);
					}
					else
					{
						current->parent->color = BLACK;
						current = current->get_grand_parent();
						if (current)
						{
							current->color = RED;
							_right_rotate(current);
						}
					}
				}
				else
				{
					if (aunt && aunt->color == RED)
					{
						current->parent->color = BLACK;
						aunt->color = BLACK;
						current = current->get_grand_parent();
						if (current)
							current->color = RED;
					}
					else if (current->is_left())
					{
						current = current->parent;
						if (current)
							_right_rotate(current->parent);
					}
					else
					{

						current->parent->color = BLACK;
						current = current->get_grand_parent();
						if (current)
						{
							current->color = RED;
							_left_rotate(current);
						}
					}
				}
			}
			_root->color = BLACK;
			return true;
		}


		bool	_compare(const node_pointer x, const node_pointer y) const
		{
			return _comp(x->data, y->data);
		}


// left_rotate:
// 					x										y
// 			x.l				y						x				y.r
// 						y.l		y.r				x.l		y.l	


		void		_left_rotate(node_pointer x)
		{
			node_pointer y = x->right;

			x->right = y->left;
			if (y->left != NULL)
				y->left->parent = x;
			y->left = x;
			y->parent = x->parent;
			if (x->parent == NULL)
				_root = y;
			else if (x->is_left())
				x->parent->left = y;
			else
				x->parent->right = y;
			x->parent = y;
		}

// right_rotate:
// 					x								y
// 			y			x.r					y.l				x
// 	y.l			y.r										y.r		x.r



		void		_right_rotate(node_pointer x)
		{
			node_pointer y = x->left;

			x->left = y->right;
			if (y->right != NULL)
				y->right->parent = x;
			y->right = x;
			y->parent = x->parent;
			if (x->parent == NULL)
				_root = y;
			else if (x->is_left())
				x->parent->left = y;
			else
				x->parent->right = y;
			x->parent = y;
		}


		bool	insert_left(node_pointer to_add)
		{
			this->set_left(to_add);
			to_add->set_parent(this);
			// reagence color
			// rotate or not
		}


		void	printer()
		{
			_first->print();
		}

		void	print_node(node_reference node)
		{
			node.print();
		}
		// node_pointer	_m_allocate_node(node_pointer node)
		// {
		// 	if (node != NULL)
		// 	{
		// 		this->_allocator.allocate(1);
		// 		this->allocator.construct();
		// 	}
		// 	return node_pointer();
		// }

		// node_pointer	_m_allocate_node(const key_type & key, const key_value_type & value)
		// {
		// 	return _m_allocate_node(make_pair(key, value));
		// }

		node_pointer	_m_allocate_node(const node_type & value)
		{
			node_pointer	node = _allocator.allocate(1);

			_allocator.construct(node, value);
			return node;
		}


		node_pointer	minimum()
		{
			return _first ;
		}

		node_pointer maximum()
		{
			return _last ;
		}

		bool	empty() const
		{
			return (_root == NULL);
		}

		size_type	size() const
		{
			return this->size;
		}

		// size_type	max_size() const
		// {
		// 	return this->_allocator.
		// }

		// void	erase(iterator pos);
		// void	erase(const key_type & x);
		// void	erase(iterator first, iterator last);

		// void	clear();

		// iterator find(const key_type & x);
		// const_iterator find(const key_type & x) const ;


		// // divers map return rb_tree functions
		// key_compare	key_comp() const ;
		// value_compare	value_comp() const ;


		// size_type count(const key_type & x) const ;

		// iterator lower_bound(const key_type & x) ;
		// const_iterator lower_bound(const key_type & x) const ;

		// 	iterator upper_bound(const key_type & x) ;
		// const_iterator upper_bound(const key_type & x) const ;

		// ft::pair<iterator, iterator> equal_range(const key_type & x);
		// ft::pair<const_iterator, const_iterator> equal_range(const key_type & x) const ;



// insert
// predecessor : before
// successor : next
// minimum
// maximum
// insert
// delete / erase


};


}// end namespace ft


# endif
