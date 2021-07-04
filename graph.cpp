//
// Created by Mahta Shafiee Sabet on 2021-05-10.
//
#include "graph.h"
#include "tree.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stack>
#include <set>

using namespace std;

void graph::readGraph(string fileName) {
    ifstream ifs;
    ifs.open(fileName);

    int x, numOfNodes, curNode, curNodeNeighb;
    string line;
    if (!ifs) {
        cerr << "Unable to open file datafile.txt";
        exit(1);   // call system to stop
    }

    stringstream s;
    getline(ifs, line);
    s << line;
    s >> numOfNodes;
    node n[numOfNodes];
    for (int i = 0; i < numOfNodes; i++) {
        this->adjList.push_back(n[i]);
    }
    getline(ifs, line);
    getline(ifs, line);
    getline(ifs, line);

    while (getline(ifs, line)) {
        s = stringstream();
        s << line;
        s >> curNode;
        adjList[curNode].indx = curNode;
        while (s >> curNodeNeighb) {
            adjList[curNode].neighbours.push_back(&adjList[curNodeNeighb]);
        }
    }

    ifs.close();
}

void graph::printGraph() {
    for (auto &i : this->adjList) {
        cout << "indx " << i.indx << ":\n";
        for (auto &neighbour : i.neighbours) {
            cout << neighbour->indx << ",";
        }
        cout << "\n";
    }
}

tree graph::ComputeDFSTree() {
    node *dummyNode;
    dummyNode = &this->dummyNode;
    for (auto &i : this->adjList) {
        i.neighbours.push_back(dummyNode);//connecting dummy node to all vertices
        i.cpNbrs = i.neighbours;
        i.visited = false;
        dummyNode->neighbours.push_back(&i);
    }
    dummyNode->cpNbrs = dummyNode->neighbours;
    tree T;

    node *stack_top, *stack_top_rnd_nbr;
    stack<node *> s;
    s.push(dummyNode);
    dummyNode->visited = true;
    T.root = dummyNode;

    while (!s.empty()) {
        stack_top = s.top();
        if (stack_top->cpNbrs.empty()) {
            s.pop();
        } else {
            stack_top_rnd_nbr = stack_top->cpNbrs.back();
            stack_top->cpNbrs.pop_back();
            if (!stack_top_rnd_nbr->visited) {// if u's visited is unvisited add it to the DFS tree
                T.adjList.push_back(stack_top_rnd_nbr);
                stack_top_rnd_nbr->par = stack_top;
                stack_top->children.push_back(stack_top_rnd_nbr);
                stack_top_rnd_nbr->visited = true;
                s.push(stack_top_rnd_nbr);
            }
        }
    }
//    T.adjList.push_back(T.root);
//    T.ComputeSubtreeSizes(T.root);
    return T;
}

void graph::makeAllNodesUnvisited() {
    for(auto &i: this->adjList){
        i.visited = false;
    }
}
