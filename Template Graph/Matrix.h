#pragma once
#include "IMatrix.h"
#include<exception>
#include<stdexcept>

#define DEFAULT_VALUE 0

template<class T>
Matrix<T>::Matrix(int n, int mm) :n(n), m(mm ? mm : n), mat(new T*[n])
{
	for (int i = 0; i < n; ++i) {
		mat[i] = new T[m];
		std::fill_n(mat[i], m, DEFAULT_VALUE);
	}
}

template<class T>
inline Matrix<T>::Matrix(const Matrix &matrix)
{
	copy(matrix);
}

template<class T>
inline Matrix<T>::Matrix(Matrix &&matrix)
{
	move(std::move(matrix));
}

template<class T>
inline Matrix<T> & Matrix<T>::operator=(const Matrix<T> &matrix)
{
	if (this != &matrix) {
		this->~Matrix();
		copy(matrix);
	}
	return *this;

}

template<class T>
inline Matrix<T> & Matrix<T>::operator=(Matrix<T> &&matrix)
{
	if (this != &matrix) {
		this->~Matrix();
		move(std::move(matrix));
	}
	return *this;
	
}

template<class T>
inline Matrix<T>::~Matrix()
{
	for (int i = 0; i < n; ++i) {
		delete[] mat[i];
		mat[i] = nullptr;
	}
	delete[] mat;
	mat = nullptr;
	m = n = 0;
}

template<class T>
inline T & Matrix<T>::operator[](const Index &index) noexcept(false)
{
	return wrong_location(index.i, index.j) ? throw(std::out_of_range("Wrong")) : mat[index.i][index.j];
}

template<class T>
inline const T & Matrix<T>::operator[](const Index &index) const noexcept(false)
{
	return wrong_location(index.i, index.j) ? throw(std::out_of_range("Wrong")) : mat[index.i][index.j];
}

template<class T>
inline bool Matrix<T>::setAtLocation(T value, int row, int col)
{
	if (!wrong_location(row, col))
	{
		mat[row][col] = value;
		return true;
	}
	return false;
}

template<class T>
inline int Matrix<T>::get_row_capacity()
{
	return n;
}

template<class T>
inline int Matrix<T>::get_column_capacity()
{
	return m;
}

template<class T>
inline void Matrix<T>::initialize(std::initializer_list<std::initializer_list<T>> list)
{
	int i, j;
	for (i = 0; i != list.size(); ++i)
	{
		std::initializer_list<T> l = list.begin()[i];
		for (j = 0; j != l.size(); ++j)
			mat[i][j] = l.begin()[j];
		if (j < m)
			for (; j < m; ++j)
				mat[i][j] = 0;
	}
	if (i < n)
		for (; i < n; ++i)
			for (j = 0; j < m; ++j)
				mat[i][j] = 0;
}

template<class T>
inline void Matrix<T>::realloc(int n_new, int m_new)
{
	bool quad = false;
	if (n == m) quad = true;
	if (n_new == 0 && !quad) n_new = n;
	if (m_new == 0) {
		m_new = m;
		if (quad) m_new = n_new;
	}
	Matrix<T> matr(n_new, m_new);
	if (n_new < n) n = n_new;
	if (m_new < m) m = m_new;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			matr.mat[i][j] = mat[i][j];
	*this = matr;
}

template<class T>
inline void Matrix<T>::copy(const Matrix & matrix)
{
	n = matrix.n;
	m = matrix.m;
	mat = new T*[n];
	for (int i = 0; i < n; i++)
	{
		mat[i] = new T[m];
		std::copy(matrix.mat[i], matrix.mat[i] + m, mat[i]);
	}


}

template<class T>
inline void Matrix<T>::move(Matrix &&matrix)
{
	n = matrix.n;
	m = matrix.m;
	/*for (int i = 0; i < n; ++i)
	{
	mat[i] = matrix.mat[i];
	matrix.mat[i] = nullptr;
	}*/
	mat = matrix.mat;
	matrix.mat = nullptr;
}

template<class T>
inline bool Matrix<T>::wrong_location(int i, int j) const
{
	return (i < 0 || i >= n || j < 0 || j >= m) ? true : false;
}

