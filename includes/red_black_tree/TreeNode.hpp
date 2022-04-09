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

	enum rb_tree_color
	{
		RED,
		BLACK
	};


	template <typename Value >
	// template <typename Value, typename Compare = ft::less< Value> >
	struct Node
	{
		typedef Node *			pointer;
		typedef const Node *	const_pointer;
		typedef Node &			reference;
		typedef const Node &	const_reference;
		typedef Value			value_type;

		bool			color;
		pointer			parent;
		pointer			left;
		pointer			right;
		value_type		data;
	
		
	/* -------------------------------------------------------------------------- */
	/*                     Constructor Destructor                                 */
	/* -------------------------------------------------------------------------- */
	
		// Node()
		// : color(BLACK), parent(NULL), left(NULL), right(NULL), data()
		// {}

		Node(const value_type & o_data, pointer o_parent = NULL, pointer o_left = NULL, pointer o_right = NULL)
		: color(RED), parent(o_parent), left(o_left), right(o_right), data(o_data)
		{}


		~Node()
		{}

		
		Node(const_reference copy)
		: color(copy.color), parent(copy.parent), left(copy.left), right(copy.right), data(copy.data)
		{}

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


		// bool			operator<(const_reference other)
		// {
		// 	return comp(this->data, other.data);
		// }


		bool		is_left()
		{
			if (this->parent != NULL && this->parent->left == this)
				return true ;
			return false ;
		}

		bool		is_right()
		{
			if (this->parent != NULL && this->parent->right == this)
				return true;
			return false;
		}


		void	print()
		{
			std::cout << "THIS = " << this->data.first << " " << (color ? "black" : "red");
			if (this->parent == NULL)
				std::cout << " is root" << std::endl;
			else if (is_left())
				std::cout << " is left" << std::endl;
			else
				std::cout << " is right" << std::endl;
			if (this->parent)
				std::cout << "parent = " << this->parent->data.first << std::endl;
			if (this->get_sister() != NULL)
				std::cout << "sister = " << this->get_sister()->data.first << std::endl;
			if (left)
				std::cout << "left = " << this->left->data.first << std::endl;
			if (right)
				std::cout << "right = " << this->right->data.first << std::endl;
			std::cout << std::endl;
		}

		// void	print(int	generation = 0)
		// {
		// 	pointer	sister = get_sister();
			
		// 	if (parent != NULL)
		// 	{
		// 		parent->print(generation + 1);
		// 		// if (parent->is_right())
		// 		// {
		// 		// 	for (int i = 0; i < (generation + 1) *2; i++)
		// 		// 		std::cout << "	";
		// 		// }
		// 	}	
		// 	for (int i = 0; i <= generation; i++)
		// 		std::cout << "	";
		// 	if (parent == NULL || is_left())
		// 		std::cout << data.first;
		// 	else if (sister != NULL)
		// 		std::cout << sister->data.first;
		// 	for (int i = 0; i <= generation; i++)
		// 		std::cout << "	";
		// 	if (is_right())
		// 		std::cout << data.first;
		// 	else if (sister != NULL)
		// 		std::cout << sister->data.first;
		// 	std::cout << std::endl;
		// 	if (is_right() && generation != 0)
		// 	{
		// 		for (int i = 0; i <= generation * 2; i++)
		// 		std::cout << "	";
		// 	}
		// }



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

		
		pointer		increment()
		{
			pointer	result = this;

			if (result->right != NULL)
				return result->right->get_most_left();
			while (result->is_right())
				result = result->parent;
			return result->parent;
		}

		pointer		get_most_left()
		{
			pointer	result = this;

			while (result->left != NULL)
				result = result->left;
			return (result);
		}

		pointer		get_most_right()
		{
			pointer result = this;

			while (result->right != NULL)
				result = result->right;
			return (result);
		}


		pointer		get_sister()
		{
			if (this->parent == NULL)
				return (NULL);
			if (this->is_left())
				return (this->parent->right);
			else
				return (this->parent->left);	
		}


		pointer		get_aunt()
		{

			if (this->parent == NULL)
				return (NULL);
			return this->parent->get_sister();
		}


		pointer	get_grand_parent()
		{
			if (this->parent != NULL)
				return (this->parent->parent);
			return (NULL);
		}

		// void		set_parent(pointer o_parent)
		// {
		// 	this->parent = o_parent;
		// }

		// void		set_left(pointer o_left)
		// {
		// 	this->left = o_left;
		// }

		// void		set_right(pointer o_right)
		// {	
		// 	this->right = o_right;
		// }
	};

} // end namespace ft

#endif
