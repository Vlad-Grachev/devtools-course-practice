// Copyright 2017 Kalinin Vladimir
#include <gtest/gtest.h>

#include "include/Graph.h"


TEST(Kalinin_dijkstra_tests, Can_Create_Edge) {
  // Arrange
  Edge a1;
  Edge a2(1, 2);

  // Act

  // Assert
  EXPECT_EQ(a2.GetWeight(), 1);
  EXPECT_EQ(a2.GetKey(), 2);
  EXPECT_EQ(a1.GetWeight(), 0);
  EXPECT_EQ(a1.GetKey(), 0);
}

TEST(Kalinin_dijkstra_tests, Can_Set_Next) {
  // Arrange
  Edge a1;
  Edge a2;
  // Act
  a1.SetNext(&a2);

  // Assert
  EXPECT_EQ(a1.GetNext(), &a2);
}

TEST(Kalinin_dijkstra_tests, Can_Create_Graph) {
  // Arrange

  // Act
  Graph gr1;
  Graph gr2(5);

  // Assert
  EXPECT_EQ(gr1.GetSize(), 0);
  EXPECT_EQ(gr2.GetSize(), 5);
}

TEST(Kalinin_dijkstra_tests, IsConnect_Works) {
  // Arrange
  Graph gr(6);

  // Act
  gr.AddEdge(9, 1, 3);

  // Assert
  EXPECT_EQ(gr.IsConnect(1, 3), true);
  EXPECT_EQ(gr.IsConnect(3, 1), true);
  EXPECT_EQ(gr.IsConnect(1, 2), false);
}

TEST(Kalinin_dijkstra_tests, Can_Set_Edge_Weight) {
  // Arrange
  Graph gr(6);

  // Act
  gr.AddEdge(9, 1, 3);

  // Assert
  EXPECT_EQ(gr.GetNode(1)->GetWeight(), 9);
  EXPECT_EQ(gr.GetNode(3)->GetWeight(), 9);
}

TEST(Kalinin_dijkstra_tests, Diykstra_Result_Is_Correct) {
  // Arrange
  Graph gr(6);
  gr.AddEdge(7, 1, 2);
  gr.AddEdge(10, 2, 3);
  gr.AddEdge(9, 1, 3);
  gr.AddEdge(15, 2, 4);
  gr.AddEdge(11, 3, 4);
  gr.AddEdge(14, 1, 0);
  gr.AddEdge(2, 3, 0);
  gr.AddEdge(9, 5, 0);
  gr.AddEdge(6, 4, 5);
  int correct_answer[6] = { 11, 0, 7, 9, 20, 20 };

  // Act
  int* tmp = gr.Dijkstra(1);

  // Assert
  for (int i = 0; i < 6; i++) {
      EXPECT_EQ(correct_answer[i], tmp[i]);
  }
}

TEST(Kozlov_dijkstra_tests, ConnectioWith_is_working_correctly) {
    // Arrange
    int* result_to_test;
    int predicted_result[2] = { 2, 3 };
    int _weight = 10;
    Graph graph_to_test(3);

    // Act
    result_to_test = graph_to_test.ConnectedWith(1);

    // Assert
    for (int i = 0; i < 1; i++) {
        EXPECT_EQ(predicted_result[i], result_to_test[i]);
    }
}

TEST(Kozlov_dijkstra_tests, AddNode_is_working_correctly_1) {
    // Arrange
    int val = 10;
    Graph to_test;

    // Act
    to_test.AddNodes(val);

    // Assert
    EXPECT_EQ(val, to_test.GetSize());
}

TEST(Kozlov_dijkstra_tests, AddNode_is_working_correctly_2) {
    // Arrange
    Edge* tmp;
    int val = 10;
    Graph to_test;

    // Act
    to_test.AddNodes(val);

    // Assert
    for (int i = 0; i < to_test.GetSize; i++) {
        EXPECT_NO_FATAL_FAILURE(tmp = to_test.GetNode(i));
    }
}

TEST(Kozlov_dijkstra_tests, AddNode_is_working_correctly_3) {
    // Arrange
    int val = 0;
    Graph to_test;

    // Act
    to_test.AddNodes(val);

    // Assert
    EXPECT_EQ(0, to_test.GetSize());
}