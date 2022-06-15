#include "func.h"

void init_mas(int **mas, int row, int col) {
    for (int i = 0; i < row; ++i) {
        mas[i] = new int[col];
    }
}

void delete_mas(int **mas, int row) {
    for (int i = 0; i < row; ++i) {
        delete[]mas[i];
    }
    delete[]mas;
}

void init_mas(string **mas, int row, int col) {
    for (int i = 0; i < row; ++i) {
        mas[i] = new string[col];
    }
}

void delete_mas(string **mas, int row) {
    for (int i = 0; i < row; ++i) {
        delete[]mas[i];
    }
    delete[]mas;
}

void out_mas(int **mas, int row, int col) {
    cout << endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << mas[i][j] << " ";
        }
        cout << endl;
    }
}

void out_mas(string **mas, int row, int col) {
    cout << endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << mas[i][j] << " ";
        }
        cout << endl;
    }
}

void out_result(string **way, int **dir, int vertex) {
    for (int i = 0; i < vertex; ++i) {
        for (int j = 0; j < vertex; ++j) {
            if (i != j){
                cout << i + 1 << " to " << j + 1 << " direction - " << dir[i][j] << " way: {" << way[i][j] << "}" << endl;
            }
        }
    }
}

void in_mas(int **mas, int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cin >> mas[i][j];
        }
    }
}

void set_zero_mas(int **dir, int vertex){
    for (int i = 0; i <vertex ; ++i) {
        for (int j = 0; j < vertex; ++j) {
            dir[i][j] = 0;
        }
    }
}

void dantsig(string **way, int **dir, int vertex, int **graph) {
    for (int i = 1; i <= vertex; ++i) {
        search(way, dir, i, graph);
//        out_mas(dir, i, i);
//        out_mas(way, i, i);
    }
}

void search(string **way, int **dir, int vertex, int **graph) {
//    cout << "Start vertex -  " << vertex << endl;
    for (int i = 0; i < vertex; ++i) {
        for (int j = 0; j < vertex; ++j) {
            if (i == j) {
                dir[i][j] = 0;
                way[i][j] = "-";
            } else if (i == vertex - 1) {
                find_min_i(i, j, dir, graph, way);
            } else if (j == vertex - 1) {
                find_min_j(i, j, dir, graph, way);
            }
        }
    }

//    out_mas(dir, vertex, vertex);

    for (int i = 0; i < vertex; ++i) {
        for (int j = 0; j < vertex; ++j) {
            if (i != j && i < vertex - 1 && j < vertex - 1){
//                cout << i << " " << j << endl;
                 find_min(i, j, dir, vertex, way);
            }
        }
    }
}

void find_min_i(int i, int j, int **dir, int **graph, string **way) {
    int min = INT_MAX;
    string left, right;
    for (int k = 0; k < i; ++k) {
        if (min > graph[i][k] + dir[k][j] && graph[i][k] != 0) {
            min = graph[i][k] + dir[k][j];
            if(i != k){
                left = "(" + to_string(i + 1) + ";" + to_string(k + 1) + ")";
            }else{
                left = "";
            }
            right = way[k][j];
            if (right == "-"){
                right = "";
            }
        }
    }
    if (dir[i][j] > min) {
        dir[i][j] = min;
        way[i][j] =  left + right;
    }
}

void find_min_j(int i, int j, int **dir, int **graph, string **way) {
    int min = INT_MAX;
    string left, right;
    for (int k = 0; k < j; ++k) {
        if (min > dir[i][k] + graph[k][j] && graph[k][j] != 0) {
            min = dir[i][k] + graph[k][j];

            left = way[i][k];
            if (left == "-"){
                left = "";
            }
            if (k != j){
                right = "(" + to_string(k + 1) + ";" + to_string(j + 1) + ")";
            }
            else{
                right = "";
            }
        }
    }
    if (dir[i][j] > min ) {
        dir[i][j] = min;
        way[i][j] =  left + right;
    }
}

void find_min(int i, int j, int **dir, int vertex, string **way) {
    string left, right;
//    cout << dir[i][j] << " " << dir[i][vertex - 1] << " " << dir[vertex - 1][j] << endl;
    if (dir[i][j] >  dir[i][vertex - 1] + dir[vertex - 1][j]) {
//        cout << "min" << endl;
        dir[i][j] = dir[i][vertex - 1] + dir[vertex - 1][j];
        left = "(" + to_string(i + 1) + ";" + to_string(vertex) + ")";
        right = "(" + to_string(vertex) + ";" + to_string(j + 1) + ")";
        way[i][j] = left + right;

    }
}