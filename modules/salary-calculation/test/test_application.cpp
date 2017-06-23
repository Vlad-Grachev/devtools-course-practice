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

/*TEST(Application, Operator_0) {
    Application app;
    char** chr = nullptr;
    EXPECT_NO_FATAL_FAILURE(app(0, chr));
}

TEST(Application, Operator_1) {
    Application app;
    char** chr = new char*[1];
    chr[0] = new char[2];
    chr[0][0] = '1';
    chr[0][1] = '0';
    EXPECT_EQ(app(1, chr), 0);
}

TEST(Application, Operator_2) {
    Application app;
    char** chr = new char*[1];
    chr[0] = new char[2];
    chr[0][0] = '1';
    chr[0][1] = '0';
    EXPECT_EQ(app(2, chr), 0);
}

TEST(Application, Operator_3) {
    Application app;
    char** chr = new char*[1];
    chr[0] = new char[2];
    chr[0][0] = '1';
    chr[0][1] = '0';
    EXPECT_EQ(app(3, chr), 0);
}

TEST(Application, Operator_4) {
    Application app;
    char** chr = new char*[1];
    chr[0] = new char[2];
    chr[0][0] = '1';
    chr[0][1] = '0';
    EXPECT_EQ(app(4, chr), 0);
}

TEST(Application, Operator_5) {
    Application app;
    char** chr = new char*[1];
    chr[0] = new char[2];
    chr[0][0] = '1';
    chr[0][1] = '0';
    EXPECT_EQ(app(5, chr), 0);
}

TEST(Application, Operator_6) {
    Application app;
    char** chr = new char*[1];
    chr[0] = new char[2];
    chr[0][0] = '1';
    chr[0][1] = '0';
    EXPECT_EQ(app(6, chr), 0);
}

TEST(Application, Operator_7) {
    Application app;
    char** chr = new char*[1];
    chr[0] = new char[1];
    chr[0][0] = '1';
    Salary sal;
    sal.CalculateSalary();
    EXPECT_EQ(app(7, chr), sal.GetSalary());
}

TEST(Application, Operator_8) {
    Application app;
    char** chr = nullptr;
    EXPECT_NO_FATAL_FAILURE(app(8, chr));
}*/

TEST(Application, Char_To_Int_1) {
    char a[3] = { '1', '2', '3' };
    Application app;
    EXPECT_EQ(app.ToInt(a), 123);
}

TEST(Application, Char_To_Int_2) {
    char a[3] = { '1' };
    Application app;
    EXPECT_EQ(app.ToInt(a), 1);
}

/*TEST(Application, Arr_Char_To_Int_Arr) {
    char** arr = new char*[2];
    arr[0] = new char[1];
    arr[1] = new char[2];
    arr[0][0] = '2';
    arr[1][0] = '2';
    arr[1][1] = '0';
    Application app;
    app.ToIntArray(arr);
    EXPECT_EQ(app.GetArray()[0], 2);
    EXPECT_EQ(app.GetArray()[1], 20);
}*/
