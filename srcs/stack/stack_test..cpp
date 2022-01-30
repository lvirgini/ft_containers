/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test_constructor.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:35:47 by lvirgini          #+#    #+#             */
/*   Updated: 2022/01/30 19:29:14 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.hpp"

void	stack_test_constructor(void)
{
	std::vector<int>		v;

	M_NAMESPACE::stack<int, std::vector<int> >	st(v);
	M_NAMESPACE::stack<int, std::vector<int> >	st2;

	PRINT("TESTING STACK <vector>");
	PRINT(SEP_FUNCTIONS);

	PRINT("empty vector :");
	std::cout << "stack.empty() :" << st.empty() << std::endl;
	std::cout <<"stack.size() " << st.size() << std::endl;

	PRINT(SEP_FUNCTIONS);
	PRINT("push * 10");
	for (int i = 0; i < 10; i++)
		st.push(5);

	std::cout << "stack.empty() :" << st.empty() << std::endl;
	std::cout <<"stack.size() :" << st.size() << std::endl;

	PRINT(SEP_FUNCTIONS);
	PRINT("pop one");
	st.pop();

	std::cout << "stack.empty() :" << st.empty() << std::endl;
	std::cout <<"stack.size() :" << st.size() << std::endl;



	PRINT(SEP_FUNCTIONS);
	PRINT("test operator st2 = st");
	
	st2 = st;

	std::cout<< "(st2 == st)	:" << (st2 == st) << std::endl;
	std::cout<< "(st2 != st)	:" << (st2 != st) << std::endl;
	std::cout<< "(st2 < st)	:" << (st2 < st) << std::endl;
	std::cout<< "(st2 >= st)	:" << (st2 <= st) << std::endl;
	std::cout<< "(st2 > st)	:" << (st2 > st) << std::endl;
	std::cout<< "(st2 >= st)	:" << (st2 >= st) << std::endl;


	PRINT(SEP_FUNCTIONS);
	PRINT("test operator after one push() on st2");

	st.push(78);
	std::cout<< "(st2 == st)	:" << (st2 == st) << std::endl;
	std::cout<< "(st2 != st)	:" << (st2 != st) << std::endl;
	std::cout<< "(st2 < st)	:" << (st2 < st) << std::endl;
	std::cout<< "(st2 >= st)	:" << (st2 <= st) << std::endl;
	std::cout<< "(st2 > st)	:" << (st2 > st) << std::endl;
	std::cout<< "(st2 >= st)	:" << (st2 >= st) << std::endl;

	PRINT(SEP_FUNCTIONS);
}
