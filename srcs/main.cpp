/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:16:00 by lvirgini          #+#    #+#             */
/*   Updated: 2022/04/21 19:40:57 by lvirgini         ###   ########.fr       */
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
	// vector_test_iterator();
	// vector_test_reverse_iterator();
	// vector_test_empty();
	// vector_test_insert();
	// vector_test_push_pop();
	// vector_test_assign();
	// vector_test_erase();
	// test_operator();
}

void	test_stack(void)
{
	stack_test();
}

void	test_map(void)
{
	test_pair();
	// test_node();
	map_test_creation();
	map_test_capacity();
	map_test_insert();
	map_test_erase();
	map_test_iterator();
	map_test_others_functions();
}

int main(void)
{


	// return (0);

	PRINT(STR_NAMESPACE);
	PRINT(SEP_FUNCTIONS);
	
	// test_vector();
	// stack_test();
	test_map();

	return (0);
}



