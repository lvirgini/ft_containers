/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:02:34 by lvirgini          #+#    #+#             */
/*   Updated: 2022/04/24 12:14:54 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "pair.hpp"
# include "RedBlackTree.hpp"

/*
23.3.1 Template class map [lib.map]
1 A map is a kind of associative container that supports unique keys (contains at most one of each key value)
and provides for fast retrieval of values of another type T based on the keys. Map supports bidirectional
iterators.
2 A map satisfies all of the requirements of a container and of a reversible container (23.1) and of an associative container (23.1.2). A map also provides most operations described in (23.1.2) for unique keys. This
means that a map supports the a_uniq operations in (23.1.2) but not the a_eq operations. For a
map<Key,T> the key_type is Key and the value_type is pair<const Key,T>. Descriptions
are provided here only for operations on map that are not described in one of those tables or for operations
where there is additional semantic information.
*/

namespace ft
{

template < typename Key, typename T, typename Compare = ft::less<Key>, class Allocator = std::allocator< ft::pair<const Key, T> > >
class map
{
/* -------------------------------------------------------------------------- */
	/* Member type	*/
	public:
		typedef Key						key_type;
		typedef T						mapped_type;
		typedef Compare					key_compare;
		typedef ft::pair<const Key, T>	value_type;
		typedef Allocator				allocator_type;
		
		
		class value_compare : public std::binary_function <value_type,value_type,bool>
		{
			friend class map;
			
			protected:
				Compare comp;
			
			explicit value_compare(Compare c) 
			: comp(c) {}
	
		public:
			bool operator()(const value_type& x, const value_type& y) const 
			{
				return comp(x.first, y.first);
			}
		};
		
	private:
		typedef typename allocator_type:: template rebind <value_type>::other	_pair_alloc_type;
		typedef Rb_tree<value_type, value_compare, _pair_alloc_type>		_tree_type;
		typedef map<Key, T, Compare, Allocator>								self;

	public:
		typedef typename _pair_alloc_type::reference		reference;
		typedef typename _pair_alloc_type::const_reference	const_reference;
		typedef typename _pair_alloc_type::pointer			pointer;
		typedef typename _pair_alloc_type::const_pointer	const_pointer;

		typedef typename _tree_type::size_type				size_type;
		typedef typename _tree_type::difference_type		difference_type;
		typedef typename _tree_type::iterator				iterator;
		typedef typename _tree_type::const_iterator			const_iterator;
		typedef typename _tree_type::reverse_iterator		reverse_iterator;
		typedef typename _tree_type::const_reverse_iterator	const_reverse_iterator;

	/* -------------------------------------------------------------------------- */

	
	private:
		allocator_type	_alloc;
		value_compare	_value_comp;
		key_compare		_key_comp;
		_tree_type		_tree;
		
	/* -------------------------------------------------------------------------- */
	/*                     Constructor Destructor                                  */
	/* -------------------------------------------------------------------------- */

	public:

	/*
	** Default constructor create an empty map.
	** Create an empty map with comparaison and allocator.
	*/
		explicit map (const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type())
		: _alloc(alloc), _value_comp(value_compare(comp)), _key_comp(comp), _tree(value_compare(comp), _pair_alloc_type(alloc))
		{}

	/*
	** Copy constructor : create a complete copy of each element in copy.tree.
	*/

		map(const self & copy)
		: _alloc(copy._alloc), _value_comp(copy._value_comp), _key_comp(copy._key_comp), _tree(copy._tree)
		{}

	/*
	** Create map from elements first to last with comparaison and/or allocator_type
	*/

		template <typename InputIterator>
		map(InputIterator first, InputIterator last, const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type(),
		typename ft::enable_if<!ft::is_integer<InputIterator>::value, InputIterator>::type * = NULL )
		: _alloc(alloc), _value_comp(value_compare(comp)), _key_comp(comp), _tree(first, last, value_compare(comp), _pair_alloc_type(alloc))
		{}

	/*
	** Destructor:
	*/

		~map()
		{}

/* -------------------------------------------------------------------------- */
/*                         Assignation / Element access                        */
/* -------------------------------------------------------------------------- */

	/*
	** call operator= of tree: clear tree and copie all the element from other into this tree.
	*/

		map	&	operator=(const map<Key, T, Compare, Allocator> & other)
		{
			if (this != &other)
				_tree = other._tree;
			return *this;
		}

	/*
	** if key exist: return a reference to the corresponding mapped_type.
	** else insert a new element with that key and default mapped_value;
	*/

		mapped_type & operator[](const key_type & key)
		{
			return (*((this->insert(ft::make_pair(key,mapped_type()))).first)).second;
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
			return _tree.begin();
		}

		const_iterator	begin() const
		{
			return _tree.begin();
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
			return _tree.end();
		}

		const_iterator	end() const
		{
			return _tree.end();
		}

	/*
	** rend()
	**		Return reverse iterator to reverse beginning:
	**		pointing to the last element in the container. iterate backwards.
	*/

		reverse_iterator	rbegin()
		{
			return _tree.rbegin();
		}

		const_reverse_iterator rbegin() const
		{
			return _tree.rbegin();
		}

		reverse_iterator	rend()
		{
			return _tree.rend();
		}

		const_reverse_iterator	rend() const
		{
			return _tree.rend();
		}

/* -------------------------------------------------------------------------- */
/*                                Capacity                                    */
/* -------------------------------------------------------------------------- */

	/*
	** empty()
	**		Return true if the map is empty.
	*/

		bool	empty() const 
		{
			return _tree.empty();
		}

	/*
	**	size()
	**		Return current size : the number of elements in the tree
	*/

		size_type size() const
		{
			return _tree.size();
		}

	/*
	**	max_size()
	**		Returns the maximum number of elements that the vector can hold.
	*/

		size_type	max_size() const
		{
			return _tree.max_size();
		}
	
/* -------------------------------------------------------------------------- */
/*                            Modifiers                                       */
/* -------------------------------------------------------------------------- */

	/*
	** insert single element
	*/

		ft::pair<iterator, bool>	insert(const value_type & x)
		{
			return _tree.insert(x);
		}

	/*
	** insert single element with position for max efficiency if value position
	**	is just before insert value. 
	*/
		iterator insert(iterator position, const value_type & x)
		{
			(void) position;
			return (_tree.insert(x)).first;
		}

	/*
	** insert a range of elements between [first to last]
	*/

		template <typename InputIterator>
		void	insert(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integer<InputIterator>::value, InputIterator>::type * = NULL )
		{
				_tree.insert(first, last);
		}

	/*
	** removes from the tree a single element at position
	*/

		void	erase(iterator position)
		{
				_tree.erase(position);
		}

	/*
	** removes from the tree a single element with key (key)
	**	return the number of element erased.
	*/

		size_type	erase(const key_type & key)
		{
			iterator	it = find(key);
			if (it != end())
			{
				_tree.erase(it);
				return (1);
			}	
			return (0);
		}

	/*
	** erase all element between [first to last].
	*/
		void erase(iterator first, iterator last)
		{
			_tree.erase(first, last);
		}

		void swap (map<Key, T, Compare, Allocator> & other)
		{
		_tree.swap(other._tree);
		}

	/*
	** Removes all element from the map which is destroyed, leaving the container 
	**	with the size of 0;
	*/

		void	clear()
		{
			_tree.clear();
		}

/* -------------------------------------------------------------------------- */
/*                                observer                                    */
/* -------------------------------------------------------------------------- */

	/*
	** Return a copy of key comparaison object
	*/

		key_compare key_comp() const
		{
			return _key_comp;
		}

	/*
	** Return a copy of value comparaison object : defined by value type as pair<key, mapped type>
	** but the mapped type part of the value is not taken iinto consideration in this comparaison.
	*/

		value_compare	value_comp() const
		{
			return _value_comp;
		}

/* -------------------------------------------------------------------------- */
/*                                operation                                   */
/* -------------------------------------------------------------------------- */

	/*
	** searches element with a key and return an iterator if found, otherwize it returns an iterator
	**	to map::end();
	*/
		iterator	find(const key_type & key)
		{
			return _tree.find(ft::make_pair<key_type, mapped_type>(key, mapped_type()));
		}

		const_iterator	find(const key_type & key) const
		{
			return _tree.find(ft::make_pair<key_type, mapped_type>(key, mapped_type()));
		}

	/*  
	**	This function only makes sense for multimaps; for map the result will
	**		either be 0 (not present) or 1 (present).
	*/

		size_type	count(const key_type & key) const
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

		iterator	lower_bound(const key_type & key)
		{
			return _tree.lower_bound(ft::make_pair<key_type, mapped_type>(key, mapped_type()));
		}

		const_iterator	lower_bound(const key_type & key) const
		{
			return _tree.lower_bound(ft::make_pair<key_type, mapped_type>(key, mapped_type()));
		}

	/*
	** return iterator to upper bound : first element whose key is considered to go after
	**	key
	*/

		iterator	upper_bound(const key_type & key)
		{
			return _tree.upper_bound(ft::make_pair<key_type, mapped_type>(key, mapped_type()));
		}

		const_iterator	upper_bound(const key_type & key) const
		{
			return _tree.upper_bound(ft::make_pair<key_type, mapped_type>(key, mapped_type()));
		}

	/*
	**	equal range : return pair(lower_bound(key), upper_bound(key))
	*/

		ft::pair<iterator, iterator> equal_range(const key_type & key)
		{	
			return ft::make_pair<iterator, iterator>(lower_bound(key), upper_bound(key));
		}

		ft::pair<const_iterator, const_iterator> equal_range(const key_type & key) const
		{
			return ft::make_pair<const_iterator, const_iterator>(lower_bound(key), upper_bound(key));
		}
/* -------------------------------------------------------------------------- */
/*                                Allocator                                   */
/* -------------------------------------------------------------------------- */

	/*
	** return a copy of the memory allocator
	*/

		allocator_type	get_allocator() const 
		{
			return allocator_type(_tree.get_allocator());
		}
/* -------------------------------------------------------------------------- */
/*                                Display for debug                           */
/* -------------------------------------------------------------------------- */

	private:
		void	display()
		{
			_tree.debug_print_btree_structure();
		}

/* -------------------------------------------------------------------------- */
/*                                operator                                     */
/* -------------------------------------------------------------------------- */
	public:


template <class Key_1, class T_1, class Comp_1, class Alloc_1>
friend bool operator==(const map<Key_1,T_1,Comp_1,Alloc_1>& x, const map<Key_1,T_1,Comp_1,Alloc_1>& y)
{
	return (x._tree == y._tree);
}

template <class Key_1, class T_1, class Comp_1, class Alloc_1>
friend bool operator< (const map<Key_1,T_1,Comp_1,Alloc_1>& x, const map<Key_1,T_1,Comp_1,Alloc_1>& y)
{
	return (x._tree < y._tree);
}

template <class Key_1, class T_1, class Comp_1, class Alloc_1>
friend bool operator!=(const map<Key_1,T_1,Comp_1,Alloc_1>& x, const map<Key_1,T_1,Comp_1,Alloc_1>& y)
{
	return (x._tree != y._tree);
}

template <class Key_1, class T_1, class Comp_1, class Alloc_1>
friend bool operator> (const map<Key_1,T_1,Comp_1,Alloc_1>& x, const map<Key_1,T_1,Comp_1,Alloc_1>& y)
{
	return (x._tree > y._tree);
}

template <class Key_1, class T_1, class Comp_1, class Alloc_1>
friend bool operator>=(const map<Key_1,T_1,Comp_1,Alloc_1>& x, const map<Key_1,T_1,Comp_1,Alloc_1>& y)
{
	return (x._tree >= y._tree);
}

template <class Key_1, class T_1, class Comp_1, class Alloc_1>
friend bool operator<=(const map<Key_1,T_1,Comp_1,Alloc_1>& x, const map<Key_1,T_1,Comp_1,Alloc_1>& y)
{
	return (x._tree <= y._tree);
}

// specialized algorithms:
template <class Key_1, class T_1, class Comp_1, class Alloc_1>
friend void swap(map<Key_1,T_1,Comp_1,Alloc_1>& x, map<Key_1,T_1,Comp_1,Alloc_1>& y)
{
	x._tree.swap(y._tree);
}



};


} // end namespace ft


#endif
