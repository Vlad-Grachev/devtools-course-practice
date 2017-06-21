// Copyright 2017 Kozlov Ilya

#include "include/Application.h"
#include "include/Graph.h"

Application::Application() {}

int Application::parseOperation(const char* arg) {
    int op = 0;
    if (strcmp(arg, "set_new_graph") == 0) {
        op = 1;
    }
    else if (strcmp(arg, "set_new_edge") == 0) {
        op = 2;
    }
    else if (strcmp(arg, "optimals_ways_from") == 0) {
        op = 3;
    }
    else if (strcmp(arg, "show_graph") == 0) {
        op = 4;
    }
    else {
        throw std::string("Wrong operation name!");
    }
    return op;
}

void Application::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a optimal way calculator application.\n\n" +
        "Please choose an operation and provide arguments " +
        "in the following format:\n\n" +

        "  $ " + appname + "<operation> <argument1> <argument2> <argument3>\n\n" +

        "Operations and those argunents:\n\n" +
        "set_new_graph <nodes_number> -  sets new graph with selected number of nodes (must be done first!)\n" +
        "set_new_edge <node_from> <node_to> <weight> - sets new edge between selected nodes with selected weight\n" +
        "optimals_ways_from <node_from> - shows optimal way weights from selected node to other ones\n\n" +
        "show_graph - shows nodes and edges of the graph" +

        "Hints:\n" +
        "All arguments must be unsigned integers!\n" +
        "set_new_graph <nodes_number> must be done first!" +
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
            (parseOperation(argv[1]) == 1 && argc != 1) ||
            (parseOperation(argv[1]) == 2 && argc != 3) ||
            (parseOperation(argv[1]) == 3 && argc != 1) ||
            (parseOperation(argv[1]) == 4 && argc != 0))
    {
        help(argv[0], "ERROR: Incorrect arguments num.\n\n");
        return false;
    }
    return true; 
}

std::string operator()(int argc, const char** argv);
