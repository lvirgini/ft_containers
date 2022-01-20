/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:55:57 by lvirgini          #+#    #+#             */
/*   Updated: 2022/01/20 14:13:32 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.hpp"

void	test_vector(void)
{
	PRINT("TEST CONSTRUCTOR");

	std::vector<int>	std_v(5);
	ft::vector<int>		ft_v(5);

	print_all_value(std_v, ft_v);
	print_all_functions(std_v, ft_v);

	PRINT("test reserve() : for vector created with 5 capacity and no value :");

	try
	{
		std_v.reserve(-1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		ft_v.reserve(-1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}


	std_v.reserve(666);
	ft_v.reserve(666);

	std_v.reserve(0);
	ft_v.reserve(0);

	print_all_functions(std_v, ft_v);

// 	//PRINT(std_v.capacity());
// 	std_v.resize(100, 42);
// //	PRINT(std_v.capacity());
// //	std_v.resize(7, 42);
// 	PRINT(std_v.capacity());
// 	std_v.reserve(101);
// 	PRINT(std_v.capacity());

	//print_all_value(std_v, ft_v);
//	print_all_functions(std_v, ft_v);

//	PRINT(std_v.capacity());
//	std_v.resize(5, 3);

	PRINT(SEP_FUNCTIONS);

}
