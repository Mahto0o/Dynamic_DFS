//
// Created by Mahta Shafiee Sabet on 2021-06-01.
//
#ifndef CLION_PATH_H
#define CLION_PATH_H
#include "node.h"
#include <vector>

using namespace std;
class node;
class path {
public:
//    path* next = nullptr;
//    path* prev = nullptr;
    node* start = nullptr;
    node* end = nullptr;
    path* par = nullptr;
    int size = 0;
    void setPathSize();
    path();
    path(node* start);
    ~path();
    bool operator() (path *p1, path *p2) const;
};


#endif //CLION_PATH_H
