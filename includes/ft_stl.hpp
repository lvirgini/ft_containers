/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stl.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:14:04 by lvirgini          #+#    #+#             */
/*   Updated: 2022/05/02 12:24:50 by lvirgini         ###   ########.fr       */
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
# include <set>
# include <cstring>
# include <iostream>

# include "vector.hpp"
# include "stack.hpp"
# include "map.hpp"
# include "set.hpp"
# include "RedBlackTree.hpp"

# define SEP	" | "
# define SEP_FUNCTIONS "\n* -------------------------------------------------------------------------- *"
# define PRINT(x)	std::cout << x << std::endl


// typedef for simplify 
typedef M_NAMESPACE::map<int, std::string, M_NAMESPACE::less<int> >  named_map;
typedef std::map<int, std::string, std::less<int> >  std_map;
typedef ft::map<int, std::string, ft::less<int> >  ft_map;

typedef M_NAMESPACE::pair<int, std::string>	named_pair;
typedef ft::pair<int, std::string>			ft_pair;
typedef std::pair<int, std::string>			std_pair;

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
void	map_test_creation();
void	map_test_capacity();
void	map_test_insert();
void	map_test_erase();
void	map_test_iterator();
void	map_test_others_functions();


/* set */

void	set_test_constructor();
void	set_test_iterator();
void	test_bound();
void	set_test_erase();
void	set_test_find();
void	set_test_insert();
void	set_test_others_functions();
void	set_test_size();

# include "printer.tpp"

#endif
