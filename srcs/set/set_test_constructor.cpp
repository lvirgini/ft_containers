/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_test_constructor.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:18:07 by lvirgini          #+#    #+#             */
/*   Updated: 2022/04/23 21:29:31 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.hpp"

bool fncomp (int lhs, int rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const int& lhs, const int& rhs) const
  {return lhs<rhs;}
};

void	set_test_constructor()
{
	PRINT(SEP_FUNCTIONS);
	PRINT("constructor");

	M_NAMESPACE::set<int> first;                           // empty set of ints

	int myints[]= {10,20,30,40,50};
	M_NAMESPACE::set<int> second (myints,myints+5);        // range

	M_NAMESPACE::set<int> third (second);                  // a copy of second

	M_NAMESPACE::set<int> fourth (second.begin(), second.end());  // iterator ctor.

	M_NAMESPACE::set<int,classcomp> fifth;                 // class as Compare

	bool(*fn_pt)(int,int) = fncomp;
	M_NAMESPACE::set<int,bool(*)(int,int)> sixth (fn_pt);  // function pointer as Compare


	PRINT(SEP_FUNCTIONS);
	PRINT("operator =");

	int list_int[]={ 12,82,37,64,15 };
	M_NAMESPACE::set<int> set1 (list_int,list_int+5);   // set with 5 ints
	M_NAMESPACE::set<int> set2;                    // empty set

	set2 = set1;                          // now set2 contains the 5 ints
	set1 = M_NAMESPACE::set<int>();                 // and set1 is empty

	std::cout << "Size of set1: " << int (set1.size()) << '\n';
	std::cout << "Size of set2: " << int (set2.size()) << '\n';

}
