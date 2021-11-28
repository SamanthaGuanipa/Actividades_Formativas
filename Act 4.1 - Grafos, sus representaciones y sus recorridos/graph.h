#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;
 
class Graph {
    private:
        int edgesList;
        int edgesMat;
        int nodes;
        vector<int> *adjList;
        int *adjMatrix;
        void addEdgeAdjList(int u, int v);
        void addEdgeAdjMatrix(int u, int v);
        void sortAdjList();
        void dfsHelper(int init, int fin, stack<int> &s, list<int> &visited, vector<vector<int>> &paths);
        void bfsHelper(int init, int fin, queue<int> &q, list<int> &visited, vector<vector<int>> &paths);
        string printPaths(vector<vector<int>> &paths, int init, int fin);
        string printVisited(list<int> visited);
        bool contains(list<int> visited, int data);

    public:
        Graph();
        Graph(int n);
        void loadGraphList(string file, int n, int m);
        void loadGraphMat(string file, int n, int m);
        string printAdjMat();
        string printAdjList();
        string DFS(int init, int fin);
        string BFS(int init, int fin);
};

Graph::Graph() {
    edgesList = edgesMat = 0;
}

Graph::Graph(int n) {
    nodes = n;
    adjList = new vector<int> [nodes];
    adjMatrix = new int [nodes*nodes];
    for (int i = 0; i < nodes*nodes; i++) {
        adjMatrix[i] = 0;
    }
    edgesList = edgesMat = 0;
}

void Graph::addEdgeAdjList(int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
    edgesList++;
}

void Graph::addEdgeAdjMatrix(int u, int v) {
    adjMatrix[u*nodes+v] = 1;
    adjMatrix[v*nodes+u] = 1;
    edgesMat++;
}

void Graph::loadGraphList(string file, int n, int m) {
    adjList = new vector<int> [n];
    nodes = n;

    string line;
    ifstream read(file);
    int x, y;
    if (read.is_open()) {
        while (getline(read, line)) {
            x = stoi(line.substr(1,1));
            y = stoi(line.substr(4,1));
            addEdgeAdjList(x, y);
        }
        read.close();
    }
    else {
        cout << "Unable to open file" << endl;
    }
}

void Graph::loadGraphMat(string file, int n, int m) {
    adjMatrix = new int [n*m];
    nodes = n;
    for (int i = 0; i < n*m; i++) {
        adjMatrix[i] = 0;
        string line;
        ifstream read(file);
        int j, k;
        if (read.is_open()) {
            while (getline(read, line)) {
                j = stoi(line.substr(1,1));
                k = stoi(line.substr(4,1));
                addEdgeAdjMatrix(j, k);
            }
            read.close();
        }
        else {
            cout << "Unable to open file" << endl;
        }
    }
}

string Graph::printAdjMat() {
    stringstream aux;
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            aux << adjMatrix[i*nodes+j] << ' ';
        }
    }
    return aux.str();
}

string Graph::printAdjList() {
    stringstream aux;
    sortAdjList();
    for (int i = 0; i < nodes; i++) {
        aux << "vertex " << i << " :";
        for (int j = 0; j < adjList[i].size(); j++) {
            aux << " " << adjList[i][j];
        }
        aux << " ";
    }
    return aux.str();
}

void Graph::sortAdjList() {
    for (int i = 0; i < nodes; i ++) {
        sort(adjList[i].begin(), adjList[i].end());
    }
}

string Graph::DFS(int init, int fin) {
    stringstream aux;
    stack <int> s;
    list <int> visited;
    vector<vector<int>> paths(nodes, vector<int>(1, -1));
    s.push(init);
    dfsHelper(init, fin, s, visited, paths);
    aux << printVisited(visited);
    aux << printPaths(paths, init, fin);
    return aux.str();
}

void Graph::dfsHelper(int init, int fin, stack<int> &s, list<int> &visited, vector<vector<int>> &paths) {
    if (init == fin) {
        printVisited(visited);
    }
    else if (s.empty()) {
        cout << " node not found";
    }
    else {
        init = s.top();
        s.pop();
        visited.push_back(init);
        for (int i = 0; i < adjList[init].size(); i++) {
            if (!contains(visited, adjList[init][i])) {
                s.push(adjList[init][i]);
                paths[adjList[init][i]][0] = init;
            }
        }
        dfsHelper(init, fin, s, visited, paths);
    }
}

string Graph::BFS(int init, int fin) {
    stringstream aux;
    queue<int> q;
    list<int> visited;
    vector<vector<int>> paths(nodes, vector<int>(0));
    q.push(init);
    bfsHelper(init, fin, q, visited, paths);
    aux << printVisited(visited);
    aux << printPaths(paths, init, fin);
    return aux.str();
}

void Graph::bfsHelper(int init, int fin, queue<int> &q, list<int> &visited, vector<vector<int>> &paths) {
    stringstream aux;
    if (init == fin) {
        printVisited(visited);
    }
    else if (q.empty()) {
        aux << " node not found";
    }
    else {
        init = q.front();
        q.pop();
        visited.push_back(init);
        for (int i = 0; i < adjList[init].size(); i++) {
            if (!contains(visited, adjList[init][i])) {
                q.push(adjList[init][i]);
                paths[adjList[init][i]].push_back(init);
            }
        }
        bfsHelper(init, fin, q, visited, paths);
    }
}

string Graph::printVisited(list<int> visited) {
    stringstream aux;
    aux << "visited: ";
    while (!visited.empty()) {
        aux << visited.front() << " ";
        visited.pop_front();
    }
    return aux.str();
}

bool Graph::contains(list<int> visited, int data) {
    list<int>::iterator it;
    it = find(visited.begin(), visited.end(), data);
    if (it != visited.end()) {
        return true;
    }
    else {
        return false;
    }
}

string Graph::printPaths(vector<vector<int>> &paths, int init, int fin) {
    stringstream aux;
    int node = paths[fin][0];
    stack<int> reverso;
    reverso.push(fin);
    aux << "path:";
    while (node != init) {
        reverso.push(node);
        node = paths[node][0];
    }
    reverso.push(init);
    while (!reverso.empty()) {
        aux << " " << reverso.top();
        reverso.pop();
    }
    return aux.str();
}

#endif