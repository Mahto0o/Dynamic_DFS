//
// Created by Mahta Shafiee Sabet on 2021-06-07.
//
#ifndef CLION_DATASTRUCTURE_H
#define CLION_DATASTRUCTURE_H
#include <set>
#include <vector>
#include "node.h"
#include "graph.h"
#include "tree.h"
#include "nodeDfnCmp.h"
#include "nodeCMP.h"
#include <type_traits>

using namespace std;

class dataStructure {
public:
    using Cmp = std::integral_constant<decltype(&nodeCMP), &nodeCMP>;
    vector<set<node *, Cmp> > ds;


    void computeDs(graph G, tree T);
    node* query(node* x, node* pathStart, node* pathEnd);
};


#endif //CLION_DATASTRUCTURE_H
