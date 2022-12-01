// =================================================================
//
// File: graph.h
// Author: Ricardo Navarro Gómez - A01708825
//		   Alain Vicenzio Arizabalo - A01620758
// 		   Fernando Josué Matute Soto - A00833375
// Date: 25/11/22
//
// =================================================================
#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <set>

using namespace std;

// =================================================================
// Definition of the Graph Class
// =================================================================

template <class T>
class Graph{
    private:
        vector<vector<bool>> graphMatrix;
        vector<T> vertexes;

    public:
        Graph();
        ~Graph();

        void addVertex(T);
        void addEdge(T, T);

        set<T> getNeighbors(T);
        string toString();

        int numVertex();
};
// =================================================================
// Constructor. Creates the graph, but doesn't give the vectors and
//              arrays a value.
// =================================================================
template <class T>
Graph<T>::Graph()
{
}

template <class T>
Graph<T>::~Graph()
{
}

// =================================================================
// addVertex. The function adds a value into the graph, first adding
//            it into the vertex vector, and then finding a place
//            in the matrix of the graph in which it could be placed
//            and connected.
//
// @param vertex, the value to be include.
// =================================================================
template <class T>
void Graph<T>::addVertex(T vertex){
  vertexes.push_back(vertex);
  for (int i = 0; i < graphMatrix.size(); i++){
    graphMatrix[i].push_back(false);
  }
  vector<bool> newRow;
  for (int i = 0; i < graphMatrix.size() + 1; i++){
    newRow.push_back(false);
  }
  graphMatrix.push_back(newRow);
}

// =================================================================
// addEdge, first it will search for the position of insertion in
//          the vertexes' vector, to then call the addVertex function
//          so that you could include both of them into the matrix
//          then, with the given position of both of them in the matrix,
//          it will change the state to true, that both values are
//          connected by an edge.
//
// @param vertex1, on of the values to be connected by an edge.
//        vertex2, the other value to be connected.
// =================================================================
template <class T>
void Graph<T>::addEdge(T vertex1, T vertex2){
  int index1 = -1;
  int index2 = -1;
  for (int i = 0; i < vertexes.size(); i++){
    if (vertexes[i] == vertex1){
      index1 = i;
    }
    if (vertexes[i] == vertex2){
      index2 = i;
    }
  }
  if (index1 == -1) {
    addVertex(vertex1);
    index1 = vertexes.size() - 1;
  }
  if (index2 == -1){
    addVertex(vertex2);
    index2 = vertexes.size() - 1;
  }
  graphMatrix[index1][index2] = true;
  graphMatrix[index2][index1] = true;
}

// =================================================================
// getNeighbors, returns the values that are conneccted to an
//               specific value contained in the graph.
//
// @param vertex, the value who's neighbours are going to be searched
// @return neighbors, all the neighbours that the given value have
// =================================================================
template <class T>
set<T> Graph<T>::getNeighbors(T vertex){
  set<T> neighbors;
  int index = -1;
  for (int i = 0; i < vertexes.size(); i++){
    if (vertexes[i] == vertex)
    {
      index = i;
    }
  }
  if (index == -1){
    return neighbors;
  }
  for (int i = 0; i < graphMatrix[index].size(); i++){
    if (graphMatrix[index][i])
    {
      neighbors.insert(vertexes[i]);
    }
  }
  return neighbors;
}

// =================================================================
// toString, gives all the graph in a string form
//
// @return ss, the graph in string value and not in structure
// =================================================================
template <class T>
string Graph<T>::toString()
{
  stringstream ss;
  for (int i = 0; i < graphMatrix.size(); i++){
    ss << vertexes[i] << ": ";
    for (int j = 0; j < graphMatrix[i].size(); j++){
      if (graphMatrix[i][j]){
        ss << vertexes[j] << " ";
      }
    }
    ss << endl;
  }
  return ss.str();
}

// =================================================================
// numVertexes, gives the total amount of vertex in the graph
//
// @return vertexes.size(), the total amount of vertex.
// =================================================================
template <class T>
int Graph<T>::numVertex(){
  return vertexes.size();
}

#endif