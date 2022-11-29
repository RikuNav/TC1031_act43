#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <set>

using namespace std;

template <class T>
class Graph{
    private:
        vector<vector<bool>> graphMatrix;
        vector<T> vertices;

    public:
        Graph();
        ~Graph();

        void addVertex(T);
        void addEdge(T, T);

        set<T> getNeighbors(T);
        string toString();

        int numVertices();
};

template <class T>
Graph<T>::Graph()
{
}

template <class T>
Graph<T>::~Graph()
{
}

template <class T>
void Graph<T>::addVertex(T vertex){
  vertices.push_back(vertex);
  for (int i = 0; i < graphMatrix.size(); i++){
    graphMatrix[i].push_back(false);
  }
  vector<bool> newRow;
  for (int i = 0; i < graphMatrix.size() + 1; i++){
    newRow.push_back(false);
  }
  graphMatrix.push_back(newRow);
}

template <class T>
void Graph<T>::addEdge(T vertex1, T vertex2){
  int index1 = -1;
  int index2 = -1;
  for (int i = 0; i < vertices.size(); i++){
    if (vertices[i] == vertex1){
      index1 = i;
    }
    if (vertices[i] == vertex2){
      index2 = i;
    }
  }
  if (index1 == -1) {
    addVertex(vertex1);
    index1 = vertices.size() - 1;
  }
  if (index2 == -1){
    addVertex(vertex2);
    index2 = vertices.size() - 1;
  }
  graphMatrix[index1][index2] = true;
  graphMatrix[index2][index1] = true;
}

template <class T>
set<T> Graph<T>::getNeighbors(T vertex){
  set<T> neighbors;
  int index = -1;
  for (int i = 0; i < vertices.size(); i++){
    if (vertices[i] == vertex)
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
      neighbors.insert(vertices[i]);
    }
  }
  return neighbors;
}

template <class T>
string Graph<T>::toString()
{
  stringstream ss;
  for (int i = 0; i < graphMatrix.size(); i++){
    ss << vertices[i] << ": ";
    for (int j = 0; j < graphMatrix[i].size(); j++){
      if (graphMatrix[i][j]){
        ss << vertices[j] << " ";
      }
    }
    ss << endl;
  }
  return ss.str();
}

template <class T>
int Graph<T>::numVertices(){
  return vertices.size();
}

#endif