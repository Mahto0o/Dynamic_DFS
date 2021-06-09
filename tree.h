//
// Created by Mahta Shafiee Sabet on 2021-05-11.
//

#ifndef CLION_TREE_H
#define CLION_TREE_H
#include "node.h"

class tree {
public:
    vector<node*> adjList;
    vector<node*> preOrderList;
    node* root;
    void printGraph();
    void ComputePreorderList();
    void ComputeSubtreeSizes(node * r);
};


#endif //CLION_TREE_H
