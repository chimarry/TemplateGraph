#pragma once
#include "MatrixGraph.h"
#include"Matrix.h"
#include<iostream>
template<class T>
class WeightedGraph :virtual public MatrixGraph<T>
{
public:
	WeightedGraph(int n);
	WeightedGraph(int n, std::initializer_list<std::initializer_list<int>>);

	virtual ~WeightedGraph();
	void floyd(Matrix<int> &paths, Matrix<int> &ancestors) const;
	void init(Matrix<int> &paths, Matrix<int> &ancestors);
	void pathOnStandardOutput(int, int, const Matrix<int>&, int) const;
	int& index_of_node(T) noexcept(false);
	inline virtual int getSize() const { return _n; }
protected:
	virtual void print(std::ostream&) const override;
private:
	int _n = MatrixGraph<T>::_n;
	Matrix<int> mat = MatrixGraph<T>::mat;
	T* names;
public:
	template <class A>
	friend std::istream& operator>>(std::istream& s, WeightedGraph<A>& g)
	{
		int n;
		s >> n;
		if (n != g._n) {
			g.mat.realloc(n);
			delete[] g.names;
			g.names = new T[n];
			g._n = n;
		}
		for (int i = 0; i<g._n; ++i) {
			s >> g.names[i];
		}
		for (int i = 0; i < g._n; ++i)
			for (int j = 0; j < g._n; ++j)
				s >> g.mat[{i, j}];
		return s;
	}
};