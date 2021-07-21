//
// Created by Mahta Shafiee Sabet on 2021-07-14.
//
//#include "node.h"
#ifndef CLION_NODECMP_H
#define CLION_NODECMP_H

class node;
bool nodeCMP (const node *a, const node *b);
//bool nodeRLCMP(const node *a, const node *b);
struct nodeRLCMP {
    bool operator() (const node *a, const node *b)const;
//    bool operator() (const node *a, const node *b) const {
//        return  a->indexInOrderedList < b->indexInOrderedList;
//    }
};

#endif //CLION_NODECMP_H