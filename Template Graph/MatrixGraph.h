#pragma once
#include "IMatrixGraph.h"


template<class T>
inline MatrixGraph<T>::MatrixGraph(int n, T* nodes) :Graph(n, nodes), mat(n, n)
{
}

template<class T>
inline MatrixGraph<T>::MatrixGraph(int n, std::initializer_list<T> list) : Graph<T>(n, list), mat(n, n)
{
}

template<class T>
inline MatrixGraph<T>::MatrixGraph(int n, std::initializer_list<T> nodes,
	std::initializer_list<std::initializer_list<int>>l) : MatrixGraph<T>(n, nodes)
{
	mat.initialize(l);
}

template<class T>
inline MatrixGraph<T>::~MatrixGraph()
{
}

template<class T>
inline void MatrixGraph<T>::dfs() const
{
	int* visit = new int[_n];
	std::fill_n(visit, _n, 0);
	dfs_visit(0, &visit);
	delete[] visit;
}

template<class T>
inline void MatrixGraph<T>::dfs_visit(int u, int** visit) const
{
	(*visit)[u] = 1;
	std::cout << _nodes[u];
	for (int v = 0; v <_n; ++v)
	{
		int a = (*visit)[v];
		if (mat[{u, v}] && !(*visit)[v]) {
			dfs_visit(v, visit);
		}
	}
}

template<class T>
inline void MatrixGraph<T>::print(std::ostream & s) const
{
	s << _n << std::endl;
	for (int i = 0; i < _n; ++i)
		s << _nodes[i] << " ";
	s << std::endl << mat << std::endl;
}

//ITERATOR



