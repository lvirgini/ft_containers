/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:11:19 by lvirgini          #+#    #+#             */
/*   Updated: 2022/03/22 10:23:11 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_NODE_HPP
# define TREE_NODE_HPP


namespace ft
{
	enum rb_tree_color
	{
		RED,
		BLACK
	};


	template <typename Value>
	struct Node
	{
		// typedef ft::Node		pointer;
		// typedef const ft::Node	const_pointer;

		typedef Node *			pointer;
		typedef const Node *	const_pointer;
		typedef Node &			reference;
		typedef const Node &	const_reference;
		typedef Value			value_type;

		rb_tree_color	color;
		pointer			parent;
		pointer			left;
		pointer			right;
		value_type		data;
	
		
	/* -------------------------------------------------------------------------- */
	/*                     Constructor Destructor                                 */
	/* -------------------------------------------------------------------------- */
	
		Node()
		: color(BLACK), parent(NULL), left(NULL), right(NULL), data()
		{};

		Node(const value_type & o_data, pointer o_parent = NULL, pointer o_left = NULL, pointer o_right = NULL)
		: color(RED), parent(o_parent), left(o_left), right(o_right), data(o_data)
		{};


		~Node()
		{};

		
		Node(const_reference copy)
		: color(copy.color), parent(copy.parent), left(copy.left), right(copy.right), data(copy.data)
		{
			this = copy;
		}

		reference		operator=(const_reference other)
		{
			if (this != &other)
			{
				this->parent = other.parent;
				this->left = other.left;
				this->right = other.right;
				this->data = other.data;
				this->color = other.color;
			}
			return *this ;
		}


		bool		is_left()
		{
			if (this->parent != NULL && this->parent->left == this)
				return true ;
			return false ;
		}

		bool		is_right()
		{
			if (this->parent != NULL && this->parent->right == this)
				return (true);
			return (false);
		}


		void	print()
		{
			std::cout << data.first << " " << data.second << std::endl;
		}



		// reference	get_aunt()
		// {
		// 	if (this->parent != NULL && this->parent->parent != NULL)
		// 	{
		// 		if this->parent.is
		// 	}
		// }


		// is left
		// is right
		// has aunt
		// get aunt
		// get sister

		// increment
		// {
			
		// 	if (this.right != NULL)
		// 	{
		// 		this = get_most_left();
		// 		return this;
		// 	}
		// 	if this._is_left()
		// 	{
		// 		this = this.parent;
		// 		return this;
		// 	}
		// 	if (this.right == NULL)
		// 	{
		// 		if this has_parent() && this is_right()
		// 			this = this.parent.
		// 		return (this.increment())
		// 	}

		// }

		// pointer		_increment()
		// {
		// 	if (this->right != NULL)
		// 	{
		// 		this = _get_most_left();
		// 		return (this);
		// 	}
		// 	if (this.parent != NULL && this._is_left())
		// 	{
		// 		this = this->parent;
		// 		return (this);
		// 	}
		// 	while (this._is_right())
		// 		this = this->parent;
		// 	return (this);

		// }


		// pointer		_increment()
		// {
		// 	if (this->right != NULL)
		// 	{
		// 		while (this->left != NULL)
		// 			this = this->left;
		// 	}
		// 		// this = this->right->_get_most_left();
		// 	else
		// 	{
		// 		while (this->is_right())
		// 			this = this->parent;
		// 		this = this->parent;
		// 	}
		// 	return (this);
		// }

		
		pointer		_increment()
		{
			pointer	result = this;

			if (result->right != NULL)
				return result->right->_get_most_left();
			while (result->is_right())
				result = result->parent;
			return result->parent;
		}

		pointer		_get_most_left()
		{
			pointer	result = this;

			while (result->left != NULL)
				result = result->left;
			return (result);
		}

		void		set_parent(pointer o_parent)
		{
			this->parent = o_parent;
		}

		void		set_left(pointer o_left)
		{
			this->left = o_left;
		}

		void		set_right(pointer o_right)
		{	
			this->right = o_right;
		}

		
		// begin = most_left from root
		// end = most right fromm root




		// decrement



	};






} // end namespace ft



#endif

