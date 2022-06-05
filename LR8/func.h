#pragma once

#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>

using namespace std;

int getVertex(string name);

void init_mas(int **mas, int row, int col);

void init_mas(double **mas, int row, int col);

void delete_mas(int **mas, int row);

void delete_mas(double **mas, int row);

void out_mas(int **mas, int row, int col);

void out_mas(double **mas, int row, int col);

void in_coor(string name, int **coor, int vertex);

double distance(int x1, int y1, int x2, int y2);

void in_graph(double **graph, int **coor, int vertex);

void greed(double **graph, int vertex);

void comb_output(vector<int> comb);

bool no_repeat(int index, vector<int> comb);

void search_comb(int vertex, vector<int> comb, double **graph, int &min, vector<int> &total_comb);

void greed(double **graph, int vertex, int &min, vector<int> &total_comb);

double find_dir(vector<int> comb, double **graph);

void writeResult(string name, int min, vector<int> &comb);