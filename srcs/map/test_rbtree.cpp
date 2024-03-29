#include "ft_stl.hpp"

#include <map>



void		create_tree(ft::Rb_tree< ft::pair<int, std::string> >::reference tree)
{

	// Init pair of value
	ft::pair<int, std::string> value5(5, "E");
	ft::pair<int, std::string> value4(4, "D");
	ft::pair<int, std::string> value3(3, "C");
	ft::pair<int, std::string> value2(2, "B");
	ft::pair<int, std::string> value1(1, "A");
	ft::pair<int, std::string> value6(6, "A");
	ft::pair<int, std::string> value8(8, "A");
	ft::pair<int, std::string> value0(0, "A");
	ft::pair<int, std::string> value1m(-1, "A");


	tree.insert(value1);
	tree.insert(value2);
	tree.insert(value3);
	tree.insert(value4);
	tree.insert(value5);
	tree.insert(value6);
	tree.insert(value0);
	tree.insert(value8);
	tree.insert(value1m);
}

// Testing nodes functions in codage progression
void	test_node_in_progression()
{

	ft::pair<int, std::string>		test(3, "A");
	ft::pair<int, std::string>		test2(3, "A");
	ft::pair<int, std::string>		test3(3, "C");

		// test < test2.

	ft::less< ft::pair<int, std::string> > ft_less;

	std::cout << "less (3,A)(3,A) =>" << ft_less(test, test2) << std::endl;
	std::cout << "less (3,A)(3,C) =>" << ft_less(test, test3) << std::endl;
	PRINT(SEP_FUNCTIONS);


	// Init pair of value
	ft::pair<int, std::string> value5(5, "E");
	ft::pair<int, std::string> value4(4, "D");
	ft::pair<int, std::string> value3(3, "C");
	ft::pair<int, std::string> value2(2, "B");
	ft::pair<int, std::string> value1(1, "A");

	// init nodes
	ft::Node< ft::pair<int, std::string> >	node1(value1);
	ft::Node< ft::pair<int, std::string> >	node2(value2);
	ft::Node< ft::pair<int, std::string> >	node3(value3);
	ft::Node< ft::pair<int, std::string> >	node4(value4);
	ft::Node< ft::pair<int, std::string> >	node5(value5);


	// test less
	std::cout << "less(node1, node2) = " << ft_less(node1.data, node2.data) << std::endl;
	PRINT(SEP_FUNCTIONS);


	// making genealogic link
	node2.left = &node1;
	node2.right = &node4;
	
	node1.parent = &node2;
	node3.parent = &node4;
	node5.parent = &node4;
	
	
	node4.parent = &node2;
	node4.left = &node3;
	node4.right = &node5;


	// testing print : 
	node5.print();
	PRINT(SEP_FUNCTIONS);

	
	// testing functions node.
	std::cout << "node2 :" << std::endl;
	std::cout << "most left = " << node2.get_most_left()->data.first << std::endl;
	std::cout << "most right = " << node2.get_most_right()->data.first << std::endl << std::endl;
	

	std::cout << "node 4 :" << std::endl;
	std::cout << "most left = " << node4.get_most_left()->data.first << std::endl;
	std::cout << "most right = " << node4.get_most_right()->data.first << std::endl;
	std::cout << "sister = " << node4.get_sister()->data.first << std::endl << std::endl;

	std::cout << "node 3 :" << std::endl;
	std::cout << "grand_parent = " << node3.get_grand_parent()->data.first << std::endl;
	std::cout << "aunt = " << node3.get_aunt()->data.first << std::endl << std::endl;

	// std::_Rb_tree_node< M_NAMESPACE::pair<int, std::string>	 >	std_node;
	// node1.

	PRINT(SEP_FUNCTIONS);
}



void	test_tree_in_progression()
{
	PRINT(SEP_FUNCTIONS);
	PRINT("TREE TESTING");
	
	ft::Rb_tree< ft::pair<int, std::string> >	tree;


	std::cout << "created tree" << std::endl;
	// Init pair of value
	ft::pair<int, std::string> value5(5, "E");
	ft::pair<int, std::string> value4(4, "D");
	ft::pair<int, std::string> value3(3, "C");
	ft::pair<int, std::string> value2(2, "B");
	ft::pair<int, std::string> value1(1, "A");
	ft::pair<int, std::string> value6(6, "A");
	ft::pair<int, std::string> value8(8, "A");
	ft::pair<int, std::string> value0(0, "A");
	ft::pair<int, std::string> value1m(-1, "A");

	// init nodes
	// ft::Node< ft::pair<int, std::string> >	node1(value1);
	// ft::Node< ft::pair<int, std::string> >	node2(value2);
	// ft::Node< ft::pair<int, std::string> >	node3(value3);
	// ft::Node< ft::pair<int, std::string> >	node4(value4);
	// ft::Node< ft::pair<int, std::string> >	node5(value5);
	// ft::Node< ft::pair<int, std::string> >	node6(value0);
	// ft::Node< ft::pair<int, std::string> >	node7(value1m);
	// ft::Node< ft::pair<int, std::string> >	node8(value8);
	// ft::Node< ft::pair<int, std::string> >	node9(value6);

	// tree.insert(&node1);
	// tree.insert(&node2);
	// tree.insert(&node3);
	// tree.insert(&node4);
	// tree.insert(&node5);
	// tree.insert(&node6);
	// tree.insert(&node7);
	// tree.insert(&node8);
	// tree.insert(&node9);

	tree.insert(value1);
	tree.insert(value2);
	tree.insert(value3);
	tree.insert(value4);
	tree.insert(value5);
	tree.insert(value6);
	tree.insert(value0);
	tree.insert(value8);
	tree.insert(value1m);

	// testing print : 
	// node1.print();
	// node2.print();
	// node3.print();
	// node4.print();
	// node5.print();
	// node6.print();
	// node7.print();
	// node8.print();
	// node9.print();

	// testing print all
	PRINT(SEP_FUNCTIONS);
	std::cout << std::endl;
	tree.minimum()->print();
	tree.maximum()->print();
	tree.minimum()->increment()->print();


	PRINT(SEP_FUNCTIONS);
	PRINT("ALL TREE");
	// ft::Node< ft::pair<int, std::string> > *node_begin = tree.minimum();

	// ft::Node< ft::pair<int, std::string> > *node_end = tree.maximum();

	// for (; node_begin != NULL; node_begin = node_begin->increment())
	// 	node_begin->print();


	tree.display();

	// ft::Node < ft::pair<int, std::string> > *node_search = tree.find(value1);

	// std::cout << "search result is ";
	// if (node_search == NULL)
	// 	std::cout << "NULL";
	// else
	// 	std::cout << node_search->data.first;
	// std::cout << std::endl;
		
	// tree.erase(value1);

	// std::cout << tree.find(value0)->data.first << std::endl;

	tree.display();
}


void	test_rbtree_iterator()
{
	PRINT(SEP_FUNCTIONS);
	PRINT("ITERATOR");


	ft::Rb_tree<ft::pair <int, std::string> >	tree;
	
	create_tree(tree);
	tree.display();

	ft::Rb_tree<ft::pair <int, std::string> >::iterator it = tree.begin();
	ft::Rb_tree<ft::pair <int, std::string> >::iterator ite = tree.end();
	
	// std::_Rb_tree<ft::pair < int, std::string> > std_tree;

	// std_tree.insert()
	// std::_Rb_tree<ft::pair < int, std::string> >::iterator std_it = 
	// ft::pair <int, std::string>	pair;


	// std::cout << it->first << " " << it->second << std::endl;
	// it++;
	// std::cout << it->first << " " << it->second << std::endl;


	// std::cout << &(*ite) << std::endl;

	PRINT("TEST ITERATOR");
	for (; it != ite; it++)
	{
		// std::cout << &(*it) << std::endl;
		std::cout << it->first << " " << it->second <<  std::endl;
	}

	ft::Rb_tree<ft::pair <int, std::string> >::const_iterator cit = tree.begin();
	return ;
	ft::Rb_tree<ft::pair <int, std::string> >::const_iterator cite = tree.end();
	PRINT("TEST CONST ITERATOR");
	
	std::cout << &(*ite) << std::endl;

	std::cout << cit->first << " " << cit->second << std::endl;
	cit++;
	std::cout << cit->first << " " << cit->second << std::endl;

	for (; cit != cite; cit++)
	{

		// std::cout << &(*cit) << std::endl;
		std::cout << cit->first << " " << cit->second <<  std::endl;
	}
	std::cout << std::endl;

}

void	test_node()
{

	test_node_in_progression();
	test_tree_in_progression();
	test_rbtree_iterator();

	// ft::Rb_tree<ft::pair<int, std::string> >	tree;


	// std::_Rb_tree<int,

	// tree.insert(value1);
	// tree.insert(value2);
	// tree.insert(value3);
	// tree.insert(value4);
	// tree.insert(value5);

	// return ;

	// while (ptr != NULL)
	// {
	// 	std::cout << ptr->data.first << " " << ptr->data.second << std::endl;
	// 	ptr = ptr->increment();
	// }

}
