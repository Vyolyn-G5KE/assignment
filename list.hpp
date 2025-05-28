#ifndef LIST_HPP
#define LIST_HPP

template <typename T>
struct node {
	node* next;
	node* prev;
	T value;

	node();
	node(node* next, node* prev, const T& value);
};

template <typename T>
class iterator {
public:
	iterator(node<T>* current);

	const T& operator*() const;
	iterator& operator++();
	bool operator!=(const iterator& other) const;

private:
	node<T>* current;
};

template <typename T>
class list {
public:
	list();
	~list();

	iterator<T> begin() const;
	iterator<T> end() const;

	size_t size() const;
	bool empty() const;
	const T& front() const;
	const T& back() const;

	void push_front(const T& value);
	void pop_front();
	void push_back(const T& value);
	void pop_back();
	void clear();

private:
	node<T>* head;
	size_t count;
};

template <typename T>
node<T>::node() : next(this), prev(this), value() {}

template <typename T>
node<T>::node(node* next, node* prev, const T& value) : next(next), prev(prev), value(value) {}

template <typename T>
iterator<T>::iterator(node<T>* current) : current(current) {}

template <typename T>
const T& iterator<T>::operator*() const { return current->value; }

template <typename T>
iterator<T>& iterator<T>::operator++() { current = current->next; return *this; }

template <typename T>
bool iterator<T>::operator!=(const iterator& other) const { return current != other.current; }

template <typename T>
list<T>::list() : head(new node<T>()), count(0) {}

template <typename T>
list<T>::~list() { clear(); delete head; }

template <typename T>
iterator<T> list<T>::begin() const { return iterator<T>(head->next); }

template <typename T>
iterator<T> list<T>::end() const { return iterator<T>(head); }

template <typename T>
size_t list<T>::size() const { return count; }

template <typename T>
bool list<T>::empty() const { return count == 0; }

template <typename T>
const T& list<T>::front() const { return head->next->value; }

template <typename T>
const T& list<T>::back() const { return head->prev->value; }

template <typename T>
void list<T>::push_front(const T& value) {
	node<T>* new_node = new node<T>(head->next, head, value);
	new_node->prev->next = new_node;
	new_node->next->prev = new_node;
	++count;
}

template <typename T>
void list<T>::pop_front() {
	if (count == 0) return;
	node<T>* delete_node = head->next;
	delete_node->prev->next = delete_node->next;
	delete_node->next->prev = delete_node->prev;
	delete delete_node;
	--count;
}

template <typename T>
void list<T>::push_back(const T& value) {
	node<T>* new_node = new node<T>(head, head->prev, value);
	new_node->prev->next = new_node;
	new_node->next->prev = new_node;
	++count;
}

template <typename T>
void list<T>::pop_back() {
	if (count == 0) return;
	node<T>* delete_node = head->prev;
	delete_node->prev->next = delete_node->next;
	delete_node->next->prev = delete_node->prev;
	delete delete_node;
	--count;
}

template <typename T>
void list<T>::clear() {
	node<T>* current = head->next;
	for (node<T>* next; current != head; current = next) {
		next = current->next;
		delete current;
	}
	head->next = head;
	head->prev = head;
	count = 0;
}

#endif // LIST_HPP