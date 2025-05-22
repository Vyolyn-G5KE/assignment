#include <iostream>
#include "list.hpp"

int main() {
	list<size_t> list;
	list.push_back(1);
	list.push_back(1);
	list.print();
	list.pop_back();
	list.print();
}