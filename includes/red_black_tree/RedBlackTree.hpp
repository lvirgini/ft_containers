/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 10:13:38 by lvirgini          #+#    #+#             */
/*   Updated: 2022/03/24 16:50:26 by lvirgini         ###   ########.fr       */
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
//   /// One of the @link comparison_functors comparison functors@endlink.
//   template<typename _Tp>
//     struct less : public binary_function<_Tp, _Tp, bool>
//     {
//       _GLIBCXX14_CONSTEXPR
//       bool
//       operator()(const _Tp& __x, const _Tp& __y) const
//       { return __x < __y; }
//     };

	
	template < typename T>
	struct less
	{
		bool	operator()(const T & x, const T & y) const
		{
			return (x < y);
		}
	};



	// IMPLEMENTATION ITERATORS


	template <typename Key, typename Value, typename Compare = ft::less<Key>, typename Node_Alloc = std::allocator < ft::Node < ft::pair<Key, Value> > > >
	class Rb_tree
	{
			public:

			typedef	Key								key_type;
			typedef	Value							key_value_type;

			typedef	ft::pair< key_type, key_value_type>	value_type;
			typedef	ft::Node<value_type >				node_type;

			typedef	node_type *			node_pointer;
			typedef	const node_type *	const_node_pointer;
			typedef	node_type &			node_reference;
			typedef	const node_type &	const_node_reference;

			typedef	size_t				size_type;
			typedef	ptrdiff_t			difference_type;
			typedef	Node_Alloc			node_allocator;



			private:
				// typedef rb_tree_node_base			_Base_ptr;
				// typedef const rb_tree_node_base		_Const_Base_ptr;
				// typedef rb_tree_node<Val> *			_Link_type;
				// typedef const rb_tree_node<Val> *	_Const_Link_type;


			// typedef size_t							size_type;						
			// typedef ft::pair < Key, Value >			value_type;
			// typedef ft::Node<value_type> *		Node_ptr;
			// typedef const ft::Node<value_type> *	Const_Node_ptr;

			node_pointer		_root;
			node_pointer		_first;
			node_pointer		_last;
			size_type			_tree_size;
			node_allocator		_allocator;


			/* -------------------------------------------------------------------------- */
			/*                     Constructor Destructor                                 */
			/* -------------------------------------------------------------------------- */

				Rb_tree(const node_allocator & alloc = node_allocator())
				: _root(NULL), _first(NULL), _last(NULL), _tree_size(0), _allocator(alloc)
				{};

				// Rb_tree(pointer first)
				// : _root(first), _first(first), _last(first), _tree_size(1)
				// {};

				Rb_tree(node_pointer first, const node_allocator & alloc = node_allocator())
				: _tree_size(1), _allocator(alloc)
				{
					_root = m_allocate_node(first);
					_first = _root;
					_last = _root;
				}

				// Rb_tree(const Rb_tree & copy) ;

				// operator=

				~Rb_tree()
				{
					


				}


				bool	insert(const node_type & value)
				{
					node_pointer	to_insert = _m_allocate_node(value);

					return (_insert(to_insert));
					
				}


				// bool	_insert(node_pointer	to_add)
				// {
				// 	if (_root == NULL)
				// 	{
				// 		_root = to_add;
				// 		return (true) ;
				// 	}
				// 	return (_root._insert_next(to_add));
				// 	// node_pointer current = _root;
				// 	// if (to_add < current)
				// 	// {
				// 	// 	if (current->left == NULL)
				// 	// 	{
				// 	// 		current->set_left(to_add);
				// 	// 		to_add->set_parent(current);
				// 	// 		return (true);
				// 	// 	}
				// 	// 	return (current->left._insert_next(to_add);
				// 	// }
				// 	// if (to_add == current)
				// 	// 	return (false);
				// 	// while to_add > current
					
					
				// 	// (current->right == NULL)
				// 	// {
				// 	// 	current->set_right(to_add);
				// 	// 	to_add->set_parent(current);
				// 	// 	return (true);
				// 	// }
				// }

				bool	_insert_next(node_pointer to_add)
				{
					node_pointer current = this;

					if (to_add == current)
						return (false);
					if (to_add < current)
					{
						if (current->left == NULL)
						{
							current->set_left(to_add);
							to_add->set_parent(current);
							return (true);
						}
						return (current->left._insert_next(to_add));
					}
					else
					{
						if (current->right == NULL)
						{
							current->set_right(to_add);
							to_add->set_parent(current);
							return (true);
						}
						return (current->right.insert_next(to_add));
					}
					return false ;
				}


				// INSERT FROM introduction to Algorithms:

				bool	_insert(node_pointer to_add)
				{
					node_pointer	current = _root;
					node_pointer	parent = NULL;

					while (current != NULL)
					{
						parent = current;
						if (to_add < current)
							current = current->left;
						else
							current = current->right;
					}

					to_add->parent = parent;
					if (parent == NULL)
						_root = to_add;
					else if to_add < parent
						parent->left = to_add;
					else
						parent->right = to_add;
					to_add->left = NULL;
					to_add->right = NULL;
					to_add->color = RED;
					_insert_fixup(to_add);
					return (true);
				}


				bool	insert_fixup(node_pointer to_add)
				{

					node_pointer aunt;
					node_pointer 

					while (to_add->color == RED)
					{
						if (to_add->parent->is_left())
							aunt = to->add->parent.get_aunt();
						if aunt->color == RED
						{
							to_add
						}
					}
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

				node_pointer	_m_allocate_node(const key_type & key, const value_type & value)
				{
					return _m_allocate_node(make_pair(key, value));
				}

				node_pointer	_m_allocate_node(const node_type & value)
				{
					node_pointer	node = _allocator.allocate(1);

					_allocator.construct(node, value);
					return node;
				}


				
		
				// void	insert(const pointer node)
				// {
					
				// }


				// void	insert(const )

				node_pointer	minimum()
				{
					return _first ;
				}

				node_pointer maximum()
				{
					return _last ;
				}



			



// insert
//	Search / find
// predecessor : before
// successor : next
// minimum
// maximum
// insert
// delete

// left_rotate

// right rotate

	};





}// end namespace ft


# endif
