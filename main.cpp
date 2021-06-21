#include <iostream>
#include "graph.h"
#include "tree.h"
#include "shallowTree.h"
#include "dataStructure.h"
#include "DynamicDFS.h"

using namespace std;
#define FILENAME   "/Users/mahtashafieesabet/Desktop/codes/CLion/graphs/g3.txt"

int main() {
//    cout << "Hello, World!" << std::endl;
    graph G;
    G.readGraph(FILENAME);
//    cout << "print original graph";
//    G.printGraph();
    tree T;
    T = G.ComputeDFSTree();
//    cout<<"print dfs tree of the original graph\n";
//    T.printGraph();

//    T.ComputeSubtreeSizes(T.root);
//    for (int i = 0; i < T.adjList.size(); i++) {
//        cout << T.adjList[i]->indx << ":\t" << T.adjList[i]->sizeofST << endl;
//    }
//    cout << T.root->indx << T.root->kids.size() << endl;
    cout << "list:\n";

    T.ComputePreorderList();
    cout << T.preOrderList.size() << endl;
    for (int i = 0; i < T.preOrderList.size(); i++) {
        cout << T.preOrderList[i]->indx << " dfn:" << i << " " << T.preOrderList[i]->indexInOrderedList << "\n";
    }
    shallowTree st;
    st.makeShallowTreeOfTree(T);
    dataStructure D;
    D.computeDs(G, T);
    cout << D.query(T.preOrderList[4], T.preOrderList[0], T.preOrderList[2])->indx << endl;
    cout << D.query(T.preOrderList[5], st.paths[0].start, st.paths[0].end)->indx;
    return 0;
}
