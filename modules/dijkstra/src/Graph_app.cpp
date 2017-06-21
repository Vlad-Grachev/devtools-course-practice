// Copyright 2017 Kozlov Ilya

#include <iostream>
#include <cstdlib>
#include "include/Graph_app.h"

void GraphApp::Work() {
    system("cls");
    ShowInfo(0);
    SetGraph();
    ShowGraph(); // Здесь и будет реализовано все
    AddConnections();
    ShowOptimalWays();
    MakeNewGraph();
}
    
void GraphApp::AddConnections() {
    unsigned int _connection_from;
    unsigned int _connection_to;
    unsigned int _weight;
    bool _solution = 1;

    while (_solution != 0) {
        std::cout << "Do you want to set a new edge?\n\t 1 - yes\t0-no\n";
        std::cin >> _solution;
        if (_solution == 1) {
            system("cls");
            ShowInfo(graph_[0].GetSize());
            std::cout << "Do you want to set a new edge?\n\t 1 - yes\t0-no\n";
            std::cout << "From: ";
            std::cin >> _connection_from;
            if (_connection_from > graph_[0].GetSize()) {
                throw "The value is incorrect!";
            }
            std::cout << "\nTo: ";
            std::cin >> _connection_to;
            if (_connection_to > graph_[0].GetSize() || _connection_to == _connection_from) {
                throw "The value is incorrect!";
            }
            std::cout << "\nWeight: ";
            std::cin >> _weight;
            graph_[0].AddEdge(_weight, _connection_from, _connection_to);
        }
        system("cls");
        ShowInfo(graph_[0].GetSize());
        ShowGraph();
    }
    system("cls");
    ShowInfo(graph_[0].GetSize());
    ShowGraph();
}

void GraphApp::SetGraph() {
    unsigned int _graph_size;
    std::cout << "Enter your graph's size: ";
    std::cin >> _graph_size;
    graph_ = new Graph(_graph_size);
    system("cls");
    ShowInfo(graph_[0].GetSize());
}

GraphApp::~GraphApp() {
    delete graph_;
}

GraphApp::GraphApp() : graph_(nullptr) {}

void GraphApp::MakeNewGraph() {
    bool _solution;
    system("cls");
    ShowInfo(graph_[0].GetSize());
    ShowGraph();
    std::cout << "Do you want to set a new graph?\n\t 1 - yes\t0-no\n";
    std::cin >> _solution;
    if (_solution == 1) {
        delete graph_;
        Work();
    }
}

/*
void GraphApp::ShowOptimalWays() {
    unsigned int _way_from;
    bool _solution = 1;

    while (_solution != 0) {
        std::cout << "Do you want to see a new optimal ways weight?\n\t 1 - yes\t0-no\n";
        std::cin >> _solution;
        if (_solution == 1) {
            system("cls");
            ShowInfo(graph_[0].GetSize());
            std::cout << "From: ";
            std::cin >> _way_from;
            if (_way_from > graph_[0].GetSize()) {
                throw "The value is incorrect!";
            }
        }
        system("cls");
        ShowInfo(graph_[0].GetSize());
        ShowGraph();
        ShowDijkstraBetween(_way_from);
    }
}

void GraphApp::ShowDijkstraBetween(unsigned int _way_from) {
    int* _optimal_ways = graph_[0].Dijkstra(_way_from);
    for (int i = 0; i < graph_[0].GetSize() - 1; i++) {
        std::cout<<"\n"
    }
}
*/