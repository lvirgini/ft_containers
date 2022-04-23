/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_test_bound.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 20:22:18 by lvirgini          #+#    #+#             */
/*   Updated: 2022/04/23 21:04:04 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.hpp"

void	test_bound()
{
	PRINT(SEP_FUNCTIONS);
	PRINT("SET: lower and upper bound");

	M_NAMESPACE::set<int> myset;
	M_NAMESPACE::set<int>::iterator itlow,itup;

	for (int i=1; i<10; i++) myset.insert(i*10); // 10 20 30 40 50 60 70 80 90

	itlow=myset.lower_bound (30);                //       ^
	itup=myset.upper_bound (60);                 //                   ^

	myset.erase(itlow,itup);                     // 10 20 70 80 90

	std::cout << "myset contains:";
	for (M_NAMESPACE::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';

	

	PRINT(SEP_FUNCTIONS);
	PRINT("SET: equal range");

	M_NAMESPACE::set<int> set2;

	for (int i=1; i<=5; i++) set2.insert(i*10);   // set2: 10 20 30 40 50

	M_NAMESPACE::pair<M_NAMESPACE::set<int>::const_iterator,M_NAMESPACE::set<int>::const_iterator> ret;
	ret = set2.equal_range(30);

	std::cout << "the lower bound points to: " << *ret.first << '\n';
	std::cout << "the upper bound points to: " << *ret.second << '\n';

}
