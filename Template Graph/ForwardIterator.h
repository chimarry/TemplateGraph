#pragma once
#include "IForwardIterator.h"

template<class T>
inline ForwardIterator<T>::~ForwardIterator()
{
}

template<class T>
inline ForwardIterator<T> & ForwardIterator<T>::operator++()
{
	// pretend to increment
	return *this;

}

template<class T>
inline T ForwardIterator<T>::operator*()
{
	//pretend to dereference
	return T();
}


