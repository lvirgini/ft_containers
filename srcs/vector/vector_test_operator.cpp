/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test_operator.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:23:18 by lvirgini          #+#    #+#             */
/*   Updated: 2022/04/23 18:53:15 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.hpp"


void	vector_test_operator(void)
{
	PRINT("TESTING OPERATOR");

	M_NAMESPACE::vector<std::string>	vstr;
	M_NAMESPACE::vector<int>	v1;
	M_NAMESPACE::vector<int>	v2(5);
	M_NAMESPACE::vector<int>	v22 = v2;
	M_NAMESPACE::vector<int>	v3(10, 3);
	M_NAMESPACE::vector<int>	v4(10, 4);

	std::cout << (v1 < v1) << std::endl;
	std::cout << (v1 <= v1) << std::endl;
	std::cout << (v1 > v1) << std::endl;
	std::cout << (v1 >= v1) << std::endl;
	std::cout << (v1 == v1) << std::endl;
	std::cout << (v1 != v1) << std::endl;


	std::cout << (v1 < v2) << std::endl;
	std::cout << (v1 <= v2) << std::endl;
	std::cout << (v1 > v2) << std::endl;
	std::cout << (v1 >= v2) << std::endl;
	std::cout << (v1 == v2) << std::endl;
	std::cout << (v1 != v2) << std::endl;

	

	PRINT(SEP_FUNCTIONS);

}
