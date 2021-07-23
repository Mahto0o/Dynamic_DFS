//
// Created by Mahta Shafiee Sabet on 2021-06-08.
//
#include "DynamicDFS.h"
#include <iostream>

bool myNodeCF(node *a, node *b) {
    return (a->sizeofST < b->sizeofST);
}

void ComputeReducedAL(node *x, node *y, dataStructure ds, tree *T, shallowTree *st) {
    path *miu;
    node *z;
    node *w;
    node *u;
    miu = T->preOrderList[x->dfn]->nodePath->par;   //p.par;
    while (miu != nullptr && miu->start != nullptr && miu->end != nullptr) {
        for (int i = x->dfn; i <= y->dfn; i++) {
            if(ds.query(T->preOrderList[i], miu->start, miu->end)!= nullptr){
                T->preOrderList[i]->ReducedAL.insert(ds.query(T->preOrderList[i], miu->start, miu->end));
            }
        }
        miu = miu->par;
    }

    // C = descT(z) \ {v(dfn(x)), ..., v(dfn(y))}
    for (int i = y->dfn + 1; i < x->dfn + x->sizeofST; i++) { //2 to 10
        u = T->preOrderList[i];
        w = ds.query(u, x, y);
        if (w != nullptr && u->active) {
            w->ReducedAL.insert(u);
        }
    }

//    path *temp = st->paths.head;
//    while (temp != nullptr) {
//        if(temp->par == x->nodePath){
//            for (int i = temp->start->indexInOrderedList; i <= temp->end->indexInOrderedList; i++) {
//                u = T->preOrderList[i];
//                if(!u->active){
//                    continue;
//                }
//                w = ds.query(u, x, y);
//                if (w != nullptr) {
//                    w->ReducedAL.insert(u);
//                }
//            }
//        }
//        temp = temp->next;
//    }


}

void Reroot(node *x, tree *T, tree *Tstar, dataStructure ds, shallowTree *st) {
    bool startIsfurthur;
    // handle node insertion
    int startdfn = x->nodePath->start->indexInOrderedList;
    int enddfn = x->nodePath->end->indexInOrderedList;
    if (x->indexInOrderedList - startdfn >= enddfn - x->indexInOrderedList) {
        startIsfurthur = true;

        // attach path (x.nodepath.start, x) to Tstar
        for (int i = x->indexInOrderedList - 1; i >= startdfn; i--) {
            if (i == x->indexInOrderedList - 1 && Tstar->adjList.empty()) {
                //add the node to Tstar
                Tstar->adjList.push_back(T->preOrderList[i + 1]);
                T->preOrderList[i + 1]->childreni.clear();
            }
            //add the node to Tstar
            Tstar->adjList.push_back(T->preOrderList[i]);
            // set the node parent
            T->preOrderList[i]->pari = T->preOrderList[i + 1];
            T->preOrderList[i + 1]->childreni.push_back(T->preOrderList[i]);
            // set the node children
            T->preOrderList[i]->childreni.clear();
        }
        if (x->indexInOrderedList == startdfn && Tstar->adjList.empty()) {
            Tstar->adjList.push_back(T->preOrderList[x->indexInOrderedList]);
            T->preOrderList[x->indexInOrderedList]->childreni.clear();
        }

        //Update RAL(L) for vertices on the path (x.nodepath.start, x)
        ComputeReducedAL(x->nodePath->start, x, ds, T, st);

        // add untraversed path to paths
        if (x != x->nodePath->end) {
            x->nodePath->start = T->preOrderList[x->indexInOrderedList + 1];
        } else {
            //to check the correctness
//            x->nodePath->start = x->nodePath->end;
            st->paths.erase(x->nodePath);
//            x->nodePath->~path();

        }

        // mark all nodes on the path as visited
        for (int i = startdfn; i <= x->indexInOrderedList; i++) {
            T->preOrderList[i]->visited = true;
        }

        for (int i = x->indexInOrderedList; i >= startdfn; i--) {
            for (auto &u: T->preOrderList[i]->ReducedAL) {
                if (!u->visited) {
                    Tstar->adjList.push_back(u);
                    T->preOrderList[i]->childreni.push_back(u);
                    u->pari = T->preOrderList[i];
                    u->childreni.clear();
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
                Tstar->adjList.push_back(T->preOrderList[i - 1]);
                T->preOrderList[i - 1]->childreni.clear();
            }
            //add the node to Tstar
            Tstar->adjList.push_back(T->preOrderList[i]);
            // set the node parent
            T->preOrderList[i]->pari = T->preOrderList[i - 1];
            T->preOrderList[i - 1]->childreni.push_back(T->preOrderList[i]);
            // set the node children
            T->preOrderList[i]->childreni.clear();
        }

        //Update L for vertices on path (x.nodepath.start, x)
        ComputeReducedAL(x, x->nodePath->end, ds, T, st);

        // add untraversed path to paths
        if (x != x->nodePath->start) {
            x->nodePath->end = T->preOrderList[x->indexInOrderedList - 1];
        } else {
            //to check the correctness
//            x->nodePath->end = x->nodePath->start;
            st->paths.erase(x->nodePath);
//            x->nodePath->~path();
        }

        // mark all nodes on the path as visited
        for (int i = x->indexInOrderedList; i <= enddfn; i++) {
            T->preOrderList[i]->visited = true;
        }

        for (int i = enddfn; i >= x->indexInOrderedList; i--) {
            for (auto &u: T->preOrderList[i]->ReducedAL) {
                if (!u->visited) {
                    Tstar->adjList.push_back(u);
                    T->preOrderList[i]->childreni.push_back(u);
                    u->pari = T->preOrderList[i];
                    u->childreni.clear();
                    Reroot(u, T, Tstar, ds, st);
                }
            }
        }
    }

}

void Toggle(vector<int> inactiveNodes, vector<int> activeNodes, shallowTree *st, graph *G) {
    for (auto &i: inactiveNodes) {
        G->adjList[i].active = false;
    }
    for (auto &i: activeNodes) {
        G->adjList[i].active = true;
    }
}

void UpdateShallowTree(vector<int> inactiveNodes, vector<int> activeNodes, shallowTree *st, tree *T, graph *G) {

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
//                    continue;
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
        }
    }


/*
    for (auto &i:activeNodes) {
        //add the node to shallow tree
        st->paths.push_back(&G->adjList[i]);
        st->paths.back()->end = &G->adjList[i];
        st->paths.back()->setPathSize();

        //add the node to dfs tree and set the indexInOrderedList
        T->adjList.push_back(&G->adjList[i]);
        T->preOrderList.push_back(&G->adjList[i]);
        G->adjList[i].indexInOrderedList = T->preOrderList.size() - 1;


        //add the node to it's neighbour ReducedAl and vice versa
        int lowerNbr = 0;
        for (auto &j:G->adjList[i].neighbours) {
            if (j->active) {
                j->ReducedAL.insert(&G->adjList[i]);
                G->adjList[i].ReducedAL.insert(j);
                if(j->indexInOrderedList > lowerNbr){
                    lowerNbr = j->indexInOrderedList;
                }
            }
        }
        // add activated nodes to the tree for reroot
        T->preOrderList[lowerNbr]->children.push_back(&G->adjList[i]);
        G->adjList[i].par = T->preOrderList[lowerNbr];
        G->adjList[i].children.clear();
        G->adjList[i].sizeofST = 1;
    }
    */
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

//    // add activated nodes to the tree for reroot
//    for (auto &i:activeNodes) {
//        T->root->children.push_back(&G->adjList[i]);
//        G->adjList[i].par = T->root;
//        G->adjList[i].children.clear();
//        G->adjList[i].sizeofST = 1;
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

    // set size of st
//    T->root->sizeofST = 1;
//    for (auto &i:T->root->children) {
//        T->root->sizeofST += i->sizeofST;
//    }
//    T->ComputeSubtreeSizes(T->root);
}
