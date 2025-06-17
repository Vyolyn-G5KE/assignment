#ifndef LIST_HPP
#define LIST_HPP

#include <cstddef>

template <typename T>
struct node_t {
	node_t* next_{};
	node_t* prev_{};
	T value_{};

	node_t();
	node_t(node_t* next, node_t* prev, const T& value);
};

template <typename T>
class iterator_t {
public:
	iterator_t(node_t<T>* node);

	const T& operator*() const;
	iterator_t& operator++();
	bool operator!=(const iterator_t& other) const;

private:
	node_t<T>* node_{};
};

template <typename T>
class list_t {
public:
	list_t();
	~list_t();

	iterator_t<T> begin() const;
	iterator_t<T> end() const;

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
	node_t<T>* head_{};
	std::size_t size_{};
};

template <typename T>
node_t<T>::node_t() : next_{ this }, prev_{ this } {}

template <typename T>
node_t<T>::node_t(node_t* next, node_t* prev, const T& value) : next_{ next }, prev_{ prev }, value_{ value } {}

template <typename T>
iterator_t<T>::iterator_t(node_t<T>* node) : node_{ node } {}

template <typename T>
const T& iterator_t<T>::operator*() const { return node_->value_; }

template <typename T>
iterator_t<T>& iterator_t<T>::operator++() { node_ = node_->next_; return *this; }

template <typename T>
bool iterator_t<T>::operator!=(const iterator_t& other) const { return node_ != other.node_; }

template <typename T>
list_t<T>::list_t() : head_{ new node_t<T>() } {}

template <typename T>
list_t<T>::~list_t() { clear(); delete head_; }

template <typename T>
iterator_t<T> list_t<T>::begin() const { return iterator_t<T>(head_->next_); }

template <typename T>
iterator_t<T> list_t<T>::end() const { return iterator_t<T>(head_); }

template <typename T>
std::size_t list_t<T>::size() const { return size_; }

template <typename T>
bool list_t<T>::empty() const { return size_ == 0; }

template <typename T>
const T& list_t<T>::front() const { /*if (empty()) return;*/ return head_->next_->value_; }

template <typename T>
const T& list_t<T>::back() const { /*if (empty()) return;*/ return head_->prev_->value_; }

template <typename T>
void list_t<T>::push_front(const T& value) {
	node_t<T>* node = new node_t<T>(head_->next_, head_, value);
	node->prev_->next_ = node;
	node->next_->prev_ = node;
	++size_;
}

template <typename T>
void list_t<T>::pop_front() {
	/*if (empty()) return;*/
	node_t<T>* node = head_->next_;
	node->prev_->next_ = node->next_;
	node->next_->prev_ = node->prev_;
	delete node;
	--size_;
}

template <typename T>
void list_t<T>::push_back(const T& value) {
	node_t<T>* node = new node_t<T>(head_, head_->prev_, value);
	node->prev_->next_ = node;
	node->next_->prev_ = node;
	++size_;
}

template <typename T>
void list_t<T>::pop_back() {
	/*if (empty()) return;*/
	node_t<T>* node = head_->prev_;
	node->prev_->next_ = node->next_;
	node->next_->prev_ = node->prev_;
	delete node;
	--size_;
}

template <typename T>
void list_t<T>::clear() {
	head_->prev_->next_ = nullptr;
	node_t<T>* node = head_->next_;
	for (node_t<T>* next{}; node; node = next) {
		next = node->next_;
		delete node;
	}
	head_->next_ = head_;
	head_->prev_ = head_;
	size_ = 0;
}

#endif  // LIST_HPP