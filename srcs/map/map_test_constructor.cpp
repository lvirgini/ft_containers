/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test_constructor.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:38:55 by lvirgini          #+#    #+#             */
/*   Updated: 2022/05/03 12:11:56 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_stl.hpp"

void	map_test_creation()
{
	PRINT("Map creation");
	PRINT(SEP_FUNCTIONS);

	named_map									map1;
	named_map									map2;
	named_pair									result;

	
	named_pair	pair_to_insert;

	for (int i = 0; i < 10; i++)
	{
		map1.insert(M_NAMESPACE::make_pair<int, std::string> (i * 2, "coucou"));
		pair_to_insert = M_NAMESPACE::make_pair<int, std::string>(i, "coucou");
		map2.insert(pair_to_insert);
	}
/* -------------------------------------------------------------------------- */

	PRINT(SEP_FUNCTIONS);
	PRINT("print map1");
	named_map::iterator it = map1.begin();
	named_map::iterator ite = map1.end();

	for (; it != ite; it++)
		std::cout << it->first << it->second << std::endl;
/* -------------------------------------------------------------------------- */

	PRINT(SEP_FUNCTIONS);
	PRINT("print map2");
	it = map2.begin();
	ite = map2.end();

	for (; it != ite; it++)
		std::cout << it->first << it->second << std::endl;
/* -------------------------------------------------------------------------- */

	PRINT(SEP_FUNCTIONS);
	PRINT("print map3 copy creation of map1");
	named_map									map3(map1);
	it = map3.begin();
	ite = map3.end();

	for (; it != ite; it++)
		std::cout << it->first << it->second << std::endl;
/* -------------------------------------------------------------------------- */

	PRINT(SEP_FUNCTIONS);
	PRINT("print map4 constructor by iterator from map2");
	named_map		map4(map2.begin(), map2.end());
	it = map4.begin();
	ite = map4.end();

	for (; it != ite; it++)
		std::cout << it->first << it->second << std::endl;
/* -------------------------------------------------------------------------- */

	PRINT(SEP_FUNCTIONS);
	PRINT("print map5 constructor by iterator from empty map");

	map1.clear();
	named_map		map5(map1.begin(), map1.end());
	
	it = map5.begin();
	ite = map5.end();

	for (; it != ite; it++)
		std::cout << it->first << it->second << std::endl;

	std::cout << "map 1 is empty ? " << map1.empty() << std::endl;
	std::cout << "map 5 is empty ? " << map5.empty() << std::endl;
/* -------------------------------------------------------------------------- */

	PRINT(SEP_FUNCTIONS);
	PRINT("print map6 constructor by copy from empty map");

	named_map		map6(map1);
	
	it = map6.begin();
	ite = map6.end();

	for (; it != ite; it++)
		std::cout << it->first << it->second << std::endl;

	std::cout << "map 1 is empty ? " << map1.empty() << std::endl;
	std::cout << "map 6 is empty ? " << map6.empty() << std::endl;
	PRINT(SEP_FUNCTIONS);
}
