/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test_vector.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:55:57 by lvirgini          #+#    #+#             */
/*   Updated: 2022/05/03 12:17:05 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.hpp"

void	vector_test_vector(void)
{
	int test[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};


	PRINT("TEST CONSTRUCTOR");

	std::vector<int>	std_v(5);
	ft::vector<int>		ft_v(5);

	print_all_value(std_v, ft_v);
	print_all_functions(std_v, ft_v);

	PRINT("test reserve() : for vector created with 5 capacity and no value :");


	// PRINT("try reserve(-1)");
	// try
	// {
	// 	std_v.reserve(-1);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }

	// try
	// {
	// 	ft_v.reserve(-1);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }

	PRINT("reserve(666)");
	std_v.reserve(666);
	ft_v.reserve(666);

	PRINT("reserve(0)");
	std_v.reserve(0);
	ft_v.reserve(0);

	print_all_functions(std_v, ft_v);

	PRINT("resize(5)");
	std_v.resize(5);
	ft_v.resize(5);

	print_all_functions(std_v, ft_v);
	print_all_value(std_v, ft_v);

	PRINT("resize(3)");
	std_v.resize(3);
	ft_v.resize(3);

	print_all_functions(std_v, ft_v);
	print_all_value(std_v, ft_v);

	PRINT("resize(8)");
	std_v.resize(8, 5);
	ft_v.resize(8, 5);

	print_all_functions(std_v, ft_v);
	print_all_value(std_v, ft_v);



	std::vector<int>::iterator i_std = std_v.insert(std_v.end(), 42);
	ft::vector<int>::iterator i_ft = ft_v.insert(ft_v.end(), 42);

	std::cout << *i_std << SEP << *i_ft << std::endl;

	print_all_functions(std_v, ft_v);
	print_all_value(std_v, ft_v);

	PRINT("TESTING assign()");

	std_v.assign(5, 123);
	ft_v.assign(5, 123);
	print_all_functions(std_v, ft_v);
	print_all_value(std_v, ft_v);


	std_v.assign(0, 123);
	ft_v.assign(0, 123);
	print_all_functions(std_v, ft_v);
	print_all_value(std_v, ft_v);


	std_v.insert(std_v.begin(), test, test + 10);
	ft_v.insert(ft_v.begin(), test, test + 10);
	print_all_functions(std_v, ft_v);
	print_all_value(std_v, ft_v);


	PRINT(std_v.capacity());
	std_v.resize(100, 42);
	PRINT(std_v.capacity());
	std_v.resize(7, 42);
	PRINT(std_v.capacity());
	std_v.reserve(101);
	PRINT(std_v.capacity());

	print_all_value(std_v, ft_v);
	print_all_functions(std_v, ft_v);

	PRINT(std_v.capacity());
	std_v.resize(5, 3);


	M_NAMESPACE::vector<int> foo (3,0);
	M_NAMESPACE::vector<int> bar (5,0);

	bar = foo;
	foo = M_NAMESPACE::vector<int>();

	std::cout << "Size of foo: " << int(foo.size()) << '\n';
	std::cout << "Size of bar: " << int(bar.size()) << '\n';
	PRINT(SEP_FUNCTIONS);

}
