/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_empty.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:05:53 by lvirgini          #+#    #+#             */
/*   Updated: 2022/01/27 15:25:46 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.hpp"


void	test_empty(void)
{
	PRINT("TESTING EMPTY VECTOR ");

	M_NAMESPACE::vector<int>	empty;

	// AT()
	try
	{
		empty.at(156) = 45;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	print_all_value(empty);
	print_all_functions(empty);

	PRINT(SEP_FUNCTIONS);
}
