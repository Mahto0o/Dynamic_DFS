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
    vector<path *> kids;
    path* par = NULL;
    int size = 0;
    path();
    path(node* start);
};


#endif //CLION_PATH_H
