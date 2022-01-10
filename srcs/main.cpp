/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:16:00 by lvirgini          #+#    #+#             */
/*   Updated: 2022/01/10 23:12:31 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
# include <cstring>
#include "vector.hpp"

int main2(void)
{
	std::vector<int> 	v(5);
//	ft::vector<int>		v(5);


	std::cout << "function size : " << v.size() << std::endl;

	return (0);
}

void	test_iterator(void)
{
	std::vector<int>	stdV(10);
	ft::vector<int>		ftV(10);

	for( int i = 0; i < 10; i++)
	{
		stdV[i] = i;
		ftV[i] = i;
	}


	std::vector<int>::iterator	it_std = stdV.begin();
	ft::vector<int>::iterator	it_ft = ftV.begin();

	std::vector<int>::iterator	ite_std = stdV.end();
	ft::vector<int>::iterator	ite_ft = ftV.end();

	//std::cout << *(it_ft + it_ft) << std::endl;
	
	// in pos 1
	it_std += 15;
	it_std -= 13;

	it_ft += 15;
	it_ft -= 13;

	//ite_std - 

	// change the position 6;
	it_ft[4] = 0;
	it_std[4] = 0;

	//in pos 0
	it_std--;
	it_ft--;

	--it_ft;
	--it_std;

	

	while (it_std < ite_std)
	{
		std::cout << *it_std << " ";
		it_std++;
	//	++it_std;
	//	it_std += 2;
	//	it_std += 12;
	}
	std::cout << std::endl;


	while (it_ft < ite_ft)
	{
		std::cout << *it_ft << " ";
		it_ft++;
	//	++it_ft;
	//	it_ft += 2;
	//	it_ft += 12;
	}
	std::cout << std::endl;


}

int main(void)
{

	test_iterator();
	return (0);

	std::string			sep = " | ";

	std::vector<int>	stdEmpty;
	ft::vector<int>		ftEmpty;

	std::vector<int>	stdFive(5);
	ft::vector<int>		ftFive(5);

	std::vector<int>	stdValue(10, 10);
	ft::vector<int>		ftValue(10, 10);

	//std::vector<int>	stdInit = { 0, 1, 2, 3, 4};
	//ft::vector<int>		ftInit = {0, 1, 2, 3, 4};



	//double j = std::vector<double>::allocator_type();

	/*stdEmpty.assign(15, 789);
	stdEmpty.assign(0, 456);*/

/*	stdEmpty.insert(stdEmpty.begin(), 15);
	stdEmpty.push_back(456);

	for (size_t i = 0; i < stdEmpty.size(); i++)
		std::cout << i << " " << stdEmpty.at(i) << std::endl;
*/


/*	for (size_t i = 0; i < ftEmpty.size(); i++)
		std::cout << i << " " << ftEmpty.at(i) << std::endl;

	//stdFive.insert(stdFive.begin(), 15);
	//stdFive.push_back(456);

	for (size_t i = 0; i < stdFive.size(); i++)
		std::cout << i << " " << stdFive.at(i) << std::endl;

	for (size_t i = 0; i < ftFive.size(); i++)
		std::cout << i << " " << ftFive.at(i) << std::endl;

	for (size_t i = 0; i < ftValue.size(); i++)
		std::cout << i << " " << ftValue.at(i) << std::endl;

	for (size_t i = 0; i < stdValue.size(); i++)
		std::cout << i << " " << stdValue.at(i) << std::endl;*/


	// push_back()
	stdValue.push_back(123);
	stdValue.push_back(123);
	stdValue.push_back(123);
	stdValue.push_back(123);
	stdValue.push_back(123);
	stdValue.push_back(123);
	stdValue.push_back(123);
	stdValue.push_back(123);
	stdValue.push_back(123);
	stdValue.push_back(123);
/*	ftValue.push_back(123);
	ftValue.push_back(123);
	ftValue.push_back(123);*/

	// MAXSIZE()

	std::cout << std::endl << "vector.maxSize()" << std::endl;
	std::cout << stdEmpty.max_size() << sep << ftEmpty.max_size() << std::endl;
	std::cout << stdFive.max_size() << sep << ftFive.max_size() << std::endl;

	// SIZE()
	std::cout << std::endl << "vector.size() : " << std::endl << "std | ft" << std::endl; 
	std::cout << stdEmpty.size() << sep << ftEmpty.size() << std::endl;
	std::cout << stdFive.size() << sep << ftFive.size() << std::endl;
	std::cout << stdValue.size() << sep << ftValue.size() << std::endl;


	// capacity()
	std::cout << std::endl << "vector.capacity()" << std::endl;
	std::cout << stdEmpty.capacity() << sep << ftEmpty.capacity() << std::endl;
	std::cout << stdFive.capacity() << sep << ftFive.capacity() << std::endl;
	std::cout << stdValue.capacity() << sep << ftValue.capacity() << std::endl;



	//empty()

	std::cout << std::endl << "vector.empty()" << std::endl;
	std::cout << stdEmpty.empty() << std::endl;
	std::cout << stdFive.empty() << std::endl;
	std::cout << stdValue.empty() << std::endl;




	// AT()
	std::cout << std::endl << "vector.at()" << std::endl;
	try
	{
		ftEmpty.at(156) = 45;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		stdEmpty.at(156) = 45;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	// iterator : 


	std::vector<int>::iterator 	stdIt;
	ft::vector<int>::iterator 	ftIt;

	std::cout << *stdIt << std::endl;
	std::cout << *ftIt << std::endl;
//	std::vector<int>::iterator	stdit = stdValue.begin();
//	ft::vector<int>::iterator	ftit = ftValue.begin();

	return (0);
}
