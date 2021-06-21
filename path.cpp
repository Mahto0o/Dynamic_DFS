//
// Created by Mahta Shafiee Sabet on 2021-06-01.
//

#include "path.h"

path::path() {

}

path::path(node *st) {
    this->start = st;
}

void path::setPathSize() {
    this->size =  this->end->indexInOrderedList - this->start->indexInOrderedList + 1;
}

path::~path() {
    this->start = nullptr;
    this->end = nullptr;
    this->par = nullptr;
}
