/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test_insert.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:09:59 by lvirgini          #+#    #+#             */
/*   Updated: 2022/04/15 19:53:20 by lvirgini         ###   ########.fr       */
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
	{
		map1.insert(M_NAMESPACE::make_pair<int, std::string>(i*2, "truc"));
	}



	for (it = map1.begin(), ite = map1.end(); it != ite; it++)
		std::cout << it->first << " " << it->second << std::endl;

	PRINT(SEP_FUNCTIONS);

}
