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


void ComputeReducedAL(node *x, node *y, dataStructure *ds, tree *T, bool startIsFurthur);

void Reroot(node *x, tree *T, tree *Tstar, dataStructure *ds);

void Toggle(vector<int> &inactiveNodes, vector<int> &activeNodes, graph *G);

void UpdateShallowTree(vector<int> &inactiveNodes, vector<int> &activeNodes, shallowTree *st, tree *T, graph *G);

bool myNodeCF(node *a, node *b);

bool Node_cmp_for_ds(node *a, node *b);

node *lower_bound(node *nd, vector<node *> &path);


#endif //CLION_DYNAMICDFS_H


