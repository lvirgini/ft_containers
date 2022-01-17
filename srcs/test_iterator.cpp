/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_iterator.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:13:22 by lvirgini          #+#    #+#             */
/*   Updated: 2022/01/12 14:24:33 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.hpp"
#include <iostream>
#include <cstring>
#include <vector>

void	test_iterator(void)
{
	std::vector<int>	stdV(10);
	ft::vector<int>		ftV(10);

	// enter 0 to 9 value in vector value
	for( int i = 0; i < 10; i++)
	{
		stdV[i] = i;
		ftV[i] = i;
	}

	// create iterator + 1
	std::vector<int>::iterator	it_std = stdV.begin() + 1;
	ft::vector<int>::iterator	it_ft = ftV.begin() + 1;

	// return iterator to iterator begin (-1)
	it_std = it_std - 1;
	it_ft = it_ft - 1;

	// create iterator end
	std::vector<int>::iterator	ite_std = stdV.end();
	ft::vector<int>::iterator	ite_ft = ftV.end();

	// in pos 15 then 2
	it_std += 15;
	it_std -= 13;

	it_ft += 15;
	it_ft -= 13;

	// change the value of position 6  (4 + 2);
	it_ft[4] = 0;
	it_std[4] = 0;

	//return to pos 0
	it_std--;
	it_ft--;

	--it_ft;
	--it_std;

	// print all value
	while (it_std < ite_std)
	{
		std::cout << *it_std << " ";
		it_std++;
	//	++it_std;
	//	it_std += 2;
	//	it_std += 12;
	}
	std::cout << std::endl;


	while (it_ft < ite_ft)
	{
		std::cout << *it_ft << " ";
		it_ft++;
	//	++it_ft;
	//	it_ft += 2;
	//	it_ft += 12;
	}
	std::cout << std::endl;
}


void	test_const_iterator(void)
{
	std::vector<int>	stdV(10);
	ft::vector<int>		ftV(10);

	// enter 0 to 9 value in vector value
	for( int i = 0; i < 10; i++)
	{
		stdV[i] = i;
		ftV[i] = i;
	}

	// create iterator + 1
	std::vector<int>::const_iterator	it_std = stdV.begin() + 1;
	ft::vector<int>::const_iterator		it_ft = ftV.begin();

	// return iterator to iterator begin (-1)
	it_std = it_std - 1;
	it_ft = it_ft - 1;

	// create iterator end
	std::vector<int>::const_iterator	ite_std = stdV.end();
	ft::vector<int>::const_iterator		ite_ft = ftV.end();

	// in pos 15 then 2
	it_std += 15;
	it_std -= 13;

	it_ft += 15;
	it_ft -= 13;

	// change the value of position 6  (4 + 2); NOT possible in const
	//it_ft[4] = 0;
	//it_std[4] = 0;

	//return to pos 0
	it_std--;
	it_ft--;

	--it_ft;
	--it_std;

	// print all value
	while (it_std < ite_std)
	{
		std::cout << *it_std << " ";
		it_std++;
	//	++it_std;
	//	it_std += 2;
	//	it_std += 12;
	}
	std::cout << std::endl;


	while (it_ft < ite_ft)
	{
		std::cout << *it_ft << " ";
		it_ft++;
	//	++it_ft;
	//	it_ft += 2;
	//	it_ft += 12;
	}
	std::cout << std::endl;
}
