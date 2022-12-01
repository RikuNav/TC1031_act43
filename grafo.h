// =================================================================
//
// File: main.cpp
// Author: Ricardo Navarro Gómez - A01708825
//		   Alain Vicenzio Arizabalo - A01620758
// 		   Fernando Josué Matute Soto - A00833375
// Date: 25/11/22
//
// =================================================================
#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
#include <list>

using namespace std;

class Grafo{
    private:
        int V;
        list<string> *adjList;
        void DF(int v, bool visited[]);

    public:
        Grafo(int);
        void add(int, string);
        void DFS();
};

Grafo::Grafo(int V){
    this->V = V;
    adjList = new list<string>[V];
}

void Grafo::add(int v, string name){
    adjList[v].push_back(name);
}

void Grafo::DF(int v, bool visited[]){
    visited[v] = true;
    cout << v << " ";
    while(adjList[v].begin() != adjList[v].end()){
        DF(v,visited);
    }
}

void Grafo::DFS(){
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++){
        visited[i] = false;
    }
    for (int j = 0; j < V; j++){
        if (visited[j] == false){
            DF(j, visited);
        }
    }
}




#endif /* GRAFO_H */
