// Copyright 2017 Kiselev Ivan

#include <string>
#include "../include/Application.h"

Application::Application() {
    worker_salary_ = new Salary();
    worker_salary_->CalculateSalary();
}

int Application::operator()(int argv, const char** argc) {
    return argv;    
}
