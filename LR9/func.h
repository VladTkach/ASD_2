#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "item.h"

using namespace std;

void getSize(const string &name, int &max_weight, int &num_element);

vector<item> getListItem(const string &name, int num_element);

void outList(vector<item> listItem);

void init_mas(int **mas, int row, int col);

void delete_mas(int **mas, int row);

void out_mas(int **mas, int row, int col);

void dynamic(vector<item> &listItem, int **mas, int num_element, int max_weight);