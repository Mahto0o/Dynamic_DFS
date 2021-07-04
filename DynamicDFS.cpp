//
// Created by Mahta Shafiee Sabet on 2021-06-08.
//
#include "DynamicDFS.h"
#include <iostream>


void ComputeReducedAL(node *x, node *y, dataStructure ds, tree T) {
    path *miu;
    node *z;
    node *w;
    node *u;
    miu = T.preOrderList[x->indexInOrderedList]->nodePath->par;   //p.par;
    while (miu != nullptr && miu->start != nullptr && miu->end != nullptr) {
        for (int i = x->indexInOrderedList; i < y->indexInOrderedList; i++) {
            T.preOrderList[i]->ReducedAL.insert(ds.query(T.preOrderList[i], miu->start, miu->end));
        }
        miu = miu->par;
    }
    if (x->indexInOrderedList < y->indexInOrderedList) {
        z = x;
    } else {
        z = y;
    }
    // C = descT(z) \ {v(dfn(x)), ..., v(dfn(y))}
    for (int i = y->indexInOrderedList + 1; i < x->indexInOrderedList + x->sizeofST; i++) { //2 to 11
        u = T.preOrderList[i];
        w = ds.query(u, x, y);
        if (w != nullptr && u->active) {
            w->ReducedAL.insert(u);
        }
    }

}

void Reroot(node *x, tree T, tree *Tstar, dataStructure ds, shallowTree *st) {
    bool startIsfurthur;
    int startdfn = x->nodePath->start->indexInOrderedList;
    int enddfn = x->nodePath->end->indexInOrderedList;
    if (x->indexInOrderedList - startdfn >= enddfn - x->indexInOrderedList) {
        startIsfurthur = true;

        // attach path (x.nodepath.start, x) to Tstar
        for (int i = x->indexInOrderedList - 1; i >= startdfn; i--) {
            if (i == x->indexInOrderedList - 1 && Tstar->adjList.empty()) {
                //add the node to Tstar
                Tstar->adjList.push_back(T.preOrderList[i + 1]);
                T.preOrderList[i + 1]->children.clear();
            }
            //add the node to Tstar
            Tstar->adjList.push_back(T.preOrderList[i]);
            // set the node parent
            T.preOrderList[i]->par = T.preOrderList[i + 1];
            T.preOrderList[i + 1]->children.push_back(T.preOrderList[i]);
            // set the node children
            T.preOrderList[i]->children.clear();
        }

        //Update RAL(L) for vertices on the path (x.nodepath.start, x)
        ComputeReducedAL(x->nodePath->start, x, ds, T);

        // add untraversed path to paths
        if (x != x->nodePath->end) {
            x->nodePath->end = T.preOrderList[x->indexInOrderedList + 1];
        } else {
            //to check the correctness
//            x->nodePath->start = x->nodePath->end;
            st->paths.erase(x->nodePath);
//            x->nodePath->~path();

        }

        // mark all nodes on the path as visited
        for (int i = startdfn; i <= x->indexInOrderedList; i++) {
            T.preOrderList[i]->visited = true;
        }

        for (int i = startdfn; i <= x->indexInOrderedList; i++) {
            for (auto &u: T.preOrderList[i]->ReducedAL) {
                if (!u->visited) {
                    Tstar->adjList.push_back(u);
                    T.preOrderList[i]->children.push_back(u);
                    u->par = T.preOrderList[i];
                    u->children.clear();
                    Reroot(u, T, Tstar, ds, st);
                }
            }
        }

    } else {
        startIsfurthur = false;

        // attach path (x , x.nodepath.end) to Tstar
        for (int i = x->indexInOrderedList + 1; i <= enddfn; i++) {
            if (i == x->indexInOrderedList + 1 && Tstar->adjList.empty()) {
                //add the node to Tstar
                Tstar->adjList.push_back(T.preOrderList[i - 1]);
                T.preOrderList[i - 1]->children.clear();
            }
            //add the node to Tstar
            Tstar->adjList.push_back(T.preOrderList[i]);
            // set the node parent
            T.preOrderList[i]->par = T.preOrderList[i - 1];
            T.preOrderList[i - 1]->children.push_back(T.preOrderList[i]);
            // set the node children
            T.preOrderList[i]->children.clear();
        }

        //Update L for vertices on path (x.nodepath.start, x)
        ComputeReducedAL(x, x->nodePath->end, ds, T);

        // add untraversed path to paths
        if (x != x->nodePath->start) {
            x->nodePath->end = T.preOrderList[x->indexInOrderedList - 1];
        } else {
            //to check the correctness
//            x->nodePath->end = x->nodePath->start;
            st->paths.erase(x->nodePath);
//            x->nodePath->~path();
        }

        // mark all nodes on the path as visited
        for (int i = x->indexInOrderedList; i <= enddfn; i++) {
            T.preOrderList[i]->visited = true;
        }
        for (int i = x->indexInOrderedList; i <= enddfn; i++) {
            for (auto &u: T.preOrderList[i]->ReducedAL) {
                if (!u->visited) {
                    Tstar->adjList.push_back(u);
                    T.preOrderList[i]->children.push_back(u);
                    u->par = T.preOrderList[i];
                    u->children.clear();
                    Reroot(u, T, Tstar, ds, st);
                }
            }
        }
    }

}

void Toggle(vector<int> inactiveNodes, shallowTree *st, graph *G) {
    for (auto &i: inactiveNodes) {
        G->adjList[i].active = false;
    }
}

void UpdateShallowTree(vector<int> inactiveNodes, shallowTree *st, tree *T, graph *G) {

    for (auto &i:inactiveNodes) {
        if (G->adjList[i].nodePath != nullptr) {

            path *p = G->adjList[i].nodePath;
            bool startIsSet = false;

            //delete the inactive nodes and add the remaining pieces of path to st
            for (int j = p->start->indexInOrderedList; j <= p->end->indexInOrderedList; j++) {

                if (!T->preOrderList[j]->active && !startIsSet) {
                    T->preOrderList[j]->nodePath = nullptr;
                    continue;
                }

                if (T->preOrderList[j]->active && !startIsSet) {
                    //set the start
                    st->paths.push_back(T->preOrderList[j]);
                    startIsSet = true;
                    continue;
                }

                if (!T->preOrderList[j]->active && startIsSet) {
                    T->preOrderList[j]->nodePath = nullptr;
                    st->paths.back()->end = T->preOrderList[j - 1];
                    st->paths.back()->setPathSize();
                    startIsSet = false;
                }
                if (T->preOrderList[j]->active && T->preOrderList[j] == p->end) {
                    st->paths.back()->end = T->preOrderList[j];
                    st->paths.back()->setPathSize();
                    startIsSet = false;
                }
            }
            // delete this nodePath G.adjList[i].nodePath
            st->paths.erase(p);
//            p->~path();
        }
    }
    //set nodePath for all the active nodes
    path *temp = st->paths.head;
    if (temp == nullptr) {
        cout << "Error: even the dummy node is inactive!";
    }
    while (temp != nullptr) {
        for (int j = temp->start->indexInOrderedList; j <= temp->end->indexInOrderedList; j++) {
            T->preOrderList[j]->nodePath = temp;
        }
        temp = temp->next;
    }
//    for (auto &i:st->paths) {
//        for (int j = i.start->indexInOrderedList; j <= i.end->indexInOrderedList; j++) {
//            T->preOrderList[j]->nodePath = &i;
//        }
//    }
    //set the parent for each nodePath in st
    temp = st->paths.head;
    while (temp != nullptr) {
        if (temp->start->indx == -1) {
            temp->par = nullptr;
            temp = temp->next;
            continue;
        }
        node *nearestActiveAncestor = temp->start->par;
        while (!nearestActiveAncestor->active) {
            nearestActiveAncestor = nearestActiveAncestor->par;
        }
        temp->par = nearestActiveAncestor->nodePath;
        temp = temp->next;
    }
//    for (auto &i:st->paths) {
//        node *nearestActiveAncestor = i.start->par;
//        while (!nearestActiveAncestor->active) {
//            nearestActiveAncestor = nearestActiveAncestor->par;
//        }
//        i.par = nearestActiveAncestor->nodePath;
//    }
}



//void Toggle(vector<bool> NodesStatus, shallowTree st, graph G) {
//    for(auto &i: G.adjList){
//        i.active = NodesStatus[i.indx];
//    }
//}