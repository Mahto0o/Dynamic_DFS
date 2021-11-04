//
// Created by Mahta Shafiee Sabet on 2021-06-02.
//
#include <iostream>
#include "shallowTree.h"

void shallowTree::makeShallowTreeOfTree(tree *T) {
    //empty the path
    paths.clear();

    //making the first path starting at dummy node or preorderList[0]
    path *p;
    p = new path(T->preOrderList[0]);

    this->paths.insert(p);

    //making other path as well and pushing back all of them to the vector paths
    for (int i = 0; i < T->preOrderList.size(); i++) {
        if (!T->preOrderList[i]->children.empty()) {
            continue;
        }
//        this->paths.back()->end = T->preOrderList[i];
        p->end = T->preOrderList[i];

        //set the size of the path
//        this->paths.back()->size =
//                this->paths.back()->end->indexInOrderedList - this->paths.back()->start->indexInOrderedList + 1;
        p->size = p->end->indexInOrderedList - p->start->indexInOrderedList + 1;
//        this->paths.back().setPathSize();

        //after stting the end of a path if there is still nodes left in the tree we make a new path starting at the next element of preorderList
        if (i + 1 < T->preOrderList.size()) {
            p = new path(T->preOrderList[i + 1]);
            this->paths.insert(p);
//            this->paths.push_back(T->preOrderList[i + 1]);
        }
    }

    // setting the nodePath for each node in the DFS tree T, while, we're reaching each node through preorderList

//    path *temp = this->paths.head;
//    while (temp != NULL) {
//        for (int j = temp->start->indexInOrderedList; j <= temp->end->indexInOrderedList; j++) {
//            T->preOrderList[j]->nodePath = temp;
//        }
//        temp = temp->next;
//    }

    for (auto &i : this->paths) {
        for (int j = i->start->indexInOrderedList; j <= i->end->indexInOrderedList; j++) {
            T->preOrderList[j]->nodePath = i;
        }
    }


    //setting parent of each path in the shallow tree
    for (auto &i : this->paths) {
        if (i->start == T->root) {
            i->par = NULL;
        } else {
            i->par = i->start->par->nodePath;
        }
    }

//    temp = this->paths.head;
//    while (temp != NULL) {
//        if (temp->start == T->root) {
//            temp->par = NULL;
//        } else {
//            temp->par = temp->start->par->nodePath;
//        }
//        temp = temp->next;
//    }
}


shallowTree::shallowTree() {

}


