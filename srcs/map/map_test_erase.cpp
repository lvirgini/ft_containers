/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test_erase.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:24:53 by lvirgini          #+#    #+#             */
/*   Updated: 2022/04/20 10:30:49 by lvirgini         ###   ########.fr       */
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



  for (it = mymap.begin(); it != mymap.end(); it++)
  std::cout << it->first << " " << it->second <<  std::endl;
PRINT(SEP_FUNCTIONS);
PRINT("delete b");

  it=mymap.find('b');
  std::cout << it->first << std::endl;
  mymap.erase (it);                   // erasing by iterator
  

  for (it = mymap.begin(); it != mymap.end(); it++)
  std::cout << it->first << " " << it->second <<  std::endl;

PRINT(SEP_FUNCTIONS);
PRINT("delete c");
  mymap.erase ('c');                  // erasing by key
PRINT(SEP_FUNCTIONS);
PRINT("delete a");               // erasing by key
  mymap.erase ('a');


PRINT(SEP_FUNCTIONS);
PRINT("delete begin to end");
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
  mymap.erase ( mymap.begin(), mymap.end() );    // erasing by range

// if (STR_NAMESPACE[0] == 'f')
//   mymap.display();
  // show content:
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

}
