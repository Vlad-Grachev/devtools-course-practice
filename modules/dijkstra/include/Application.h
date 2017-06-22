// Copyright 2017 Kozlov Ilya

#ifndef MODULES_DIJKSTRA_INCLUDE_APPLICATION_H_
#define MODULES_DIJKSTRA_INCLUDE_APPLICATION_H_

#include <string>
#include "include/Graph.h"


class Application {
 public:
    ~Application();
    Application();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    int parseInt(const char* arg);
    bool validateNumberOfArguments(int argc, const char** argv);
    int parseOperation(const char* arg);
    std::string message_;
    Graph* graph;
    typedef struct {
        int operation, arg1, arg2, arg3;
    } Arguments;
};
#endif  // #ifndef MODULES_DIJKSTRA_INCLUDE_APPLICATION_H_

