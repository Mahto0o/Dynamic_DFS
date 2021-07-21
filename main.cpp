#include <iostream>
#include <chrono>
#include "graph.h"
#include "tree.h"
#include "shallowTree.h"
#include "dataStructure.h"
#include "DynamicDFS.h"
#include "npy.hpp"

using namespace std;
using namespace std::chrono;
#define X   "/Users/mahtashafieesabet/Desktop/codes/pythonproject/GRAPH_SW_N11_E22_P0.5_K4_T/"
#define FILENAME   X"Graph.txt"
#define INPUTMATRIX X"data/07-13--23-45-34-DENSITY0.55_TS10_input.npy"

//#define INPUTMATRIX "/Users/mahtashafieesabet/Desktop/codes/pythonproject/GRAPH_SW_N15_E30_P0.5_K4_T/data/07-13--23-52-08-DENSITY0.55_TS10_input.npy"

int main() {
//    cout << "Hello, World!" << std::endl;
    auto start = high_resolution_clock::now();
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
//    cout << "list:\n";

    T.ComputePreorderList();
//    cout << T.preOrderList.size() << endl;
//    for (int i = 0; i < T.preOrderList.size(); i++) {
//        cout << T.preOrderList[i]->indx << " dfn:" << i << " " << T.preOrderList[i]->indexInOrderedList << "\n";
//    }
    shallowTree st;
    st.makeShallowTreeOfTree(&T);
    dataStructure D;
    D.computeDs(G, T);
//    int x = 0;
//    for(auto &j:D.ds){
//        cout<<x++<<":"<<")";
//        for(auto &i: j){
//            cout << i->indx<<" ";
//        }
//        cout<<endl;
//    }

    auto itup = D.ds[8].lower_bound(&G.adjList[2]);
    node* temp ;
    temp = *itup;
//    cout <<"hello:"<<T.preOrderList[8]->indx<<":"<< D.query(T.preOrderList[12], T.preOrderList[13], T.preOrderList[13])->indx << endl;
//    cout << D.query(T.preOrderList[5], st.paths[0].start, st.paths[0].start)->indx;

    vector<unsigned long> shape;
    bool fortran_order;
    vector<int64_t> data;
    // data is a vector which has the matrix's rows: a 10 by 15 matrix will be pushed 10 by 10 into data vector
    npy::LoadArrayFromNumpy(INPUTMATRIX, shape, fortran_order, data);
    vector<vector<bool>> matrix;
    for (int i = 0; i < shape[1]; i++) { //10
        vector<bool> v1;
        for (int j = 0; j < shape[0]; j++) {//15
            v1.push_back(data[j * 10 + i]);
        }
        matrix.push_back(v1);
    }
    vector<int> inactiveNodes;
    vector<int> activeNodes;
    tree *TStar = new tree();
    for (int t = 0; t < shape[1]; t++) {
        inactiveNodes.clear();
        activeNodes.clear();
        if (t == 0) {
            for (int i = 0; i < shape[0]; i++) {
                if (matrix[t][i] == 0) {
                    inactiveNodes.push_back(i);
                }
            }
        } else {
            inactiveNodes.clear();
            activeNodes.clear();
            for (int i = 0; i < shape[0]; i++) {
                if (matrix[t][i] == 1 && matrix[t - 1][i] == 0) {
                    activeNodes.push_back(i);
                }
                if (matrix[t][i] == 0 && matrix[t - 1][i] == 1) {
                    inactiveNodes.push_back(i);
                }
            }
        }
        G.makeAllNodesUnvisited();
        if (t % 2 == 0) {
            T.root->visited = false;
            T.root->ReducedAL.clear();
            st.makeShallowTreeOfTree(&T);
            Toggle(inactiveNodes, activeNodes, &st, &G);
            UpdateShallowTree(inactiveNodes, activeNodes, &st, &T, &G);

            TStar->adjList.clear();
            TStar->preOrderList.clear();
            TStar->root = nullptr;
            Reroot(T.root, &T, TStar, D, &st);
            TStar->root = T.root;
            TStar->ComputePreorderList();
        } else {
            TStar->root->visited = false;
            TStar->root->ReducedAL.clear();
            st.makeShallowTreeOfTree(TStar);
            Toggle(inactiveNodes, activeNodes, &st, &G);
            UpdateShallowTree(inactiveNodes, activeNodes, &st, TStar, &G);

            T.adjList.clear();
            T.preOrderList.clear();
            T.root = nullptr;
            Reroot(TStar->root, TStar, &T, D, &st);
            T.root = TStar->root;
            T.ComputePreorderList();
        }

    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << endl;

    //DFS
    start = high_resolution_clock::now();

    G.readGraph(FILENAME);

    T = G.ComputeDFSTree();
    npy::LoadArrayFromNumpy(INPUTMATRIX, shape, fortran_order, data);
    matrix.clear();
    for (int i = 0; i < shape[1]; i++) { //10
        vector<bool> v1;
        for (int j = 0; j < shape[0]; j++) {//15
            v1.push_back(data[j * 10 + i]);
        }
        matrix.push_back(v1);
    }
    for (int t = 0; t < shape[1]; t++){
        inactiveNodes.clear();
        activeNodes.clear();
        if (t == 0) {
            for (int i = 0; i < shape[0]; i++) {
                if (matrix[t][i] == 0) {
                    inactiveNodes.push_back(i);
                }
            }
        } else {
            inactiveNodes.clear();
            activeNodes.clear();
            for (int i = 0; i < shape[0]; i++) {
                if (matrix[t][i] == 1 && matrix[t - 1][i] == 0) {
                    activeNodes.push_back(i);
                }
                if (matrix[t][i] == 0 && matrix[t - 1][i] == 1) {
                    inactiveNodes.push_back(i);
                }
            }
        }
        G.makeAllNodesUnvisited();
        T.root->visited = false;
        T.root->ReducedAL.clear();
        Toggle(inactiveNodes, activeNodes, &st, &G);
        T = G.ComputeDFSTree();
    }
    stop = high_resolution_clock::now();
    cout << duration.count() << endl;
//    inactiveNodes.push_back(2);
//    inactiveNodes.push_back(3);
//    inactiveNodes.push_back(8);

//    G.makeAllNodesUnvisited();
//    Toggle(inactiveNodes, activeNodes, &st, &G);
//    UpdateShallowTree(inactiveNodes, activeNodes, &st, &T, &G);
//    tree *Tsrar = new tree();
//    Reroot(T.root, &T, TStar, D, &st);
//    TStar->root = T.root;
//    TStar->ComputePreorderList();
//    inactiveNodes.clear();
//    inactiveNodes.push_back(7);
//    inactiveNodes.push_back(9);
//    inactiveNodes.push_back(1);
//    activeNodes.push_back(3);
//    G.makeAllNodesUnvisited();
//    TStar->root->visited = false;
//    TStar->root->ReducedAL.clear();
//    st.makeShallowTreeOfTree(TStar);
//    Toggle(inactiveNodes, activeNodes, &st, &G);
//    UpdateShallowTree(inactiveNodes, activeNodes, &st, TStar, &G);
//    T.adjList.clear();
//    T.preOrderList.clear();
//    T.root = nullptr;
//    Reroot(TStar->root, TStar, &T, D, &st);
//    T.root = TStar->root;
//    T.ComputePreorderList();
    return 0;
}
