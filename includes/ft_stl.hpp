/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stl.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:14:04 by lvirgini          #+#    #+#             */
/*   Updated: 2022/03/24 09:50:16 by lvirgini         ###   ########.fr       */
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

# include <vector>
# include <stack>
# include <map>
# include <cstring>
# include <iostream>

# include "vector.hpp"
# include "stack.hpp"
# include "map.hpp"

# define SEP	" | "
# define SEP_FUNCTIONS "\n* -------------------------------------------------------------------------- *"
# define PRINT(x)	std::cout << x << std::endl

/*
** Function PRINT vector
*/

template <typename T>
void	print_all_functions(M_NAMESPACE::vector<T> & v);

template <typename T>
void	print_all_functions(std::vector<T> & STD, ft::vector<T> & FT);

template <typename T>
void	print_all_value(M_NAMESPACE::vector<T> & v);

template <typename T>
void	print_all_value(std::vector<T> & STD, ft::vector<T> & FT);

template <typename T>
void	print_vector(M_NAMESPACE::vector<T> & v);

/*
** Function TEST
*/


/* Vector */
void	vector_test_iterator(void);
void	vector_test_reverse_iterator(void);
void	vector_test_empty(void);
void	vector_test_erase(void);
void	vector_test_vector(void);
void	vector_test_insert(void);
void	vector_test_push_pop(void);
void	vector_test_assign(void);
void	vector_test_operator(void);

/* stack */
void	stack_test(void);


/* map */
void	test_node();
void	test_pair();


# include "printer.tpp"

#endif
