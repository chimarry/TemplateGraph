#pragma once
#include "Graph.h"
#include "Matrix.h"
#include"ForwardIterator.h"
template<class T>
class MatrixGraph :public Graph<T>
{
public:
	MatrixGraph(int, T*);
	MatrixGraph(int, std::initializer_list<T>);
	MatrixGraph(int, std::initializer_list<T>,
		std::initializer_list<std::initializer_list<int>>);
	virtual ~MatrixGraph();
	virtual void dfs() const override;
	inline virtual int getSize() const{ return _n; }
	class m_iterator :public ForwardIterator<T>
	{
	public:
		explicit m_iterator(T* el,n=0) :element(el),visited(new int[n]) {}
		m_iterator(const m_iterator&)=default ;
		m_iterator(m_iterator&&)=default;
		m_iterator& operator=(const m_iterator&)=default;
		m_iterator& operator=(m_iterator&&)=default;
		virtual ~m_iterator()=default;
		inline virtual m_iterator& operator++() override;
		inline virtual T operator*();
	private:
		int n;
		T * element;
		int offset;
		int* visited;
		//MatrixGraph* collection;
	};
	virtual m_iterator& begin();
	virtual m_iterator& end() ;
protected:
	int _n = Graph<T>::_n;
	T* _nodes = Graph<T>::_nodes;
	virtual void dfs_visit(int, int**) const override;
	virtual void print(std::ostream&) const override;
	Matrix<int> mat;
};

template<class T>
MatrixGraph<T>::m_iterator & MatrixGraph<T>::m_iterator::operator++()
{
   	
}
