//
// Created by Mahta Shafiee Sabet on 2021-05-18.
//

#ifndef CLION_SEGMENTTREE_H
#define CLION_SEGMENTTREE_H

#include "graph.h"
#include "tree.h"
#include <set>
#include <vector>
//using Cmp = std::integral_constant<decltype(&cmp), &cmp>;


class SegmentTree {
public:
    struct cmp {
        bool operator()(tuple<node *, node *> a, tuple<node *, node *> b) const {
            int a0, b0, a1, b1;
            a0 = get<0>(a)->indexInOrderedList;
            b0 = get<0>(b)->indexInOrderedList;
            if (a0 != b0) {
                return a0 < b0;
            }
            a1 = get<1>(a)->indexInOrderedList;
            b1 = get<1>(b)->indexInOrderedList;
            return a1 < b1;

//            if (get<0>(a)->sizeofST != get<0>(b)->sizeofST) {
//                return get<0>(a)->sizeofST < get<0>(b)->sizeofST;
//            } else {
//                if (get<1>(a)->sizeofST != get<1>(b)->sizeofST) {
//                    return get<1>(a)->sizeofST < get<1>(b)->sizeofST;
//                } else {
//                    if (get<0>(a) != get<0>(b)) {
//                        return get<0>(a) < get<0>(b);
//                    } else {
//                        if (get<1>(a) != get<1>(b)) {
//                            return get<1>(a) < get<1>(b);
//                        }
//                    }
//                }
//
//            }

        }
    };

    SegmentTree(graph g);

    ~SegmentTree();

    int sizeOfSegTree;
    set<tuple<node *, node *>, cmp> *segTree;// = new set<tuple<node *, node *>, cmp> [sizeOfSegTree];
    void FillSegTree(graph g, tree T);
//    vector<set<tuple<node *, node *>, cmp>> segTree;
};


#endif //CLION_SEGMENTTREE_H
