//
// Created by Mahta Shafiee Sabet on 2021-07-14.
//
#include "node.h"
#include "nodeCMP.h"
bool nodeCMP (const node *a, const node *b) { //(val, element)

    if(b->active){
        return a->indexInOrderedList > b->indexInOrderedList;
    }
    else{
        return false;
    }

}
//bool nodeRLCMP (const node *a, const node *b) {
//        return a->indexInOrderedList < b->indexInOrderedList;
//}
//bool nodeRLCMP::operator() (const node *a, const node *b) const {
//    return  a->indexInOrderedList < b->indexInOrderedList;
//}