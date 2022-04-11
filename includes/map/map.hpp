/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:02:34 by lvirgini          #+#    #+#             */
/*   Updated: 2022/04/11 17:12:39 by lvirgini         ###   ########.fr       */
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
	/*
	** TYPE
	*/

	public:
		typedef Key						key_type;
		typedef T						mapped_type;
		typedef Compare					key_compare;
		typedef ft::pair<const Key, T>	value_type;

		typedef Allocator				allocator_type;
		typedef typename allocator_type:: template rebind <value_type>::other	pair_alloc_type;
		typedef Rb_tree<value_type, Compare, pair_alloc_type>		tree_type;

		typedef typename Allocator::reference		reference;
		typedef typename Allocator::const_reference	const_reference;
		typedef typename Allocator::pointer			pointer;
		typedef typename Allocator::const_pointer	const_pointer;

		typedef ft::normal_iterator<pointer, map>		iterator;
		typedef ft::normal_iterator<const_pointer, map>	const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

	/* -------------------------------------------------------------------------- */

	private:
		Compare		_comp;
		tree_type	_tree;
		
	/* -------------------------------------------------------------------------- */
	/*                     Constructor Destructor                                  */
	/* -------------------------------------------------------------------------- */

	public:

	/*
	** Default constructor create an empty map.
	*/

		map()
		: _tree()
		{}


	/*
	** Create an empty map with comparaison and allocator.
	*/
		explicit map (const Compare & comp, const allocator_type & alloc = allocator_type())
		: _tree(alloc, comp)
		{};


	/*
	** Copy constructor : create a complete copy of tree.
	*/

		map(const map & copy)
		: _tree(copy._tree)
		{}


	/*
	** Create map from elements first to last.
	*/

		template <typename InputIterator>
		map(InputIterator first, InputIterator last)
		: _tree(first, last)
		{}


	/*
	** Create map from elements first to last with comparaison and/or allocator_type
	*/

		template <typename InputIterator>
		map(InputIterator first, InputIterator last, const Compare & comp, const allocator_type & alloc = allocator_type())
		: _tree(alloc, comp)
		{
			_tree.insert(first, last);
		}


	/*
	** Destructor:
	*/

		~map()
		{}

/* -------------------------------------------------------------------------- */
/*                         Assignation / modifiers                            */
/* -------------------------------------------------------------------------- */

	map	&	operator=(const map & other)
	{
		if (this != *other)
			_tree = other._tree;
		return *this;
	}






/* -------------------------------------------------------------------------- */
/*                                Iterator / getter                            */
/* -------------------------------------------------------------------------- */


	/*
	** return a copy of the memory allocator
	*/

		allocator_type	get_allocator() const 
		{
			return allocator_type(_tree.get_allocator());
		}

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
	** Return true if the map is empty.
	*/

	bool	empty() const 
	{
		return _tree.empty();
	}


/* -------------------------------------------------------------------------- */
/*                                Display                                     */
/* -------------------------------------------------------------------------- */


void	display()
{
	_tree.display();
}

};

/*

typedef implementation defined iterator; // See 23.1
typedef implementation defined const_iterator; // See 23.1
typedef implementation defined size_type; // See 23.1
typedef implementation defined difference_type;// See 23.1

typedef std::reverse_iterator<iterator> reverse_iterator;
typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

class value_compare
: public binary_function<value_type,value_type,bool> {
friend class map;
protected:
Compare comp;
value_compare(Compare c) : comp(c) {}
public:
bool operator()(const value_type& x, const value_type& y) const {
return comp(x.first, y.first);
}
};

// 23.3.1.1 construct/copy/destroy:
explicit map(const Compare& comp = Compare(),
const Allocator& = Allocator());
template <class InputIterator>
map(InputIterator first, InputIterator last,
const Compare& comp = Compare(), const Allocator& = Allocator());
map(const map<Key,T,Compare,Allocator>& x);
~map();
map<Key,T,Compare,Allocator>&
operator=(const map<Key,T,Compare,Allocator>& x);

// iterators:
iterator begin();
const_iterator begin() const;
iterator end();
const_iterator end() const;
reverse_iterator rbegin();
const_reverse_iterator rbegin() const;
reverse_iterator rend();
const_reverse_iterator rend() const;

// capacity:
bool empty() const;
size_type size() const;
size_type max_size() const;

// 23.3.1.2 element access:
T& operator[](const key_type& x);

// modifiers:
pair<iterator, bool> insert(const value_type& x);
iterator insert(iterator position, const value_type& x);
template <class InputIterator>
void insert(InputIterator first, InputIterator last);
void erase(iterator position);
size_type erase(const key_type& x);
void erase(iterator first, iterator last);
void swap(map<Key,T,Compare,Allocator>&);
void clear();

// observers:
key_compare key_comp() const;
value_compare value_comp() const;


// 23.3.1.3 map operations:
iterator find(const key_type& x);
const_iterator find(const key_type& x) const;
size_type count(const key_type& x) const;
iterator lower_bound(const key_type& x);
const_iterator lower_bound(const key_type& x) const;
iterator upper_bound(const key_type& x);
const_iterator upper_bound(const key_type& x) const;
pair<iterator,iterator>
equal_range(const key_type& x);
pair<const_iterator,const_iterator>
equal_range(const key_type& x) const;
};


template <class Key, class T, class Compare, class Allocator>
bool operator==(const map<Key,T,Compare,Allocator>& x,
const map<Key,T,Compare,Allocator>& y);
template <class Key, class T, class Compare, class Allocator>
bool operator< (const map<Key,T,Compare,Allocator>& x,
const map<Key,T,Compare,Allocator>& y);
template <class Key, class T, class Compare, class Allocator>
bool operator!=(const map<Key,T,Compare,Allocator>& x,
const map<Key,T,Compare,Allocator>& y);
template <class Key, class T, class Compare, class Allocator>
bool operator> (const map<Key,T,Compare,Allocator>& x,
const map<Key,T,Compare,Allocator>& y);
template <class Key, class T, class Compare, class Allocator>
bool operator>=(const map<Key,T,Compare,Allocator>& x,
const map<Key,T,Compare,Allocator>& y);
template <class Key, class T, class Compare, class Allocator>
bool operator<=(const map<Key,T,Compare,Allocator>& x,
const map<Key,T,Compare,Allocator>& y);
// specialized algorithms:
template <class Key, class T, class Compare, class Allocator>
void swap(map<Key,T,Compare,Allocator>& x,
map<Key,T,Compare,Allocator>& y);
}*/


} // end namespace ft


#endif
