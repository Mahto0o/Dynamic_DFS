//
// Created by Mahta Shafiee Sabet on 2021-06-07.
//
//
#include "dataStructure.h"
#include "DynamicDFS.h"
#include <iostream>
#include <vector>

void dataStructure::computeDs(graph* G, tree* T) {
    // filling the data structure
    for (auto &i : T->preOrderList) {
        i->dfn = i->indexInOrderedList;

        this->data_structure.emplace_back();
        for (auto &j: i->neighbours) {
            if (j->indexInOrderedList < i->indexInOrderedList) {
                this->data_structure.back().push_back(j);
            }
        }
    }

    // sorting each vector based on indexInOrderedList
    for(auto &i: data_structure){
        std:sort(i.begin(),i.end(),Node_cmp_for_ds);
    }


}

node *dataStructure::query(node *x, node *pathStart, node *pathEnd) {
    // array query
    node *temp;
    temp = lower_bound(pathEnd, this->data_structure[x->dfn]);

    if (temp->dfn < pathStart->dfn || temp->dfn > pathEnd->dfn || !temp->active) {
        return nullptr;
    }
    return temp;
}
node *dataStructure::query2(node *x, node *pathStart, node *pathEnd) {
    std::vector<node*> &ancestors = this->data_structure[x->dfn];
    int min = 0, max = ancestors.size() - 1;
    int mean;
    if(ancestors[min]->dfn > pathEnd->dfn || ancestors[max]->dfn < pathStart->dfn){
        return nullptr;
    }
    while (max > min) {
        mean = (max + min) / 2;
        if (ancestors[mean]->dfn >= pathStart->dfn &&
        ancestors[mean]->dfn <= pathEnd->dfn ) {
            return ancestors[mean];
        } else if (ancestors[mean]->dfn < pathStart->dfn) {
            min = (mean + 1);
        } else {
            max = (mean - 1);
        }
    }
    if(min == max){
        mean = max;
        if (ancestors[mean]->dfn >= pathStart->dfn &&
        ancestors[mean]->dfn <= pathEnd->dfn) {
            return ancestors[mean];
        }
    }
    return nullptr;
}
