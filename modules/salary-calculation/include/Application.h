// Copyright 2017 Kiselev Ivan

#ifndef MODULES_SALARY_CALCULATION_INCLUDE_APPLICATION_H_
#define MODULES_SALARY_CALCULATION_INCLUDE_APPLICATION_H_


#include "salary_caculationl.h"
#include <string>

class Application {
 public:
    Application();
    std::string Application::operator()(int argv, const char** argc);
};

#endif // !MODULES_SALARY_CALCULATION_INCLUDE_APPLICATION_H_
