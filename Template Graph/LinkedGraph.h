#pragma once
#include "ILinkedGraph.h"

template<class T>
inline LinkedGraph<T>::LinkedGraph(int n, T* nodes) :Graph<T>(0, nodes), lists(new LinkedList<int>[n])
{
}

template<class T>
inline LinkedGraph<T>::LinkedGraph(int n, std::initializer_list<T> list) : Graph<T>(n, list), lists(new LinkedList<int>[n])
{
}


template<class T>
inline LinkedGraph<T>::LinkedGraph(int n, std::initializer_list<T>node,
	std::initializer_list<std::initializer_list<int>>list) :Graph<T>(n, node), lists(new LinkedList<int>[n])
{
	for (int i = 0; i != list.size(); ++i)
	{
		std::initializer_list<int> l = list.begin()[i];
		for (int j = 0; j != l.size(); ++j)
			lists[i].add_back(l.begin()[j]);
	}
}

template<class T>
inline void LinkedGraph<T>::setFromStandardInput()
{

	for (int i = 0; i <_n; ++i)
	{
		int n;
		std::cout << i + 1 << ".node:" << std::endl;
		std::cout << "Number of neighbours:" << std::endl;
		std::cin >> n;
		std::cout << "Set neighbours:" << std::endl;
		for (int j = 0; j < n; ++j) {
			T neighbour;
			std::cin >> neighbour;
			lists[i].add_back(neighbour);
		}
	}
}
template<class T>
inline LinkedGraph<T>::~LinkedGraph()
{
	delete[] lists;
	lists = nullptr;
}

template<class T>
inline void LinkedGraph<T>::dfs() const
{
	int* visit = new int[_n] {0};
	dfs_visit(0, &visit);
}

template<class T>
inline void LinkedGraph<T>::dfs_visit(int u, int **visit) const
{
	(*visit)[u] = 1;
	std::cout << _nodes[u];
	for (int v = 0; v < _n; ++v)
		if (!(*visit)[v] && lists[v].contains(u))
			dfs_visit(v, visit);
}

template<class T>
inline void LinkedGraph<T>::print(std::ostream &s) const
{
	s << _n << std::endl;
	for (int i = 0; i < _n; ++i)
		s << _nodes[i] << " ";
	for (int i = 0; i < _n; ++i)
	{
		s << std::endl << lists[i];
	}
}


