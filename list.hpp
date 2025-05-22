#pragma once

#include <iostream>

template <typename T>
class list {
private:
	struct node {
		node* next;
		node* prev;
		T value;

		node();
		node(node* next, node* prev, const T& value);
	};

	node* head;
	size_t count;

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
};

template <typename T>
list<T>::node::node() : next(this), prev(this), value() {}

template <typename T>
list<T>::node::node(node* next, node* prev, const T& value) : next(next), prev(prev), value(value) {}

template <typename T>
list<T>::list() : head(new node()), count(0) {}

template <typename T>
list<T>::~list() { clear(); delete head; }

template <typename T>
size_t list<T>::size() const { return count; }

template <typename T>
bool list<T>::empty() const { return count == 0; }

template <typename T>
const T& list<T>::back() const { return head->prev->value; }

template <typename T>
void list<T>::push_back(const T& value) {
	node* new_node = new node(head, head->prev, value);
	head->prev->next = new_node;
	head->prev = new_node;
	++count;
}

template <typename T>
void list<T>::pop_back() {
	node* delete_node = head->prev;
	delete_node->prev->next = head;
	head->prev = delete_node->prev;
	delete delete_node;
	--count;
}

template <typename T>
void list<T>::clear() {
	head->prev->next = nullptr;
	node* current = head->next;
	for (node* next; current; current = next) {
		next = current->next;
		delete current;
	}
	head->next = head;
	head->prev = head;
	count = 0;
}

template <typename T>
void list<T>::print() const {
	node* current = head->next;
	while (current != head) {
		std::cout << current->value << " ";
		current = current->next;
	}
	std::cout << std::endl;
}
