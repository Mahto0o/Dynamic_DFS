//
// Created by Mahta Shafiee Sabet on 2021-06-07.
//

#include "dataStructure.h"

void dataStructure::computeDs(graph G, tree T) {

    for (int i = 0; i < T.preOrderList.size(); i++) {
        this->ds.push_back(set<node*> ());
        for (int j = 0; j < T.preOrderList[i]->neighbours.size(); j++) {
            if (T.preOrderList[i]->neighbours[j]->indexInOrderedList < T.preOrderList[i]->indexInOrderedList) {
                this->ds.back().insert(T.preOrderList[i]->neighbours[j]);
            }
        }
    }

}

node *dataStructure::query(node *x, node *pathStart, node *pathEnd) {
    set<node* >::iterator itup;
    node* temp;
    if(this->ds[x->indexInOrderedList].find(pathEnd) != this->ds[x->indexInOrderedList].end()){
        return pathEnd;
    }
    itup = this->ds[x->indexInOrderedList].upper_bound(pathEnd);
    if(itup != this->ds[x->indexInOrderedList].end()){
        temp = *itup;
    }
    if(temp->indexInOrderedList < pathStart->indexInOrderedList){
        return nullptr;
    }
    return temp;

//    return nullptr;
}
