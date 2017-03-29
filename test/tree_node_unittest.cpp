#include "tree_node.h"
#include "gtest/gtest.h"

/*
 This file will include all the test for the TreeNode class.
*/

TEST(TreeNodeTest, AddChild) {
  // Initialize a node with some children.
  TreeNode<int> focusNode;
  TreeNode<int> child1;
  TreeNode<int> child2;

  focusNode.addChild(&child1);
  focusNode.addChild(&child2);
  EXPECT_EQ(focusNode.getChildren().size(), 2);
}

TEST(TreeNodeTest, SetChild) {
	// Initialize a node with some children.
	TreeNode<int> focusNode;
	TreeNode<int> child1;

	focusNode.setChild(&child1, 3);
	EXPECT_EQ(focusNode.getChildren().size(), 4);

	auto children = focusNode.getChildren();
	for (int i = 0; i < 3; i++) {
		EXPECT_EQ(children[i], nullptr);
	}
	EXPECT_EQ(children[3], &child1);
}

TEST(TreeNodeTest, RemoveChild) {
  // Initialize a node with some children then remove them.
  TreeNode<int> focusNode;
  TreeNode<int> child1;
  TreeNode<int> child2;

  focusNode.addChild(&child1);
  focusNode.addChild(&child2);

  focusNode.removeChild(1);
  EXPECT_EQ(focusNode.getChildren().size(), 1);

  focusNode.removeChild(0);
  EXPECT_EQ(focusNode.getChildren().size(), 0);

  EXPECT_NO_THROW(focusNode.removeChild(0));
}

TEST(TreeNodeTest, AddParent) {
  // Initialize a node with a parent.
  TreeNode<int> root;
  TreeNode<int> focusNode;

  EXPECT_EQ(focusNode.getParent(), nullptr);

  focusNode.setParent(&root);
  EXPECT_EQ(focusNode.getParent(), &root);
}

TEST(TreeNodeTest, RemoveParent) {
  // Initialize a node with a parent and then remove it.
  TreeNode<int> root;
  TreeNode<int> focusNode;

  focusNode.setParent(&root);
  EXPECT_EQ(focusNode.getParent(), &root);

  focusNode.removeParent();
  EXPECT_EQ(focusNode.getParent(), nullptr);
}

TEST(TreeNodeTest, Value) {
  // Initialize a node with a value.
  TreeNode<int> focusNode;

  focusNode.setValue(1);
  EXPECT_EQ(focusNode.getValue(), 1);
}