//
// Created by Mahta Shafiee Sabet on 2021-06-07.
//
//
#include "dataStructure.h"
#include "DynamicDFS.h"
#include <iostream>

void dataStructure::computeDs(graph* G, tree* T) {

//    for (auto &i : T->preOrderList) {
//
//        i->dfn = i->indexInOrderedList;
//        this->ds.emplace_back();
//        for (auto &j: i->neighbours) {
//            if (j->indexInOrderedList < i->indexInOrderedList) {
//                this->ds.back().insert(j);
//            }
//        }
//    }
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
//    static int count = 1;
//    count++;
//    cout << "query() is called " << count << " times" << endl;
//    set<node*, decltype(nodeCMP)*>::iterator itup;
//    node *temp;
//    itup = this->ds[x->dfn].lower_bound(pathEnd);
////    auto itup = this->ds[x->dfn].upper_bound(pathEnd);
//    if (itup != this->ds[x->dfn].end()) {
//        temp = *itup;
//    } else {
//        return nullptr;
//    }
//    if (temp->dfn < pathStart->dfn) {
//        return nullptr;
//    }
//    return temp;

    // array query
    node *temp;
    temp = lower_bound(pathEnd, this->data_structure[x->dfn]);

    if (temp->dfn < pathStart->dfn || temp->dfn > pathEnd->dfn || !temp->active) {
        return nullptr;
    }
    return temp;


}
