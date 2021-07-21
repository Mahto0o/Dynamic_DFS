//
// Created by Mahta Shafiee Sabet on 2021-06-24.
//

#include "nodeDfnCmp.h"

bool nodeDfnCmp::operator () (const node *a, const node *b) { //(val, element)

    if(b->active){
        return a->indexInOrderedList <= b->indexInOrderedList;
    }
    else{
        return false;
    }

}

