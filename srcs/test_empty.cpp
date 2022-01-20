/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_empty.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:05:53 by lvirgini          #+#    #+#             */
/*   Updated: 2022/01/19 13:55:25 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.hpp"


void	test_empty(void)
{
	PRINT("TESTING EMPTY VECTOR ");

	std::vector<int>	stdEmpty;
	ft::vector<int>		ftEmpty;

	// AT()
	std::cout << std::endl << "vector.at()" << std::endl;
	try
	{
		ftEmpty.at(156) = 45;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		stdEmpty.at(156) = 45;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	print_all_value(stdEmpty, ftEmpty);
	print_all_functions(stdEmpty, ftEmpty);

	

	// TESTING ASSIGNEMENT : 
	// std::cout << "TESTING ASSIGN()" << std::endl;


	// stdEmpty.assign(5, 10);
	// stdEmpty.assign(2, 10);
	// stdEmpty.assign(3, 10);
	// stdEmpty.resize(4, 45);

	// ftEmpty.assign(5, 10);

	PRINT(SEP_FUNCTIONS);
}
