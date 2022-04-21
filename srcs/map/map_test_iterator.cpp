/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test_iterator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:22:04 by lvirgini          #+#    #+#             */
/*   Updated: 2022/04/21 21:40:38 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.hpp"

void	map_test_iterator()
{
	named_map		map1;
	ft_map			ftmap;
	std_map			stdmap;

	for (int i = 0; i < 100; i += 5)
	{
		map1.insert(M_NAMESPACE::make_pair<int, std::string>(i, "ok"));
		stdmap.insert(std::make_pair<int, std::string>(i, "ok"));
		ftmap.insert(ft::make_pair<int, std::string>(i, "ok"));

	}


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
	PRINT("map test const iterators : change pair->second : ");

	{
			named_map::const_iterator		cit = map1.begin();
			named_map::const_iterator		cite = map1.end();

			ft_map::const_iterator		ft_cit = ftmap.begin();
			ft_map::const_iterator		ft_cite = ftmap.end();

			std_map::const_iterator		std_cit = stdmap.begin();
			std_map::const_iterator		std_cite = stdmap.end();


	// cannot work for const iterator :
		// for (cit = map1.find(10), cite = map1.find(35); cit != cite; cit++)
		// 	cit->second = "Salut";

		// for (std_cit = stdmap.find(10), std_cite = stdmap.find(35); std_cit != std_cite; std_cit++)
		// std_cit->second = "Salut";

		// for (ft_cit = ftmap.find(10), ft_cite = ftmap.find(35); ft_cit != ft_cite; ft_cit++)
		// ft_cit->second = "Salut";

		for (; cit != cite; cit++)
			std::cout << cit->first << " -> " << cit->second << std::endl;

		for (; ft_cit != ft_cite; ft_cit++)
			std::cout << ft_cit->first << " -> " << ft_cit->second << std::endl;

		for (; std_cit != std_cite; std_cit++)
			std::cout << std_cit->first << " -> " << std_cit->second << std::endl;
	}



/* -------------------------------------------------------------------------- */

	PRINT(SEP_FUNCTIONS);
	PRINT("map test const reverse iterators : change pair->second : ");

	{
			named_map::const_reverse_iterator		cit = map1.rbegin();
			named_map::const_reverse_iterator		cite = map1.rend();

			ft_map::const_reverse_iterator		ft_cit = ftmap.rbegin();
			ft_map::const_reverse_iterator		ft_cite = ftmap.rend();

			std_map::const_reverse_iterator		std_cit = stdmap.rbegin();
			std_map::const_reverse_iterator		std_cite = stdmap.rend();


	// cannot work for const iterator :
		// for (cit = map1.find(10), cite = map1.find(35); cit != cite; cit++)
		// 	cit->second = "Salut";

		// for (std_cit = stdmap.find(10), std_cite = stdmap.find(35); std_cit != std_cite; std_cit++)
		// std_cit->second = "Salut";

		// for (ft_cit = ftmap.find(10), ft_cite = ftmap.find(35); ft_cit != ft_cite; ft_cit++)
		// ft_cit->second = "Salut";

		for (; cit != cite; cit++)
			std::cout << cit->first << " -> " << cit->second << std::endl;

		for (; ft_cit != ft_cite; ft_cit++)
			std::cout << ft_cit->first << " -> " << ft_cit->second << std::endl;

		for (; std_cit != std_cite; std_cit++)
			std::cout << std_cit->first << " -> " << std_cit->second << std::endl;
	}
/* -------------------------------------------------------------------------- */

	PRINT(SEP_FUNCTIONS);
	PRINT("map test reverse iterator");
	{
		named_map::reverse_iterator		rit = map1.rbegin();
		named_map::reverse_iterator		rite;


		PRINT(SEP_FUNCTIONS);
		PRINT("map test reverse iterators : change pair->second : ");

		// rit->second = "reverse iterator OK";
		// for (rit = map1.rbegin(), rite = map1.rend(); rit != rite; rit++)
		// 	std::cout << rit->first << " -> " << rit->second << std::endl;

	// 	for (rit = map1.rend(), rite = map1.rend(); rit != rite; rit++)
	// 		std::cout << rit->first << " -> " << rit->second << std::endl;
	}

	std::cout << "end" << std::endl;
}
