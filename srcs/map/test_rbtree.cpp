#include "ft_stl.hpp"

#include <map>

// Testing nodes functions in codage progression
void	test_node_in_progression()
{

	ft::pair<int, std::string>		test(1, "A");
	ft::pair<int, std::string>		test2(2, "F");

		// test < test2.

	ft::less< ft::pair<int, std::string> > ft_less;

	std::cout << "less =>" << ft_less(test, test2) << std::endl;



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

	PRINT("TREE TESTING");
	
	ft::Rb_tree< ft::pair<int, std::string> >	tree;

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

	tree.insert(&node1);
	tree.insert(&node2);
	tree.insert(&node3);
	tree.insert(&node4);
	tree.insert(&node5);

	// testing print : 
	node1.print();
	node2.print();
	node3.print();
	node4.print();
	node5.print();

	PRINT("left rotate : node 1");

	tree._left_rotate(&node1);
	node1.print();
	node2.print();
	node3.print();
	node4.print();
	node5.print();


}

void	test_node()
{

	test_node_in_progression();
	test_tree_in_progression();

	ft::Rb_tree<ft::pair<int, std::string> >	tree;


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
