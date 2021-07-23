//
// Created by Mahta Shafiee Sabet on 2021-05-11.
//
#include <iostream>
#include <stack>
#include "DynamicDFS.h"
#include "tree.h"
#include <algorithm>

using namespace std;
//bool myNodeCF(node *a, node *b) {
//    return (a->sizeofST < b->sizeofST);
//}
void tree::printGraph() {
    cout << this->root->indx << " is the root:\n";
    for (auto &j: this->root->children) {
        cout << j->indx << ",";
    }
    cout << endl;
    for (auto &i : this->adjList) {
        cout << i->indx << " with par" << i->par->indx << ":\n";
        for (auto &j : i->children) {
            cout << j->indx << ",";
        }
        cout << "\n";
    }

}

void tree::ComputePreorderList() {

    this->ComputeSubtreeSizes(this->root);
    for (auto &i : this->adjList) {
        if (i->children.empty()) continue;
        sort(i->children.begin(), i->children.end(), myNodeCF);
//        reverse(i->children.begin(), i->children.end());
    }
    for (auto &i : this->adjList) {
//        i->cpNbrs.clear();
        i->cpNbrs = i->children;
        i->visited = false;
    }
    this->root->cpNbrs = this->root->children;

    preOrderList.push_back(this->root);
    stack<node *> s;
    s.push(this->root);
    this->root->visited = true;
    node *w, *u;
    while (!s.empty()) {
        w = s.top();
        if (w->cpNbrs.empty()) {
            s.pop();
        } else {
            u = w->cpNbrs.back();
            w->cpNbrs.pop_back();
            if (!u->visited) {// if u's status is unvisited
                preOrderList.push_back(u);
                u->visited = true;
                s.push(u);
            }
        }

    }
//    return list;
    for (int i = 0; i < preOrderList.size(); i++) {
        preOrderList[i]->indexInOrderedList = i;
    }
}

void tree::ComputeSubtreeSizes(node *r) {
    r->sizeofST = 1;
    if (r->children.empty()) return;
    for (int i = 0; i < r->children.size(); i++) {
        this->ComputeSubtreeSizes(r->children[i]);
        r->sizeofST += r->children[i]->sizeofST;
    }

}

tree::tree() {
    this->root = nullptr;
    this->adjList.clear();
    this->preOrderList.clear();
}


/*
    preOrderList.push_back(this->adjList.front());
    stack<node *> s;
    s.push(this->adjList.front());
    this->adjList.front()->status = true;
    node *w, *u;
    while (!s.empty()) {
        w = s.top();
        if (w->cpNbrs.empty()) {
            s.pop();
        } else {
            u = w->cpNbrs.back();
            w->cpNbrs.pop_back();
            if (u->status == 0) {// if u's status is unvisited
                preOrderList.push_back(u);
                u->status = true;
                s.push(u);
            }
        }

    }
*/