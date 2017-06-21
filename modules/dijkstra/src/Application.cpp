// Copyright 2017 Kozlov Ilya

#include "include\Application.h"
#include "include\Graph.h"

Application::Application() {}

int parseOperation(const char* arg) {
}

void Application::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a optimal way calculator application.\n\n" +
        "Please choose an operation and provide arguments " +
        "in the following format:\n\n" +

        "  $ " + appname + "<argument1> <argument2> <argument3>\n\n" +

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
