/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_insert.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 22:42:31 by lvirgini          #+#    #+#             */
/*   Updated: 2022/01/27 22:49:19 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.hpp"

void	test_insert(void)
{

  PRINT("TEST INSERT()");

  M_NAMESPACE::vector<int>    v;

  // v.insert(v.begin(), -421);
  // v.insert(v.begin(), -422);
  // v.insert(v.begin(), -423);
  // v.insert(v.begin(), -423);
  // v.insert(v.begin(), -423);
  // v.insert(v.begin(), -423);
  // v.insert(v.begin(), -423);
  // v.insert(v.begin(), -423);
  // v.insert(v.begin(), -423);
  // v.insert(v.begin(), -423);
  // v.insert(v.begin(), -423);
  // v.insert(v.begin(), -423);
  // v.insert(v.begin(), -423);
  // v.insert(v.begin(), -423);

  // print_all_functions(v);
  // print_all_value(v);

  
  int   tab[] = {100, 200, 300, 400, 500, 600, 700, 800, 900};

  PRINT("insert (begin, 3, 5) on empty vector");
  v.insert(v.begin(), 3, 5);
  print_all_functions(v);
  print_all_value(v);

  PRINT("insert (end(), 42)");

  v.insert(v.end(), 42);
  print_all_functions(v);
  print_all_value(v);

  PRINT("insert (end(),0, 666)");

  v.insert(v.end(),0,  666);
  print_all_functions(v);
  print_all_value(v);


  PRINT("insert (begin(), -42)  twice");

  v.insert(v.begin(), -421);
  v.insert(v.begin(), -422);
  v.insert(v.begin(), -423);
  print_all_functions(v);
  print_all_value(v);

  PRINT("insert (begin(), iterator first, iterator last) [200 et 300]");

  v.insert(v.begin(), tab + 1, tab + 3);
  print_all_functions(v);
  print_all_value(v);

    PRINT("insert (end(), iterator first, iterator last) [500 et 600]");

  v.insert(v.end(), tab + 4, tab + 6);
  print_all_functions(v);
  print_all_value(v);


   PRINT("insert (end() - 4, 100");

  v.insert(v.end() - 4, *(tab + 0));
  print_all_functions(v);
  print_all_value(v);


   PRINT("insert (begin() + 1, iterator [700 800 900");

  v.insert(v.begin() + 1 , tab + 6, tab + 8);
  print_all_functions(v);
  print_all_value(v);


  PRINT(SEP_FUNCTIONS);
}

