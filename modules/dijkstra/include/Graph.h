// Copyright 2017 Kalinin Vladimir & Kozlov Ilya

#ifndef MODULES_DIJKSTRA_INCLUDE_GRAPH_H_
#define MODULES_DIJKSTRA_INCLUDE_GRAPH_H_

#include <algorithm>
#include <vector>
#include <utility>

using std::pair;
using std::vector;

class Graph
{
public:
    Graph();
    explicit Graph(const size_t _size);
    void AddEdge(const unsigned int _weight, const size_t _node_A, const size_t _node_B);
    vector<int> GetOptimalWayFrom(size_t _start_n);
    bool IsConnect(const size_t _node_A, const size_t _node_B);
    const int INF = 1000000000;
protected:
    class Edge:public pair<int, int> {
     public:
         int weight = first;
         int connection = second;
    };
    vector< vector<Edge>> graph_;
    size_t size_;
};

#endif  // MODULES_DIJKSTRA_INCLUDE_GRAPH_H_
