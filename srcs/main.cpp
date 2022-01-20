/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:16:00 by lvirgini          #+#    #+#             */
/*   Updated: 2022/01/20 09:59:00 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.hpp"

int main2(void)
{
	std::vector<int> 	v(5);
//	ft::vector<int>		v(5);


	std::cout << "function size : " << v.size() << std::endl;

	return (0);
}


int main(void)
{
	PRINT(SEP_FUNCTIONS);
	test_iterator();
	test_const_iterator();
	test_empty();
	test_vector();

	std::vector<int>	stdValue(10, 10);
	ft::vector<int>		ftValue(10, 10);

	stdValue.push_back(123);

/*
	// SIZE()
	std::cout << std::endl << "vector.size() : " << std::endl << "std | ft" << std::endl; 
	std::cout << stdValue.size() << SEP << ftValue.size() << std::endl;


	// capacity()
	std::cout << std::endl << "vector.capacity()" << std::endl;
	std::cout << stdValue.capacity() << SEP << ftValue.capacity() << std::endl;



	//empty()

	std::cout << std::endl << "vector.empty()" << std::endl;
	std::cout << stdValue.empty() << std::endl;


*/
	return (0);
}



