#pragma once

#include <iostream>

template <typename T>
struct node {
	node* next;
	node* prev;
	T value;
	node();
	node(node* next, node* prev, const T& value);
};

template <typename T>
class list {
public:
	list();
	~list();
	size_t size() const;
	bool empty() const;
	const T& back() const;
	void push_back(const T& value);
	void pop_back();
	void clear();
	void print() const;
private:
	node<T>* head;
	size_t count;
};

template <typename T>
node<T>::node() : next(this), prev(this), value() {}

template <typename T>
node<T>::node(node* next, node* prev, const T& value) : next(next), prev(prev), value(value) {}

template <typename T>
list<T>::list() : head(new node<T>()), count(0) {}

template <typename T>
list<T>::~list() { clear(); delete head; }

template <typename T>
size_t list<T>::size() const {
	return count;
}

template <typename T>
bool list<T>::empty() const {
	return count == 0;
}

template <typename T>
const T& list<T>::back() const {
	return head->prev->value;
}

template <typename T>
void list<T>::push_back(const T& value) {
	node<T>* new_node = new node<T>(head, head->prev, value);
	head->prev->next = new_node;
	head->prev = new_node;
	++count;
}

template <typename T>
void list<T>::pop_back() {
	node<T>* delete_node = head->prev;
	delete_node->prev->next = head;
	head->prev = delete_node->prev;
	delete delete_node;
	--count;
}

template <typename T>
void list<T>::clear() {
	while (!empty()) {
		pop_back();
	}
}

template <typename T>
void list<T>::print() const {
	node<T>* current = head->next;
	while (current != head) {
		std::cout << current->value << " ";
		current = current->next;
	}
	std::cout << std::endl;
}
