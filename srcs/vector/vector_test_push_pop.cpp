/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_push_pop.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:52:50 by lvirgini          #+#    #+#             */
/*   Updated: 2022/01/30 17:34:25 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.hpp"

void	vector_test_push_pop(void)
{
	PRINT("TESTING PUSH POP");

	M_NAMESPACE::vector<int>	v;

	std::cout << "pop empty vector : segfault" << std::endl;
	// M_NAMESPACE::vector<int>	empty;
	// empty.pop_back();
	// print_all_functions(empty);
	// print_all_value(empty);


	std::cout << "push 42" << std::endl;
	v.push_back(42);
	print_vector(v);

	std::cout << "only one value : pop back : " << std::endl;
	v.pop_back();
	print_vector(v);

	std::cout << "push 42 * 2" << std::endl;
	v.push_back(42);
	v.push_back(42);
	print_vector(v);

	std::cout << "push sequence [0 to 9]" << std::endl;

	for (int i = 0; i < 10; i++)
		v.push_back(i);
	print_vector(v);

	std::cout << "pop * 10" << std::endl;

	for (int i = 0; i < 10; i++)
		v.pop_back();
	print_vector(v);

	std::cout << "pop * 2 : return to empty" << std::endl;

	for (int i = 0; i < 2; i++)
		v.pop_back();
	print_vector(v);

	PRINT(SEP_FUNCTIONS);
}
