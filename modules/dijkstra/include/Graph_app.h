// Copyright 2017 Kozlov Ilya

#ifndef  MODULES_DIJKSTRA_INCLUDE_GRAPH_APP_H_
#define MODULES_DIJKSTRA_INCLUDE_GRAPH_APP_H_

#include <iostream>
#include "include/Graph.h"

class GraphApp {
 public:
     GraphApp();
     ~GraphApp();
     void Work();
 protected:
     Graph* graph_;
     void ShowDijkstraBetween(unsigned int _way_from);
     void ShowInfo(unsigned int _graph_size);
     void ShowGraph();
     void AddConnections();
     void MakeNewGraph();
     void ShowOptimalWays();
     void SetGraph();
};
#endif  // MODULES_DIJKSTRA_INCLUDE_GRAPH_APP_H_
