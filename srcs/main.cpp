/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:16:00 by lvirgini          #+#    #+#             */
/*   Updated: 2022/01/27 15:35:47 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.hpp"

template <class T>
struct truc
{
    typedef T   type;
    typedef T*  pointer;
	typedef const T * const_pointer;


};

#include "type_traits.hpp"


int main(void)
{

    std::cout << ft::are_same<int const *, truc<int const>::pointer>::value << std::endl;
    std::cout << ft::are_same<int const *, truc<int const>::const_pointer>::value << std::endl;
	std::cout << ft::are_same<int *, truc<int >::pointer>::value << std::endl;
    std::cout << ft::are_same<int *, truc<int >::const_pointer>::value << std::endl;
    std::cout << ft::are_same<std::vector<int>::const_iterator::pointer , int const *>::value << std::endl;

	// return (0);

	PRINT(STR_NAMESPACE);
	PRINT(SEP_FUNCTIONS);
	
	test_iterator();
	test_reverse_iterator();
	test_empty();
	//test_insert();
	//test_vector();

	return (0);
}



