//
// Created by Mahta Shafiee Sabet on 2021-06-02.
//
#include <iostream>
#include "shallowTree.h"

void shallowTree::makeShallowTreeOfTree(tree* T) {

    //making the first path starting at dummy node or preorderList[0]
    path p(T->preOrderList[0]);
    this->paths.push_back(T->preOrderList[0]);

    //making other path as well and pushing back all of them to the vector paths
    for (int i = 0; i < T->preOrderList.size(); i++) {
        if (!T->preOrderList[i]->children.empty()) {
            continue;
        }
        this->paths.back()->end = T->preOrderList[i];

        //set the size of the path
        this->paths.back()->size =
                this->paths.back()->end->indexInOrderedList - this->paths.back()->start->indexInOrderedList + 1;
//        this->paths.back().setPathSize();

        //after stting the end of a path if there is still nodes left in the tree we make a new path starting at the next element of preorderList
        if (i + 1 < T->preOrderList.size()) {
            this->paths.push_back(T->preOrderList[i + 1]);
        }
    }

    // setting the nodePath for each node in the DFS tree T, while, we're reaching each node through preorderList
//    for (int i = 0; i < this->paths->size(); i++) {
//        for (int j = this->paths[i].start->indexInOrderedList; j <= this->paths[i].end->indexInOrderedList; j++) {
//            T.preOrderList[j]->nodePath = &this->paths[i];
//        }
//    }

    path* temp = this->paths.head;
    while (temp != NULL) {
        for (int j = temp->start->indexInOrderedList; j <= temp->end->indexInOrderedList; j++){
            T->preOrderList[j]->nodePath = temp;
        }
        temp = temp->next;
    }


    //setting parent of each path in the shallow tree
//    for (int i = 0; i < this->paths.size(); i++) {
//        if (paths[i].start == T.root) {
//            paths[i].par = NULL;
//        } else {
//            paths[i].par = paths[i].start->par->nodePath;
//        }
//    }

    temp = this->paths.head;
    while (temp != NULL) {
        if (temp->start == T->root) {
            temp->par = NULL;
        } else {
            temp->par = temp->start->par->nodePath;
        }
        temp = temp->next;
    }
}


shallowTree::shallowTree() {

}


