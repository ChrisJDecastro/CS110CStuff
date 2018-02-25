#ifndef _AIRLINES_GRAPH
#define _AIRLINES_GRAPH

#include <iostream>
#include <string>
#include <cmath>
#include "LinkedList.h" // ADT list operations
using namespace std;

const int SIZE = 6;

class AirlinesGraph
{
private:
  float adjacencyMatrix[SIZE][SIZE];
  float weightArray[SIZE];
  string airportNames[SIZE];
  ListInterface<int>* vertexSetListPtr;
  ListInterface<int>* notInVertexSetListPtr;

  void printVertexSet(string name, ListInterface<int>* listPtr);
  void printWeightArray();
  bool isInVertexSet(int vertex);
  void removeFromList(int vertex, ListInterface<int>* listPtr);
  void printCheapestPath();

public:
  AirlinesGraph();
  void computeCheapestPath();
};

#endif

