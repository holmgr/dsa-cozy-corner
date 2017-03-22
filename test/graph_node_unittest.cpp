#include "graph_node.h"
#include "gtest/gtest.h"

/*
 This file will includ all the test for the GraphNode class.
*/

/*
 This test will check if neighbors can be added.
*/
TEST(GraphNodeTest, Add) {
  // Initialize a node with some children
  GraphNode<int> root1;
  GraphNode<int> neighbor1;
  GraphNode<int> neighbor2;
  root1.addNeighbor(&neighbor1);
  root1.addNeighbor(&neighbor2);

  EXPECT_EQ(root1.getNeighbors().size(), 2);
}

/*
This test will check if neighbors can be removed.
*/
TEST(GraphNodeTest, Remove) {
  // Initialize a node with some children
  GraphNode<int> root1;
  GraphNode<int> neighbor1;
  GraphNode<int> neighbor2;
  root1.addNeighbor(&neighbor1);
  root1.addNeighbor(&neighbor2);

  EXPECT_EQ(root1.getNeighbors().size(), 2);

  // Remove one neighbor and check it is removed
  root1.removeNeighbor(1);

  EXPECT_EQ(root1.getNeighbors().size(), 1);

  // Remove the last neighbor and check it the neighbors list is empty
  root1.removeNeighbor(0);

  EXPECT_EQ(root1.getNeighbors().size(), 0);

  // Check if removing when there is no neighbors will chrash
  EXPECT_NO_THROW(root1.removeNeighbor(0));
}

/*
This test will check if the value for each node can be set and extracted.
*/
TEST(GraphNodeTest, Value) {
  // Initialize a node with some children
  GraphNode<int> root1;
  root1.setValue(1);

  EXPECT_EQ(root1.getValue(), 1);
}