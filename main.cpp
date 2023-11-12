#include <iostream>
#include "DoublyLinkedList.h"

int main()
{
	DoublyLinkedList myList;
	for (int i = 0; i < 5; ++i) {
		myList.push_back(i + 1);
	}
	
	try {
		myList.insert(1, 6);
	}
	catch(const std::out_of_range & e) {
		std::cerr << e.what() << std::endl;
		std::exit(1);
	}
	try {
		myList.remove(1);
	}
	catch (const std::out_of_range& e) {
		std::cerr << e.what() << std::endl;
		std::exit(1);
	}
	std::cout << myList.get(4) << std::endl;
	std::cout << myList.getSize() << std::endl;
	myList.printReverse();
	return 0;
}