/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:02:34 by lvirgini          #+#    #+#             */
/*   Updated: 2022/04/23 23:40:26 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

# include "pair.hpp"
# include "RedBlackTree.hpp"

namespace ft
{

template < class Key, class Compare = ft::less<Key>, class Allocator = std::allocator<Key> >
class set
{
/* -------------------------------------------------------------------------- */
	/* Member type	*/
	public:
		typedef Key						key_type;
		typedef Key						value_type;
		typedef Compare					key_compare;
		typedef Compare					value_compare;
		typedef Allocator				allocator_type;

		typedef typename Allocator::reference		reference;
		typedef typename Allocator::const_reference	const_reference;
		typedef typename Allocator::pointer			pointer;
		typedef typename Allocator::const_pointer	const_pointer;
		
		
	private:
		typedef Rb_tree<value_type, value_compare, allocator_type>	m_tree_type;
		typedef typename m_tree_type::iterator						m_tree_iterator;

		typedef set<Key, Compare, Allocator>						self;

	public:
		typedef typename m_tree_type::size_type					size_type;
		typedef typename m_tree_type::const_iterator			iterator;
		typedef typename m_tree_type::const_iterator			const_iterator;
		typedef typename m_tree_type::const_reverse_iterator	reverse_iterator;
		typedef typename m_tree_type::const_reverse_iterator	const_reverse_iterator;

		typedef typename iterator_traits<iterator>::difference_type		difference_type;
	/* -------------------------------------------------------------------------- */

	
	private:
		allocator_type	m_alloc;
		key_compare		m_comp;
		m_tree_type		m_tree;
		
	/* -------------------------------------------------------------------------- */
	/*                     Constructor Destructor                                  */
	/* -------------------------------------------------------------------------- */

	public:

	/*
	** Default constructor create an empty set.
	** Create an empty set with comparaison and allocator.
	*/
		explicit set (const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type())
		: m_alloc(alloc), m_comp(comp), m_tree(comp, alloc)
		{}

	/*
	** Copy constructor : create a complete copy of each element in copy.tree.
	*/

		set(const self & copy)
		: m_alloc(copy.m_alloc), m_comp(copy.m_comp), m_tree(copy.m_tree)
		{}

	/*
	** Create set from elements first to last with comparaison and/or allocator_type
	*/

		template <typename InputIterator>
		set(InputIterator first, InputIterator last, const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type(),
		typename ft::enable_if<!ft::is_integer<InputIterator>::value, InputIterator>::type * = NULL )
		: m_alloc(alloc), m_comp(comp), m_tree(first, last, comp, alloc)
		{}

	/*
	** Destructor:
	*/

		~set()
		{}

/* -------------------------------------------------------------------------- */
/*                         Assignation / Element access                        */
/* -------------------------------------------------------------------------- */


	/*
	** call operator= of tree: clear tree and copie all the element from other into this tree.
	*/

	self	&	operator=(const self & other)
	{
		if (this != &other)
			m_tree = other.m_tree;
		return *this;
	}

/* -------------------------------------------------------------------------- */
/*                                Iterator                                     */
/* -------------------------------------------------------------------------- */

	/*
	** begin()
	**		return an iterator pointing to the first element in the tree.
	*/

		iterator		begin()
		{
			return m_tree.begin();
		}

		const_iterator	begin() const
		{
			return m_tree.begin();
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
			return m_tree.end();
		}

		const_iterator	end() const
		{
			return m_tree.end();
		}

	/*
	** rend()
	**		Return reverse iterator to reverse beginning:
	**		pointing to the last element in the container. iterate backwards.
	*/

		reverse_iterator	rbegin()
		{
			return m_tree.rbegin();
		}

		const_reverse_iterator rbegin() const
		{
			return m_tree.rbegin();
		}

		reverse_iterator	rend()
		{
			return m_tree.rend();
		}

		const_reverse_iterator	rend() const
		{
			return m_tree.rend();
		}


/* -------------------------------------------------------------------------- */
/*                                Capacity                                    */
/* -------------------------------------------------------------------------- */

	/*
	** empty()
	**		Return true if the set is empty.
	*/

	bool	empty() const 
	{
		return m_tree.empty();
	}

	/*
	**	size()
	**		Return current size : the number of elements in the tree
	*/

	size_type size() const
	{
		return m_tree.size();
	}

	/*
	**	max_size()
	**		Returns the maximum number of elements that the vector can hold.
	*/

	size_type	max_size() const
	{
		return m_tree.max_size();
	}
	
/* -------------------------------------------------------------------------- */
/*                            Modifiers                                       */
/* -------------------------------------------------------------------------- */

/*
** insert single element
*/

	ft::pair<iterator, bool>	insert(const value_type & x)
	{
		return m_tree.insert(x);;
	}

/*
** insert single element with position for max efficiency if value position
**	is just before insert value. 
*/
	iterator insert(iterator position, const value_type & x)
	{
		m_tree_iterator pos = position.M_const_cast();
		return m_tree.insert(pos, x);
	}

/*
** insert a range of elements between [first to last]
*/

	template <typename InputIterator>
	void	insert(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integer<InputIterator>::value, InputIterator>::type * = NULL )
	{
			m_tree.insert(first, last);
	}

/*
** removes from the tree a single element at position
*/

	void	erase(iterator position)
	{
			m_tree_iterator pos = position.M_const_cast();
			m_tree.erase(pos);
	}

/*
** removes from the tree a single element with key (key)
**	return the number of element erased.
*/

	size_type	erase(const value_type & key)
	{
		m_tree_iterator	it = m_tree.find(key);
		
		if (it != end())
		{
			m_tree.erase(it);
			return (1);
		}	
		return (0);
	}

/*
** erase all element between [first to last].
*/
	void erase(iterator first, iterator last)
	{
		m_tree_iterator it = first.M_const_cast();
		m_tree_iterator ite = last.M_const_cast();
		m_tree.erase(it, ite);
	}

	void swap (self & other)
	{
		m_tree.swap(other.m_tree);
	}

	/*
	** Removes all element from the set which is destroyed, leaving the container 
	**	with the size of 0;
	*/

	void	clear()
	{
		m_tree.clear();
	}

/* -------------------------------------------------------------------------- */
/*                                observer                                    */
/* -------------------------------------------------------------------------- */

	/*
	** Return a copy of key comparaison object
	*/

	key_compare key_comp() const
	{
		return m_comp;
	}

	/*
	** Return a copy of value comparaison object : defined by value type as pair<key, setped type>
	** but the setped type part of the value is not taken iinto consideration in this comparaison.
	*/

	value_compare	value_comp() const
	{
		return m_comp;
	}


/* -------------------------------------------------------------------------- */
/*                                operation                                   */
/* -------------------------------------------------------------------------- */

/*
** searches element with a key and return an iterator if found, otherwize it returns an iterator
**	to set::end();
*/
	iterator	find(const value_type & key) const
	{
		return m_tree.find(key);
	}

/* 
**	This function only makes sense for multimaps; for set the result will
**		either be 0 (not present) or 1 (present).
*/

	size_type	count(const value_type & key) const
	{
		const_iterator	it = find(key);
		if (it == end())
			return 0;
		return 1;
	}
/*
** return iterator to lower bound : pointing to the first element in the container
**	 whose key is not considered to go before;
*/

	iterator	lower_bound(const value_type & key) const
	{
		return m_tree.lower_bound(key);
	}

/*
** return iterator to upper bound : first element whose key is considered to go after
**	key
*/

	iterator	upper_bound(const value_type & key) const
	{
		return iterator(m_tree.upper_bound(key));
	}


	ft::pair<iterator, iterator> equal_range(const value_type & key) const
	{	
		return ft::make_pair<iterator, iterator>(m_tree.lower_bound(key),m_tree.upper_bound(key));
	}

/* -------------------------------------------------------------------------- */
/*                                Allocator                                   */
/* -------------------------------------------------------------------------- */
	/*
	** return a copy of the memory allocator
	*/

		allocator_type	get_allocator() const 
		{
			return m_alloc;
		}
/* -------------------------------------------------------------------------- */
/*                                Display                                     */
/* -------------------------------------------------------------------------- */

	private:

		void	display()
		{
			m_tree.debug_print_btree_structure();
		}


	public:
	
	template <class Key_1, class Comp_1, class Alloc_1>
	friend bool operator==(const set<Key_1, Comp_1,Alloc_1>& x, const set<Key_1, Comp_1,Alloc_1>& y)
	{
		return (x.m_tree == y.m_tree);
	}

	template <class Key_1, class Comp_1, class Alloc_1>
	friend bool operator< (const set<Key_1, Comp_1,Alloc_1>& x, const set<Key_1, Comp_1,Alloc_1>& y)
	{
		return (x.m_tree < y.m_tree);
	}

	template <class Key_1, class Comp_1, class Alloc_1>
	friend bool operator!=(const set<Key_1, Comp_1,Alloc_1>& x, const set<Key_1, Comp_1,Alloc_1>& y)
	{
		return (x.m_tree != y.m_tree);
	}

	template <class Key_1, class Comp_1, class Alloc_1>
	friend bool operator> (const set<Key_1, Comp_1,Alloc_1>& x, const set<Key_1, Comp_1,Alloc_1>& y)
	{
		return (x.m_tree > y.m_tree);
	}

	template <class Key_1, class Comp_1, class Alloc_1>
	friend bool operator>=(const set<Key_1, Comp_1,Alloc_1>& x, const set<Key_1, Comp_1,Alloc_1>& y)
	{
		return (x.m_tree >= y.m_tree);
	}

	template <class Key_1, class Comp_1, class Alloc_1>
	friend bool operator<=(const set<Key_1, Comp_1,Alloc_1>& x, const set<Key_1, Comp_1,Alloc_1>& y)
	{
		return (x.m_tree <= y.m_tree);
	}

	// specialized algorithms:
	template <class Key_1, class Comp_1, class Alloc_1>
	friend void swap(set<Key_1, Comp_1,Alloc_1>& x, set<Key_1, Comp_1,Alloc_1>& y)
	{
		x.m_tree.swap(y.m_tree);
	}

};


} // end namespace ft


#endif
