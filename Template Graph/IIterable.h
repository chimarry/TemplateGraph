#pragma once
#include"ForwardIterator.h"
template<class T>
class IIterable
{
public:
	virtual ForwardIterator<T>& begin() = 0;
	virtual ForwardIterator<T>& end() = 0;
};
