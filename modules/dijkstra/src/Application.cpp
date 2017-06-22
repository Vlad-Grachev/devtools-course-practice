// Copyright 2017 Kozlov Ilya

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>
#include "include/Application.h"
#include "include/Graph.h"

Application::Application() {}

int Application::parseOperation(const char* arg) {
    int op = 0;
    if (strcmp(arg, "add_nodes") == 0) {
        op = 1;
    }
    else if (strcmp(arg, "set_new_edge") == 0) {
        op = 2;
    }
    else if (strcmp(arg, "optimal_weights_from") == 0) {
        op = 3;
    }
    else if (strcmp(arg, "new_graph") == 0) {
        op = 4;
    }
    else {
        throw std::string("Wrong operation name!");
    }
    return op;
}

void Application::help(const char* appname, const char* message)  {
    message_ =
        std::string(message) +
        "This is a optimal way calculator application.\n\n" +
        "Please choose an operation and provide arguments " +
        "in the following format:\n\n" +

        "  $ " + appname + "<operation> <argument1> <argument2> <argument3>\n\n" +

        "Operations and those argunents:\n\n" +
        "add_nodes <nodes_number> -  adds a value of nodes\n" +
        "set_new_edge <weight> <node_from> <node_to> - sets new edge between selected nodes with selected weight\n" +
        "optimals_ways_from <node_from> - shows optimal way weights from selected node to other ones\n\n" +
        "new_graph <nodes_number> - creates a new graph with selected nodes (old is being deleted)" +

        "Hints:\n" +
        "All arguments must be unsigned integers!\n" +
        "You're to set a graph by adding some nodes and edges or creating new at first!" +
        "If nodes has no edges between the result of optimal_ways_from wil be 'inf'!\n\n";

}

int Application::parseInt(const char* arg) {
    int value = atoi(arg);

    if (value < 0) {
        throw std::string("Wrong number format!");
    }
    return value;
}

bool Application::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    else if (argc > 4 ||
            (parseOperation(argv[1]) == 1 && argc != 2) ||
            (parseOperation(argv[1]) == 2 && argc != 4) ||
            (parseOperation(argv[1]) == 3 && argc != 2) ||
            (parseOperation(argv[1]) == 4 && argc != 1))
    {
        help(argv[0], "ERROR: Incorrect arguments num.\n\n");
        return false;
    }
    return true; 
}

std::string Application::operator()(int argc, const char** argv) {
    Arguments args;
    int* res = nullptr;
    Graph* graph = new Graph;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
            args.operation = parseOperation(argv[1]);
            args.arg1 = parseOperation(argv[2]);
        if (args.operation == 2) {
            args.arg2 = parseOperation(argv[3]);
            args.arg3 = parseOperation(argv[4]);
        }
    }
    catch (std::string& str) {
        return str;
    }

    std::ostringstream stream;
    switch (args.operation) {
    case 1:
        graph[0].AddNodes(args.arg1);
        break;
    case 2:
        graph[0].AddEdge(args.arg1, args.arg2, args.arg3);
        break;
    case 3:
        res = graph[0].Dijkstra(args.arg1);
        for (int i = 0; i < graph[0].GetSize(); i++) {
            if (res[i] != INT_MAX) {
                stream << "\n" << args.arg1 << "-->" << i << "=" << res[i];
            }
            else if (res[i] == INT_MAX) {
                stream << "\n" << args.arg1 << "-->" << i << "= inf";
            }
        }
        break;
    case 4:
        delete[] graph;
        graph = new Graph(args.arg1);
    }

    message_ = stream.str();
    delete[] graph;
    return message_;
}
