#pragma once
#include<iostream>
#include<initializer_list>
#include"IIterable.h"
template<class T>
class Graph:virtual public IIterable<T>
{
public:
	explicit Graph(int, T*);
	explicit Graph(int, std::initializer_list<T>);
	virtual ~Graph();
	virtual void dfs() const = 0;
	template<class A>
	friend std::ostream& operator<<(std::ostream& s, const Graph<A>& g)
	{
		g.print(s);
		return s;
	}
	virtual int getSize() const;
protected:
	int _n;
	T *_nodes;
	virtual void print(std::ostream&) const = 0;
	virtual void dfs_visit(int, int**) const = 0;
};

