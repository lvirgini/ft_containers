/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_iterator.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:13:22 by lvirgini          #+#    #+#             */
/*   Updated: 2022/01/27 14:43:23 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.hpp"

void	test_iterator(void)
{
	PRINT("TESTING ITERATOR && CONST ITERATOR");

	int		size = 5;

	M_NAMESPACE::vector<int>					v(size);
	M_NAMESPACE::vector<int>::iterator			it = v.begin();
	M_NAMESPACE::vector<int>::const_iterator	cit = v.begin();


/* -------------------------------------------------------------------------- */
	PRINT("\n * testing operator[]");

	for (int i = 0; i < size; i++)
		it[i] = i;

	print_all_functions(v);
	print_all_value(v);

/* -------------------------------------------------------------------------- */

	PRINT("\n * testing operator > >= < <= == != -");

	// NOT EXISTING 
	//	std::cout << "v.begin() + v.end() : " << ( v.begin() + v.end() ) << std::endl;
	std::cout << "v.begin() - v.end() : " << ( v.begin() - v.end() ) << std::endl;
	std::cout << "v.begin() > v.end() : " << ( v.begin() > v.end() ) << std::endl;
	std::cout << "v.begin() >= v.end() : " << ( v.begin() >= v.end() ) << std::endl;
	std::cout << "v.begin() < v.end() : " << ( v.begin() < v.end() ) << std::endl;
	std::cout << "v.begin() <= v.end() : " << ( v.begin() <= v.end() ) << std::endl;
	std::cout << "v.begin() == v.end() : "  << ( v.begin() == v.end() ) << std::endl;
	std::cout << "v.begin() != v.end() : "  << ( v.begin() != v.end() ) << std::endl;

	std::cout << "it - cit : " << ( it - cit ) << std::endl;
	std::cout << "it > cit : " << ( it > cit ) << std::endl;
	std::cout << "it >= cit : " << ( it >= cit ) << std::endl;
	std::cout << "it < cit : " << ( it < cit ) << std::endl;
	std::cout << "it <= cit : " << ( it <= cit ) << std::endl;
	std::cout << "it == cit : "  << ( it == cit ) << std::endl;
	std::cout << "it != cit : "  << ( it != cit ) << std::endl;

/* -------------------------------------------------------------------------- */
	
	PRINT("\n * testing operator ++ -- += -=  =");

	std::cout << "iterator | const_iterator" << std::endl;
	std::cout << "it++ : " << *(it++) << SEP << *(cit++) << std::endl;
	std::cout << "++it : " << *(++it) << SEP << *(++cit) <<std::endl;

	std::cout << "it-- : " << *(it--) << SEP << *(cit--) <<std::endl;
	std::cout << "--it : " << *(--it) << SEP  << *(--cit) << std::endl;

	it += 3;
	cit += 3;
	std::cout << "it += 3 : " << *it << SEP << *cit << std::endl;

	it -= 3;
	cit -= 3;
	std::cout << "it -= 3 : "<< *it << SEP << *cit << std::endl;

	it = it + 2;
	cit = cit + 2;
	std::cout << "it = it + 2 : " << *it << SEP << *cit << std::endl;

	it = it - 2;
	cit = cit - 2;
	std::cout << "it = it - 2 : " << *it << SEP << *cit << std::endl;

	it =  1 + it;
	cit =  1 + cit;
	std::cout << "it = 1 + it : " << *it << SEP << *cit << std::endl;

	it = it + 4;
	cit = cit + 4;
	std::cout << "it = it + 4 : " << *it << SEP << *cit << std::endl;

	// NOT EXISTING
	// it =  1 - it;
	// cit =  1 - cit;
	// std::cout << "it = 1 - it : " << *it << SEP << *cit << std::endl;

	it = it - 4;
	cit = cit - 4;
	std::cout << "it = it - 4 : " << *it << SEP << *cit << std::endl;

/* -------------------------------------------------------------------------- */

	
	*(it) = 42;
	//*(cit) = 42; cannot work for const OK
	std::cout << "*it = 42 : " << *it << SEP << *cit << std::endl;

	*(it + 1) = 12;
	std::cout << "*(it + 1) = 12 : " << *(it + 1) << SEP << *(cit + 1)<< std::endl;

	*(it - 1) = -42;
	std::cout << "*(it - 1) = 42 : " << *(it - 1) << SEP << *(cit - 1) << std::endl;


	// NO VIABLE OVERLOAD 
	// it = cit;

	it += 666;
	cit = it;
	cit -= 665;
	std::cout << "it += 666; cit = it; it -= 665 : " << *it << SEP << *cit << std::endl; // no segfault ???


	std::cout << "(it == cit): " << (it == cit) << std::endl;
	std::cout << "(it - cit) : " << (it - cit) << std::endl;
	std::cout << "(ite + 3 == it): " << (it + 3 == cit) << std::endl;
	
	PRINT(SEP_FUNCTIONS);
}



void	test_reverse_iterator(void)
{
	PRINT("TESTING REVERSE ITERATOR && CONST REVERSE ITERATOR");

		int		size = 5;

	M_NAMESPACE::vector<int>	v(size);
	M_NAMESPACE::vector<int>::reverse_iterator			rit = v.rbegin();
	M_NAMESPACE::vector<int>::const_reverse_iterator	crit = v.rbegin();

/* -------------------------------------------------------------------------- */
	PRINT("\n * testing operator[]");

	for (int i = 0; i < size; i++)
		rit[i] = i;

	print_all_functions(v);
	print_all_value(v);

/* -------------------------------------------------------------------------- */

	PRINT("\n * testing operator > >= < <= == != -");

	// NOT EXISTING 
	//	std::cout << "v.rbegin() + v.rend() : " << ( v.rbegin() + v.rend() ) << std::endl;
	std::cout << "v.rbegin() - v.rend() : " << ( v.rbegin() - v.rend() ) << std::endl;
	std::cout << "v.rbegin() > v.rend() : " << ( v.rbegin() > v.rend() ) << std::endl;
	std::cout << "v.rbegin() >= v.rend() : " << ( v.rbegin() >= v.rend() ) << std::endl;
	std::cout << "v.rbegin() < v.rend() : " << ( v.rbegin() < v.rend() ) << std::endl;
	std::cout << "v.rbegin() <= v.rend() : " << ( v.rbegin() <= v.rend() ) << std::endl;
	std::cout << "v.rbegin() == v.rend() : "  << ( v.rbegin() == v.rend() ) << std::endl;
	std::cout << "v.rbegin() != v.rend() : "  << ( v.rbegin() != v.rend() ) << std::endl;

	std::cout << "rit - crit : " << (rit - crit ) << std::endl;
	std::cout << "rit > crit : " << (rit > crit ) << std::endl;
	std::cout << "rit >= crit : " << (rit >= crit ) << std::endl;
	std::cout << "rit < crit : " << (rit < crit ) << std::endl;
	std::cout << "rit <= crit : " << (rit <= crit ) << std::endl;
	std::cout << "rit == crit : "  << (rit == crit ) << std::endl;
	std::cout << "rit != crit : "  << (rit != crit ) << std::endl;

/* -------------------------------------------------------------------------- */
	
	PRINT("\n * testing operator ++ -- += -=  =");

	std::cout << "iterator | const_iterator" << std::endl;
	std::cout << "rit++ : " << *(rit++) << SEP << *(crit++) << std::endl;
	std::cout << "++rit : " << *(++rit) << SEP << *(++crit) <<std::endl;

	std::cout << "rit-- : " << *(rit--) << SEP << *(crit--) <<std::endl;
	std::cout << "--rit : " << *(--rit) << SEP  << *(--crit) << std::endl;

	rit += 3;
	crit += 3;
	std::cout << "it += 3 : " << *rit << SEP << *crit << std::endl;

	rit -= 3;
	crit -= 3;
	std::cout << "it -= 3 : "<< *rit << SEP << *crit << std::endl;

	rit = rit + 2;
	crit = crit + 2;
	std::cout << "rit = rit + 2 : " << *rit << SEP << *crit << std::endl;

	rit = rit - 2;
	crit = crit - 2;
	std::cout << "rit = rit - 2 : " << *rit << SEP << *crit << std::endl;

	rit =  1 + rit;
	crit =  1 + crit;
	std::cout << "rit = 1 + rit : " << *rit << SEP << *crit << std::endl;

	rit = rit + 4;
	crit = crit + 4;
	std::cout << "rit = rit + 4 : " << *rit << SEP << *crit << std::endl;

	// NOT EXISTING
	// rit =  1 - rit;
	// crit =  1 - crit;
	// std::cout << "rit = 1 - it : " << *rit << SEP << *crit << std::endl;

	rit = rit - 4;
	crit = crit - 4;
	std::cout << "it = it - 4 : " << *rit << SEP << *crit << std::endl;

/* -------------------------------------------------------------------------- */

	
	*(rit) = 42;
	//*(crit) = 42; cannot work for const OK
	std::cout << "*rit = 42 : " << *rit << SEP << *crit << std::endl;

	*(rit + 1) = 12;
	std::cout << "*(rit + 1) = 12 : " << *(rit + 1) << SEP << *(crit + 1)<< std::endl;

	*(rit - 1) = -42;
	std::cout << "*(rit - 1) = 42 : " << *(rit - 1) << SEP << *(crit - 1) << std::endl;


	// NO VIABLE OVERLOAD 
	// it = crit;

	rit += 666;
	crit = rit;
	crit -= 665;
	std::cout << "it += 666; crit = it; it -= 665 : " << *rit << SEP << *crit << std::endl; // no segfault ???


	std::cout << "(rit == crit): " << (rit == crit) << std::endl;
	std::cout << "(rit - crit) : " << (rit - crit) << std::endl;
	std::cout << "(rit + 3 == it): " << (rit + 3 == crit) << std::endl;
	
	PRINT(SEP_FUNCTIONS);
}

