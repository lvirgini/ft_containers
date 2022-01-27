/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_erase.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:42:33 by lvirgini          #+#    #+#             */
/*   Updated: 2022/01/27 20:20:53 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.hpp"

void	test_erase(void)
{
	PRINT("TEST ERASE");

	M_NAMESPACE::vector<int>	v(10);

	for (int i = 0; i < 10; i++)
		v[i] = i * 11;

	print_all_value(v);
	print_all_functions(v);

	PRINT("erase( end() - 1");
	v.erase(v.end() -1);
	print_all_value(v);
	print_all_functions(v);

	PRINT("erase( begin()");
	v.erase(v.end() -1);
	print_all_value(v);
	print_all_functions(v);

// 	PRINT("TEST VECTOR.ERASE");
// 	std::vector<int>	std_insert(10, 10);
// 	ft::vector<int>		ft_insert(10, 10); 

// 	//std_insert.push_back(77);
// 	// std_insert.push_back(77);

// 	std::vector<int>::iterator 	std_it_erase = std_insert.erase(std_insert.end() - 5, std_insert.end());
// 	ft::vector<int>::iterator 	ft_it_erase = ft_insert.erase(ft_insert.end() - 5, ft_insert.end());

// 	std_insert.back() = 22;
// 	ft_insert.back() = 22;

// 	std_it_erase = std_insert.erase(std_insert.end() - 1);
// 	ft_it_erase = ft_insert.erase(ft_insert.end() - 1);	


// 	std::cout << "Erase medium data" << std::endl << *std_it_erase << std::endl;
// 	std::cout << *ft_it_erase << std::endl;


// //  std_insert.insert(std_insert.end(), 5);
// //  std_insert.insert(std_insert.end(), 5);


// //std_insert.clear();
// //std_insert.insert(std_insert.end() - 2, 44);

// 	std_insert.front() = 55;
// 	ft_insert.front() = 55;

// 	std_insert.back() = 22;
// 	ft_insert.back() = 22;

// 	std_insert.pop_back();
// 	ft_insert.pop_back();

// 	std_insert.clear();
// 	ft_insert.clear();

// 	 print_all_functions(std_insert, ft_insert);
// 	print_all_value(std_insert, ft_insert);

	PRINT(SEP_FUNCTIONS);
}
