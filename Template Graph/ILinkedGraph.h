#pragma once
#include "Graph.h"
#include"LinkedList.h"

template<class T>
class LinkedGraph :public Graph<T>
{
public:
	LinkedGraph(int, T*);
	LinkedGraph(int, std::initializer_list<T>);
	LinkedGraph(int, std::initializer_list<T>,
		std::initializer_list<std::initializer_list<int>>);
	void setFromStandardInput();
	virtual ~LinkedGraph();
	virtual void dfs() const override;
private:
	LinkedList<int> * lists;
	T* _nodes = Graph<T>::_nodes;
	int _n = Graph<T>::_n;
	virtual void  dfs_visit(int, int**) const override;
	virtual void print(std::ostream&) const override;
};

