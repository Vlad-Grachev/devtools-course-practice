// Copyright 2017 Kiselev Ivan

#include <string>
#include "../salary-calculation/include/application.h"

Application::Application() {}

std::string Application::operator()(int argv, const char** argc) {
    return "Comleted";
}
