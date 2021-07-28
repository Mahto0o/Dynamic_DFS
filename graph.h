//
// Created by Mahta Shafiee Sabet on 2021-05-10.
//
#include <vector>
#include <string>
#include "node.h"
#include "tree.h"
using namespace std;
#ifndef CLION_GRAPH_H
#define CLION_GRAPH_H


class graph {
public:
    vector<node> adjList;
    node dummyNode;
    void readGraph(string fileName);
    void printGraph();
    tree ComputeDFSTree();
    void makeAllNodesUnvisited();
    tree ComputeDFSTreeBetweenActiveNodes();

};


#endif //CLION_GRAPH_H
