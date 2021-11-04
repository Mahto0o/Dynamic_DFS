//
// Created by Mahta Shafiee Sabet on 2021-06-08.
//
#include "DynamicDFS.h"
#include <iostream>
#include <chrono>

using namespace std::chrono;
using namespace std;

bool myNodeCF(node *a, node *b) {
    return (a->sizeofST < b->sizeofST);
}

bool Node_cmp_for_ds(node *a, node *b) {
    return a->indexInOrderedList < b->indexInOrderedList;
}

node *lower_bound(node *nd, vector<node *> &ancestors) {
    int min = 0, max = ancestors.size() - 1;
    int mean;
    while (max > min) {
        mean = (max + min) / 2;
        if (ancestors[mean]->indexInOrderedList == nd->indexInOrderedList) {
            return ancestors[mean];
        } else if (ancestors[mean]->indexInOrderedList > nd->indexInOrderedList) {
            max = (mean - 1);
        } else {
            min = (mean + 1);
        }
    }

    if (ancestors[min]->indexInOrderedList <= nd->indexInOrderedList)
        return ancestors[min];
    else if (ancestors[min - 1]->indexInOrderedList <= nd->indexInOrderedList)
        return ancestors[min - 1];
    else
        cout << "hello" << endl;
    return nullptr;
}

void ComputeReducedAL(node *x, node *y, dataStructure *ds, tree *T, bool startIsFurthur) {
    static int count = 1;
    count++;
//    cout << "CmpReducedAL() is called " << count << " times" << endl;
    path *miu;
//    node *z;
    node *w;
    node *u;
    if (!startIsFurthur && x != x->nodePath->start) {
        for (int i = x->dfn; i <= y->dfn; i++) {
            w = ds->query(T->preOrderList[i], x->nodePath->start, T->preOrderList[x->indexInOrderedList - 1]);
            if (w != nullptr && w->active && !w->visited) {
                T->preOrderList[i]->ReducedAL.insert(w);
            }
        }
    }
    miu = T->preOrderList[x->dfn]->nodePath->par;   //p.par;
    while (miu != nullptr && miu->start != nullptr && miu->end != nullptr) {
        for (int i = x->dfn; i <= y->dfn; i++) {

            w = ds->query(T->preOrderList[i], miu->start, miu->end);
            if (w != nullptr && w->active && !w->visited) {
                T->preOrderList[i]->ReducedAL.insert(w);
            }
        }
        miu = miu->par;
    }

    // C = descT(z) \ {v(dfn(x)), ..., v(dfn(y))}
    for (int i = y->dfn + 1; i < x->dfn + x->sizeofST; i++) { //2 to 10
        u = T->preOrderList[i];
        if (u->active && !u->visited) {
//            auto start = high_resolution_clock::now();
            w = ds->query(u, x, y);
//            auto stp = high_resolution_clock::now();
//            auto durationpre = duration_cast<microseconds>(stp - start);
//            cout << durationpre.count();
            if (w != nullptr) {
                w->ReducedAL.insert(u);

            }
        }
    }
}

void ComputeReducedAL2(node *x, node *y, dataStructure *ds, tree *T) {

    path *miu;
    node *w;
    node *u;
//    bool flag = false;

    miu = T->preOrderList[x->dfn]->nodePath->par;   //p.par;
    while (miu != nullptr && miu->start != nullptr && miu->end != nullptr) {
        for (int i = y->dfn; i >= x->dfn; i--) {
            if (miu->end->visited) {
                break;
            }
            w = ds->query2(T->preOrderList[i], miu->start, miu->end);
            if (w != nullptr ){//&& w->active && !w->visited) {
                T->preOrderList[i]->ReducedAL.insert(w);
                break;
            }
        }
        miu = miu->par;
    }

    // C = descT(z) \ {v(dfn(x)), ..., v(dfn(y))}
    if (x->indexInOrderedList != 0) {
        for (int i = y->dfn + 1; i < x->dfn + x->sizeofST; i++) { //2 to 10
            u = T->preOrderList[i];
            if(u->visited){
                i = u->nodePath->end->indexInOrderedList;
                continue;
            }
            if (u->active && !u->visited) {
                w = ds->query2(u, x, y);
                if (w != nullptr) {
                    w->ReducedAL.insert(u);
                    i = u->nodePath->end->indexInOrderedList;
                }
            }
        }
    } else {
        if (y != x) {
            for (int i = y->dfn + 1; i < x->dfn + x->sizeofST; i++) { //2 to 10
                u = T->preOrderList[i];
//                if(u->visited){
//                    i = u->nodePath->end->indexInOrderedList;
//                    continue;
//                }
                if (u->active && !u->visited) {
                    w = ds->query2(u, T->preOrderList[x->dfn + 1], y);
                    if (w != nullptr) {
                        w->ReducedAL.insert(u);
                        i = u->nodePath->end->indexInOrderedList;
                    } else if(u->active) {
                        x->ReducedAL.insert(u);
                        i = u->nodePath->end->indexInOrderedList;
                    }
                }
            }
        } else {
            for (int i = y->dfn + 1; i < x->dfn + x->sizeofST; i++) {
                u = T->preOrderList[i];
                if(u->visited){
                    i = u->nodePath->end->indexInOrderedList;
                }
                if (u->active && !u->visited) {
                    x->ReducedAL.insert(u);
                    i = u->nodePath->end->indexInOrderedList;
                }
            }
        }
    }

}

void Reroot(node *x, tree *T, tree *Tstar, dataStructure *ds) {

//    static int count = 1;
//    count++;
//    cout << "Reroot() is called " << count << " times" << endl;
    // handle node insertion
    int start, end, endp;
    int inc;
    bool startIsFurthur;
    int startdfn = x->nodePath->start->indexInOrderedList;
    int enddfn = x->nodePath->end->indexInOrderedList;
    if (x->indexInOrderedList - startdfn >= enddfn - x->indexInOrderedList) {
        start = x->indexInOrderedList - 1;
        end = startdfn;
        inc = 1;
        startIsFurthur = true;
        endp = x->indexInOrderedList;
    } else {
        start = x->indexInOrderedList + 1;
        end = enddfn;
        inc = -1;
        startIsFurthur = false;
        endp = end;
    }


    // attach path (x.nodepath.start, x) to Tstar
    for (int i = start; startIsFurthur && (i >= end) || !startIsFurthur && (i <= end); i -= inc) {
        if (i == start && Tstar->adjList.empty()) {
            //add the node to Tstar
            Tstar->adjList.push_back(T->preOrderList[i + 1 * (inc)]);
            T->preOrderList[i + 1 * (inc)]->childreni.clear();
        }
        //add the node to Tstar
        Tstar->adjList.push_back(T->preOrderList[i]);
        // set the node parent
        T->preOrderList[i]->pari = T->preOrderList[i + 1 * (inc)];
        T->preOrderList[i + 1 * (inc)]->childreni.push_back(T->preOrderList[i]);
        // clear the node children
        T->preOrderList[i]->childreni.clear();
    }

    if (x->indexInOrderedList == startdfn && Tstar->adjList.empty()) {
        Tstar->adjList.push_back(T->preOrderList[x->indexInOrderedList]);
        T->preOrderList[x->indexInOrderedList]->childreni.clear();
    }

//    auto strt = std::chrono::high_resolution_clock::now();
    //Update RAL(L) for vertices on the path (x.nodepath.start, x)
    if (startIsFurthur) {
        ComputeReducedAL(x->nodePath->start, x, ds, T, startIsFurthur);
    } else {
        ComputeReducedAL(x, x->nodePath->end, ds, T, startIsFurthur);
    }
//    auto stp = std::chrono::high_resolution_clock::now();
//    auto duration = duration_cast<std::chrono::microseconds>(stp - strt);
//    cout << duration.count() << endl;

    // add untraversed path to paths
    if ((x != x->nodePath->end) && startIsFurthur || (x != x->nodePath->start) && !startIsFurthur) {
        if (startIsFurthur) {
            x->nodePath->start = T->preOrderList[x->indexInOrderedList + 1];
        } else {
            x->nodePath->end = T->preOrderList[x->indexInOrderedList - 1];
        }
    } else {
//        st->paths.erase(x->nodePath);

    }

    // mark all nodes on the path as visited
    for (int i = end; i != x->indexInOrderedList; i += inc) {
        T->preOrderList[i]->visited = true;
    }
    T->preOrderList[x->indexInOrderedList]->visited = true;


    for (int i = endp; startIsFurthur && (i >= end) || !startIsFurthur && (i >= x->indexInOrderedList); i--) {
        for (auto &u: T->preOrderList[i]->ReducedAL) {
            if (!u->visited) {
                Tstar->adjList.push_back(u);
                T->preOrderList[i]->childreni.push_back(u);
                u->pari = T->preOrderList[i];
                u->childreni.clear();
                Reroot(u, T, Tstar, ds);
            }
        }
    }
}

void Reroot2(node *x, tree *T, tree *Tstar, dataStructure *ds) {

    int start;
//    bool startIsFurthur;
    int startdfn = x->nodePath->start->indexInOrderedList;
    int enddfn = x->nodePath->end->indexInOrderedList;
    start = x->indexInOrderedList - 1;

    // attach path (x, x.nodepath.start] to Tstar
    for (int i = x->indexInOrderedList - 1; i >= startdfn; i--) {
        //add the dummy node to Tstar
        if (i == start && Tstar->adjList.empty()) {
            Tstar->adjList.push_back(T->preOrderList[i + 1]);
            T->preOrderList[i + 1]->childreni.clear();
        }
        //add the node to Tstar
        Tstar->adjList.push_back(T->preOrderList[i]);
        // set the node parent
        T->preOrderList[i]->pari = T->preOrderList[i + 1];
        T->preOrderList[i + 1]->childreni.push_back(T->preOrderList[i]);
        // clear the node children
        T->preOrderList[i]->childreni.clear();
    }

    if (x->indexInOrderedList == startdfn && Tstar->adjList.empty()) {
        Tstar->adjList.push_back(T->preOrderList[x->indexInOrderedList]);
        T->preOrderList[x->indexInOrderedList]->childreni.clear();
    }

    // attach path (x, x.nodepath.end] to Tstar
    for (int i = x->indexInOrderedList + 1; i <= enddfn; i++) {
        //add the node to Tstar
        Tstar->adjList.push_back(T->preOrderList[i]);
        // set the node parent
        T->preOrderList[i]->pari = T->preOrderList[i - 1];
        T->preOrderList[i - 1]->childreni.push_back(T->preOrderList[i]);
        // clear the node children
        T->preOrderList[i]->childreni.clear();
    }

    //Update RAL(L) for vertices on the path (x.nodepath.start, x.nodepath.end)
    ComputeReducedAL2(x->nodePath->start, x->nodePath->end, ds, T);

    // mark all nodes on the path as visited
    for (int i = startdfn; i <= enddfn; i++) {
        T->preOrderList[i]->visited = true;
    }


    for (int i = enddfn; i >= startdfn; i--) {
        for (auto &u: T->preOrderList[i]->ReducedAL) {
            if (!u->visited) {
                Tstar->adjList.push_back(u);
                T->preOrderList[i]->childreni.push_back(u);
                u->pari = T->preOrderList[i];
                u->childreni.clear();
                Reroot2(u, T, Tstar, ds);
            }
        }
    }
}

void Toggle(vector<int> &inactiveNodes, vector<int> &activeNodes, graph &G) {
    for (auto &i: inactiveNodes) {
        G.adjList[i].active = false;
    }
    for (auto &i: activeNodes) {
        G.adjList[i].active = true;
    }
}

void UpdateShallowTree(vector<int> &inactiveNodes, vector<int> &activeNodes, shallowTree *st, tree *T, graph *G) {

    for (auto &i:inactiveNodes) {
        if (G->adjList[i].nodePath != nullptr) {

            path *p = G->adjList[i].nodePath;
            st->paths.erase(p);
            path *pp;
            bool startIsSet = false;

            //delete the inactive nodes and add the remaining pieces of path to st
            for (int j = p->start->indexInOrderedList; j <= p->end->indexInOrderedList; j++) {

                if (!T->preOrderList[j]->active && !startIsSet) {
                    T->preOrderList[j]->nodePath = nullptr;
                    continue;
                }

                if (T->preOrderList[j]->active && !startIsSet) {
                    //set the start
                    pp = new path(T->preOrderList[j]);
                    st->paths.insert(pp);
                    startIsSet = true;
//                    continue;
                }

                if (!T->preOrderList[j]->active && startIsSet) {
                    T->preOrderList[j]->nodePath = nullptr;
                    pp->end = T->preOrderList[j - 1];
                    pp->setPathSize();
                    startIsSet = false;
                }
                if (T->preOrderList[j]->active && T->preOrderList[j] == p->end) {
                    pp->end = T->preOrderList[j];
                    pp->setPathSize();
                    startIsSet = false;
                }
            }
            // delete this nodePath G.adjList[i].nodePath

//            st->paths.erase(p);
        }
    }
    //set nodePath for all the active nodes
    for (auto &i : st->paths) {
        for (int j = i->start->indexInOrderedList; j <= i->end->indexInOrderedList; j++) {
            T->preOrderList[j]->nodePath = i;
        }
    }

    //set the parent for each nodePath in st
    for (auto &i : st->paths) {
        if (i->start->indx == -1) {
            i->par = nullptr;
            continue;
        }
        node *nearestActiveAncestor = i->start->par;
        while (!nearestActiveAncestor->active) {
            nearestActiveAncestor = nearestActiveAncestor->par;
        }
        i->par = nearestActiveAncestor->nodePath;
    }

}

