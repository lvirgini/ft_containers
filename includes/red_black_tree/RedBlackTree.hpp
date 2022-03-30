/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 10:13:38 by lvirgini          #+#    #+#             */
/*   Updated: 2022/03/30 20:52:00 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

# include <memory>
# include <cmath>

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
		typedef ft::Node<value_type>	node_type;

		typedef	node_type *			node_pointer;
		typedef	const node_type *	const_node_pointer;
		typedef	node_type &			node_reference;
		typedef	const node_type &	const_node_reference;

		typedef	size_t				size_type;
		typedef	ptrdiff_t			difference_type;
		typedef	Node_Alloc			node_allocator;

		typedef Rb_tree *			pointer;
		typedef const Rb_tree *		const_pointer;
		typedef Rb_tree &			reference;
		typedef const Rb_tree &		const_reference;

		typedef ft::normal_iterator<pointer, Rb_tree>		iterator;
		typedef ft::normal_iterator<const_pointer, Rb_tree>	const_iterator;

	private:

		node_pointer		_root;
		size_type			_tree_size;
		node_allocator		_allocator;
		Compare				_comp;

		// node_pointer		_null_node;
		// node_pointer		_first;
		// node_pointer		_last;
		
	/* -------------------------------------------------------------------------- */
	/*                     Constructor Destructor                                 */
	/* -------------------------------------------------------------------------- */

	public:

		Rb_tree(const node_allocator & alloc = node_allocator(), const Compare & comp = Compare())
		: _root(NULL), _tree_size(0), _allocator(alloc), _comp(comp)
		{};

		Rb_tree(node_pointer first, const node_allocator & alloc = node_allocator(), const Compare & comp = Compare())
		: _tree_size(1), _allocator(alloc), _comp(comp)
		{
			_root = m_allocate_node(first);
		}

		// Rb_tree(const Rb_tree & copy) ;


		~Rb_tree()
		{
			this->clear();
		}

/* -------------------------------------------------------------------------- */
/*                               PRINT                                        */
/* -------------------------------------------------------------------------- */

		#define STR_BLACK "\033[0m"
		#define STR_RED "\033[31m"


		void	display()
		{
			if (_root == NULL)
				return ;

			int level = 0;
			bool finished = false;



			_print_space(level);
			finished = _print_level(_root, 0, level++);
			std::cout << std::endl;

			_print_space(level);
			finished = _print_level(_root, 0, level++);
			std::cout << std::endl;

			_print_space(level);
			finished = _print_level(_root, 0, level++);
			std::cout << std::endl;

			_print_space(level);
			finished = _print_level(_root, 0, level++);
			std::cout << std::endl;

			// _print(_root->left, 1);
			// _print(_root->right, 1);


			// finished = _print_level(_root, 0, level);


			// while (finished == false)
			// {
			// 	finished = _print_level(_root, 0, level);
			// 	level++;
				std::cout << std::endl;
			// }

			// _print(_root, this->_tree_size, 0);
		}

		bool 	_print_level(node_pointer current, int actual_level, int level_to_print)
		{
			bool left = false;
			bool right = false;
			if (current == NULL)
			{
				_print(NULL, level_to_print);
				return false;
			}
			if (actual_level != level_to_print)
			{
				left = _print_level(current->left, actual_level + 1, level_to_print);
				right = _print_level(current->right, actual_level + 1, level_to_print);
			}
			else
				_print(current, actual_level);
			if (right == false && left == false)
				return false;
			return true;



			// static int to_print = 0;

			// if (current == _root)
			// 	to_print = 0;
			// if (current != NULL && actual_level != to_print)
			// {
			// 	if (current->left)
			// 		_print_level(current->left, actual_level + 1, level_to_print);
			// 	if (current->right)
			// 		_print_level(current->right, actual_level + 1, level_to_print);
			// }
			// else if (actual_level == level_to_print)
			// {
			// 	_print(current->left, actual_level);
			// 	_print(current->right, actual_level);
			// }
			// if (current != NULL)
			// 	to_print++;
			// if (to_print > 0)
			// 	return (false);
			// return (true);
		}

		void	_print_space(int level)
		{
			if (level == 0)
			{
				for (size_t i = 0; i < _tree_size; i++)
					std::cout << " ";
			}
			else
			{
				for (size_t i = 0; i < (_tree_size) / std::pow(2, level); i++)
					std::cout << " ";
			}
		}

	
		void	_print(node_pointer current, int level)
		{

			_print_space(level);
			if (current == NULL)
				std::cout << STR_BLACK << ".";
			else
			{
				std::string color = current->color == RED ? STR_RED: STR_BLACK;
				std::cout << color << current->data.first;
			}
			_print_space(level);
		}



/* -------------------------------------------------------------------------- */
/*                         Assignation / modifiers                            */
/* -------------------------------------------------------------------------- */
		// operator=

		void	clear()
		{
			_clear_forward(_root);
		}


		void	insert(const value_type & value)
		{
			node_pointer	to_insert = _m_allocate_node(value);

			insert(to_insert);
		}


		void	insert(node_pointer	to_add)
		{
			if (_root == NULL)
				_root = to_add;
			else
				_insert_not_empty(to_add);
			_root->color = BLACK;
			_tree_size++;
		}


		node_pointer	minimum()
		{
			return _root->get_most_left();
		}

		node_pointer maximum()
		{
			return _root->get_most_right();
		}

/* -------------------------------------------------------------------------- */
/*                                Iterator                                    */
/* -------------------------------------------------------------------------- */

	/*
	** begin()
	**		return an iterator pointing to the first element in the tree.
	*/

		iterator	begin()
		{
			return iterator(_root->get_most_left());
		}

		const_iterator	begin() const 
		{
			return const_iterator(_root->get_most_left());
		}

	/*
	**	end()
	**		Return an iterator reffering to the past-the_end element in the tree.
	**		past-the-end is last element + 1 theorical element.
	**		that means it shall not be be dereferenced.
	**		in the tree it meens parent of root -> NULL
	*/

		iterator	end()
		{
			// ou NULL ???
			return iterator(_root->get_most_right()->increment());
		}

		const_iterator	end() const
		{
			// ou NULL ???
			return const_iterator(_root->get_most_right()->increment());
		}


/* -------------------------------------------------------------------------- */
/*                                Capacity                                    */
/* -------------------------------------------------------------------------- */

	/*
	**	size()
	**		Return current size : the number of elements in the tree
	*/

		size_type	size() const
		{
			return this->_tree_size;
		}

	/*
	**	max_size()
	**		Returns the maximum number of elements that the vector can hold.
	*/

		size_type	max_size(void) const
		{
			return (this->_allocator.max_size());
		}
		

	/*
	**	empty()
	**		Returns true if the tree is empty.
	*/

		bool	empty() const
		{
			return (_root == NULL);
		}


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


// predecessor : before
// successor : next
// minimum
// maximum
// insert
// delete / erase

	private:

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


		void	_insert_fixup(node_pointer current)
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
							_right_rotate(current);
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
		
		/*
		** Clear all element behind current (usefull only for clear all is not a RB tree after ...)
		*/
		
		void	_clear_forward(node_pointer current)
		{
			if (current->left != NULL)
				_clear_forward(current->left);
			if (current->right != NULL)
				_clear_forward(current->right);
			_allocator.destroy(current);
			_allocator.deallocate(current, 1);
		}

};


}// end namespace ft


# endif
