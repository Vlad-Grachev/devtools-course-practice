// Copyright 2017 Kiselev Ivan

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "../include/Application.h"

int main(int argc, int args) {
    Application app;
    int output = app(argc, args);
    printf("%i\n", output);
    return 0;
}
