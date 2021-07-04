//
// Created by Mahta Shafiee Sabet on 2021-05-10.
//
#ifndef CLION_NODE_H
#define CLION_NODE_H
#include <vector>
#include <string>
#include <set>
#include "path.h"
using namespace std;
class path;
class node {
public:
    vector<node *> neighbours;
    vector<node *> children;// for tree
    node *par = NULL;// for tree
    vector<node* > cpNbrs;// extra neighbours list for DFS
    set<node* > ReducedAL;
//    string attr; //tree or path
    int sizeofST = 1;
    int indexInOrderedList;// dfn(x)
    bool visited = false; // 0:unvisited, 1:visited
    bool active = true; // 1:active, 0:inactive
    int indx = -1;// indx of the node in graph.txt
    path* nodePath = nullptr;

    node();

//    node(vector<node *> neighbours);


    node(vector<node *> neighbours);

    bool operator<(const node &other) const;
    bool operator>(const node &other) const;
    bool less(const node &other) const;
};


#endif //CLION_NODE_H
