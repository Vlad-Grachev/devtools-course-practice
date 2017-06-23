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

TEST(Application, Operator) {
    Application app;
    char** chr = new char*[2];
    chr[0] = new char[1];
    chr[0][0] = '7';
    chr[1] = new char[1];
    chr[1][0] = '1';
    Salary sal;
    sal.CalculateSalary();
    EXPECT_EQ(app(4, chr), 3200);
}

TEST(Application, Char_To_Int_1) {
    char a[3] = { '1', '2', '3' };
    Application app;
    EXPECT_EQ(app.ToInt(a), 123);
}

TEST(Application, Char_To_Int_2) {
    char a[1] = { '1' };
    Application app;
    EXPECT_EQ(app.ToInt(a), 1);
}

TEST(Application, Hard_Test) {
    char** arr = new char*[14];
    Application app;
    for (int i = 0; i <= 12; i += 2) {
        arr[i] = new char[1];
        arr[i][0] = '0' + i / 2 + 1;
    }
    arr[1] = new char[2];
    arr[1][0] = '5';
    arr[1][1] = '0';
    arr[3] = new char[2];
    arr[3][0] = '3';
    arr[3][1] = '0';
    arr[5] = new char[2];
    arr[5][0] = '6';
    arr[5][1] = '0';
    arr[7] = new char[1];
    arr[7][0] = '0';
    arr[9] = new char[2];
    arr[9][0] = '2';
    arr[9][1] = '0';
    arr[11] = new char[1];
    arr[11][0] = '8';
    arr[13] = new char[1];
    arr[13][0] = '0';
    int res = app(15, arr);
    EXPECT_EQ(res, 1600);
}
