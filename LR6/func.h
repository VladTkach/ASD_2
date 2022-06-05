#pragma once

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node* makeTree(int n);

void printTree(Node *tree);

void printBT(const string &prefix, const Node *node, bool isLeft);

Node* deleteLeaf(Node* root);
