// Copyright 2017 Kiselev Ivan

#include <string>
#include <iostream>
#include "../include/Application.h"

Application::Application() {
    worker_salary_ = new Salary();
    worker_salary_->CalculateSalary();
}

int Application::operator()(int argv, int args) {
    if (argv == 0) {
        PrintHelp();
        return 0;
    }
    switch (argv) {
        case 1: {

            break;
        }
        case 2 : {

            break;
        }
        case 3 : {

            break;
        }
        case 4 : {

            break;
        }
        case 5 : {

            break;
        }
        case 6 : {

            break;
        }
        case 7 : {

            break;
        }
    default:
        break;
    }
}

void Application::PrintHelp() {
    std::cout << "1 - Set salary per hour , Value \n";
    std::cout << "2 - Set work hours , Value \n";
    std::cout << "3 - Set overtime bonus , Value \n";
    std::cout << "4 - Set admin rest , Value \n";
    std::cout << "5 - Set needed hours\n";
    std::cout << "6 - Set How many hours in workday , Value \n";
    std::cout << "7 - Get Salary\n";
}
