/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test_iterator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:22:04 by lvirgini          #+#    #+#             */
/*   Updated: 2022/04/21 15:40:19 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.hpp"

void	map_test_iterator()
{
	named_map		map1;

	for (int i = 0; i < 100; i += 5)
		map1.insert(M_NAMESPACE::make_pair<int, std::string>(i, "ok"));


/* -------------------------------------------------------------------------- */

	PRINT(SEP_FUNCTIONS);
	PRINT("map test iterators");
	{
		named_map::iterator		it;
		named_map::iterator		ite = map1.end();


	PRINT(SEP_FUNCTIONS);
	PRINT("map test iterators : change pair->second : ");

		for (it = map1.find(10), ite = map1.find(35); it != ite; it++)
			it->second = "Salut";

		for (it = map1.begin(), ite = map1.end(); it != ite; it++)
			std::cout << it->first << " -> " << it->second << std::endl;

		for (it = map1.end(), ite = map1.end(); it != ite; it++)
			std::cout << it->first << " -> " << it->second << std::endl;
	}

/* -------------------------------------------------------------------------- */

	PRINT(SEP_FUNCTIONS);
	PRINT("map test reverse iterator");
	{
		named_map::reverse_iterator		rit = map1.rbegin();
		named_map::reverse_iterator		rite;

		// std_map				std_map;
		// std_map::reverse_riterator rrit = std_map.find(5);

		PRINT(SEP_FUNCTIONS);
		PRINT("map test reverse iterators : change pair->second : ");

		rit->second = "reverse iterator OK";
		for (rit = map1.rbegin(), rite = map1.rend(); rit != rite; rit++)
			std::cout << rit->first << " -> " << rit->second << std::endl;

		for (rit = map1.rend(), rite = map1.rend(); rit != rite; rit++)
			std::cout << rit->first << " -> " << rit->second << std::endl;
	}

/* -------------------------------------------------------------------------- */





}
