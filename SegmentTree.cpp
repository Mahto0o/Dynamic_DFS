//
// Created by Mahta Shafiee Sabet on 2021-05-18.
//

#include "SegmentTree.h"
#include <set>
#include <tuple>
#include "node.h"
#include <cmath>
//#include "iostream"

//bool cmp(tuple<node *, node *> a, tuple<node *, node *> b) {
//    return get<0>(a) < get<0>(b);
//}
//
//using Cmp = std::integral_constant<decltype(&cmp), &cmp>;

using namespace std;

SegmentTree::SegmentTree(graph g) {
    int n;
    n = g.adjList.size();
    this->sizeOfSegTree = pow(2, floor(log(n) / log(2))) + n - 1;
    this->segTree = new set<tuple<node *, node *>, cmp>[sizeOfSegTree];
}

void SegmentTree::FillSegTree(graph g, tree T) {
    //n is number of nodes in the graph g
    int n;
    n = g.adjList.size();
//    cout << "ji";
//    //make an array as a balanced binary tree (segment tree)
//    sizeOfSegTree = pow(2, floor(log(n) / log(2))) + n - 1;

    //setting the leaves of the balanced binary tree
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < T.preOrderList[n-i-1]->neighbours.size(); j++) {
            segTree[sizeOfSegTree - 1 - i].insert(make_tuple(T.preOrderList[n - i - 1]->neighbours[j], T.preOrderList[n - i - 1]));
        }
    }
    //filling the other nodes of the segment tree
    for (int i = sizeOfSegTree - n - 1; i >= 0; i--) {
        for (auto it = segTree[(i + 1) * 2].begin(); it != segTree[(i + 1) * 2].end(); it++) {
            segTree[i].insert(*it);
        }
        for (auto it = segTree[(i + 1) * 2 - 1].begin(); it != segTree[(i + 1) * 2 - 1].end(); it++) {
            segTree[i].insert(*it);
        }
    }

}

SegmentTree::~SegmentTree() {
    delete[] segTree;
}
