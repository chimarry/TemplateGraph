#include<iostream>
#include<fstream>
#include"Matrix.h"
#include"MatrixGraph.h"
#include"LinkedGraph.h"
#include"WeightedGraph.h"
#include<string>
int main()
{/*
 MatrixGraph g = { 6,{ '1', '2', '3', '4', '5', '6' },
 { { 0, 1, 1, 1, 0, 0 },
 { 1, 0, 0, 1, 0, 0 },
 { 1, 0, 0, 1, 1, 0 },
 { 1, 1, 1, 0, 1, 0 },
 { 0, 0, 1, 1, 0, 1 },
 { 0, 0, 0, 0, 1, 0 } } };

 LinkedGraph l= { 6,{ '1', '2', '3', '4', '5', '6' },
 { { 1,2,3 },
 {0,3},
 {0,3},
 {0,1,2,4},
 { 2,3,5},
 { 4}       } };
 std::cout << g << std::endl;
 std::cout << l;
 std::cout << std::endl;
 g.dfs();
 std::cout << std::endl;
 l.dfs();*/
	std::ifstream file;
	file.open("Gradovi.txt");
	WeightedGraph<std::string> w(5);

	file >> w;
	std::cout << w;
	Matrix<int> paths(w.getSize()), ancestors(w.getSize());
	w.init(paths, ancestors);
	w.floyd(paths, ancestors);
	int begin = w.index_of_node("Prijedor");
	int end = w.index_of_node("Brcko");
	std::cout << "Shortest path:" << std::endl;
	w.pathOnStandardOutput(begin, end, ancestors, end);
	std::cout << std::endl << "Length:" << std::endl;
	std::cout << paths[{begin, end}];
	
	std::cin.ignore();
	getchar();
}