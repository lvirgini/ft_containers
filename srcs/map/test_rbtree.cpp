#include "ft_stl.hpp"

#include <map>

void	test_node()
{

	M_NAMESPACE::pair<int, std::string> value5(5, "E");
	M_NAMESPACE::pair<int, std::string> value4(4, "D");
	M_NAMESPACE::pair<int, std::string> value3(3, "C");
	M_NAMESPACE::pair<int, std::string> value2(2, "B");
	M_NAMESPACE::pair<int, std::string> value1(1, "A");



	ft::Node< M_NAMESPACE::pair<int, std::string> >	node1(value1);
	ft::Node< M_NAMESPACE::pair<int, std::string> >	node2(value2);
	ft::Node< M_NAMESPACE::pair<int, std::string> >	node3(value3);
	ft::Node< M_NAMESPACE::pair<int, std::string> >	node4(value4);
	ft::Node< M_NAMESPACE::pair<int, std::string> >	node5(value5);
	


	node2.set_left(&node1);
	node2.set_right(&node4);
	
	node1.set_parent(&node2);
	node3.set_parent(&node4);
	node5.set_parent(&node4);
	
	
	node4.set_parent(&node2);
	node4.set_left(&node3);
	node4.set_right(&node5);
	

	ft::Node< M_NAMESPACE::pair<int, std::string> > *ptr = &node1;
	// ptr = node4._get_most_left();
	// std::cout << ptr->data.first << " " << ptr->data.second << std::endl;
	
	// ptr = node4._increment();
	// std::cout << ptr->data.first << " " << ptr->data.second << std::endl;



	while (ptr != NULL)
	{
		std::cout << ptr->data.first << " " << ptr->data.second << std::endl;
		ptr = ptr->_increment();
	}


	std::_Rb_tree_node< M_NAMESPACE::pair<int, std::string>	 >	std_node();
	// std::_Rb_tree<int,

}
