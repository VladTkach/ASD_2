#include "func.h"

int main() {
    int vertex = getVertex("input.txt");

    int **coor = new int *[vertex];
    init_mas(coor, vertex, 2);

    in_coor("input.txt", coor, vertex);

    double **graph = new double *[vertex];
    init_mas(graph, vertex, vertex);

    in_graph(graph, coor, vertex);

    int min = INT_MAX;
    vector<int> total_comb;
    greed(graph, vertex, min, total_comb);
    writeResult("output.txt", min, total_comb);

    delete_mas(graph, vertex);
    delete_mas(coor, vertex);
    return 0;
}
