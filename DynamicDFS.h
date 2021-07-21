//
// Created by Mahta Shafiee Sabet on 2021-06-08.
//

#ifndef CLION_DYNAMICDFS_H
#define CLION_DYNAMICDFS_H
#include "path.h"
#include "graph.h"
#include "tree.h"
#include "shallowTree.h"
#include "dataStructure.h"
#include <vector>



void ComputeReducedAL(node* x, node* y, dataStructure ds, tree* T, shallowTree *st);

void Reroot(node* x, tree *T, tree* Tstar, dataStructure ds, shallowTree *st);

void Toggle(vector<int> inactiveNodes, vector<int> activeNodes, shallowTree* st, graph* G);

void UpdateShallowTree(vector<int> inactiveNodes, vector<int> activeNodes, shallowTree* st, tree* T, graph* G);
bool myNodeCF(node *a, node *b);












#endif //CLION_DYNAMICDFS_H


