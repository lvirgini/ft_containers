/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_functions.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:37:20 by lvirgini          #+#    #+#             */
/*   Updated: 2022/04/14 12:31:28 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.hpp"


// typedef for simplify 
typedef M_NAMESPACE::map<int, std::string, M_NAMESPACE::less<int> >  named_map;
typedef std::map<int, std::string, std::less<int> >  std_map;
typedef ft::map<int, std::string, ft::less<int> >  ft_map;

typedef M_NAMESPACE::pair<int, std::string>	named_pair;
typedef ft::pair<int, std::string>			ft_pair;
typedef std::pair<int, std::string>			std_pair;


// typedef  M_NAMESPACE::make_pair<int, std::string> 	named_makepair;
// typedef ft::make_pair<int, std::string> 			ft_makepair;
// typedef std::make_pair<int, std::string> 			std_makepair;


// void	map_test_creation()
// {
// 	PRINT("Map creation");
// 	PRINT(SEP_FUNCTIONS);
// 	std_map									map1;
// 	// std_map									map2;
// 	std_map									map3;
// 	std::pair<std_map::iterator, bool> 		result;


// 	// insert 1 to 10 pair of "coucou"
// 		std_pair	pair_to_insert;
// 	for (int i = 0; i < 10; i++)
// 	{
// 		pair_to_insert = std::make_pair<int, std::string>(i, "coucou");
// 		map1.insert(pair_to_insert);
// 		map3.insert(std::make_pair<int, std::string> (i * 2, "coucou"));
// 	}
// 	std_map									map2(map1);
// 	map3 = map1;
// 	map3 = map2;
// 	map1.clear();

// 	std_map::iterator it = map1.begin();
// 	std_map::iterator ite = map1.end();

// 	for (; it != ite; it++)
// 		std::cout << it->first << it->second << std::endl;



// 	it = map2.begin();
// 	ite = map2.end();

// 	for (; it != ite; it++)
// 		std::cout << it->first << it->second << std::endl;


// 	return ;
// }

void	map_test_creation()
{
	PRINT("Map creation");
	PRINT(SEP_FUNCTIONS);

	named_map									map1;
	named_map									map3;
	named_pair									result;


	// insert 1 to 10 pair of "coucou"
		ft_pair	pair_to_insert;
	for (int i = 0; i < 10; i++)
	{
		pair_to_insert = M_NAMESPACE::make_pair<int, std::string>(i, "coucou");
		map1.insert(pair_to_insert);
		map3.insert(M_NAMESPACE::make_pair<int, std::string> (i * 2, "coucou"));
	}
	named_map									map2(map1);
	map3 = map1;
	map3 = map2;
	map1.clear();

	named_map::iterator it = map1.begin();
	named_map::iterator ite = map1.end();

	for (; it != ite; it++)
		std::cout << it->first << it->second << std::endl;



	it = map2.begin();
	ite = map2.end();

	for (; it != ite; it++)
		std::cout << it->first << it->second << std::endl;


	return ;
}

void	map_test_insertion()
{
	// // try insert two same paire
	// result = map1.insert(std::make_pair<int, std::string> (5, "coucou"));
	// std::cout << result.second << std::endl;
	// result = map1.insert(std::make_pair<int, std::string> (5, "coucou"));


	// // testing result from insert
	// std_map::iterator it_result = result.first;

	// std::cout << result.second << std::endl;
	// std::cout << it_result->first << std::endl;

	// for (int i = 0; i < 10; i++)
	// {
	// 	map1.insert(std::make_pair<int, std::string> (i, "coucou"));

	// }





	// std_map	map2(map1);

	// std_map::iterator it2 = map1.begin();
	// std_map::iterator ite2 = map1.end();


	// for (; it2 != ite2; it2++)
	// {
	// 	// it2->first = 45; no possible
	// 	it2->second = "coucou map2";
	// 	std::cout << it2->first << it2->second << std::endl;
	// }

	// std::cout << (map2[2] == map1[2]) << std::endl;
}


// void	map_test_creation()
// {
// 	// M_NAMESPACE::map<int, std::string, M_NAMESPACE::less<int> >		map;
// 	M_NAMESPACE::map<int, std::string, M_NAMESPACE::less<int> >		mmap;

// 	mmap.insert(M_NAMESPACE::make_pair<int, std::string> (5, "coucou"));
// 	mmap.insert(M_NAMESPACE::make_pair<int, std::string> (4, "coucou"));
// 	mmap.insert(M_NAMESPACE::make_pair<int, std::string> (3, "coucou"));
// 	mmap.insert(M_NAMESPACE::make_pair<int, std::string> (2, "coucou"));
// 	mmap.insert(M_NAMESPACE::make_pair<int, std::string> (1, "coucou"));
	

// 	M_NAMESPACE::map<int, std::string, std::less<int> >::iterator it = mmap.begin();
// 	M_NAMESPACE::map<int, std::string, std::less<int> >::iterator ite = mmap.end();


// 	std::cout << it->first << it->second << std::endl;

// }

