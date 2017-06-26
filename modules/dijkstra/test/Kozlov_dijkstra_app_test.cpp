// Copyright 2017 Kozlov Ilya

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include\Application.h"


using ::testing::internal::RE;
using std::vector;
using std::string;

class OptimalWayCalculatorAppTest : public ::testing::Test {
protected:
    void Act(vector<string> args_) {
        vector<const char*> options;
        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }
        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;
        output_ = app_(argc, argv);
    }
    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }
private:
    Application app_;
    string output_;
};

TEST_F(OptimalWayCalculatorAppTest, Do_Print_Help_Without_Arguments) {
    // Arrange
    vector<string> args = {};
    // Act
    Act(args);
    // Assert
    Assert("This is a optimal way calculator application*");
}

TEST_F(OptimalWayCalculatorAppTest, Is_Checking_Number_Of_Arguments1) {
    // Arrange
    const string test_val = "10";
    vector<string> args = { test_val };
    // Act
    Act(args);
    // Assert
    Assert("ERROR: Incorrect arguments num.*");
}

TEST_F(OptimalWayCalculatorAppTest, Is_Checking_Number_Of_Arguments2) {
    // Arrange
    const string test_val = "10";
    vector<string> args = { test_val,test_val, test_val };
    // Act
    Act(args);
    // Assert
    Assert("ERROR: Incorrect arguments num.*");
}

TEST_F(OptimalWayCalculatorAppTest, Can_Detect_Wrong_Number_Format) {
    // Arrange
    const string test_val = "ten";
    vector<string> args = { test_val,test_val };
    // Act
    Act(args);
    // Assert
    Assert("Wrong number format!*");
}

TEST_F(OptimalWayCalculatorAppTest, Can_Calculate_Correct) {
    // Arrange
    vector<string> args = { "6", "1",
                            "7", "1", "2",
                            "10", "2", "3",
                            "9", "1", "3",
                            "15", "2", "4",
                            "11", "3", "4",
                            "14", "1", "0",
                            "2", "3", "0",
                            "9", "5", "0",
                            "6", "4", "5" };
    const string expected_answer = std::string(expected_answer) + "1 --> 0 = 11\n" +
        "1 --> 2 = 7\n" + "1 --> 3 = 9\n" + "1 --> 4 = 20\n" + "1 --> 5 = 20\n";
    // Act
    Act(args);
    // Assert
    Assert(expected_answer);
}

TEST_F(OptimalWayCalculatorAppTest, Can_Calculate_With_Unrelated_Graph) {
    // Arrange
    const string test_val_size = "2";
    const string test_val_start = "0";
    vector<string> args = { test_val_size, test_val_start };
    // Act
    Act(args);
    // Assert
    Assert("0 --> 1 = inf\n");
}

