//
// Created by Mahta Shafiee Sabet on 2021-06-02.
//
#include <vector>
#include "path.h"
#include "tree.h"
//#include <deque>
#include "linkedList.h"
using namespace std;
#ifndef CLION_SHALLOWTREE_H
#define CLION_SHALLOWTREE_H


class shallowTree {
public:
    linkedList paths;//list of path*
    shallowTree();
    void makeShallowTreeOfTree(tree* T);

};


#endif //CLION_SHALLOWTREE_H
