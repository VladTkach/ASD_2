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

void out_mas(int **mas, int row, int col) {
    cout << endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << mas[i][j] << " ";
        }
        cout << endl;
    }
}

void out_result(int **mas, int row, int col) {
    cout << endl;
    for (int i = 0; i < row; ++i) {
        cout << "(" << mas[i][0] << ") - " << mas[i][1] << " - (" << mas[i][2] << ")" << endl;
    }
}

void in_graph(int **graph, int vertex) {
    for (int i = 0; i < vertex; ++i) {
        for (int j = 0; j < vertex; ++j) {
            cin >> graph[i][j];
        }
    }
}

void prim(int **graph, int num_vertex, int **tree) {
    bool *vertex = new bool[num_vertex];

    for (int i = 0; i < num_vertex; ++i) {
        vertex[i] = false;
    }

    vertex[0] = true;
    int min_i, min_j;
    for (int i = 0; i < num_vertex - 1; ++i) {
        find_min(vertex, graph, num_vertex, min_i, min_j);

        vertex[min_j] = true;

        tree[i][0] = min_i + 1;
        tree[i][1] = graph[min_i][min_j];
        tree[i][2] = min_j + 1;


    }
    delete[] vertex;
}

void find_min(bool *vertex, int **graph, int num_vertex, int &min_i, int &min_j) {
    int min = INT_MAX;
    for (int i = 0; i < num_vertex; ++i) {
        if (vertex[i]) {
            for (int j = 0; j < num_vertex; ++j) {
                if (min > graph[i][j] && graph[i][j] != 0 && !vertex[j]) {
                    min = graph[i][j];
                    min_i = i;
                    min_j = j;
                }

            }
        }
    }
}