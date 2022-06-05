#include "func.h"

Node *makeTree(int n) {
    if (n == 0) {
        return NULL;
    }
    Node *p = new Node;
    p->data = n;
    p->left = makeTree(n - 1);
    p->right = makeTree(n - 1);

    return p;
}

Node* deleteLeaf(Node* tree)
{
    if (tree == NULL)
        return NULL;
    if (tree->left == NULL && tree->right == NULL) {
        free(tree);
        return NULL;
    }

    tree->left = deleteLeaf(tree->left);
    tree->right = deleteLeaf(tree->right);

    return tree;
}

void printBT(const string &prefix, const Node *node, bool isLeft) {
    if (node != NULL) {
        cout << prefix;

        cout << (isLeft ? "|--" : "|--");

        cout << node->data << endl;

        printBT(prefix + (isLeft ? "|   " : "    "), node->left, true);
        printBT(prefix + (isLeft ? "|   " : "    "), node->right, false);
    }
}