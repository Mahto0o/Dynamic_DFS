//
// Created by Mahta Shafiee Sabet on 2021-06-08.
//
#include "DynamicDFS.h"


void ComputeReducedAL(node *x, node *y, dataStructure ds, tree T) {
    path *miu;
    node *z;
    node *w;
    node *u;
    miu = T.preOrderList[x->indexInOrderedList]->nodePath->par;   //p.par;
    while (miu != NULL) {
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
    for (int i = y->indexInOrderedList + 1; i < x->indexInOrderedList + x->sizeofST; i++) {
        u = T.preOrderList[i];
        w = ds.query(u, x, y);
        if (w != NULL) {
            w->ReducedAL.insert(u);
        }
    }

//    for (each u in C) {
//        w = ds.query(u, x, y);
//        if (w != NULL){
//            w->ReducedAL.insert(u);
//        }
//    }

}

void Reroot(node *x, tree T, tree Tstar, dataStructure ds) {
    bool startIsfurthur;
    int startdfn = x->nodePath->start->indexInOrderedList;
    int enddfn = x->nodePath->end->indexInOrderedList;
    if (x->indexInOrderedList - startdfn > enddfn - x->indexInOrderedList) {
        startIsfurthur = true;

//        if (!Tstar.adjList.empty()) {
//            Tstar.adjList.back()->children.push_back(T.preOrderList[startdfn]);
//        }
        // attach path (x.nodepath.start, x) to Tstar
        for (int i = startdfn; i < x->indexInOrderedList; i++) {
            Tstar.adjList.push_back(T.preOrderList[i]);
            T.preOrderList[i]->children.clear();
            T.preOrderList[i]->children.push_back(T.preOrderList[i + 1]);
            T.preOrderList[i + 1]->par = T.preOrderList[i];
        }
        Tstar.adjList.push_back(x);
        x->children.clear();

        //Update RAL(L) for vertices on the path (x.nodepath.start, x)
        ComputeReducedAL(x->nodePath->start, x, ds, T);

        // add untraversed path to paths
        if (x != x->nodePath->end) {
            x->nodePath->end = T.preOrderList[x->indexInOrderedList + 1];
        } else {
            //to check the correctness
            x->nodePath->~path();
//            x->nodePath->start = nullptr;
//            x->nodePath->end = nullptr;
//            x->nodePath->par = nullptr;
//            x->nodePath->size = 0;
        }

        // mark all nodes on the path as visited
        for (int i = startdfn; i <= x->indexInOrderedList; i++) {
            T.preOrderList[i]->visited = true;
        }

        for (int i = startdfn; i <= x->indexInOrderedList; i++) {
            for (auto &u: T.preOrderList[i]->ReducedAL) {
                if (!u->visited) {
                    T.preOrderList[i]->children.push_back(u);
                    u->par = T.preOrderList[i];
                    Reroot(u, T, Tstar, ds);
                }
            }
        }

    } else {
        startIsfurthur = false;
        // attach path (x , x.nodepath.end) to Tstar
        for (int i = x->indexInOrderedList; i < enddfn; i++) {
            Tstar.adjList.push_back(T.preOrderList[i]);
            T.preOrderList[i]->children.clear();
            T.preOrderList[i]->children.push_back(T.preOrderList[i + 1]);
            T.preOrderList[i + 1]->par = T.preOrderList[i];
        }
        Tstar.adjList.push_back(x->nodePath->end);
        x->nodePath->end->children.clear();

        //Update L for vertices on path (x.nodepath.start, x)
        ComputeReducedAL(x, x->nodePath->end, ds, T);

        // add untraversed path to paths
        if (x != x->nodePath->start) {
            x->nodePath->end = T.preOrderList[x->indexInOrderedList - 1];
        } else {
            //to check the correctness
            x->nodePath->~path();
//            x->nodePath->start = nullptr;
//            x->nodePath->end = nullptr;
//            x->nodePath->par = nullptr;
//            x->nodePath->size = 0;
        }

        // mark all nodes on the path as visited
        for (int i = x->indexInOrderedList; i <= enddfn; i++) {
            T.preOrderList[i]->visited = true;
        }
        for (int i = x->indexInOrderedList; i <= enddfn; i++) {
            for (auto &u: T.preOrderList[i]->ReducedAL) {
                if (!u->visited) {
                    T.preOrderList[i]->children.push_back(u);
                    u->par = T.preOrderList[i];
                    Reroot(u, T, Tstar, ds);
                }
            }
        }
    }

}

void Toggle(vector<int> inactiveNodes, shallowTree st, graph G) {
    for (auto &i: inactiveNodes) {
        G.adjList[i].active = false;
    }
}

void UpdateShallowTree(vector<int> inactiveNodes, shallowTree st, tree T, graph G) {

    for (auto &i:inactiveNodes) {
        if (G.adjList[i].nodePath != nullptr) {

            path *p = G.adjList[i].nodePath;
            bool startIsSet = false;

            //delete the inactive nodes and add the remaining pieces of path to st
            for (int j = p->start->indexInOrderedList; j <= p->end->indexInOrderedList; j++) {

                if (!T.preOrderList[j]->active && !startIsSet) {
                    T.preOrderList[j]->nodePath = nullptr;
                    continue;
                }

                if (T.preOrderList[j]->active && !startIsSet) {
                    //set the start
                    st.paths.push_back(path(T.preOrderList[j]));
                    startIsSet = true;
                    continue;
                }

                if (!T.preOrderList[j]->active && startIsSet) {
                    T.preOrderList[j]->nodePath = nullptr;
                    st.paths.back().end = T.preOrderList[j - 1];
                    st.paths.back().setPathSize();
                    startIsSet = false;
                }
            }
            // delete this nodePath G.adjList[i].nodePath
//            G.adjList[i].nodePath->~path();
            p->~path();
        }
    }
    //set nodePath for all the active nodes
    for (auto &i:st.paths) {
        for (int j = i.start->indexInOrderedList; j <= i.end->indexInOrderedList; j++) {
            T.preOrderList[j]->nodePath = &i;
        }
    }
    //set the parent for each nodePath in st
    for (auto &i:st.paths) {
        node *nearestActiveAncestor = i.start->par;
        while (!nearestActiveAncestor->active) {
            nearestActiveAncestor = nearestActiveAncestor->par;
        }
        i.par = nearestActiveAncestor->nodePath;
    }
}



//void Toggle(vector<bool> NodesStatus, shallowTree st, graph G) {
//    for(auto &i: G.adjList){
//        i.active = NodesStatus[i.indx];
//    }
//}