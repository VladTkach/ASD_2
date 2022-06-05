#pragma once

#include <iostream>

using namespace std;

void init_mas(int **mas, int row, int col);

void delete_mas(int **mas, int row);

void out_mas(int **mas, int row, int col);

void out_result(int **mas, int row, int col);

void in_graph(int **graph, int vertex);

void find_min(bool *vortex, int **graph, int num_vertex, int &min_i, int &min_j);

void prim(int **graph, int num_vertex, int **tree);