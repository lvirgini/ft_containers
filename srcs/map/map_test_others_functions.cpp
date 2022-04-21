/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test_others_functions.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:17:56 by lvirgini          #+#    #+#             */
/*   Updated: 2022/04/21 15:21:23 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.hpp"

void	map_test_key_comp()
{

	PRINT(SEP_FUNCTIONS);
	PRINT("map test key_comp()");

	M_NAMESPACE::map<char,int> mymap;
	M_NAMESPACE::map<char,int>::key_compare mycomp = mymap.key_comp();

	mymap['a']=100;
	mymap['b']=200;
	mymap['c']=300;

	std::cout << "mymap contains:\n";

	char highest = mymap.rbegin()->first;     // key value of last element

	M_NAMESPACE::map<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mycomp((*it++).first, highest) );

	std::cout << std::endl;
}




void	map_test_value_comp()
{
		PRINT(SEP_FUNCTIONS);
		PRINT("map test value_comp()");

		M_NAMESPACE::map<char, int>		mymap;

		mymap['x']=1001;
		mymap['y']=2002;
		mymap['z']=3003;

		std::cout << "mymap contains:\n";

		M_NAMESPACE::pair<char,int> highest = *mymap.rbegin();          // last element

		M_NAMESPACE::map<char,int>::iterator it = mymap.begin();
		do {
		std::cout << it->first << " => " << it->second << '\n';
		} while ( mymap.value_comp()(*it++, highest) );

}



void	map_test_others_functions()
{
	map_test_value_comp();
	map_test_key_comp();
}
