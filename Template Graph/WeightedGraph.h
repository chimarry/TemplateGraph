#pragma once
#include<stdexcept>
#include "IWeightedGraph.h"
#define INFINITY 10000000
template<class T>
inline WeightedGraph<T>::WeightedGraph(int n) :MatrixGraph<T>(n, {}), names(new T[n])
{
}
template<class T>
inline WeightedGraph<T>::WeightedGraph(int n, std::initializer_list<std::initializer_list<int>> l) : MatrixGraph<T>(n, {}, l)
{
	names = new T[n];
}

template<class T>
inline WeightedGraph<T>::~WeightedGraph()
{

	delete[] names;
	names = nullptr;
}

template<class T>
inline void WeightedGraph<T>::floyd(Matrix<int> & paths, Matrix<int> & ancestors) const
{
	for (int k = 0; k<_n; ++k)
		for (int i = 0; i<_n; ++i)
			for (int j = 0; j < _n; ++j)
			{
				if (paths[{i, j}] > paths[{i, k}] + paths[{k, j}]) {
					paths[{i, j}] = paths[{i, k}] + paths[{k, j}];
					ancestors[{i, j}] = ancestors[{k, j}];
				}
			}
}

template<class T>
inline void WeightedGraph<T>::init(Matrix<int> & paths, Matrix<int> & ancestors)
{
	for (int i = 0; i<_n; ++i)
		for (int j = 0; j < _n; ++j)
		{
			int path;
			if (i == j)
				path = 0;
			else if (mat[{i, j}])
				path = mat[{i, j}];
			else path = INFINITY;
			paths[{i, j}] = path;
			ancestors[{i, j}] = (i == j || (mat[{i, j}] == 0)) ? -1 : i;
			//std::cout << names[i] << " " << paths[{i, j}] << " ," << ancestors[{i, j}] << names[j];
			//	std::cout << std::endl;
		}
}

template<class T>
inline void WeightedGraph<T>::pathOnStandardOutput(int i, int j, const Matrix<int> & ancestors, int flag) const
{
	if (i == j)
		std::cout << names[i] << "->";
	else if (ancestors[{i, j}] == -1)
		std::cout << "No path!";
	else {
		pathOnStandardOutput(i, ancestors[{i, j}], ancestors, flag);
		std::cout << names[j];
		if (flag != j) std::cout << "->";
	}
}

template<class T>
inline int & WeightedGraph<T>::index_of_node(T name) noexcept(false)
{
	for (int i = 0; i < _n; ++i)
		if (name == names[i]) return i;
	throw(std::out_of_range("Doesn't exist..."));
}

template<class T>
inline void WeightedGraph<T>::print(std::ostream &s) const
{
	s << _n << std::endl;
	for (int i = 0; i < _n; ++i)
		s << names[i] << " ";
	s << std::endl << mat << std::endl;
}
