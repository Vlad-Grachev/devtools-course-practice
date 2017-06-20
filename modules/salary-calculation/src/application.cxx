// Copyright 2017 Kiselev Ivan

#include <string>
#include <iostream>
#include "../include/Application.h"

Application::Application(int salary_per_hour, int needed_hours,
    int work_hours, int workday, int overtime_bonus) {
    worker_salary_ = new Salary(salary_per_hour,needed_hours,work_hours,
        workday);
    worker_salary_->SetOvertimeBonus(overtime_bonus);
    worker_salary_->CalculateSalary();
}

int Application::operator()(int argv, int args) {
    if (argv == 0) {
        PrintHelp();
        return 0;
    }
    switch (argv) {
        case 1: {
            worker_salary_->SetSalaryPerHour(args);
            break;
        }
        case 2 : {
            worker_salary_->SetWorkHours(args);
            break;
        }
        case 3 : {
            worker_salary_->SetOvertimeBonus(args);
            break;
        }
        case 4 : {
            worker_salary_->SetAdminRest(args);
            break;
        }
        case 5 : {
            worker_salary_->SetNeededHours(args);
            break;
        }
        case 6 : {
            worker_salary_->SetWorkHours(args);
            break;
        }
        case 7 : {
            worker_salary_->CalculateSalary();
            return worker_salary_->GetSalary();
            break;
        }
        default: {
            PrintHelp();
            break;
        }
    }
    worker_salary_->CalculateSalary();
    return worker_salary_->GetSalary();
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
