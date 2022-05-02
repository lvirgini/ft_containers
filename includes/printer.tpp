/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.tpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:07:36 by lvirgini          #+#    #+#             */
/*   Updated: 2022/05/02 12:25:12 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.hpp"


template <typename T>
void	print_all_functions(std::vector<T> & STD, ft::vector<T> & FT)
{
	// SIZE()
	std::cout <<  "vector.size()		"; 
	std::cout << STD.size() << SEP << FT.size() << std::endl;

	// capacity()
	std::cout << "vector.capacity()	"; 
	std::cout << STD.capacity() << SEP << FT.capacity() << std::endl;

	//empty()
	std::cout << "vector.empty()		"; 
	std::cout << STD.empty() << SEP << FT.empty() << std::endl;
}


template <typename T>
void	print_all_functions(M_NAMESPACE::vector<T> & v)
{
	// SIZE()
	std::cout << "vector.size()		"; 
	std::cout << v.size() << std::endl;

	// capacity()
	std::cout << "vector.capacity()	"; 
	std::cout << v.capacity() << std::endl;

	//empty()
	std::cout << "vector.empty()		"; 
	std::cout << v.empty() << std::endl;
}


template <typename T>
void	print_all_value(M_NAMESPACE::vector<T> & v)
{
	int i = 0;
	typename M_NAMESPACE::vector<T>::iterator 	it = v.begin();
	typename M_NAMESPACE::vector<T>::iterator 	ite = v.end();

	while (it != ite)
	{
		std::cout << i++ << "	value = " << *it << std::endl;
		it++;
	}
	std::cout << std::endl;

}

template <typename T>
void	print_all_value(std::vector<T> & STD, ft::vector<T> & FT)
{
	typename ft::vector<T>::iterator 	ft_it = FT.begin();
	typename ft::vector<T>::iterator 	ft_ite = FT.end();

	typename std::vector<T>::iterator 	std_it = STD.begin();
	typename std::vector<T>::iterator 	std_ite = STD.end();

	std::string	sep = " | ";
	int i = 0;

	while (std_it != std_ite || ft_it != ft_ite)
	{
		std::cout << i << "	value = "; 
		if (std_it != std_ite)
		{
			std::cout << *std_it;
			std_it++;
		}
		std::cout << sep;
		if (ft_it != ft_ite)
		{
			std::cout << *ft_it;
			ft_it++;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

template <typename T>
void	print_vector(M_NAMESPACE::vector<T> & v)
{
	print_all_functions(v);
	print_all_value(v);
}
