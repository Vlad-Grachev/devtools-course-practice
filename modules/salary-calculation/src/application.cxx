// Copyright 2017 Kiselev Ivan

#include <string>
#include <iostream>
#include "../include/Application.h"

Application::Application() {
    worker_salary_ = new Salary();
    worker_salary_->CalculateSalary();
}

int Application::operator()(int argv, const char** argc) {
    if (argv == 0) {
        PrintHelp();
        return 0;
    }
}

void Application::PrintHelp() {
    std::cout << "1 - Set salary per hour\n";
    std::cout << "2 - Set work hours\n";
    std::cout << "3 - Set overtime bonus\n";
    std::cout << "4 - Set admin rest\n";
    std::cout << "5 - Set needed hours\n";
    std::cout << "6 - Set How many hours in workday\n";
}
