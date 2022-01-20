/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.tpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:07:36 by lvirgini          #+#    #+#             */
/*   Updated: 2022/01/19 13:28:55 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.hpp"


template <typename T>
void	print_all_functions(std::vector<T> & STD, ft::vector<T> & FT)
{
	
	std::string			sep = " | ";


	// std::cout << std::endl << "vector.maxSize()" << std::endl;
	// std::cout << STD.max_size() << sep << FT.max_size() << std::endl;

	// SIZE()
	std::cout << std::endl << "vector.size() : " << std::endl << "std | ft" << std::endl; 
	std::cout << STD.size() << sep << FT.size() << std::endl;


	// capacity()
	std::cout << std::endl << "vector.capacity()" << std::endl << "std | ft" << std::endl; 
	std::cout << STD.capacity() << sep << FT.capacity() << std::endl;


	//empty()
	std::cout << std::endl << "vector.empty()" << std::endl << "std | ft" << std::endl; 
	std::cout << STD.empty() << sep << FT.empty() << std::endl;
}


template <typename T>
void	print_all_value(std::vector<T> & v)
{
	int i = 0;
	typename std::vector<T>::iterator 	std_it = v.begin();
	typename std::vector<T>::iterator 	std_ite = v.end();

	while (std_it != std_ite)
	{
		std::cout << i++ << "	value = " << *std_it << std::endl;
		std_it++;
	}
	std::cout << std::endl;

}

template <typename T>
void	print_all_value(ft::vector<T> & v)
{
	int i = 0;
	typename ft::vector<T>::iterator 	std_it = v.begin();
	typename ft::vector<T>::iterator 	std_ite = v.end();

	while (std_it != std_ite)
	{
		std::cout << i++ << "	value = " << *std_it << std::endl;
		std_it++;
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

