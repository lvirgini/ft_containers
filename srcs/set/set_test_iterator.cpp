/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_test_iterator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:49:07 by lvirgini          #+#    #+#             */
/*   Updated: 2022/04/24 09:40:22 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.hpp"

void set_test_it()
{
	PRINT(SEP_FUNCTIONS);
	PRINT("SET test iterator");

	int myints[] = {75,23,65,42,13};

	std::set<int> stdset (myints,myints+5);
	ft::set<int> ftset (myints,myints+5);

	{
		std::set<int>::iterator it = stdset.begin();
		ft::set<int>::iterator ftit = ftset.begin();

		// cannot compile
		// *it = 12;
		// *ftit = 12;

		std::cout << "stdset contains:";
		for (it=stdset.begin(); it != stdset.end(); ++it)
		std::cout << ' ' << *it;
		std::cout << std::endl;


		std::cout << "myset contains:";
		for (ftit=ftset.begin(); ftit != ftset.end(); ++ftit)
		std::cout << ' ' << *ftit;
		std::cout << std::endl;
	}

	PRINT(SEP_FUNCTIONS);
	PRINT("SET test const iterator");

	{
		std::set<int>::const_iterator it = stdset.begin();
		std::set<int>::const_iterator ite = stdset.end();

		// cannot compile
		// *it = 12;

		for (; it != ite; it++)
			std::cout << *it << std::endl;
	}


	{
		ft::set<int>::const_iterator it = ftset.begin();
		ft::set<int>::const_iterator ite = ftset.end();

		// cannot compile
		// *it = 12;

		for (; it != ite; it++)
			std::cout << *it << std::endl;
	}

	M_NAMESPACE::set<int> myset (myints,myints+5);

	std::cout << "myset contains:";
	for (M_NAMESPACE::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	M_NAMESPACE::set<int>::const_iterator it = myset.begin();
	M_NAMESPACE::set<int>::const_iterator ite = myset.end();

	//not compile
	// *it = 12;

	for (; it != ite; it++)
		std::cout << *it << std::endl;
}


void	set_test_it_reverse()
{
	PRINT(SEP_FUNCTIONS);
	PRINT("SET test reverse iterator and const reverse iterator");

	int myints[] = {21,64,17,78,49};
	std::set<int> stdset (myints,myints+5);
	ft::set<int> ftset (myints,myints+5);

	std::set<int>::reverse_iterator rit = stdset.rbegin();
	ft::set<int>::reverse_iterator ftrit = ftset.rbegin();

	// cannot compile
	// *rit = 12;
	// *ftrit = 12;

	std::cout << "stdset contains:";
	for (rit=stdset.rbegin(); rit != stdset.rend(); ++rit)
	std::cout << ' ' << *rit;
	std::cout << std::endl;


	std::cout << "myset contains:";
	for (ftrit=ftset.rbegin(); ftrit != ftset.rend(); ++ftrit)
	std::cout << ' ' << *ftrit;
	std::cout << std::endl;


	{
		std::set<int>::const_reverse_iterator it = stdset.rbegin();
		std::set<int>::const_reverse_iterator ite = stdset.rend();

		//not compile
		// *it_test = 12;
		// *it = 12;

		for (; it != ite; it++)
			std::cout << *it << std::endl;
	}


	{
		ft::set<int>::const_reverse_iterator it = ftset.rbegin();
		ft::set<int>::const_reverse_iterator ite = ftset.rend();

		//not compile
		// *it_test = 12;
		// *it = 12;

		for (; it != ite; it++)
			std::cout << *it << std::endl;
	}
}
void set_test_iterator()
{
	set_test_it();
	set_test_it_reverse();
}
