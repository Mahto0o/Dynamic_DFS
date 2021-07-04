//
// Created by Mahta Shafiee Sabet on 2021-06-21.
//

#ifndef CLION_LINKEDLIST_H
#define CLION_LINKEDLIST_H
#include "path.h"
#include "node.h"

class linkedList {
public:
    path* head;


    void push_back(node* newElement);
    path* back();
    void erase(path* p);
    linkedList();
};


#endif //CLION_LINKEDLIST_H
