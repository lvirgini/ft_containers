/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_test_size.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:58:13 by lvirgini          #+#    #+#             */
/*   Updated: 2022/04/23 20:11:12 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.hpp"

void	set_test_size()
{
	PRINT(SEP_FUNCTIONS);
	PRINT("SET test size, max_size and empty");

	M_NAMESPACE::set<int> myset;

	std::cout << myset.empty() << std::endl;
	std::cout << myset.size() << std::endl;
	std::cout << myset.max_size() << std::endl;

	myset.insert(20);
	myset.insert(30);
	myset.insert(10);

	std::cout << "myset contains:";
	
	std::cout << myset.empty() << std::endl;
	std::cout << myset.size() << std::endl;
	std::cout << myset.max_size() << std::endl;
	
	while (!myset.empty())
	{
		std::cout << ' ' << *myset.begin();
		myset.erase(myset.begin());
	}
	std::cout << '\n';

	std::cout << myset.empty() << std::endl;
	std::cout << myset.size() << std::endl;
	std::cout << myset.max_size() << std::endl;


	M_NAMESPACE::set<int> set2;
	std::cout << "0. size: " << set2.size() << '\n';

	for (int i=0; i<10; ++i) set2.insert(i);
	std::cout << "1. size: " << set2.size() << '\n';

	set2.insert (100);
	std::cout << "2. size: " << set2.size() << '\n';

	set2.erase(5);
	std::cout << "3. size: " << set2.size() << '\n';


  M_NAMESPACE::set<int> set3;

  if (set3.max_size()>1000)
  {
    for (int i=0; i<1000; i++) set3.insert(i);
    std::cout << "The set contains 1000 elements.\n";
  }
  else std::cout << "The set could not hold 1000 elements.\n";
}