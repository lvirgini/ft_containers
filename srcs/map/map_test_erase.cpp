/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test_erase.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:24:53 by lvirgini          #+#    #+#             */
/*   Updated: 2022/04/21 15:16:20 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.hpp"

void	map_test_erase()
{
  M_NAMESPACE::map<char,int> 		mymap;
  M_NAMESPACE::map<char,int>::iterator 	it;

  // insert some values:
  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;
  mymap['d']=40;
  mymap['e']=50;
  mymap['f']=60;

PRINT(SEP_FUNCTIONS);
PRINT("before erase");

  for (it = mymap.begin(); it != mymap.end(); it++)
  std::cout << it->first << " " << it->second <<  std::endl;

/* -------------------------------------------------------------------------- */

PRINT(SEP_FUNCTIONS);
PRINT("delete b by iterator");

  it=mymap.find('b');
  std::cout << it->first << std::endl;
  mymap.erase (it);                   // erasing by iterator
  

  for (it = mymap.begin(); it != mymap.end(); it++)
  std::cout << it->first << " " << it->second <<  std::endl;
/* -------------------------------------------------------------------------- */

PRINT(SEP_FUNCTIONS);
PRINT("delete c by key");

  mymap.erase ('c');                  // erasing by key

  for (it = mymap.begin(); it != mymap.end(); it++)
  std::cout << it->first << " " << it->second <<  std::endl;
/* -------------------------------------------------------------------------- */

PRINT(SEP_FUNCTIONS);
PRINT("delete begin to end");

  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
  mymap.erase ( mymap.begin(), mymap.end() );    // erasing by range

  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "size at end = " << mymap.size() << mymap.begin()->first << std::endl;
/* -------------------------------------------------------------------------- */

}
