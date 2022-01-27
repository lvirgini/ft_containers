/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_insert.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 22:42:31 by lvirgini          #+#    #+#             */
/*   Updated: 2022/01/27 15:09:24 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.hpp"

void	test_insert(void)
{

  PRINT("TEST INSERT()");

  M_NAMESPACE::vector<int>    v(10);

  v[1] = 2;
/*
  M_NAMESPACE::vector<int> myvector (3,100);
  M_NAMESPACE::vector<int>::iterator it;

  std::vector<int> stdmyvector (3,100);
  std::vector<int>::iterator stdit;

  print_all_value(stdmyvector, myvector);
  print_all_functions(stdmyvector, myvector);

  it = myvector.begin();
  it = myvector.insert ( it , 200 );

  stdit = stdmyvector.begin();
  stdit = stdmyvector.insert( stdit , 200 );
  
  print_all_value(stdmyvector, myvector);
  print_all_functions(stdmyvector, myvector);
  

  myvector.insert (it,2,300);
  stdmyvector.insert (stdit,2,300);
  PRINT(*it);

  print_all_value(stdmyvector, myvector);
  print_all_functions(stdmyvector, myvector);

  // "it" no longer valid, get a new one:
  it = myvector.begin();

  M_NAMESPACE::vector<int> anothervector (2,400);
  myvector.insert (it+2,anothervector.begin(),anothervector.end());

  int myarray [] = { 501,502,503 };
  myvector.insert (myvector.begin(), myarray, myarray+3);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
  	std::cout << ' ' << *it;
  std::cout << '\n';
*/
  PRINT(SEP_FUNCTIONS);
}

