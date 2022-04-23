/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test_others_functions.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:17:56 by lvirgini          #+#    #+#             */
/*   Updated: 2022/04/23 14:48:11 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.hpp"

void	map_test_key_comp()
{
	PRINT(SEP_FUNCTIONS);
	PRINT("map test key_comp()");

	M_NAMESPACE::map<char,int> mymap;
	M_NAMESPACE::map<char,int>::key_compare mycomp = mymap.key_comp();

	mymap['a']=100;
	mymap['b']=200;
	mymap['c']=300;

	std::cout << "mymap contains:\n";

	char highest = mymap.rbegin()->first;     // key value of last element

	M_NAMESPACE::map<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mycomp((*it++).first, highest) );

	std::cout << std::endl;
}


void	map_test_value_comp()
{
		PRINT(SEP_FUNCTIONS);
		PRINT("map test value_comp()");

		M_NAMESPACE::map<char, int>		mymap;

		mymap['x']=1001;
		mymap['y']=2002;
		mymap['z']=3003;

		std::cout << "mymap contains:\n";

		M_NAMESPACE::pair<char,int> highest = *mymap.rbegin();          // last element

		M_NAMESPACE::map<char,int>::iterator it = mymap.begin();
		do {
		std::cout << it->first << " => " << it->second << '\n';
		} while ( mymap.value_comp()(*it++, highest) );
}


void	map_test_lower_bound()
{
	PRINT(SEP_FUNCTIONS);
	PRINT("map test lower_bound()");

	M_NAMESPACE::map<char,int> mymap;
	M_NAMESPACE::map<char,int>::iterator itlow,itup;

	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;

	itlow = mymap.lower_bound ('b');  // itlow points to b

	itup = mymap.upper_bound ('d');   // itup points to e (not d!)
	
	mymap.erase(itlow,itup);        // erases [itlow,itup)

	// print content:
	for (M_NAMESPACE::map<char,int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

}


void	map_test_count()
{
	PRINT(SEP_FUNCTIONS);
	PRINT("map test count");

	M_NAMESPACE::map<char,int> mymap;
	char c;

	mymap ['a']=101;
	mymap ['c']=202;
	mymap ['f']=303;

	for (c='a'; c<'h'; c++)
	{
	std::cout << c;
	if (mymap.count(c)>0)
		std::cout << " is an element of mymap.\n";
	else 
		std::cout << " is not an element of mymap.\n";
	}
}


void	map_test_equal_range()
{
	PRINT(SEP_FUNCTIONS);
	PRINT("map test equal range");
	
	M_NAMESPACE::map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	M_NAMESPACE::pair< M_NAMESPACE::map<char,int>::iterator, M_NAMESPACE::map<char,int>::iterator > ret;
	ret = mymap.equal_range('b');

	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << std::endl;

	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << std::endl;

}

void	map_test_get_allocator()
{

	PRINT(SEP_FUNCTIONS);
	PRINT("map test get allocator");

	int psize;
	M_NAMESPACE::map<char,int> 			mymap;
	M_NAMESPACE::pair<const char,int> * p;

	// allocate an array of 5 elements using mymap's allocator:
	p=mymap.get_allocator().allocate(5);

	// assign some values to array
	psize = sizeof(M_NAMESPACE::map<char,int>::value_type) * 5;

	std::cout << "The allocated array has a size of " << psize << " bytes." << std::endl;

	mymap.get_allocator().deallocate(p,5);

}

void	map_test_operator_crochet()
{	
	PRINT(SEP_FUNCTIONS);
	PRINT("map test operator []");
	
	M_NAMESPACE::map<char,std::string> 			mymap;

	mymap['a']="an element";
	mymap['b']="another element";
	mymap['c']=mymap['b'];

	std::cout << "mymap['a'] is " << mymap['a'] << '\n';
	std::cout << "mymap['b'] is " << mymap['b'] << '\n';
	std::cout << "mymap['c'] is " << mymap['c'] << '\n';
	std::cout << "mymap['d'] is " << mymap['d'] << '\n';

	std::cout << "mymap now contains " << mymap.size() << " elements.\n";

}


void	map_test_swap()
{
	PRINT(SEP_FUNCTIONS);
	PRINT("map test swap");

	M_NAMESPACE::map<char,int> foo, bar, third;

	foo['x']=100;
	foo['y']=200;

	bar['a']=11;
	bar['b']=22;
	bar['c']=33;

	third['i'] = 1;
	third['j'] = 2;
	third['k'] = 3;
	third['l'] = 4;
	third['m'] = 5;
	third['n'] = 6;

	foo.swap(bar);
	swap(third, foo);

	std::cout << "foo contains:\n";
	for (M_NAMESPACE::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
	std::cout << it->first << " => " << it->second << '\n';

	std::cout << "bar contains:\n";
	for (M_NAMESPACE::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
	std::cout << it->first << " => " << it->second << '\n';

	std::cout << "third contains:\n";
	for (M_NAMESPACE::map<char,int>::iterator it=third.begin(); it!=third.end(); ++it)
	std::cout << it->first << " => " << it->second << '\n';

}

void	map_test_comparaison_operator()
{
	PRINT(SEP_FUNCTIONS);
	PRINT("map test comparaison operator");

	M_NAMESPACE::map<char,int> foo,foo2, bar;

	foo['a']=100;
	foo['b']=200;

	foo2 = foo;

	bar['a']=10;
	bar['z']=1000;

	// foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

	std::cout << std::endl;
	// foo vs foo2 ==
	if (foo==foo2) std::cout << "foo and foo2 are equal\n";
	if (foo!=foo2) std::cout << "foo and foo2 are not equal\n";
	if (foo< foo2) std::cout << "foo is less than foo2\n";
	if (foo> foo2) std::cout << "foo is greater than foo2\n";
	if (foo<=foo2) std::cout << "foo is less than or equal to foo2\n";
	if (foo>=foo2) std::cout << "foo is greater than or equal to foo2\n";
	std::cout << (foo == bar ? "foo and bar are equal" : "foo and bar are not equal") << std::endl;

}

void	map_test_others_functions()
{
	map_test_value_comp();
	map_test_key_comp();
	map_test_lower_bound();
	map_test_count();
	map_test_equal_range();
	map_test_get_allocator();
	map_test_operator_crochet();
	map_test_swap();
	map_test_comparaison_operator();
}
