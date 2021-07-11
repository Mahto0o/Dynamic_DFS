//
// Created by Mahta Shafiee Sabet on 2021-06-07.
//

#include "dataStructure.h"

void dataStructure::computeDs(graph G, tree T) {

    for (auto & i : T.preOrderList) {
//        this->ds.push_back(set<node*, nodeDfnCmp> ());
        i->dfn = i->indexInOrderedList;
        this->ds.emplace_back();
        for (int j = 0; j < i->neighbours.size(); j++) {
            if (i->neighbours[j]->indexInOrderedList < i->indexInOrderedList) {
                this->ds.back().insert(i->neighbours[j]);
            }
        }
    }

}

node *dataStructure::query(node *x, node *pathStart, node *pathEnd) {
    set<node*, nodeDfnCmp>::iterator itup;
    node* temp;
    if(this->ds[x->dfn].find(pathEnd) != this->ds[x->dfn].end()){
        return pathEnd;
    }
    itup = this->ds[x->dfn].upper_bound(pathEnd);
    if(itup != this->ds[x->dfn].end()){
        temp = *itup;
    }
    if(temp->dfn < pathStart->dfn){
        return nullptr;
    }
    return temp;

//    return nullptr;
}
