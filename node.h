//
// Created by Mahta Shafiee Sabet on 2021-05-10.
//
#ifndef CLION_NODE_H
#define CLION_NODE_H
#include <vector>
#include <string>
#include <set>
#include "path.h"
#include "nodeCMP.h"
using namespace std;
class path;

class node {
public:
    vector<node *> neighbours;
    vector<node *> children;// for tree (original dfs tree)
    vector<node *> childreni;// for i'th dfs tree
    node *par = NULL;// for tree
    node* pari = NULL;
    vector<node* > cpNbrs;// extra neighbours list for DFS
    std::set<node*> ReducedAL;
//    string attr; //tree or path
    int sizeofST = 1;
    int indexInOrderedList;// dfn(x) in current tree
    int dfn; // dfn(x) in ds
    bool visited = false; // 0:unvisited, 1:visited
    bool active = true; // 1:active, 0:inactive
    int indx = -1;// indx of the node in graph.txt
    path* nodePath = nullptr;

    node();

//    node(vector<node *> neighbours);


    node(vector<node *> neighbours);
//    bool myNodeCF(node* a, node* b);
//    bool operator<(const node &other) const;
//    bool operator>(const node &other) const;
};


#endif //CLION_NODE_H
