#pragma once
#include"Node.h"
#include<utility>
#include <iterator>
#include<functional>
template<class T>
using Compare = std::function<bool(const T&, const T&)>;
template <class T>
class LinkedList
{
public:
	LinkedList();
	LinkedList(const LinkedList<T>&);
	LinkedList(LinkedList<T>&&);
	LinkedList& operator=(const LinkedList<T>&);
	LinkedList& operator=(LinkedList<T>&&);
	virtual ~LinkedList();
	friend std::ostream& operator<<(std::ostream& stream, const LinkedList<T>& list)
	{
		list.print(stream);
		return stream;
	}
	inline virtual bool is_full() const noexcept
	{
		return false;
	};
	virtual bool is_empty() const noexcept;
	virtual bool contains(T value) const noexcept;
	virtual bool add(T) ;
	virtual bool add_back(T);
	virtual void remove() ;
	virtual void clear();
	virtual Node<T>& search(int) const noexcept(false);
	virtual bool operator==(const LinkedList<T>&) const noexcept;
	virtual const T& operator[](int) const noexcept(false);
	virtual T & operator[](int) noexcept(false);
	virtual int position_of(T) const noexcept;
	virtual void sort(Compare<T> = [](int a, int b) {return a > b; });
	class iterator;
	iterator begin() noexcept;
	iterator end() noexcept;
protected:
	int _n = Collection<T>::_n;
	Node<T>* head;
	virtual bool out_of_range(int) const noexcept;
private:
	void copy(const LinkedList&);
	void move(LinkedList&&);
	void print(std::ostream&) const;
public:
	class iterator : public std::iterator<std::bidirectional_iterator_tag, Node<T>*>
	{
		Node<T>* itr;
		Node<T>* last;
		explicit iterator(Node<T>*) noexcept;
		explicit iterator(Node<T>*, Node<T>*) noexcept;
		//friend class LinkedList;
	public:
		void swap(iterator& other);
		iterator& operator++();
		iterator operator++(int);
		iterator& operator--();
		iterator operator--(int);
		bool operator==(const iterator&) const noexcept;
		bool operator!=(const iterator&) const noexcept;
		T& operator*() const noexcept;
		T& operator->() const noexcept;
	};
};
