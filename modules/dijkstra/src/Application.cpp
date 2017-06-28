// Copyright 2017 Kozlov Ilya

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#include "include/Application.h"
#include "include/Graph.h"

using std::vector;

Application::Application() {}

void Application::Help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is an optimal way calculator application.\n\n" +
        "Pleaseprovide arguments in the following format:\n\n" +

        "  $ " + appname + "<size> <start_node_index> <edge1> <edge2> ... <edgeN>\n" +
        "WHERE <edgeN> = <weightN> <nodeIndexA> <nodeIndexB>\n\n" +

        "ATTENTION:\n"
        "\n*All arguments should be unsingned integer values!" +
        "\n*The max value of any argument is " + std::to_string(INF) + "!" +
        "\n*If there is no edge between nodes, the result of optimal way" +
        "between them will be 'inf'" +
        "\n*The number of arguments should be > 2 and 2 + n, where the 'n' is a multiple of 3!" +
        "\n*Carefully observe the format where typing the edges!";
};
int Application::ParseInt(const char* arg) {
    try {
        return std::stoi(arg);
    }
    catch (std::string& str) {
        throw str;
    }
}
vector<vector<unsigned int>> Application::ParseGraph(const int argc, const char** argv) {
    const int gr_size = argc - 3;
    vector<vector<unsigned int>> res (gr_size);
    for (int i = 0; i < res.size(); i++) {
        res[i].resize(3);
    }
    for (int i = 3; i < gr_size; i++) {
        if (i % 3 == 0) {
            res[i][0] = ParseInt(argv[i]);
            res[i][1] = ParseInt(argv[i + 1]);
            res[i][2] = ParseInt(argv[i + 2]);
        }
    }
    return res;
}
bool Application::ValidateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    }

    if (argc >= 3 && (argc - 3) % 3 == 0) {
        return true;
    }

    Help(argv[0], "ERROR: Incorrect arguments num.\n\n");
    return false;
}

std::string Application::operator()(int argc, const char** argv) {
    Arguments args;
    vector<unsigned int> res;
    std::ostringstream stream;


    if (!ValidateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.start_node_ = ParseInt(argv[2]);
        args.gm_ = ParseGraph(argc, argv);
    }
    catch (std::string& str) {
        return str;
    }
    Graph gr(args.gm_.size());
    for (int i = 0; i < args.gm_.size(); i++) {
        gr.AddEdge(args.gm_[i][0], args.gm_[i][1], args.gm_[i][2]);
    }
    res = gr.Dijkstra(args.start_node_);
    for (int i = 0; i < res.size(); i++) {
        if (res[i] == INF) {
            stream << "inf ";
        }
        if (res[i] != INF) {
            stream << res[i] << " ";
        }
        message_ += stream.str();
    }
    message_.pop_back();
    return message_;
}

