// Copyright 2017 Bilkovsky Alexander

#include "../include/salary_calculation.h"

Salary::Salary(int salary_per_hour, int needed_hours,
               int work_hours, int workday) {
    if (salary_per_hour < 0 || needed_hours < 0 ||
        work_hours < 0 || workday <= 0)
        throw("Incorrect data");
    salary_ = 0;
    penalty_ = 0;
    salary_per_hour_ = salary_per_hour;
    needed_hours_ = needed_hours;
    work_hours_ = work_hours;
    overtime_bonus_ = 0;
    admin_rest_ = 0;
    workday_ = workday;
}
void Salary::SetAdminRest(int val) {
    if (val < 0)
        throw("Incorrect data");
    admin_rest_ = val;
}
void Salary::SetOvertimeBonus(int val) {
    if (val < 0)
        throw("Incorrect data");
    overtime_bonus_ = val;
}
void Salary::SetWorkHours(int val) {
    if (val < 0)
        throw("Incorrect data");
    work_hours_ = val;
}
void Salary::SetSalaryPerHour(int val) {
    if (val < 0)
        throw("Incorrect data");
    salary_per_hour_ = val;
}
void Salary::SetNeededHours(int val) {
    if (val < 0)
        throw("Incorrect data");
    needed_hours_ = val;
}
void Salary::SetWorkDay(int val) {
    if (val < 0)
        throw("Incorrect data");
    workday_ = val;
}
void Salary::SetPenalty(int val) {
    if (val < 0)
        throw("Incorrect data");
    penalty_ = val;
}
void Salary::CalculateSalary() {
    salary_ = 0;
    if (work_hours_ < needed_hours_) {
        salary_ = work_hours_ * salary_per_hour_;
        if (!admin_rest_)
            salary_ -= (needed_hours_ - work_hours_) * penalty_;
        else
            if (work_hours_ < needed_hours_ - admin_rest_ * workday_)
                salary_ -= (needed_hours_ - work_hours_
                            - admin_rest_ * workday_) * penalty_;
    } else {
        salary_ += needed_hours_ * salary_per_hour_ +
            (work_hours_ - needed_hours_) * overtime_bonus_;
    }
}

int Salary::GetSalary() {
    return salary_;
}

int Salary::GetAdminRest() {
    return admin_rest_;
}

int Salary::GetOvertimeBonus() {
    return overtime_bonus_;
}

int Salary::GetSalaryPerHour() {
    return salary_per_hour_;
}

int Salary::GetNeededHours() {
    return needed_hours_;
}

int Salary::GetWorkHours() {
    return work_hours_;
}

int Salary::GetWorkDay() {
    return workday_;
}

int Salary::GetPenalty() {
    return penalty_;
}
