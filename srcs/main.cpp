/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:16:00 by lvirgini          #+#    #+#             */
/*   Updated: 2022/01/19 10:19:33 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <cstring>
#include "ft_stl.hpp"

template <typename T>
void	print_all_functions(std::vector<T> & STD, ft::vector<T> & FT)
{
	
	std::string			sep = " | ";


	// std::cout << std::endl << "vector.maxSize()" << std::endl;
	// std::cout << STD.max_size() << sep << FT.max_size() << std::endl;

	// SIZE()
	std::cout << std::endl << "vector.size() : " << std::endl << "std | ft" << std::endl; 
	std::cout << STD.size() << sep << FT.size() << std::endl;


	// capacity()
	std::cout << std::endl << "vector.capacity()" << std::endl;
	std::cout << STD.capacity() << sep << FT.capacity() << std::endl;


	//empty()
	std::cout << std::endl << "vector.empty()" << std::endl;
	std::cout << STD.empty() << sep << FT.empty() << std::endl;

}

template <typename T>
void	print_all_value(std::vector<T> & v)
{
	int i = 0;
	typename std::vector<T>::iterator 	std_it = v.begin();
	typename std::vector<T>::iterator 	std_ite = v.end();

	while (std_it != std_ite)
	{
		std::cout << i++ << "	value = " << *std_it << std::endl;
		std_it++;
	}
	std::cout << std::endl;

}

template <typename T>
void	print_all_value(ft::vector<T> & v)
{
	int i = 0;
	typename ft::vector<T>::iterator 	std_it = v.begin();
	typename ft::vector<T>::iterator 	std_ite = v.end();

	while (std_it != std_ite)
	{
		std::cout << i++ << "	value = " << *std_it << std::endl;
		std_it++;
	}
	std::cout << std::endl;
}





int main2(void)
{
	std::vector<int> 	v(5);
//	ft::vector<int>		v(5);


	std::cout << "function size : " << v.size() << std::endl;

	return (0);
}





int main(void)
{

	test_iterator();
	std::string			sep = " | ";

	std::vector<int>	stdEmpty;
	ft::vector<int>		ftEmpty;

	std::vector<int>	stdFive(5);
	ft::vector<int>		ftFive(5);

	std::vector<int>	stdValue(10, 10);
	ft::vector<int>		ftValue(10, 10);

	stdValue.push_back(123);

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


	// TESTING ASSIGNEMENT : 
	std::cout << "TESTING ASSIGN()" << std::endl;


	stdEmpty.assign(5, 10);
	stdEmpty.assign(2, 10);
	stdEmpty.assign(3, 10);
	stdEmpty.resize(4, 45);

	// ftEmpty.assign(5, 10);


	// print_all_value(stdEmpty);
	// print_all_value(ftEmpty);
	// print_all_functions(stdEmpty, ftEmpty);
	// std::vector<int>::iterator 	std_it = stdEmpty.begin();
	// std::vector<int>::iterator 	std_ite = stdEmpty.end();

	// while (std_it != std_ite)
	// {
	// 	std::cout << "value = " << *std_it << std::endl;
	// 	std_it++;
	// }


	// std::cout << std::endl << "vector.maxSize()" << std::endl;
	// std::cout << stdEmpty.max_size() << sep << ftEmpty.max_size() << std::endl;

	// // SIZE()
	// std::cout << std::endl << "vector.size() : " << std::endl << "std | ft" << std::endl; 
	// std::cout << stdEmpty.size() << sep << ftEmpty.size() << std::endl;


	// // capacity()
	// std::cout << std::endl << "vector.capacity()" << std::endl;
	// std::cout << stdEmpty.capacity() << sep << ftEmpty.capacity() << std::endl;



	// //empty()
	// std::cout << std::endl << "vector.empty()" << std::endl;
	// std::cout << stdEmpty.empty() << std::endl;




/// test

	std::vector<int>	std_insert(10, 10);
	ft::vector<int>		ft_insert(10, 10); 

	//std_insert.push_back(77);
	// std_insert.push_back(77);

	std::vector<int>::iterator 	std_it_erase = std_insert.erase(std_insert.end() - 5, std_insert.end());
	ft::vector<int>::iterator 	ft_it_erase = ft_insert.erase(ft_insert.end() - 5, ft_insert.end());

	std_insert.back() = 22;
	ft_insert.back() = 22;

	std_it_erase = std_insert.erase(std_insert.end() - 1);
	ft_it_erase = ft_insert.erase(ft_insert.end() - 1);	


	std::cout << "Erase medium data" << std::endl << *std_it_erase << std::endl;
	std::cout << *ft_it_erase << std::endl;


//  std_insert.insert(std_insert.end(), 5);
//  std_insert.insert(std_insert.end(), 5);


//std_insert.clear();
//std_insert.insert(std_insert.end() - 2, 44);

	std_insert.front() = 55;
	ft_insert.front() = 55;

	std_insert.back() = 22;
	ft_insert.back() = 22;

	std_insert.pop_back();
	ft_insert.pop_back();

	std_insert.clear();
	ft_insert.clear();

	print_all_functions(std_insert, ft_insert);
	print_all_value(std_insert);
	print_all_value(ft_insert);


	return (0);
}



