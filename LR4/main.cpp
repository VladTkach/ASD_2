#include "func.h"

int main() {
    int vertex;
    cout << "Enter num of vertex: ";
    cin >> vertex;

    int **graph = new int *[vertex];
    init_mas(graph, vertex, vertex);
    in_mas(graph, vertex, vertex);

//    out_mas(graph, vertex, vertex);
//    cout << "start" << endl;

    int **dir = new int *[vertex];

    init_mas(dir, vertex, vertex);

    for (int i = 0; i < vertex; ++i) {
        for (int j = 0; j < vertex; ++j) {
            dir[i][j] = INT_MAX;
        }
    }

    string **way = new string *[vertex];
    init_mas(way, vertex, vertex);

    dantsig(way, dir, vertex, graph);

    out_mas(dir, vertex, vertex);
    out_mas(way, vertex, vertex);
    out_result(way, dir, vertex);

    delete_mas(graph, vertex);
    delete_mas(dir, vertex);
    delete_mas(way, vertex);
    return 0;
}
