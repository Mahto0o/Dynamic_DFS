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
    node* start = NULL;
    node* end = NULL;
    path* par = NULL;
    int size = 0;
    void setPathSize();
    path();
    path(node* start);
    ~path();
};


#endif //CLION_PATH_H
