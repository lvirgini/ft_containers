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
	struct less : public std::binary_function<T, T, bool>
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
	struct Node
	{
		typedef Node *			pointer;
		typedef const Node *	const_pointer;
		typedef Node &			reference;
		typedef const Node &	const_reference;
		typedef Value			value_type;
		typedef Value &			value_reference;
		typedef value_type *	value_pointer;

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


		bool		is_sentinel()
		{
			if (this->parent == NULL)
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

		pointer		increment()
		{
			pointer	result = this;

			if (result->right != NULL)
				return result->right->get_most_left();
			while (result->is_right())
				result = result->parent;
			return result->parent;
		}

		pointer		decrement()
		{
			pointer	result = this;

			if (result->left != NULL)
				return result->left->get_most_right();
			while (result->is_left())
				result = result->parent;
			if (result->is_sentinel())
				return result;
			return result->parent;
		}

		pointer		get_most_left()
		{
			pointer	result = this;

			while (result->left != NULL)
				result = result->left;
			return (result);
		}

		const_pointer		get_most_left() const //
		{
			const_pointer	result = this;

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

		value_pointer	get_value_pointer() ////
		{
			return &data;
		}

		value_reference		operator*()
		{
			return data;
		}

		value_pointer		operator->()
		{
			return &data;
		}

		reference		operator++()
		{
			reference tmp = *this;
			this->increment();
			return *tmp;
		}

		reference		operator++(int)
		{
			this->increment();
			return *this;
		}


	};

} // end namespace ft

#endif
