#pragma once
#include<iostream>
#include<initializer_list>

template<class T>
class Matrix
{
private:
	struct Index
	{
		int i;
		int j;
	};
public:
	explicit Matrix(int, int = 0);
	Matrix() = delete;
	Matrix(const Matrix&);
	Matrix(Matrix&&);
	Matrix& operator=(const Matrix&);
	Matrix& operator=(Matrix&&);
	~Matrix();

	T& operator[](const Index&) noexcept(false);
	const T& operator[](const Index&) const noexcept(false);
	bool setAtLocation(T value, int row, int col) ; 
	int get_row_capacity();
	int get_column_capacity();

	void initialize(std::initializer_list<std::initializer_list<T>>);
	template<class A>
	friend std::ostream& operator<<(std::ostream& s, const Matrix<A>& matrix)
	{
		for (int i = 0; i < matrix.n; ++i, s << std::endl)
			for (int j = 0; j < matrix.m; ++j)
				s << " " << matrix.mat[i][j];
		return s;
	}
	void realloc(int = 0, int = 0);
private:
	int n;
	int m;
	T **mat;
	void copy(const Matrix&);
	void move(Matrix&&);
	bool wrong_location(int, int) const;

};



