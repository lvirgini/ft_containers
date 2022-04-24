/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:16:00 by lvirgini          #+#    #+#             */
/*   Updated: 2022/04/24 11:09:59 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.hpp"
#include "type_traits.hpp"

template <class T>
struct truc
{
    typedef T   type;
    typedef T*  pointer;
	typedef const T * const_pointer;
};

void	test_type_trait(void)
{
    std::cout << ft::are_same<int const *, truc<int const>::pointer>::value << std::endl;
    std::cout << ft::are_same<int const *, truc<int const>::const_pointer>::value << std::endl;
	std::cout << ft::are_same<int *, truc<int >::pointer>::value << std::endl;
    std::cout << ft::are_same<int *, truc<int >::const_pointer>::value << std::endl;
    std::cout << ft::are_same<std::vector<int>::const_iterator::pointer , int const *>::value << std::endl;

}

void	test_vector(void)
{
	vector_test_iterator();
	vector_test_reverse_iterator();
	vector_test_empty();
	vector_test_insert();
	vector_test_push_pop();
	vector_test_assign();
	vector_test_erase();
	vector_test_operator();
}

void	test_stack(void)
{
	stack_test();
}

void	test_map(void)
{
	test_pair();
	map_test_creation();
	map_test_capacity();
	map_test_insert();
	map_test_erase();
	map_test_iterator();
	map_test_others_functions();
}


void	test_set()
{
	set_test_constructor();
	set_test_iterator();
	test_bound();
	set_test_erase();
	set_test_find();
	set_test_insert();
	set_test_others_functions();
	set_test_size();
}

#include <list>
int main(void)
{
	PRINT(STR_NAMESPACE);
	PRINT(SEP_FUNCTIONS);
	
	// test_vector();
	// stack_test();
	// test_map();


	std::list<std::string> lst;
	std::list<std::string>::iterator itlst;

	lst.push_back("lol");
	lst.push_back("mdr");
	lst.push_back("funny");
	lst.push_back("bunny");
	lst.push_back("fizz");
	lst.push_back("this key is already inside");
	lst.push_back("fuzzy");
	lst.push_back("buzz");
	lst.push_back("inside too");

	std::cout << "List contains: " << lst.size() << " elements." << std::endl;
	for (itlst = lst.begin(); itlst != lst.end(); ++itlst)
		std::cout << *itlst << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	// ft::set<std::string> set(lst.begin(), lst.end());

	ft::set<std::string>	set;

	for (itlst = lst.begin(); itlst != lst.end(); itlst++)
	{
		std::cout << *itlst << std::endl;
		set.insert(*itlst);
	}

	std::cout << "end" << std::endl;
	lst.clear();


	ft::set<std::string>::iterator it = set.begin();
	for (; it != set.end(); it++)
		std::cout << *it << std::endl;


	return (0);
}



