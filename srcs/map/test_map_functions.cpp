/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_functions.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:37:20 by lvirgini          #+#    #+#             */
/*   Updated: 2022/04/12 16:32:50 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.hpp"


void	map_test_creation()
{
	// M_NAMESPACE::map<int, std::string, M_NAMESPACE::less<int> >		map;
	std::map<int, std::string, std::less<int> >		std_map;

	std_map.insert(std::make_pair<int, std::string> (5, "coucou"));
	std_map.insert(std::make_pair<int, std::string> (4, "coucou"));
	std_map.insert(std::make_pair<int, std::string> (3, "coucou"));
	std_map.insert(std::make_pair<int, std::string> (2, "coucou"));
	std_map.insert(std::make_pair<int, std::string> (1, "coucou"));
	

	std::map<int, std::string, std::less<int> >::iterator it = std_map.begin();
	std::map<int, std::string, std::less<int> >::iterator ite = std_map.end();


	std::cout << it->first << it->second << std::endl;

}
