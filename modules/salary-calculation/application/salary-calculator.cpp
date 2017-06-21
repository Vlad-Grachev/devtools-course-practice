// Copyright 2017 Kiselev Ivan

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "../include/Application.h"

int main(int argv, char ** argc) {
    Application app;
    int output = app(argv, argc);
    printf("%i\n", output);
    return 0;
}
