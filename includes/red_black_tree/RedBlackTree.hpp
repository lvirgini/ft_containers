/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 10:13:38 by lvirgini          #+#    #+#             */
/*   Updated: 2022/04/21 14:54:44 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

# include <memory>
# include <cmath>

# include "TreeNode.hpp"
# include "Rb_tree_iterator.hpp"
# include "reverse_iterator.hpp"
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
		: _root(NULL), _tree_size(0), _allocator(alloc), _node_allocator(node_allocator_type()) ,_comp(comp)
		{
			_sentinel = _create_sentinel();
			insert(first, last);
		}

	/*
	** Copy constructor: construct a tree with a copy of each of the element in (copy)
	*/

		Rb_tree(const self & copy)
		: _root(NULL), _tree_size(0), _allocator(copy._allocator), _node_allocator(copy._node_allocator), _comp(copy._comp)
		{			
			_sentinel = _create_sentinel();
			insert(copy.begin(), copy.end());
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
			return iterator(_sentinel->get_most_left());
		}

		const_iterator	begin() const 
		{
			return const_iterator(_sentinel->get_most_left());
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
			return iterator(_sentinel);
		}

		const_iterator	end() const
		{
			return const_iterator(_sentinel);
		}


		reverse_iterator	rbegin()
		{
			return reverse_iterator(end());
		}

		const_reverse_iterator	rbegin() const
		{
			return const_reverse_iterator(end());
		}

		reverse_iterator	rend()
		{
			return reverse_iterator(begin());
		}

		const_reverse_iterator	rend() const
		{
			return const_reverse_iterator(begin());
		}


/* -------------------------------------------------------------------------- */
/*                                Capacity                                    */
/* -------------------------------------------------------------------------- */

	/*
	**	empty()
	**		Returns true if the tree is empty.
	*/

		bool	empty() const
		{
			return (_root == NULL);
		}

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
			return (this->_node_allocator.max_size());
		}

/* -------------------------------------------------------------------------- */
/*                            Modifiers                                       */
/* -------------------------------------------------------------------------- */


	/*
	** insert single element
	*/

		ft::pair<iterator, bool>	insert(const value_type & value)
		{
			node_pointer	to_insert = _allocate_node(value);

			return _insert(_root, to_insert);
		}

	/*
	** insert single element with position for max efficiency if value position
	**	is just before insert value. 
	*/

		iterator	insert(iterator position, const value_type & value)
		{
			node_pointer	to_add = _allocate_node(value);
			iterator		next = position;

			next++;
			if (*position.is_sentinel() == false
				&& _compare(*position, to_add) == true
				&& (next->is_sentinel() == true || _compare(*next, to_add) == false))
				return (insert(position, to_add).first);
			return (_insert(_root, to_add).first);
		}

	/*
	** insert a range of elements between [first to last]
	*/

		template < typename InputIterator >
		void insert(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				_insert(_root, _allocate_node(*first));
				first++;
			}
		}


	/*
	** removes from the tree a single element at position
	*/

		void	erase(iterator position)
		{
			if (position != end())
				_delete(position._node);
		}

	/*
	** removes from the tree a single element with key (key)
	**	return the number of element erased.
	*/


		size_type	erase(const value_type & value)
		{
			iterator	to_delete = find(value);
			
			if (to_delete != end())
			{
				_delete(to_delete._node);
				return (1);
			}
			return (0);
		}

	/*
	** erase all element between [first to last].
	*/

		void erase(iterator first, iterator last)
		{
			while (first != last)
				erase(first++);
		}


	void	swap(self & other)
	{
		node_pointer	root = other._root;
		node_pointer	sentinel = other._sentinel;
		size_type		tree_size = other._tree_size;

		other._root = this->_root;
		other._tree_size = this->_tree_size;
		other._sentinel = this->_sentinel;

		this->_root = root;
		this->_tree_size = tree_size;
		this->_sentinel = sentinel;
	}

	/*
	** Removes all ele;ent from the tree which are destroyed, leaving the tree 
	**	with the size of 0;
	*/
		void	clear()
		{
			_clear_forward(_root);
			_root = NULL;
			_tree_size = 0;
			_update_sentinel();
		}

/* -------------------------------------------------------------------------- */
/*                                observer                                    */
/* -------------------------------------------------------------------------- */
	
	/*
	** searches element with a key and return an iterator if found, otherwize it returns an iterator
	**	to tree::end();
	*/

		iterator	find(const value_type & value)
		{
			return iterator(_find(_root, value));
		}

		const_iterator	find(const value_type & value) const
		{
			return const_iterator(_find(_root, value));
		}

		node_pointer _find(node_pointer current, const value_type & key)
		{
			if (current != NULL)
			{
				if (_comp(current->data, key))
					return _find(current->right, key);
				if (_comp(key, current->data))
					return _find(current->left, key);
				return (current);
			}
			return (_sentinel);
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

/* -------------------------------------------------------------------------- */
/*                                Usefull private                             */
/* -------------------------------------------------------------------------- */
	private:

		ft::pair<iterator, bool>	_insert(node_pointer current, node_pointer to_add)
		{
			ft::pair<iterator, bool>	result;

			if (_root == NULL)
			{
				_root = to_add;
				result = ft::make_pair<iterator, bool>(iterator(to_add), true);
			}
			else
			{
				_root->parent = NULL;
				result = _insert_not_empty(current, to_add);
			}
			if (result.second == false)
				_deallocate_node(to_add);
			else
				_tree_size++;
			_root->color = BLACK;
			_update_sentinel();
			return result;
		}


		// INSERT FROM introduction to Algorithms:

		ft::pair<iterator, bool>	_insert_not_empty(node_pointer current, node_pointer to_add)
		{
			node_pointer	parent = NULL;

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
			to_add->parent = parent;
			if (_compare(to_add, parent) == true)
				parent->left = to_add;
			else
				parent->right = to_add;
			_insert_fixup(to_add);
			return (ft::make_pair<iterator, bool>(iterator(to_add), true));
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
			if (x == _root)
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
			if (x == _root)
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
	if (deleted->parent->is_sentinel())
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
	node_pointer child;
	node_pointer successor = to_dell;
	node_pointer parent = to_dell->parent;

	bool original_color = to_dell->color;
	bool child_is_left = to_dell->is_left();
	
	// if is not only one
	if (_tree_size > 1)
	{
	// check if no child or onlsuccessor one
		if (to_dell->left == NULL)
		{
			child = to_dell->right;
			_transplant(to_dell, to_dell->right);
		}
		else if (to_dell->right == NULL)
		{
			child = to_dell->left;
			_transplant(to_dell, to_dell->left);
		}
		else // two childs
		{
			successor = to_dell->right->get_most_left();
			original_color = successor->color;
			child = successor->right;
			child_is_left = successor->is_left();
			if (successor->parent == to_dell) // direct child
				parent = successor;
			else
			{
				_transplant(successor, successor->right);
				successor->right = to_dell->right;
				successor->right->parent = successor;
				parent = successor->parent;
			}	
			_transplant(to_dell, successor);
			successor->left = to_dell->left;
			successor->left->parent = successor;
			successor->color = to_dell->color;
		}
		if (child != NULL)
			parent = child->parent;
		if (original_color == BLACK && _tree_size > 2)
			_delete_fixup(child, parent, child_is_left);
	}
	_deallocate_node(to_dell);
	_tree_size--;
	_update_sentinel();
	if (_root)
		_root->color = BLACK;
}

void	_delete_fixup(node_pointer current, node_pointer parent, bool is_left)
{	
	node_pointer sister;

	// while (parent->is_sentinel() == false && (current == NULL || (current != _root && current->color == BLACK )))
	while (current == NULL || (current != _root && current->color == BLACK ))
	{
		if (current != NULL)
			is_left = current->is_left();
		if (is_left == true)
		{
			sister = parent->right;
			if (sister != NULL && sister->color == RED)
			{
				sister->color = BLACK;
				parent->color = RED;
				_left_rotate(parent);
				sister = parent->right;
			}
			if (sister != NULL 
			&& (sister->left == NULL || sister->left->color == BLACK) 
			&& (sister->right == NULL || sister->right->color == BLACK))
			{
				sister->color = RED;
				current = parent;
				parent = parent->parent;
			}
			else
			{
				if (sister != NULL && (sister->right == NULL || sister->right->color == BLACK))
				{
					if (sister->left != NULL)
						sister->left->color = BLACK;
					sister->color = RED;
					_right_rotate(sister);
					sister = parent->right;
				}
				if (sister != NULL)
					sister->color = parent->color;
				parent->color = BLACK;
				if (sister && sister->right != NULL)
					sister->right->color = BLACK;
				_left_rotate(parent);
				current = _root;
				parent = _sentinel;
			}
		}
		else
		{
			sister = parent->left;
			if (sister != NULL && sister->color == RED)
			{
				sister->color = BLACK;
				parent->color = RED;
				_right_rotate(parent);
				sister = parent->left;
			}
			if (sister != NULL
			&& (sister->left == NULL || sister->left->color == BLACK) 
			&& (sister->right == NULL || sister->right->color == BLACK))
			{
				sister->color = RED;
				current = parent;
				parent = parent->parent;
			}
			else
			{
				if (sister != NULL && (sister->left == NULL || sister->left->color == BLACK))
				{
					if (sister->right != NULL)
						sister->right->color = BLACK;
					sister->color = RED;
					_left_rotate(sister);
					sister = parent->left;
				}
				if (sister != NULL)
					sister->color = parent->color;
				parent->color = BLACK;
				if (sister != NULL && sister->left != NULL)
					sister->left->color = BLACK;
				_right_rotate(parent);
				current = _root;
				parent = _sentinel;
			}
		}
	}
	if (current != NULL)
		current->color = BLACK;
}


/* -------------------------------------------------------------------------- */
/*                     Node allocate and destroy                              */
/* -------------------------------------------------------------------------- */


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
			if (_root != NULL)
				_root->parent = _sentinel;
		}

	/*
	** allocate null node for help in erased
	*/

	// node_pointer	_allocate_null_node()
	// {
	// 	node_pointer	node = _allocate_node(value_type());

	// 	return node;
	// }

	// void	_update_null_node(node_pointer parent, bool is_left)
	// {
	// 	_null_node->parent = parent;
	// 	if (parent != NULL)
	// 	{
	// 		if (is_left)
	// 			parent->left = _null_node;
	// 		else
	// 			parent->right = _null_node;
	// 	}
	// 	_null_node->left = NULL;
	// 	_null_node->right = NULL;
	// 	_null_node->color = BLACK;
	// }

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
				current = NULL;
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
			if (current == _root)
				_root = NULL;
			_node_allocator.destroy(current);
			_node_allocator.deallocate(current, 1);
			current = NULL;
		}

/* -------------------------------------------------------------------------- */
/*                                Display                                     */
/* -------------------------------------------------------------------------- */


	public:

		#define STR_BLACK "\033[0m"
		#define STR_RED "\033[31m"

	// thanks to Tony :
	void debug_print_btree_structure()
	{
    	debug_print_btree_structure_2(_root, 0);
	}

private:

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
			for ( int _ = 0 ; _ < space ; _++ )
				std::cout << " ";
			
			std::cout << (current->color == RED ? STR_RED: STR_BLACK);
			std::cout << current->data.first << ":" << current->data.second << STR_BLACK << std::endl;
			debug_print_btree_structure_2(current->left, space);
    	}
	}

};


}// end namespace ft


# endif
