#include <iostream>
#include <chrono>
#include "graph.h"
#include "tree.h"
#include "shallowTree.h"
#include "dataStructure.h"
#include "DynamicDFS.h"
#include "npy.hpp"
#include "json.hpp"
#include<string.h>

int run_experiment(string graphfile, string inputmatrix, int count);

// for convenience
using json = nlohmann::json;using namespace std;

using namespace std;
using namespace std::chrono;
//#define X   "/Users/mahtashafieesabet/Desktop/codes/pythonproject/datasets/GRAPH_SW_N1000_E300000_P0.1_K600_T/"
#define FILENAME   X"Graph.txt"
#define INPUTMATRIX X"Data/08-15--02-05-10-DENSITY0.9_TS100_input.npy"

//#define INPUTMATRIX "/Users/mahtashafieesabet/Desktop/codes/pythonproject/GRAPH_SW_N11_E22_P0.5_K4_T/data/07-13--23-52-08-DENSITY0.55_TS10_input.npy"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Missing experiment file.";
        return 1;
    }
//    cout << "Reading experiment file: " << argv[1] << '\n';

    // read a JSON file
    std::ifstream json_file(argv[1]);

    int n_exp = 1;
    json experiments;
    json_file >> experiments;

    int count = 0;
    json data = experiments["data"];
    for (auto &i: data) {
        count++;
        string graphdir = i["graph"].get<string>();
        string inputmatrix = graphdir + i["inputmatrix"].get<string>();
//        cout << "Running experiment: " << n_exp << '\n';
//        cout << graphdir << '\t' << inputmatrix << '\n';
        if(count == 9){
//            cout<<"here";
        }
        run_experiment(graphdir + "Graph.txt", inputmatrix, count);
    }

    return 0;

}

int run_experiment(string graphfile, string inputmatrix, int count) {
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
    //    char *INPUTMATRIX = argv[1];

    //    FILENAME =
    auto start = high_resolution_clock::now();
    graph G;
    G.readGraph(graphfile);
    tree T;
    T = G.ComputeDFSTree();

    T.ComputePreorderList();

    shallowTree st;
    st.makeShallowTreeOfTree(&T);
    dataStructure D;
    auto pre = high_resolution_clock::now();
    D.computeDs(&G, &T);
    auto endpre = high_resolution_clock::now();
    auto durationpre = duration_cast<microseconds>(endpre - pre);
    cout << "pre processing:" << durationpre.count() << endl;

    vector<unsigned long> shape;
    bool fortran_order;
    vector<int64_t> data;
    // data is a vector which has the matrix's rows: a 10 by 15 matrix will be pushed 10 by 10 into data vector
    npy::LoadArrayFromNumpy(inputmatrix, shape, fortran_order, data);
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

    double updateTime[shape[1]];

    for (int t = 0; t < shape[1]; t++) {
//        auto s1 = high_resolution_clock::now();

        inactiveNodes.clear();

        for (int i = 0; i < shape[0]; i++) {
            if (matrix[t][i] == 0) {
                inactiveNodes.push_back(i);
            }
        }

        G.makeAllNodesUnvisited();

        T.root->visited = false;
        T.root->ReducedAL.clear();

        st.makeShallowTreeOfTree(&T);
        //        auto sp1 = high_resolution_clock::now();
        //        auto durationf = duration_cast<microseconds>(sp1 - s1);
        //        cout << "make st:" << durationf.count() << endl;
        //        s1 = high_resolution_clock::now();
        Toggle(inactiveNodes, activeNodes, &G);
        //        sp1 = high_resolution_clock::now();
        //        durationf = duration_cast<microseconds>(sp1 - s1);
        //        cout << "tpggle st:" << durationf.count() << endl;
        //        s1 = high_resolution_clock::now();

        auto s1 = high_resolution_clock::now();
        UpdateShallowTree(inactiveNodes, activeNodes, &st, &T, &G);
        //        sp1 = high_resolution_clock::now();
        //        durationf = duration_cast<microseconds>(sp1 - s1);
        //        cout << "update st st:" << durationf.count() << endl;
        TStar->adjList.clear();
        TStar->preOrderList.clear();
        TStar->root = nullptr;
        s1 = high_resolution_clock::now();
        Reroot(T.root, &T, TStar, &D);
        //        sp1 = high_resolution_clock::now();
        //        durationf = duration_cast<microseconds>(sp1 - s1);
        //        cout << "Reroot st:" << durationf.count() << endl;
        TStar->root = T.root;
//        if (TStar->root->childreni.size() != 1)
//            cout << "numOfCom in pap: " << t << ":" << TStar->root->childreni.size() << endl;
        auto sp1 = high_resolution_clock::now();//auto
        auto durationf = duration_cast<microseconds>(sp1 - s1);//AUTO
        updateTime[t] = durationf.count();
        //        cout << "Updatee:" << t << durationf.count() << endl;
        //        TStar->ComputePreorderList();

    }
    auto stop = high_resolution_clock::now();
    auto durationf = duration_cast<microseconds>(stop - start);
//    cout << "pap: " << durationf.count() << endl;
    int paper_time = 0;
    for(auto &h: updateTime){
        paper_time+= h;
    }
    cout << "pap: " << (float) paper_time / 1e3 << endl;
    std::ofstream out("paper.csv");

    for (auto &el : updateTime) {
        out << el;
        //        cout << el;
        out << '\n';
    }

    //DFS
    auto dfsstart = high_resolution_clock::now();

    for (int t = 0; t < shape[1]; t++) {
//        auto s1 = high_resolution_clock::now();
        inactiveNodes.clear();
        activeNodes.clear();
        for (int i = 0; i < shape[0]; i++) {
            if (matrix[t][i] == 0) {
                inactiveNodes.push_back(i);
            }
        }
//        if(t == 90){
//            cout << "herein dfs";
//        }
        G.makeAllNodesUnvisited();
        T.root->visited = false;
        T.root->ReducedAL.clear();
        T.adjList.clear();
        T.preOrderList.clear();
        Toggle(inactiveNodes, activeNodes, &G);
        auto s1 = high_resolution_clock::now();
//        T = G.ComputeDFSTreeBetweenActiveNodes();
        G.RcursiveDFSBetweenAN(&T, &G.dummyNode);
//        if (T.root->children.size() != 1)
//            cout << "numOfCom in dfs: " << t << ":" << T.root->children.size() << endl;

        auto sp1 = high_resolution_clock::now();
        auto durationf = duration_cast<microseconds>(sp1 - s1);
        updateTime[t] = durationf.count();
    }

    auto dfsstop = high_resolution_clock::now();
    auto dfsduration = duration_cast<microseconds>(dfsstop - dfsstart);
//    cout << "dfs: " << dfsduration.count() << endl;
    int dfs_time = 0;
    for(auto &h: updateTime){
        dfs_time+= h;
    }
    cout << "dfs: " << (float) dfs_time / 1e3 << endl;

    float ratio =  (float) dfs_time / (float) paper_time ;
    cout << "paper/dfs: " << ratio;
    if (ratio > 1.0) {
        cout << " ****";
    }
    cout << "\n\n";
    std::ofstream dfs("dfs.csv");

    for (auto &el : updateTime) {
        dfs << el;
        //        cout << el;
        dfs << '\n';
    }

    return 0;
}
