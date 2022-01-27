/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stl.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:14:04 by lvirgini          #+#    #+#             */
/*   Updated: 2022/01/27 17:08:55 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STL_HPP
# define FT_STL_HPP

# ifndef M_NAMESPACE
#  define M_NAMESPACE	ft
#  define STR_NAMESPACE	"ft"
# endif

# ifndef STR_NAMESPACE
#  define STR_NAMESPACE	"std"
# endif

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
void	print_all_functions(M_NAMESPACE::vector<T> & v);

template <typename T>
void	print_all_value(M_NAMESPACE::vector<T> & v);

template <typename T>
void	print_all_value(std::vector<T> & STD, ft::vector<T> & FT);

void	test_iterator(void);
void	test_reverse_iterator(void);
void	test_empty(void);
void	test_erase(void);
void	test_vector(void);
void	test_insert(void);



# include "printer.tpp"

#endif
