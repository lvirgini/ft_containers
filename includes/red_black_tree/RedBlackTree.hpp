/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 10:13:38 by lvirgini          #+#    #+#             */
/*   Updated: 2022/04/14 23:31:23 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

# include <memory>
# include <cmath>

# include "TreeNode.hpp"
# include "Rb_tree_iterator.hpp"
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

/*	**	** 	RED BLACK TREE definitions	**
* 
**	Constructor:
* 			Rb_tree(const node_allocator, const Compare);
* 			Rb_tree(node_pointer first, const node_allocator, const Compare);
* 			Rb_tree(const Rb_tree & copy) ;
* 			~Rb_tree();
* 
** 	Assignation / modifiers
* 		// operator=
* 		node_pointer	find(value_type value) const ;
* 		void			insert(const value_type & value);
* 		void			insert(node_pointer	to_add);
* 		void			clear();
* 		void			erase(const value_type & value) ;
* 
**	Iterator
* 		iterator		begin();
* 		const_iterator	begin() const ;
* 		iterator		end();
* 		const_iterator	end() const;
* 		node_pointer	minimum() const ;
* 		node_pointer	maximum() const ;
* 
**	Capacity
* 		size_type		size() const ;
* 		size_type		max_size() const ;
* 		bool			empty() const ;
* 
* 
**	Usefull
* 		bool		_compare(const node_pointer x, const node_pointer y) const ;
* 
* 
**	Display
* 		void		display() ;
* 		void 		debug_print_btree_structure();
* 		void		debug_print_btree_structure_(node_pointer current, int space);
* 		void 		debug_print_btree_structure_2(node_pointer current, int space);
* 
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


template <typename Value, typename Compare = ft::less<Value>, typename Alloc = std::allocator < Value > >
class Rb_tree
{
	public:

		/* member type	*/
		typedef	Value					value_type;
		typedef ft::Node<value_type>	node_type;

		typedef	Alloc					allocator_type;
		typedef typename allocator_type::template rebind<node_type>::other node_allocator_type;

		typedef	node_type *			node_pointer;
		typedef	const node_type *	const_node_pointer;
		typedef	node_type &			node_reference;
		typedef	const node_type &	const_node_reference;

		typedef	size_t				size_type;
		typedef	ptrdiff_t			difference_type;

		typedef Rb_tree *			pointer;
		typedef const Rb_tree *		const_pointer;
		typedef Rb_tree &			reference;
		typedef const Rb_tree &		const_reference;

		// typedef ft::normal_iterator<node_pointer, Rb_tree>		iterator;
		// typedef ft::normal_iterator<const_node_pointer, Rb_tree>	const_iterator;

		// typedef ft::Rb_tree_iterator<value_type>	iterator;
		// typedef ft::Rb_tree_iterator<value_type>	const_iterator; ////
		// typedef ft::Rb_tree_iterator<value_type, node_inter>			iterator;
		// typedef ft::Rb_tree_iterator<value_type, const_node_pointer>	const_iterator;

		typedef ft::Rb_tree_iterator<value_type, node_type>			iterator;
		typedef ft::Rb_tree_const_iterator<value_type, node_type>	const_iterator;

		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		typedef ft::Rb_tree<Value, Compare, Alloc>		self;

	private:

		node_pointer			_root;
		size_type				_tree_size;
		allocator_type			_allocator;
		node_allocator_type		_node_allocator;
		node_pointer			_sentinel;

		Compare					_comp;

	/* -------------------------------------------------------------------------- */
	/*                     Constructor Destructor                                  */
	/* -------------------------------------------------------------------------- */

	public:

	/*
	** Default Constructor: construct an empty tree with no elements
	*/
		// Rb_tree()
		// : _root(NULL), _tree_size(0)
		// {
		// 	_sentinel = _create_sentinel();
		// }

		
		Rb_tree(const Compare & comp = Compare(), const allocator_type & alloc = allocator_type())
		: _root(NULL), _tree_size(0), _allocator(alloc), _comp(comp)
		{
			_sentinel = _create_sentinel();
		}

	/*
	** Range constructor: construct a tree with as many element as the range [first, last]
	** 	with each element constructed front its corresponding element in that range.
	*/

		template < typename InputIterator >
		Rb_tree(InputIterator first, InputIterator last, const Compare & comp = Compare(), const allocator_type & alloc = allocator_type())
		: _root(NULL), _tree_size(0), _allocator(alloc), _node_allocator(node_allocator_type() ,_comp(comp))
		{
			insert(first, last);
			_sentinel = _create_sentinel();
		}

	/*
	** Copy constructor: construct a tree with a copy of each of the element in (copy)
	*/

		Rb_tree(const self & copy)
		: _allocator(copy._allocator), _node_allocator(copy._node_allocator), _comp(copy._comp)
		{
			*this = copy;
		}

	/*
	** operator=(): clear this and copie all the elements from (other) into this tree.
	**	preserves its current allocator
	*/

		self &	operator=(const self & other)
		{
			if (this != &other)
			{
				this->clear();
				this->insert(other.begin(), other.end());
			}
			return *this;
		}

	/*
	** destroy all tree
	*/

		~Rb_tree()
		{
			this->clear();
			_node_allocator.destroy(_sentinel);
			_node_allocator.deallocate(_sentinel, 1);
		}

/* -------------------------------------------------------------------------- */
/*                                Iterator                                    */
/* -------------------------------------------------------------------------- */

	/*
	** begin()
	**		return an iterator pointing to the first element in the tree.
	*/

		iterator		begin()
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

		iterator		end()
		{
			// ou NULL ???
			return iterator(_sentinel);
		}

		const_iterator	end() const
		{
			// ou NULL ???
			return const_iterator(_sentinel);
		}


		// reverse_iterator	rbegin()
		// {
		// 	return reverse_iterator(_root->get_most_right());
		// }

		// const_reverse_iterator	rbegin() const
		// {
		// 	return const_reverse_iterator(_root->get_most_right());
		// }

		// reverse_iterator	rend()
		// {
		// 	return reverse_iterator(_sentinel);
		// }

		// const_reverse_iterator	rend() const
		// {
		// 	return const_reverse_iterator(_sentinel);
		// }


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
			return (this->node_allocator.max_size());
		}
		
	/*
	**	empty()
	**		Returns true if the tree is empty.
	*/

		bool	empty() const
		{
			return (_root == NULL);
		}

/* -------------------------------------------------------------------------- */
/*                            Modifiers                                       */
/* -------------------------------------------------------------------------- */

	/*
	**
	*/
		void	clear()
		{
			_clear_forward(_root);
			_tree_size = 0;
		}

	/*
	**
	*/
		ft::pair<iterator, bool>	insert(const value_type & value)
		{
			node_pointer	to_insert = _allocate_node(value);

			return (insert(to_insert));
		}

	/*
	**
	*/

		ft::pair<iterator, bool>	insert(node_pointer	to_add)
		{
			ft::pair<iterator, bool> result;

			if (_root == NULL)
			{
				_root = to_add;
				result.first = iterator(to_add);
				result.second = true;
			}
			else
			{
				_root->parent = NULL;
				result = _insert_not_empty(to_add);
				_root->parent = _sentinel;
			}
			_root->color = BLACK;
			if (result.second == true)
				_tree_size++;
			_update_sentinel();
			return result;
		}

		template < typename InputIterator >
		void insert(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				insert(*first);
				first++;
			}
		}


	void	erase(iterator position)
	{
		_delete(*position);
	}


	void erase(iterator first, iterator last)
	{
		while (first != last)
			_delete(first++);
	}
		// void	erase(iterator pos);
		// void	erase(const key_type & x);
		// void	erase(iterator first, iterator last);
		void	erase(const value_type & value)
		{
			node_pointer	to_delete = find(value);
			
			if (to_delete != NULL)
				_delete(to_delete);
		}


	// void	swap()


		node_pointer	find(value_type value) const
		{
			node_pointer current = _root;
			
			while (current != NULL)
			{
				if (current->data == value)
					return current;
				current = _comp(current->data, value) ? current->right : current->left;
			}
			return current;
		}

		node_pointer	minimum() const
		{
			return _root->get_most_left();
		}

		node_pointer 	maximum() const
		{
			return _root->get_most_right();
		}


/* -------------------------------------------------------------------------- */
/*                                Allocator                                   */
/* -------------------------------------------------------------------------- */

	/*
	** return a copy of the memory allocator
	*/
		allocator_type	get_allocator() const
		{
			return _allocator;
		}


	private:

		// INSERT FROM introduction to Algorithms:

		ft::pair<iterator, bool>	_insert_not_empty(node_pointer to_add)
		{
			node_pointer	parent = NULL;
			node_pointer	current = _root;


			while (current != NULL)
			{
				parent = current;
				if (_compare(to_add, current) == true)
					current = current->left;
				else
				{
					if (_compare(current, to_add) == false)
						return ft::make_pair<iterator, bool>(iterator(current), false);
					current = current->right;
				}
			}


			// while (current != NULL)
			// {
			// 	if (current == to_add)
			// 		return ft::make_pair<iterator, bool>(iterator(current), false);
			// 	parent = current;
			// 	current = _compare(to_add, current) == true ? current->left : current->right;
			// }
			to_add->parent = parent;
			if (_compare(to_add, parent) == true)
				parent->left = to_add;
			else
				parent->right = to_add;
			_insert_fixup(to_add);
			return ft::make_pair<iterator, bool>(iterator(to_add), true);
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
					else
					{
						if (current->is_right())
							_left_rotate(current->parent);
						current->parent->color = BLACK;
						current = current->get_grand_parent();
						if (current != NULL)
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


/*
** Rb_transplant : for help in deletion // introduction to Algorithms
*/

void	_transplant(node_pointer deleted, node_pointer replaced)
{
	if (deleted->parent == NULL)
		_root = replaced;
	else if (deleted->is_left())
		deleted->parent->left = replaced;
	else
		deleted->parent->right = replaced;
	if (replaced != NULL)
		replaced->parent = deleted->parent;
}


/*
** Delete :
*/

void	_delete(node_pointer to_dell)
{
	node_pointer replaced;
	node_pointer y = to_dell;

	bool original_color = to_dell->color;

	if (to_dell->left == NULL)
	{
		replaced = to_dell->right;
		_transplant(to_dell, replaced);
	}
	else if (to_dell->right == NULL)
	{
		replaced = to_dell->left;
		_transplant(to_dell, replaced);
	}
	else
	{
		y = to_dell->right->get_most_left();
		original_color = y->color;
		replaced = y->right;
		if (y->parent == to_dell)
			replaced->parent = y;
		else
		{
			_transplant(y, y->right);
			y->right = to_dell->right;
			y->right->parent = y;
		}	
		_transplant(to_dell, y);
		y->left = to_dell->left;
		y->left->parent = y;
		y->color = to_dell->color;
	}

	if (original_color == BLACK)
		_delete_fixup(replaced);
	_root->color = BLACK;
}


void	_delete_fixup(node_pointer current)
{
	node_pointer sister;

	while (current != _root && current->color == BLACK)
	{
		if (current->is_left())
		{
			sister = current->get_sister();
			if (sister->color == RED)
			{
				sister->color = BLACK;
				current->parent->color = RED;
				_left_rotate(current->parent);
				sister = current->parent->right;
			}
			if (sister->left->color == BLACK && sister->right->color == BLACK)
			{
				sister->color = RED;
				current = current->parent;
			}
			else
			{
				if (sister->right->color == BLACK)
				{
					sister->left->color = BLACK;
					sister->color = RED;
					_right_rotate(sister);
					sister = current->parent->right;
				}
				sister->color = current->parent->color;
				current->parent->color = BLACK;
				sister->right->color = BLACK;
				_left_rotate(current->parent);
				current = _root;
			}
		}
		else
		{
			sister = current->get_sister();
			if (sister->color == RED)
			{
				sister->color = BLACK;
				current->parent->color = RED;
				_right_rotate(current->parent);
				sister = current->parent->left;
			}
			if (sister->left->color == BLACK && sister->right->color == BLACK)
			{
				sister->color = RED;
				current = current->parent;
			}
			else
			{
				if (sister->left->color == BLACK)
				{
					sister->right->color = BLACK;
					sister->color = RED;
					_left_rotate(sister);
					sister = current->parent->left;
				}
				sister->color = current->parent->color;
				current->parent->color = BLACK;
				sister->right->color = BLACK;
				_left_rotate(current->parent);
				current = _root;
			}
		}
	}
}



		node_pointer	_create_sentinel()
		{
			node_pointer	sentinel = _node_allocator.allocate(1);

			_node_allocator.construct(sentinel, value_type());
			sentinel->parent = NULL;
			sentinel->color = BLACK;
			sentinel->left = _root;
			return (sentinel);
		}

		void		_update_sentinel()
		{
			_sentinel->left = _root;
			_root->parent = _sentinel;
		}

/* -------------------------------------------------------------------------- */
/*                     Node allocate and destroy                              */
/* -------------------------------------------------------------------------- */

	/*
	** allocate and create node
	*/
		node_pointer	_allocate_node(const value_type & value)
		{
			node_pointer	node = _node_allocator.allocate(1);
			
			_allocator.construct(node->get_value_pointer(), value);
			_node_allocator.construct(node, node->data);
			return node;
		}
		
	/*
	** Clear all element behind current (usefull only for clear all is not a RB tree after ...)
	*/
		
		void	_clear_forward(node_pointer current)
		{
			if (current != NULL)
			{
				if (current->left != NULL)
					_clear_forward(current->left);
				if (current->right != NULL)
					_clear_forward(current->right);
				_destroy_node(current);
			}
		}
		
	/*
	** destroy and deallocate node
	*/

		void	_destroy_node(node_pointer current)
		{
			_allocator.destroy(current->get_value_pointer());
			_deallocate_node(current);
		}

	/*
	** deallocate node without destroy value (usefull for sentinel)
	*/
		void	_deallocate_node(node_pointer current)
		{
			_node_allocator.destroy(current);
			_node_allocator.deallocate(current, 1);
		}

/* -------------------------------------------------------------------------- */
/*                                Display                                     */
/* -------------------------------------------------------------------------- */


	public:

		#define STR_BLACK "\033[0m"
		#define STR_RED "\033[31m"


		void	display()
		{
			if (_root == NULL)
				return ;

			int level = 0;
			bool finished = false;



			// _print_space(level);
			finished = _print_level(_root, 0, level++);
			std::cout << std::endl;

			// _print_space(level);
			finished = _print_level(_root, 0, level++);
			std::cout << std::endl;

			// _print_space(level);
			finished = _print_level(_root, 0, level++);
			std::cout << std::endl;

			// _print_space(level);
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
					std::cout << "  ";
			}
			else
			{
				for (size_t i = 0; i < (_tree_size / std::pow(2, level)) / level; i++)
					std::cout << "  ";
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


// thanks to Tony :
	void debug_print_btree_structure(){
    debug_print_btree_structure_2(_root, 0);
}


	void debug_print_btree_structure_(node_pointer current, int space){
    if ( current != NULL ){
        space += 10;
        debug_print_btree_structure_(current->right, space);
        std::cout << std::endl;
        for ( int _ = 0 ; _ < space ; _++ ){ std::cout << " "; }
        std::cout << "( " << current->data.first << " : " << current->data.second  << ", " << " )" << std::endl;
        debug_print_btree_structure_(current->left, space);
    }
	}



	void	_print_separator(node_pointer current, int space)
	{

		if (current->is_left() && current->parent && current->parent->is_right())
		{
			for ( int _ = 0 ; _ < space - 6; _++ ){ std::cout << " "; }
			std::cout << "/";
		}
		else
			for ( int _ = 0 ; _ < space - 5; _++ ){ std::cout << " "; }
		for ( int _ = 0 ; _ < 3 ; _++ ){ std::cout << " "; }
		if (current != _root && current->is_left() )
		std::cout << "\\";
		else
		std::cout << " ";
		if (current->right != NULL)
			std::cout << "     /";
		std::cout << std::endl;
	}

	void debug_print_btree_structure_2(node_pointer current, int space)
	{
		if ( current != NULL )
		{
			space += 6;
			debug_print_btree_structure_2(current->right, space);
			_print_separator(current, space);
			for ( int _ = 0 ; _ < space ; _++ ){ std::cout << " "; }
			
			std::cout << (current->color == RED ? STR_RED: STR_BLACK);
			std::cout << current->data.first << ":" << current->data.second << STR_BLACK << std::endl;
			debug_print_btree_structure_2(current->left, space);
    	}
	}

};


}// end namespace ft


# endif
