#ifndef LIST_HPP
#define LIST_HPP

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

	class iterator {
	public:
		iterator(node* current);

		const T& operator*() const;
		iterator& operator++();
		bool operator!=(const iterator& other) const;

		node* current;
	};

	node* head;
	size_t count;

public:
	list();
	~list();

	iterator begin() const;
	iterator end() const;

	size_t size() const;
	bool empty() const;
	const T& back() const;

	void push_back(const T& value);
	void pop_back();
	void clear();
};

template <typename T>
list<T>::node::node() : next(this), prev(this), value() {}

template <typename T>
list<T>::node::node(node* next, node* prev, const T& value) : next(next), prev(prev), value(value) {}

template <typename T>
list<T>::iterator::iterator(node* current) : current(current) {}

template <typename T>
const T& list<T>::iterator::operator*() const { return current->value; }

template <typename T>
typename list<T>::iterator& list<T>::iterator::operator++() { current = current->next; return *this; }

template <typename T>
bool list<T>::iterator::operator!=(const iterator& other) const { return current != other.current; }

template <typename T>
list<T>::list() : head(new node()), count(0) {}

template <typename T>
list<T>::~list() { clear(); delete head; }

template <typename T>
typename list<T>::iterator list<T>::begin() const { return iterator(head->next); }

template <typename T>
typename list<T>::iterator list<T>::end() const { return iterator(head); }

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
	if (count == 0) return;
	node* delete_node = head->prev;
	delete_node->prev->next = head;
	head->prev = delete_node->prev;
	delete delete_node;
	--count;
}

template <typename T>
void list<T>::clear() {
	node* current = head->next;
	for (node* next; current != head; current = next) {
		next = current->next;
		delete current;
	}
	head->next = head;
	head->prev = head;
	count = 0;
}

#endif LIST_HPP