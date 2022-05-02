/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test_erase.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:42:33 by lvirgini          #+#    #+#             */
/*   Updated: 2022/05/02 15:41:35 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.hpp"

void	vector_test_erase(void)
{
	PRINT("TEST ERASE");

	M_NAMESPACE::vector<int>	v(10);

	for (int i = 0; i < 10; i++)
		v[i] = i * 11;

	print_vector(v);

	PRINT("erase( end() - 1");
	v.erase(v.end() -1);
	print_vector(v);

	PRINT("erase( begin()");
	v.erase(v.begin());
	print_vector(v);

	PRINT("erase( begin() + 5");
	v.erase(v.begin() + 5);
	print_vector(v);

	PRINT("erase( begin() + 5, end()");
	v.erase(v.begin() + 5, v.end());
	print_vector(v);

	PRINT("erase( begin(), begin() + 2");
	v.erase(v.begin(), v.begin() + 2);
	print_vector(v);

	PRINT("TEST VECTOR.ERASE");
	M_NAMESPACE::vector<int>	vector2(10, 10);

	vector2.push_back(77);

	M_NAMESPACE::vector<int>::iterator 	it = vector2.erase(vector2.end() - 5, vector2.end());

	vector2.back() = 22;

	it = vector2.erase(vector2.end() - 1);

	std::cout << "Erase medium data" << std::endl << *it << std::endl;

	vector2.insert(vector2.end(), 5);
	vector2.insert(vector2.end(), 5);

	vector2.clear();
	print_vector(vector2);

	PRINT(SEP_FUNCTIONS);
}
