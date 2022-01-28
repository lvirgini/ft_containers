/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_empty.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:05:53 by lvirgini          #+#    #+#             */
/*   Updated: 2022/01/28 13:18:48 by lvirgini         ###   ########.fr       */
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

	print_vector(empty);

	PRINT(SEP_FUNCTIONS);
}
