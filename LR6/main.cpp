#include "func.h"

int main() {
    int n;
    cin >> n;
    Node *tree = makeTree(n);

    printBT("", tree, false);

    deleteLeaf(tree);

    printBT("", tree, false);


    return 0;
}
