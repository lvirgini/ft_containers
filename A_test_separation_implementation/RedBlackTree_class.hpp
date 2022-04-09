/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree_class.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 10:13:38 by lvirgini          #+#    #+#             */
/*   Updated: 2022/04/09 13:38:30 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKTREE_CLASS_HPP
# define REDBLACKTREE_CLASS_HPP



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


namespace ft {

template < typename Value, typename Compare = ft::less<Value>, typename Node_Alloc = std::allocator < ft::Node < Value > > >
class Rb_tree
{
	public:

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
		
	/* -------------------------------------------------------------------------- */
	/*                     Constructor Destructor                                 */
	/* -------------------------------------------------------------------------- */

	public:

		Rb_tree(const node_allocator & alloc = node_allocator(), const Compare & comp = Compare());
		Rb_tree(node_pointer first, const node_allocator & alloc = node_allocator(), const Compare & comp = Compare());

		// Rb_tree(const Rb_tree & copy) ;
		~Rb_tree();

/* -------------------------------------------------------------------------- */
/*                         Assignation / modifiers                            */
/* -------------------------------------------------------------------------- */
	
	public:
		// operator=
		node_pointer	 find(value_type value) const ;

		void			insert(const value_type & value);
		void			insert(node_pointer	to_add);

		void			clear();
		void			erase(const value_type & value) ;


	private:
		void			_insert_not_empty(node_pointer to_add) ;
		void			_insert_fixup(node_pointer current) ;

		void			_left_rotate(node_pointer x) ;
		void			_right_rotate(node_pointer x) ;

		void			_transplant(node_pointer deleted, node_pointer replaced) ;
		void			_delete(node_pointer to_dell) ;
		void			_delete_fixup(node_pointer current) ;

/* -------------------------------------------------------------------------- */
/*                                Iterator                                    */
/* -------------------------------------------------------------------------- */

	public:
		iterator		begin();
		const_iterator	begin() const ;

		iterator		end();
		const_iterator	end() const;

		node_pointer	minimum() const ;
		node_pointer	maximum() const ;

/* -------------------------------------------------------------------------- */
/*                                Capacity                                    */
/* -------------------------------------------------------------------------- */

	public:
		size_type		size() const ;
		size_type		max_size() const ;
		bool			empty() const ;


	private:
		node_pointer	_allocate_node(const node_type & value) ;
		node_pointer	_clear_forward(node_pointer current) ;

/* -------------------------------------------------------------------------- */
/*                                Usefull                                     */
/* -------------------------------------------------------------------------- */

	private:
		bool			_compare(const node_pointer x, const node_pointer y) const ;


/* -------------------------------------------------------------------------- */
/*                                Display                                     */
/* -------------------------------------------------------------------------- */

	public:

		#define STR_BLACK "\033[0m"
		#define STR_RED "\033[31m"

		void		display() ;

		void 		debug_print_btree_structure();
		void		debug_print_btree_structure_(node_pointer current, int space);
		void 		debug_print_btree_structure_2(node_pointer current, int space);

	private:
		bool 		_print_level(node_pointer current, int actual_level, int level_to_print) ;
		void		_print_space(int level);
		void		_print(node_pointer current, int level);
		void		_print_separator(node_pointer current, int space);

};

}	// end namespace ft

// # include "RedBlackTree_implementation.hpp"

# endif
