/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_test_find.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 20:18:50 by lvirgini          #+#    #+#             */
/*   Updated: 2022/04/23 21:25:54 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.hpp"

void	set_test_find()
{
	M_NAMESPACE::set<int> myset;
	M_NAMESPACE::set<int>::iterator it;

	// set some initial values:
	for (int i=1; i<=5; i++) myset.insert(i*10);    // set: 10 20 30 40 50

	it=myset.find(20);

	myset.erase (it);
	myset.erase (myset.find(40));

	std::cout << "myset contains:";
	for (it=myset.begin(); it!=myset.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';

	it = myset.find(30);
	return ;
}
