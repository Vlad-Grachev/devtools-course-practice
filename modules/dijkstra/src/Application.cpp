// Copyright 2017 Kozlov Ilya

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>
#include "include/Application.h"
#include "include/Graph.h"

Application::Application() {}

void Application::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is an optimal way calculator application.\n\n" +
        "Pleaseprovide arguments in the following format:\n\n" +

        "  $ " + appname + "<size> <start_node_index> <edge1> <edge2> ... <edgeN>\n" +
        "WHERE <edgeN> = <weightN> <nodeIndexA> <nodeIndexB>\n\n" +

        "ATTENTION:\n"
        "\n*All arguments should be unsingned integer values!" +
        "\n*The number of arguments should be > 2 and 2 + n, where the 'n' is a multiple of 3!" +
        "\n*Carefully observe the format where typing the edges!";
};

int Application::parseInt(const char* arg) {
    return std::stoi(arg);
}

bool Application::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    else if (argc >= 3)
    {
        if (argc > 3 && (argc - 3) % 3 != 0) {
            help(argv[0], "ERROR: Incorrect arguments num.\n\n");
            return false;
        }
        return true;
    }
    else if (argc < 3) {
        help(argv[0], "ERROR: Incorrect arguments num.\n\n");
        return false;
    }
}

std::string Application::operator()(int argc, const char** argv) {
    int k = 0;
    int* dijkstra;
    Connection* cnn;
    Arguments args;
    std::ostringstream stream;


    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.size_ = parseInt(argv[1]);
        args.start_node_ = parseInt(argv[2]);
        args.connected_nodes_ = (argc - 3) / 3;
        cnn = new Connection[args.connected_nodes_];
        for (int i = 3; i + 3 <= argc - 3; i += 3) {
            cnn[k].weight_ = parseInt(argv[i]);
            cnn[k].start_= parseInt(argv[i+1]);
            cnn[k].end_= parseInt(argv[i+2]);
            k++;
        }
    }
        catch (std::string& str) {
            return str;
    }
    Graph graph(args.size_);
    for (int i = 0; i < args.connected_nodes_; i++) {
        graph.AddEdge(cnn[i].weight_, cnn[i].start_, cnn[i].weight_);
    }
    dijkstra = graph.Dijkstra(args.start_node_);
    for (int i = 0; i < args.size_; i++) {
        if (i != args.start_node_) {
            if (dijkstra[i] != INT_MAX) {
                stream << args.start_node_ << " --> " << i;
                stream << " = " << dijkstra[i] << "\n";
            }
            else if (dijkstra[i] == INT_MAX) {
                stream << args.start_node_ << " --> " << i;
                stream << " = " << "inf" << "\n";
            }
        }
    }

    delete[] cnn;
    message_ = stream.str();
    return message_;
}

