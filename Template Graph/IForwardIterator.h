#pragma once
template<class T>
class ForwardIterator
{
	//static_assert(std::is_constructible::value, "Not constructible");
public:
	ForwardIterator(const ForwardIterator&) = default;
	ForwardIterator(ForwardIterator&&) = default;;
	ForwardIterator& operator=(const ForwardIterator&) = default;
	ForwardIterator& operator=(ForwardIterator&&) = default;
	virtual ~ForwardIterator();
	virtual ForwardIterator& operator++();
	virtual T operator*();
	//inline virtual  Iterator operator++(int) { return *this; }
};

