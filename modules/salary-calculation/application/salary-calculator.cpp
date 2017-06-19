// Copyright 2017 Korniakov Kirill

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

#include "include/application.h"

int main(int argc, const char** argv) {
    Application app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
    return 0;
}
