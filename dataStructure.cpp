//
// Created by Mahta Shafiee Sabet on 2021-06-07.
//

#include "dataStructure.h"
#include "DynamicDFS.h"

void dataStructure::computeDs(graph G, tree T) {

    for (auto & i : T.preOrderList) {
//        this->ds.push_back(set<node*, nodeDfnCmp> ());
        i->dfn = i->indexInOrderedList;
        this->ds.emplace_back();
        for (int j = 0; j < i->neighbours.size(); j++) {
//            if (i->neighbours[j]->indexInOrderedList < i->indexInOrderedList) {
                this->ds.back().insert(i->neighbours[j]);
//            }
        }
    }

}

node *dataStructure::query(node *x, node *pathStart, node *pathEnd) {
//    set<node*, decltype(nodeCMP)*>::iterator itup;
    node* temp;
    auto itup = this->ds[x->dfn].lower_bound(pathEnd);
//    auto itup = this->ds[x->dfn].upper_bound(pathEnd);
    if(itup != this->ds[x->dfn].end()){
        temp = *itup;
    }
    else{
        return nullptr;
    }
    if(temp->indexInOrderedList < pathStart->indexInOrderedList){
        return nullptr;
    }
    return temp;

//    return nullptr;
}
