#ifndef LIST_HPP_
#define LIST_HPP_

#include <cstddef>

template <typename T>
struct node {
	node* next{};
	node* prev{};
	T value{};

	node();
	node(node* next, node* prev, const T& value);
};

template <typename T>
class iterator {
public:
	iterator(node<T>* node);

	const T& operator*() const;
	iterator& operator++();
	bool operator!=(const iterator& other) const;

private:
	node<T>* node_{};
};

template <typename T>
class list {
public:
	list();
	~list();

	iterator<T> begin() const;
	iterator<T> end() const;

	std::size_t size() const;
	bool empty() const;
	const T& front() const;
	const T& back() const;

	void push_front(const T& value);
	void pop_front();
	void push_back(const T& value);
	void pop_back();
	void clear();

private:
	node<T>* head_{};
	std::size_t size_{};
};

template <typename T>
node<T>::node() : next{ this }, prev{ this } {}

template <typename T>
node<T>::node(node* next, node* prev, const T& value) : next{ next }, prev{ prev }, value{ value } {}

template <typename T>
iterator<T>::iterator(node<T>* node) : node_{ node } {}

template <typename T>
const T& iterator<T>::operator*() const { return node_->value; }

template <typename T>
iterator<T>& iterator<T>::operator++() { node_ = node_->next; return *this; }

template <typename T>
bool iterator<T>::operator!=(const iterator& other) const { return node_ != other.node_; }

template <typename T>
list<T>::list() : head_{ new node<T>() } {}

template <typename T>
list<T>::~list() { clear(); delete head_; }

template <typename T>
iterator<T> list<T>::begin() const { return iterator<T>(head_->next); }

template <typename T>
iterator<T> list<T>::end() const { return iterator<T>(head_); }

template <typename T>
std::size_t list<T>::size() const { return size_; }

template <typename T>
bool list<T>::empty() const { return size_ == 0; }

template <typename T>
const T& list<T>::front() const { return head_->next->value; }

template <typename T>
const T& list<T>::back() const { return head_->prev->value; }

template <typename T>
void list<T>::push_front(const T& value) {
	node<T>* new_node = new node<T>(head_->next, head_, value);
	new_node->prev->next = new_node;
	new_node->next->prev = new_node;
	++size_;
}

template <typename T>
void list<T>::pop_front() {
	if (empty()) return;
	node<T>* delete_node = head_->next;
	delete_node->prev->next = delete_node->next;
	delete_node->next->prev = delete_node->prev;
	delete delete_node;
	--size_;
}

template <typename T>
void list<T>::push_back(const T& value) {
	node<T>* new_node = new node<T>(head_, head_->prev, value);
	new_node->prev->next = new_node;
	new_node->next->prev = new_node;
	++size_;
}

template <typename T>
void list<T>::pop_back() {
	if (empty()) return;
	node<T>* delete_node = head_->prev;
	delete_node->prev->next = delete_node->next;
	delete_node->next->prev = delete_node->prev;
	delete delete_node;
	--size_;
}

template <typename T>
void list<T>::clear() {
	head_->prev->next = nullptr;
	node<T>* current = head_->next;
	for (node<T>* next{}; current; current = next) {
		next = current->next;
		delete current;
	}
	head_->next = head_;
	head_->prev = head_;
	size_ = 0;
}

#endif  // LIST_HPP_