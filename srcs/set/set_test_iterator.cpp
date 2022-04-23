/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_test_iterator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:49:07 by lvirgini          #+#    #+#             */
/*   Updated: 2022/04/23 23:08:33 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.hpp"

void set_test_it()
{
	PRINT(SEP_FUNCTIONS);
	PRINT("SET test iterator and const iterator");

	int myints[] = {75,23,65,42,13};
	M_NAMESPACE::set<int> myset (myints,myints+5);

	std::cout << "myset contains:";
	for (M_NAMESPACE::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	M_NAMESPACE::set<int>::iterator it_test = myset.begin();
	M_NAMESPACE::set<int>::const_iterator it = myset.begin();
	M_NAMESPACE::set<int>::const_iterator ite = myset.end();

	//not compile
	// *it_test = 12;
	// *it = 12;

	for (; it != ite; it++)
		std::cout << *it << std::endl;
}


void	set_test_it_reverse()
{
	PRINT(SEP_FUNCTIONS);
	PRINT("SET test reverse iterator and const reverse iterator");

	int myints[] = {21,64,17,78,49};
	M_NAMESPACE::set<int> myset (myints,myints+5);

	M_NAMESPACE::set<int>::reverse_iterator rit;

	std::cout << "myset contains:";
	for (rit=myset.rbegin(); rit != myset.rend(); ++rit)
	std::cout << ' ' << *rit;
	std::cout << std::endl;

	M_NAMESPACE::set<int>::reverse_iterator it_test = myset.rbegin();
	M_NAMESPACE::set<int>::const_reverse_iterator it = myset.rbegin();
	M_NAMESPACE::set<int>::const_reverse_iterator ite = myset.rend();

	//not compile
	// *it_test = 12;
	// *it = 12;

	for (; it != ite; it++)
		std::cout << *it << std::endl;
}
void set_test_iterator()
{
	set_test_it();
	set_test_it_reverse();
}