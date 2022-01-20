/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stl.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:14:04 by lvirgini          #+#    #+#             */
/*   Updated: 2022/01/19 14:02:37 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STL_HPP
# define FT_STL_HPP

#include <vector>
#include <iostream>
#include <cstring>
#include "vector.hpp"

# define SEP	" | "
# define SEP_FUNCTIONS "\n* -------------------------------------------------------------------------- *"
# define PRINT(x)	std::cout << x << std::endl

template <typename T>
void	print_all_functions(std::vector<T> & STD, ft::vector<T> & FT);

template <typename T>
void	print_all_value(std::vector<T> & v);

template <typename T>
void	print_all_value(ft::vector<T> & v);

template <typename T>
void	print_all_value(std::vector<T> & STD, ft::vector<T> & FT);

void	test_iterator(void);
void	test_const_iterator(void);
void	test_empty(void);
void	test_erase(void);
void	test_vector(void);



# include "printer.tpp"

#endif
