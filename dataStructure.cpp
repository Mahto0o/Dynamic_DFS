//
// Created by Mahta Shafiee Sabet on 2021-06-07.
//
#include <iostream>
#include "dataStructure.h"
#include "DynamicDFS.h"

void dataStructure::computeDs(graph G, tree T) {

    for (auto &i : T.preOrderList) {
//        this->ds.push_back(set<node*, nodeDfnCmp> ());
        i->dfn = i->indexInOrderedList;
        this->ds.emplace_back();
        for (auto &j: i->neighbours) {
            if (j->indexInOrderedList < i->indexInOrderedList) {
                this->ds.back().insert(j);
            }
        }
    }

}

node *dataStructure::query(node *x, node *pathStart, node *pathEnd) {
    static int count = 1;
    count++;
//    cout << "query() is called " << count << " times" << endl;
    set<node*, decltype(nodeCMP)*>::iterator itup;
    node *temp;
    itup = this->ds[x->dfn].lower_bound(pathEnd);
//    auto itup = this->ds[x->dfn].upper_bound(pathEnd);
    if (itup != this->ds[x->dfn].end()) {
        temp = *itup;
    } else {
        return nullptr;
    }
    if (temp->dfn < pathStart->dfn) {
        return nullptr;
    }
    return temp;

//    return nullptr;
}
