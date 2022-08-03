/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_test_others_functions.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 20:12:36 by lvirgini          #+#    #+#             */
/*   Updated: 2022/04/24 10:10:27 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.hpp"

void	set_test_clear()
{
	PRINT(SEP_FUNCTIONS);
	PRINT("SET: clear");
	
	M_NAMESPACE::set<int> myset;

	myset.insert (100);
	myset.insert (200);
	myset.insert (300);

	std::cout << "myset contains:";
	for (M_NAMESPACE::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';

	myset.clear();
	myset.insert (1101);
	myset.insert (2202);

	std::cout << "myset contains:";
	for (M_NAMESPACE::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';
}

void	set_key_comp()
{
	PRINT(SEP_FUNCTIONS);
	PRINT("SET: key_comp");
	
	M_NAMESPACE::set<int> myset;
	int highest;

	M_NAMESPACE::set<int>::key_compare mycomp = myset.key_comp();

	for (int i=0; i<=5; i++) myset.insert(i);

	std::cout << "myset contains:";

	highest=*myset.rbegin();
	M_NAMESPACE::set<int>::iterator it=myset.begin();
	do {
	std::cout << ' ' << *it;
	} while ( mycomp(*(++it),highest) );

	std::cout << '\n';
}

void	set_test_value_comp()
{
	PRINT(SEP_FUNCTIONS);
	PRINT("SET: value_comp");
	
	M_NAMESPACE::set<int> myset;

	M_NAMESPACE::set<int>::value_compare mycomp = myset.value_comp();

	for (int i=0; i<=5; i++) myset.insert(i);

	std::cout << "myset contains:";

	int highest=*myset.rbegin();
	M_NAMESPACE::set<int>::iterator it=myset.begin();
	do {
	std::cout << ' ' << *it;
	} while ( mycomp(*(++it),highest) );

	std::cout << '\n';
}

void	set_test_count()
{

	M_NAMESPACE::set<int> myset;

	// set some initial values:
	for (int i=1; i<5; ++i) myset.insert(i*3);    // set: 3 6 9 12

	for (int i=0; i<10; ++i)
	{
		std::cout << i;
		if (myset.count(i)!=0)
			std::cout << " is an element of myset.\n";
		else
			std::cout << " is not an element of myset.\n";
	}

}


void	set_test_get_allocator()
{
	PRINT(SEP_FUNCTIONS);
	PRINT("SET: get allocator");

	M_NAMESPACE::set<int> myset;
	int * p;
	unsigned int i;

	// allocate an array of 5 elements using myset's allocator:
	p=myset.get_allocator().allocate(5);

	// assign some values to array
	for (i=0; i<5; i++) p[i]=(i+1)*10;

	std::cout << "The allocated array contains:";
	for (i=0; i<5; i++) std::cout << ' ' << p[i];
	std::cout << '\n';

	myset.get_allocator().deallocate(p,5);

}

void	set_test_others_functions()
{
	set_test_clear();
	set_test_count();
	set_test_value_comp();
	set_test_get_allocator();
}

