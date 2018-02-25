#include "AirlinesGraph.h"
  
AirlinesGraph::AirlinesGraph()
{
  // ROW 0 | SFO
  airportNames[0] = "SFO";
  adjacencyMatrix[0][0] = 100000;
  adjacencyMatrix[0][1] = 120.0;
  adjacencyMatrix[0][2] = 150.0;   
  adjacencyMatrix[0][3] = 100000;
  adjacencyMatrix[0][4] = 100000;
  adjacencyMatrix[0][5] = 500.0;
  
  // ROW 1 | LAX
  airportNames[1] = "LAX";
  adjacencyMatrix[1][0] = 120.0;
  adjacencyMatrix[1][1] = 100000;  
  adjacencyMatrix[1][2] = 100000;
  adjacencyMatrix[1][3] = 75.0;
  adjacencyMatrix[1][4] = 100000;
  adjacencyMatrix[1][5] = 350.0;
  
  // ROW 2 | LAS
  airportNames[2] = "LAS";
  adjacencyMatrix[2][0] = 150.0;
  adjacencyMatrix[2][1] = 100000;
  adjacencyMatrix[2][2] = 100000;
  adjacencyMatrix[2][3] = 100000;
  adjacencyMatrix[2][4] = 250.0;
  adjacencyMatrix[2][5] = 100000;
  
  // ROW 3 | PHX
  airportNames[3] = "PHX";
  adjacencyMatrix[3][0] = 100000; 
  adjacencyMatrix[3][1] = 75.0;
  adjacencyMatrix[3][2] = 100000;
  adjacencyMatrix[3][3] = 100000;
  adjacencyMatrix[3][4] = 150.0;
  adjacencyMatrix[3][5] = 100000;

  // ROW 4 | DEN
  airportNames[4] = "DEN";
  adjacencyMatrix[4][0] = 100000;
  adjacencyMatrix[4][1] = 100000;
  adjacencyMatrix[4][2] = 250.0;
  adjacencyMatrix[4][3] = 150.0;
  adjacencyMatrix[4][4] = 100000;
  adjacencyMatrix[4][5] = 100000;
   
  // ROW 5 | JFK
  airportNames[5] = "JFK";
  adjacencyMatrix[5][0] = 500.0;
  adjacencyMatrix[5][1] = 350.0;
  adjacencyMatrix[5][2] = 100000;
  adjacencyMatrix[5][3] = 100000;
  adjacencyMatrix[5][4] = 100000;
  adjacencyMatrix[5][5] = 100000;
    
  vertexSetListPtr = new LinkedList<int>();
  notInVertexSetListPtr = new LinkedList<int>();
}

void AirlinesGraph::computeCheapestPath()
{
  int numVertices = SIZE;
  vertexSetListPtr->insert(1, 0);
  
  for (int i = 1; i < numVertices; i++)
  {
    notInVertexSetListPtr->insert(i, i);
  }
  
  for (int v = 0; v < numVertices; v++)
  {
    weightArray[v] = adjacencyMatrix[0][v];
  }
  
  for (int v = 0; v < numVertices; v++)
  { 
    int currentSmallest = 10000;
    if (weightArray[v] < currentSmallest && !isInVertexSet(v))
    {
      currentSmallest = weightArray[v];
      vertexSetListPtr->insert(((vertexSetListPtr->getLength())+1), v);
      removeFromList(v, notInVertexSetListPtr);
    }
    for (int i = 1; i <= notInVertexSetListPtr->getLength(); i++)
    { 
      int u = (notInVertexSetListPtr->getEntry(i));
      if (weightArray[u] > weightArray[v] + adjacencyMatrix[v][u])
      {
        weightArray[u] = weightArray[v] + adjacencyMatrix[v][u];
      }
    }
  }
  printCheapestPath();
}  

void AirlinesGraph::printVertexSet(string name, ListInterface<int>* listPtr)
{  
  cout << name << ": ";
  for (int i = 1; i <= listPtr->getLength(); i++)
  {
    cout << listPtr->getEntry(i) << ", ";
  }
  cout << endl;
}   

void AirlinesGraph::printWeightArray()
{
  cout << "Weight Array: ";
  for (int i = 0; i < SIZE; i++)
  {
    cout << "w[" << i << "]:" << weightArray[i] << " ";
  }
  cout << endl;
}  

bool AirlinesGraph::isInVertexSet(int vertex)
{
  for (int i = 1; i <= vertexSetListPtr->getLength(); i++)
  {
    if (vertexSetListPtr->getEntry(i) == vertex) 
    {
      return true;
    }
  }
  return false;
}

void AirlinesGraph::removeFromList(int vertex, ListInterface<int>* listPtr)
{
  for (int i = 1; i <= listPtr->getLength(); i++)
  {
    if (listPtr->getEntry(i) == vertex)
    {
      listPtr->remove(i);
    }
  }
}

void AirlinesGraph::printCheapestPath()
{  
  for (int i = 1; i < SIZE; i++)
  {  
    cout << "The cheapest route from SFO to " << airportNames[i] << " is:$" << weightArray[i] << endl;
  }
}
 




