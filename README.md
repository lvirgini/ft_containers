# ft_containers


Notes: 

inline: C++ provides an inline functions to reduce the function call overhead. Inline function is a function that is expanded in line when it is called. When the inline function is called whole code of the inline function gets inserted or substituted at the point of inline function call

--------------------------------------------------


__ : double underscore for everything that is used for implementation.
	it's convention for reserved the use only for implementation.

--------------------------------------------------


enable_if<bool, typename T> : 
	if bool is true : typedef T type.
	usefull for using with conditional

template < typename T>
enable_if <is_same<T,T> T>::type

--------------------------------------------------

is_something<T>
== is not one of overload is_something

is_something<int>
== is int

is_something<double>
== is double

...

--------------------------------------------------


Ressources:

ISO stdandard 98:
https://www.lirmm.fr/~ducour/Doc-objets/ISO+IEC+14882-1998.pdf


friend:
https://en.cppreference.com/w/cpp/language/friend
https://www.geeksforgeeks.org/friend-class-function-cpp/

Iterator:
https://h-deb.clg.qc.ca/Sujets/TrucsScouts/is_iterator.html
https://www.youtube.com/watch?v=F9eDv-YIOQ0


enable if:
https://h-deb.clg.qc.ca/Sujets/TrucsScouts/Comprendre_enable_if.html


rebind:
https://stackoverflow.com/questions/14148756/what-does-template-rebind-do

templates and SFINAE:
https://h-deb.clg.qc.ca/Sujets/Divers--cplusplus/SFINAE.html
https://www.youtube.com/watch?v=AvUMMljFzfI
https://www.youtube.com/watch?v=Vkck4EU2lOU

class comparator:
https://www.geeksforgeeks.org/comparator-class-in-c-with-examples/

Red Black tree:
https://www.geeksforgeeks.org/red-black-tree-set-1-introduction-2/
https://www.programiz.com/dsa/red-black-tree
https://ressources.unisciel.fr/algoprog/s46bst/emodules/rn00macours1/res/rn00cours-texte-xxx.pdf

Red Blakc tree increment stl code:
https://github.com/gcc-mirror/gcc/blob/master/libstdc%2B%2B-v3/src/c%2B%2B98/tree.cc


Red Black tree display exemple:
https://www.daniweb.com/programming/software-development/threads/146112/printing-a-binary-tree
https://stackoverflow.com/questions/801740/c-how-to-draw-a-binary-tree-to-the-console