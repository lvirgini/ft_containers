/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_functions.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:37:20 by lvirgini          #+#    #+#             */
/*   Updated: 2022/04/13 23:57:08 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.hpp"

typedef M_NAMESPACE::map<int, std::string, M_NAMESPACE::less<int> >  named_map;
typedef std::map<int, std::string, std::less<int> >  std_map;
typedef ft::map<int, std::string, ft::less<int> >  ft_map;

void	map_test_creation()
{
	// M_NAMESPACE::map<int, std::string, M_NAMESPACE::less<int> >		map;
	std_map								std_map;
	std::pair<std_map::iterator, bool> 	  result;

	result = std_map.insert(std::make_pair<int, std::string> (5, "coucou"));
	
	std::cout << result.second << std::endl;

	result = std_map.insert(std::make_pair<int, std::string> (5, "coucou"));

	std_map::iterator it_result = result.first;

	std::cout << result.second << std::endl;
	std::cout << it_result->first << std::endl;
	
	std_map.insert(std::make_pair<int, std::string> (4, "coucou"));
	std_map.insert(std::make_pair<int, std::string> (3, "coucou"));
	std_map.insert(std::make_pair<int, std::string> (2, "coucou"));
	std_map.insert(std::make_pair<int, std::string> (1, "coucou"));
	

	std::map<int, std::string, std::less<int> >::iterator it = std_map.begin();
	std::map<int, std::string, std::less<int> >::iterator ite = std_map.end();


	std::cout << it->first << it->second << std::endl;


	std::cout << std_map[2] << std::endl;
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

