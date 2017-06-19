// Copyright 2017 Korniakov Kirill

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

#include "../salary-calculation/include/salary_caculationl.h"
#include "../salary-calculation/include/Application.h"

int main(int argc, const char** argv) {
    Application app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
    return 0;
}
