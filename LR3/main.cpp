#include "func.h"

int main() {
    int num_vertex;
    cout << "Enter num of vertex: ";
    cin >> num_vertex;

    int **graph = new int *[num_vertex];
    init_mas(graph, num_vertex, num_vertex);

    in_graph(graph, num_vertex);
//    out_mas(graph, num_vertex, num_vertex);

    int **tree = new int *[num_vertex - 1];
    init_mas(tree, num_vertex - 1, 3);

    prim(graph, num_vertex, tree);

    out_result(tree, num_vertex - 1, 3);


    delete_mas(tree, num_vertex - 1);
    delete_mas(graph, num_vertex);
}