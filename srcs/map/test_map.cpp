/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 22:17:06 by lvirgini          #+#    #+#             */
/*   Updated: 2022/03/22 15:33:41 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.hpp"

void	test_pair(void)
{
	std::pair<int, std::string>			stdp;

	M_NAMESPACE::pair<int, std::string>		p;
	
	p.first = 10;
	p.second = "str";

	stdp.first = 10;
	stdp.second = "str";

	std::cout << p.first << " " << p.second << std::endl;
	std::cout << stdp.first << " " << stdp.second << std::endl;

	p = M_NAMESPACE::make_pair(15, "pouet");

	std::cout << p.first << " " << p.second << std::endl;
	std::cout << stdp.first << " " << stdp.second << std::endl;


	M_NAMESPACE::pair<int, std::string>		p2(p);

	std::cout << (p2 == p) << std::endl;
	std::cout << (p2 != p) << std::endl;
	std::cout << (p2 < p) << std::endl;
	std::cout << (p2 > p) << std::endl;
	std::cout << (p2 <= p) << std::endl;
	std::cout << (p2 >= p) << std::endl;


	p2.first = 5;
	std::cout << (p2 == p) << std::endl;
	std::cout << (p2 != p) << std::endl;
	std::cout << (p2 < p) << std::endl;
	std::cout << (p2 > p) << std::endl;
	std::cout << (p2 <= p) << std::endl;
	std::cout << (p2 >= p) << std::endl;


	M_NAMESPACE::pair<int, std::string>		p3(p2);

	p3 = p;
	std::cout << (p3 == p) << std::endl;


}


