// Copyright 2017 Kiselev Ivan

#include <gtest/gtest.h>
#include "../include/Application.h"

TEST(Application, first_simple_test) {
    EXPECT_TRUE(true);
}

TEST(Application, Open_File) {
    Salary* sal = new Salary();

    sal->CalculateSalary();

    EXPECT_EQ(sal->GetSalary() , 3200);
}

TEST(Application, Constructor_copir) {
    Application app1;
    EXPECT_NO_FATAL_FAILURE(Application app2(app1));
}

TEST(Application, Operator_0) {
    Application app;
    char** chr = nullptr;
    EXPECT_NO_FATAL_FAILURE(app(0, chr));
}

TEST(Application, Operator_1) {
    Application app;
    char** chr = nullptr;
    EXPECT_EQ(app(1, chr),1);
}

TEST(Application, Operator_2) {
    Application app;
    char** chr = nullptr;
    EXPECT_EQ(app(2, chr),2);
}

TEST(Application, Operator_3) {
    Application app;
    char** chr = nullptr;
    EXPECT_EQ(app(3, chr),3);
}

TEST(Application, Operator_4) {
    Application app;
    char** chr = nullptr;
    EXPECT_EQ(app(4, chr),4);
}

TEST(Application, Operator_5) {
    Application app;
    char** chr = nullptr;
    EXPECT_EQ(app(5, chr),5);
}

TEST(Application, Operator_6) {
    Application app;
    char** chr = nullptr;
    EXPECT_EQ(app(6, chr),6);
}

TEST(Application, Operator_7) {
    Application app;
    char** chr = nullptr;
    Salary sal;
    sal.CalculateSalary();
    EXPECT_EQ(app(7, chr), sal.GetSalary());
}

TEST(Application, Operator_8) {
    Application app;
    char** chr = nullptr;
    EXPECT_NO_FATAL_FAILURE(app(8, chr));
}
