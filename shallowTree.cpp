//
// Created by Mahta Shafiee Sabet on 2021-06-02.
//
#include <iostream>
#include "shallowTree.h"

void shallowTree::makeShallowTreeOfTree(tree T) {

    //making the first path starting at dummy node or preorderList[0]
    path p(T.preOrderList[0]);
    this->paths.push_back(p);

    //making other path as well and pushing back all of them to the vector paths
    for (int i = 0; i < T.preOrderList.size(); i++) {
        if (!T.preOrderList[i]->children.empty()) {
            continue;
        }
        this->paths.back().end = T.preOrderList[i];

        //set the size of the path
        this->paths.back().size =
                this->paths.back().end->indexInOrderedList - this->paths.back().start->indexInOrderedList + 1;

        //after stting the end of a path if there is still nodes left in the tree we make a new path starting at the next element of preorderList
        if (i + 1 < T.preOrderList.size()) {
            this->paths.push_back(path(T.preOrderList[i + 1]));
        }
    }

    // setting the nodepath for each node in the DFS tree T, while, we're reaching each node through preorderList
    for (int i = 0; i < this->paths.size(); i++) {
        for (int j = this->paths[i].start->indexInOrderedList; j <= this->paths[i].end->indexInOrderedList; j++) {
            T.preOrderList[j]->nodePath = &this->paths[i];
        }
    }

    //setting parent of each path in the shallow tree and then add each nodepath as it's parent children to the vector kids
    for (int i = 0; i < this->paths.size(); i++) {
        if (paths[i].start == T.root) {
            paths[i].par = NULL;
        } else {
            paths[i].par = paths[i].start->par->nodePath;
            paths[i].start->par->nodePath->kids.push_back(&paths[i]);
        }
    }
}


shallowTree::shallowTree() {

}
