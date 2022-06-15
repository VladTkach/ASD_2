#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void init_mas(int **mas, int row, int col);

void init_mas(string **mas, int row, int col);

void delete_mas(int **mas, int row);

void delete_mas(string **mas, int row);

void out_mas(int **mas, int row, int col);

void out_mas(string **mas, int row, int col);

void out_result(string **way, int **dir, int vertex);

void in_mas(int **mas, int row, int col);

void find_min_i(int i, int j, int **dir, int **graph, string **way);

void find_min_j(int i, int j, int **dir, int **graph, string **way);

void find_min(int i, int j, int **dir, int vertex, string **way);

void search(string **way, int **dir, int vertex, int **graph);

void dantsig(string **way, int **dir, int vertex, int **graph);

void set_zero_mas(int **dir, int vertex);