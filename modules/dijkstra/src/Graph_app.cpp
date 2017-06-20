// Copyright 2017 Kozlov Ilya

#include <iostream>
#include <cstdlib>
#include "include/Graph_app.h"

void GraphApp::SetGraph() {
    ShowInfo(0);
    unsigned int _graph_size;
    std::cout << "Enter your graph's size: ";
    std::cin >> _graph_size;
    Graph _graph(_graph_size);
    system("cls");
    ShowInfo(_graph.GetSize());
    ShowGraph();
    AddConnections();
    system("cls");
    ShowInfo(_graph.GetSize());
    ShowDijkstraResult();
}
    
void GraphApp::FormConnections() {
    unsigned int _connection_from;
    unsigned int _connection_to;
    unsigned int _weight;
    bool _solution = 1;

    while (_solution != 0) {
        std::cout << "Do you want to set a new edge?\n\t 1 - yes\t0-no\n";
        std::cin >> _solution;
        if (_solution == 1) {
            system("cls");
            ShowInfo(_graph.GetSize());
            std::cout << "Do you want to set a new edge?\n\t 1 - yes\t0-no\n";
            std::cout << "From: ";
            std::cin >> _connection_from;
            if (_connection_from > _graph.GetSize()) {
                throw "The value is incorrect!";
            }
            std::cout << "\nTo: ";
            std::cin >> _connection_to;
            if (_connection_to > _graph.GetSize() || _connection_to == _connection_from) {
                throw "The value is incorrect!";
            }
            std::cout << "\nWeight: ";
            std::cin >> _weight;
            _graph.AddEdge(_weight, _connection_from, _connection_to);
        }
        system("cls");
        ShowInfo(_graph.GetSize());
        ShowGraph();
    }
}
