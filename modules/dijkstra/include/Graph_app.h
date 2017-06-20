// Copyright 2017 Kozlov Ilya

#ifndef  MODULES_DIJKSTRA_INCLUDE_GRAPH_APP_H_
#define MODULES_DIJKSTRA_INCLUDE_GRAPH_APP_H_

#include <iostream>
#include "include/Graph.h"

class GraphApp {
 public:
     void ShowResults();
     void SetGraph();
 protected:
     void ShowInfo(int _graph_size);
};
#endif  // MODULES_DIJKSTRA_INCLUDE_GRAPH_APP_H_
