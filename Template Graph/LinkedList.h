#include "ILinkedList.h"

#include <stdexcept>
#include "IMatrixGraph.h"
template<class T>
LinkedList<T>::LinkedList() :head(nullptr), _n(0)
{
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>&list)
{
	copy(list);
}

template<class T>
LinkedList<T>::LinkedList(LinkedList<T>&& list)
{
	move(std::move(list));
}

template<class T>
LinkedList<T> & LinkedList<T>::operator=(const LinkedList<T>& list)
{
	if (&list != this)
	{
		this->~LinkedList();
		copy(list);
	}
	return *this;
}

template<class T>
LinkedList<T> &LinkedList<T>::operator=(LinkedList<T>&& list)
{
	if (&list != this)
	{
		this->~LinkedList();
		move(std::move(list));
	}
	return *this;

}

template<class T>
LinkedList<T>::~LinkedList()
{
	clear();
}

template<class T>
bool LinkedList<T>::is_empty() const noexcept
{
	return _n == 0;
}

template<class T>
bool LinkedList<T>::contains(T value) const noexcept
{
	Node<T>* tmp;
	for (tmp = head; tmp != nullptr && (tmp->getData() != value); tmp = tmp->getNext());
	if (tmp != nullptr)
		return true;
	return false;
}

template<class T>
bool LinkedList<T>::add(T data)
{
	head = new Node<T>(data, head);
	++_n;
	return true;
}

template<class T>
bool LinkedList<T>::add_back(T data)
{
	if (head == nullptr)
		add(data);
	else {
		search(_n - 1).setNext(new Node<T>(data));
		++_n;
	}
	return true;
}

template<class T>
void LinkedList<T>::remove()
{
	if (head != nullptr) {
		Node<T>* temp = head;
		head = head->getNext();
		delete temp;
		--_n;
	}

}

template<class T>
bool LinkedList<T>::operator==(const LinkedList<T>& list) const noexcept
{
	if (_n != list._n) return false;
	Node<T>* second = list.head, *first = head;
	for (; second && (second->getData() == first->getData());
		second = second->getNext(), first = first->getNext());
	if (second == nullptr)
		return true;
	return false;
}

template<class T>
const T & LinkedList<T>::operator[](int i) const noexcept(false)
{
	if (out_of_range(i))
		throw(std::out_of_range("Location is out of range."));
	return search(i).getData();
}
template<class T>
inline T & LinkedList<T>::operator[](int i) noexcept(false)
{
	if (out_of_range(i))
		throw(std::out_of_range("Location is out of range."));
	return search(i).getData();
}
template<class T>
int LinkedList<T>::position_of(T value) const noexcept
{
	int i = 0; Node<T> *tmp = head;
	for (; tmp != nullptr && i < _n && (tmp->getData() != value); ++i, tmp = tmp->getNext());
	if (i < _n) return i;
	else return -1;
}
template<class T>
void LinkedList<T>::sort(Compare<T> fun)
{
	for (int i = 0; i < _n - 1; ++i)
		for (int j = i + 1; j < _n; ++j)
			if (fun((*this)[i], (*this)[j]))
			{
				T tmp = (*this)[i];
				(*this)[i] = (*this)[j];
				(*this)[j] = tmp;
			}
}
template<class T>
typename LinkedList<T>::iterator LinkedList<T>::begin() noexcept
{
	return iterator(head);
}

template <class T>
typename LinkedList<T>::iterator LinkedList<T>::end() noexcept
{
	return iterator(nullptr, tail);
}
template<class T>
bool LinkedList<T>::out_of_range(int i) const noexcept
{
	return (i > _n || i < 0) ? true : false;
}
template<class T>
void LinkedList<T>::copy(const LinkedList &list)
{
	for (Node<T>* tmp = list.head; tmp != nullptr; tmp = tmp->getNext())
		add_back(tmp->getData());
	_n = list._n;
}
template<class T>
void LinkedList<T>::move(LinkedList && list)
{

	head = list.head;
	_n = list._n;
}
template<class T>
void LinkedList<T>::print(std::ostream & s) const
{
	for (Node<T>* node = head; node; node = node->getNext())
		s << node->getData();
}


template<class T>
void LinkedList<T>::clear()
{
	for (Node<T>* tmp = head; tmp != nullptr;
		head = head->getNext(), delete tmp, tmp = head);
	_n = 0;

}

template<class T>
Node<T>& LinkedList<T>::search(int location) const noexcept(false)
{
	if (head == nullptr) throw(NullPointerException("Searching an empty list error..."));
	Node<T> *temp = head;
	for (int i = 0; i < location; temp = temp->getNext(), ++i);
	return *temp;

}


template <class T >
LinkedList<T>::iterator::iterator(typename Node<T>* node) noexcept : itr(node), last(nullptr) {}

template <class T >
LinkedList<T>::iterator::iterator(typename Node<T>* node, typename Node<T>* last) noexcept : itr(node), last(last) {}

template <class T >
void LinkedList<T>::iterator::swap(typename LinkedList<T>::iterator& other)
{
	std::swap(itr, other.itr);
}



template <class T >
typename LinkedList<T>::iterator& LinkedList<T>::iterator::operator++()
{
	itr = itr->next;
	return *this;
}

template <class T >
typename LinkedList<T>::iterator LinkedList<T>::iterator::operator++(int)
{
	iterator tmp(*this);
	itr = itr->next;
	return tmp;
}

template <class T >
typename LinkedList<T>::iterator& LinkedList<T>::iterator::operator--()
{
	itr = itr ? itr->prev : last;
	return *this;
}

template <class T>
typename LinkedList<T>::iterator LinkedList<T>::iterator::operator--(int)
{
	iterator tmp(*this);
	itr = itr ? itr->prev : last;
	return tmp;
}

template <class T>
bool LinkedList<T>::iterator::operator==(typename const LinkedList<T>::iterator& rhs) const noexcept
{
	return itr == rhs.itr;
}

template <class T >
bool LinkedList<T>::iterator::operator!=(typename const LinkedList<T>::iterator& rhs) const noexcept
{
	return itr != rhs.itr;
}

template <class T>
T& LinkedList<T>::iterator::operator*() const noexcept
{
	return itr->data;
}

template <class T >
T& LinkedList<T>::iterator::operator->() const noexcept
{
	return itr->data;
}
