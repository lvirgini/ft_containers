/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test_capacity.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:50:19 by lvirgini          #+#    #+#             */
/*   Updated: 2022/04/22 13:42:24 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.hpp"
#include <stdlib.h>

void	map_test_capacity()
{
	named_map		empty;
	named_map		map1;
	named_map		map2;

	map1.insert(M_NAMESPACE::make_pair<int, std::string>(1, "pouet"));
	map1.insert(M_NAMESPACE::make_pair<int, std::string>(2, "pouet"));
	map1.insert(M_NAMESPACE::make_pair<int, std::string>(3, "pouet"));

	std::cout << map1.size() << std::endl;

	// exit(0);


	for (int i = 0; i < 1000; i++)
		map1.insert(M_NAMESPACE::make_pair<int, std::string>(i, "pouet"));

	for (int i = 0; i < 4; i++)
		map2.insert(M_NAMESPACE::make_pair<int, std::string>(i, "pouet"));

	std::cout << empty.empty() << std::endl;
	std::cout << map1.empty() << std::endl;
	std::cout << map2.empty() << std::endl;

	std::cout << empty.size() << std::endl;
	std::cout << map1.size() << std::endl;
	std::cout << map2.size() << std::endl;

	std::cout << empty.max_size() << std::endl;
	std::cout << map1.max_size() << std::endl;
	std::cout << map2.max_size() << std::endl;

	for (int i = 1000; i < 2000; i++)
	{
		map1.insert(M_NAMESPACE::make_pair<int, std::string>(i, "pouet"));
		std::cout << i << std::endl;
	}

	std::cout << "ok" << std::endl;
	map2.clear();

	std::cout << empty.empty() << std::endl;
	std::cout << map1.empty() << std::endl;
	std::cout << map2.empty() << std::endl;

	std::cout << empty.size() << std::endl;
	std::cout << map1.size() << std::endl;
	std::cout << map2.size() << std::endl;

	std::cout << empty.max_size() << std::endl;
	std::cout << map1.max_size() << std::endl;
	std::cout << map2.max_size() << std::endl;
}

