// Copyright 2017 Kozlov Ilya

#include <gtest/gtest.h>
#include "include/Graph.h"
#include <algorithm>
#include <vector>
#include <utility>

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
  std::vector<int> correct_answer = { 11, 0, 7, 9, 20, 20 };

  // Act
  vector<int> tmp = gr.Dijkstra(1);

  // Assert
  for (int i = 0; i < 6; i++) {
      EXPECT_EQ(correct_answer[i], tmp[i]);
  }
}

TEST(Kozlov_dijkstra_tests, Diykstra_Result_With_Unrelated_Graph) {
    // Arrange
    Graph gr(2);
    std::vector<int> correct_answer = { 0, gr.INF };

    // Act
    std::vector<int> tmp = gr.Dijkstra(0);

    // Assert
    for (int i = 0; i < 6; i++) {
        EXPECT_EQ(correct_answer[i], tmp[i]);
    }
}
