// =================================================================
//
// File: main.cpp
// Author: Ricardo Navarro Gómez - A01708825
//		   Alain Vicenzio Arizabalo - A01620758
// 		   Fernando Josué Matute Soto - A00833375
// Date: 25/11/22
//
// =================================================================
#include <iostream>
#include <list>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <string>
#include "graph.h"

using namespace std;

int main(int argc, char* argv[]) {

	ifstream input;
    ofstream mysolution;

	if (argc != 3){
		cout<< "Error"<<endl;
		return -1;
	}

	input.open(argv[1]);
	if (!input.is_open()){
		cout << "Error al abrir el archivo\n";
		return -1;
	}

	mysolution.open(argv[2]);

	int numEdges;
	string city1, city2;

	input >> numEdges;

	Graph<string> graph;
	for (int i=0; i<numEdges; i++){
		input >> city1 >> city2;
		graph.addEdge(city1, city2);
	}

	int numLines, depth;
	string startCity;
	input>>numLines;
	for (int i=0; i<numLines; i++){
		input>>startCity>> depth;
		set<string> neighbors = graph.getNeighbors(startCity);
		neighbors.insert(startCity);
		int currentDepth=1;

		while (currentDepth<depth){
			set<string> newNeighbors;
			for (string neighbor : neighbors){
				set<string> temp = graph.getNeighbors(neighbor);
				newNeighbors.insert(temp.begin(), temp.end());
			}
			neighbors.insert(newNeighbors.begin(), newNeighbors.end());
			currentDepth++;
		}

		mysolution<<"Case "<<i+1<<": "<<graph.numVertex()-neighbors.size()<<" ports not reachable from port "<<startCity<<" with MNP = "<<depth<<"."<< endl;
	}

	input.close();
	mysolution.close();

	return 0;
}

