/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test_insert.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:09:59 by lvirgini          #+#    #+#             */
/*   Updated: 2022/04/17 13:47:29 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.hpp"

void	map_test_insert()
{
	PRINT("MAP test insert");
	PRINT(SEP_FUNCTIONS);

	named_map		map1;
	named_map::iterator	it;
	named_map::iterator	ite;


	PRINT("insert same key with differente and same second param");
	map1.insert(M_NAMESPACE::make_pair<int, std::string>(1, "truc"));
	map1.insert(M_NAMESPACE::make_pair<int, std::string>(1, "truc"));
	map1.insert(M_NAMESPACE::make_pair<int, std::string>(1, "bidule"));

	std::cout << "size = " << map1.size() << std::endl;

	for (it = map1.begin(), ite = map1.end(); it != ite; it++)
		std::cout << it->first << " " << it->second << std::endl;


	PRINT(SEP_FUNCTIONS);
	PRINT("insert with iterator");

	for (int i = 0; i < 10; i++)
		map1.insert(M_NAMESPACE::make_pair<int, std::string>(i*2, "truc"));

	named_map	map2(map1.begin(), map1.end());
	named_map	map3(map1.end(), map1.end());


	for (it = map1.begin(), ite = map1.end(); it != ite; it++)
		std::cout << it->first << " " << it->second << "	map2: "<< it->first << " " << it->second << std::endl;


	PRINT(SEP_FUNCTIONS);
	PRINT("insert with iterator end() : nothing to insert");

	for (it = map3.begin(), ite = map3.end(); it != ite; it++)
		std::cout << it->first << " " << it->second << std::endl;
	std::cout << "size = " << map3.size() << std::endl;


	map1.insert(map1.end()--, M_NAMESPACE::make_pair<int, std::string>(20, "bidule"));
	map1.insert(map1.end()--, M_NAMESPACE::make_pair<int, std::string>(-1, "bidule"));
	map1.insert(map1.end()--, M_NAMESPACE::make_pair<int, std::string>(20, "bidule"));

for (it = map1.begin(), ite = map1.end(); it != ite; it++)
		std::cout << it->first << " " << it->second << std::endl;

	PRINT(SEP_FUNCTIONS);

}
