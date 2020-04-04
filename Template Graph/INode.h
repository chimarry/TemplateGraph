#pragma once
template<class T>
class Node
{
public:
	Node(T) noexcept;
	Node(T, Node*) noexcept;
	Node(Node&&) noexcept;
	Node& operator=(Node&&) noexcept;
	~Node();

	Node* getNext() noexcept(false);
	const Node* getNext() const noexcept(false);
	T& getData() noexcept(false);
	const T&  getData() const noexcept(false);
	Node& setNext(Node*) noexcept(false);
	Node& setData(T) noexcept(false);

private:
	T _data;
	Node* next;
	void move(Node&&);
};

