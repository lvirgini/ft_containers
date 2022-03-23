# ft_containers


Rules:

	Containers STL : only C++98

	VECTOR  (pas obligatoire de coder la specialisation vector<bool>)
	MAP
	STACK (Votre pile utilisera votre classe vectorielle comme conteneur sous-jacent par défaut, il doit toujours être compatible avec d’autres conteneurs comme celui de STL.)


		- Les fonctions membres
		- les non-membres 
		- les overloads
		- les iterators
			iterators_traits				OK
			reverse_iterator
			enable_if						OK
			is_integral
			equal/lexicographical compare
			std ::pair
			std ::make_pair

	Vous devez utiliser std : :allocator






	VECTOR to do:

	//// const_iterator					OK

	//// iterator with two template		OK

	//// reverse_iterator				OK

	//// ~destroy vector alloc			OK

	//// ALL functions 
				swap
				push_back to check
				operator <
				constructor iterator



Notes: 

inline: C++ provides an inline functions to reduce the function call overhead. Inline function is a function that is expanded in line when it is called. When the inline function is called whole code of the inline function gets inserted or substituted at the point of inline function call


__ : double underscore for everything that is used for implementation.
	it's convention for reserved the use only for implementation.


enable_if<bool, typename T> : 
	if bool is true : typedef T type.
	usefull for using with conditional

template < typename T>
enable_if <is_same<T,T> T>::type



is_something<T>
== is not one of overload is_something

is_something<int>
== is int

is_something<double>
== is double