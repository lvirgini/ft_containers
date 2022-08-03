/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test_assign.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 13:24:56 by lvirgini          #+#    #+#             */
/*   Updated: 2022/04/23 18:26:26 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.hpp"

void	vector_test_assign(void)
{
	PRINT("TESTING ASSIGN()");

	M_NAMESPACE::vector<int>	v;
	M_NAMESPACE::vector<int>	v2;

	int		tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	std::cout << "assign (0, 42) to an emplty vector" << std::endl;
	v2.assign(0, 42);
	print_vector(v2);


	std::cout << "assign (5, 42) to an emplty vector" << std::endl;
	v.assign(5, 42);
	print_vector(v);


	std::cout << "assign (1, 55) " << std::endl;
	v.assign(1, 55);
	print_vector(v);

	std::cout << "assign (4, 44) " << std::endl;
	v.assign(4, 44);
	print_vector(v);

	std::cout << "assign (6, 66) " << std::endl;
	v.assign(6, 66);
	print_vector(v);

	std::cout << "assign (0, 77) " << std::endl;
	v.assign(0, 77);
	print_vector(v);

	std::cout << "assign [0 to 4]" << std::endl;
	v.assign(tab, tab + 5);
	print_vector(v);

	std::cout << "assign [8 to 9]" << std::endl;
	v.assign(tab + 8, tab + 10);
	print_vector(v);

	std::cout << "assign [0 to 9]" << std::endl;
	v.assign(tab, tab + 10);
	print_vector(v);

	std::cout << "try assign [1 to 0] : throw an exception" << std::endl;
	try
	{
		v.assign(tab + 1, tab);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "try assign (-1, -42) : throw an exception" << std::endl;
	try
	{
		v.assign(-1, 42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}



	print_vector(v);

	std::cout << "assign [0 to 0]" << std::endl;
	v.assign(tab, tab);
	print_vector(v);

	PRINT(SEP_FUNCTIONS);

}
