#include "INode.h"
#include"NullPointerException.h"
#include<utility>

#define ERROR_PTR  "Trying to derefernce null pointer..."

template<class T>
Node<T>::Node(T data) noexcept:Node(data, nullptr)
{}
template<class T>
Node<T>::Node(T data, Node* next) noexcept : _data(data), next(next)
{}
template<class T>
Node<T>::Node(Node && other) noexcept
{
	move(std::move(other));
}
template<class T>
Node<T> & Node<T>::operator=(Node &&other) noexcept
{
	if (&other != this) {
		this->~Node();
		move(std::move(other));
	}
	return *this;
}
template<class T>
Node<T>::~Node()
{
	next = nullptr;
}
template<class T>
Node<T> * Node<T>::getNext() noexcept(false)
{
	if (this == nullptr)
		throw(NullPointerException(ERROR_PTR));
	return next;
}
template<class T>
const Node<T> * Node<T>::getNext() const noexcept(false)
{
	if (this == nullptr)
		throw(NullPointerException(ERROR_PTR));
	return next;
}
template<class T>
T& Node<T>::getData() noexcept(false)
{
	if (this == nullptr)
		throw(NullPointerException(ERROR_PTR));
	return _data;
}
template<class T>
const T & Node<T>::getData() const noexcept(false)
{
	if (this == nullptr)
		throw(NullPointerException(ERROR_PTR));
	return _data;
}
template<class T>
Node<T>& Node<T>::setNext(Node * other)  noexcept(false)
{
	if (this == nullptr)
		throw(NullPointerException(ERROR_PTR));
	next = other;
	return *this;
}
template<class T>
Node<T> & Node<T>::setData(T data) noexcept(false)
{
	if (this == nullptr)
		throw(NullPointerException(ERROR_PTR));
	_data = data;
	return *this;
}
template<class T>
void Node<T>::move(Node &&other)
{
	next = other.next;
	_data = other._data;
	other.next = nullptr;
}
