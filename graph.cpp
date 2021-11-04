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

    int x = 0, numOfNodes, curNode, curNodeNeighb;
    string line;
    if (!ifs) {
        cerr << "Unable to open file datafile.txt";
        exit(1);   // call system to stop
    }

    stringstream s;
    getline(ifs, line);
    getline(ifs, line);
    getline(ifs, line);
    node nd;
    while (getline(ifs, line)) {
        s = stringstream();
        s << line;
        s >> curNode;
        x++;

    }
    ifs.clear();
    ifs.seekg(0);


//    getline(ifs, line);
//    s << line;
//    s >> numOfNodes;
    numOfNodes = x;
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
            adjList[curNodeNeighb].neighbours.push_back(&adjList[curNode]);
        }
    }
    // new reaed
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
    dummyNode->children.clear();
    for (auto &i : this->adjList) {
        i.neighbours.push_back(dummyNode);//connecting dummy node to all vertices
        i.cpNbrs = i.neighbours;
        i.visited = false;
        i.children.clear();
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
    for (auto &i: this->adjList) {
        i.visited = false;
        i.active = true;
        i.ReducedAL.clear();
    }
}

tree graph::ComputeDFSTreeBetweenActiveNodes() {
    node *dummyNode;
    dummyNode = &this->dummyNode;
    dummyNode->children.clear();
    dummyNode->neighbours.clear();
    for (auto &i : this->adjList) {
//        i.neighbours.push_back(dummyNode);//connecting dummy node to all vertices
        i.cpNbrs = i.neighbours;
        i.visited = false;
        i.children.clear();
        if (i.active)
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
            if (!stack_top_rnd_nbr->visited &&
                stack_top_rnd_nbr->active) {// if u's visited is unvisited add it to the DFS tree
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

void graph::RcursiveDFSBetweenAN(tree *T, node *v) {
//    static int c=1;
//    c++;
//    cout << "dfs() is called " << c << " times" << endl;
    if (T->adjList.empty()) {
        node *dummyNode;
        dummyNode = &this->dummyNode;
        dummyNode->children.clear();
        dummyNode->neighbours.clear();
        for (auto &i : this->adjList) {
            i.cpNbrs = i.neighbours;
            i.visited = false;
            i.children.clear();
            if (i.active)
                dummyNode->neighbours.push_back(&i);
        }
        dummyNode->cpNbrs = dummyNode->neighbours;

        T->root = dummyNode;
    }
    if (v->cpNbrs.empty()) {
        T->adjList.push_back(v);
        v->visited = true;
        return;
    } else {
        T->adjList.push_back(v);
        v->visited = true;
        for (auto &i: v->cpNbrs) {
//            static int c=1;
//            c++;
//            cout << "dfs() is called " << c << " times" << endl;
            if (!(i->visited) && i->active) {
                v->children.push_back(i);
                i->par = v;
                v->cpNbrs.pop_back();
                this->RcursiveDFSBetweenAN(T, i);
            }
        }
    }
}

