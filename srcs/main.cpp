/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:16:00 by lvirgini          #+#    #+#             */
/*   Updated: 2022/05/02 16:30:33 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.hpp"
#include "type_traits.hpp"


int subject_main(int argc, char **argv);

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
	test_type_trait();
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

int main(int argc, char** argv)
{
	PRINT(STR_NAMESPACE);
	PRINT(SEP_FUNCTIONS);
	
	test_vector();
	stack_test();
	test_map();
	test_set();
	
	if (argc == 2)
		subject_main(argc, argv);
	return (0);

}

/* -------------------------------------------------------------------------- */
/*		MAIN FROM SUBJECT 42 :												  */
/* -------------------------------------------------------------------------- */


#include <iostream>
#include <string>
#include <deque>
#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public ft::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};





int subject_main(int argc, char **argv) {
	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);

	M_NAMESPACE::vector<std::string> vector_str;
	M_NAMESPACE::vector<int> vector_int;
	M_NAMESPACE::stack<int> stack_int;
	M_NAMESPACE::vector<Buffer> vector_buffer;
	M_NAMESPACE::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	M_NAMESPACE::map<int, int> map_int;

	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	M_NAMESPACE::vector<Buffer>().swap(vector_buffer);

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}
	
	for (int i = 0; i < COUNT; ++i)
	{
		map_int.insert(M_NAMESPACE::make_pair(rand(), rand()));
	}

	int sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		int access = rand();
		sum += map_int[access];
	}
	std::cout << "should be constant with the same seed: " << sum << std::endl;

	{
		M_NAMESPACE::map<int, int> copy = map_int;
	}
	MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;
	return (0);
}


