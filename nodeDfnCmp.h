//
// Created by Mahta Shafiee Sabet on 2021-06-24.
//

#ifndef CLION_NODEDFNCMP_H
#define CLION_NODEDFNCMP_H
#include "node.h"

class nodeDfnCmp {
public:
    bool operator () (const node* a, const node* b);
};


#endif //CLION_NODEDFNCMP_H
