#pragma once
#include "IGraph.h"

template<class T>
inline Graph<T>::Graph(int n, std::initializer_list<T> list) :_n(n), _nodes(new T[n])
{
	for (int i = 0; i != list.size(); ++i)
		_nodes[i] = list.begin()[i];
}

template<class T>
inline Graph<T>::~Graph()
{
	delete[] _nodes;
	_n = 0;
}

template<class T>
inline Graph<T>::Graph(int n, T *nodes) :_n(n), _nodes(new T[n])
{
	std::copy_n(nodes, n, _nodes);
}

template<class T>
inline int Graph<T>::getSize() const
{
	return _n;
}
