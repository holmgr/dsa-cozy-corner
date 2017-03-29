#include "tree_searching.h"
#include "gtest/gtest.h"

TEST(TreeSearchTest, NoValue) {
	TreeNode<int>* root_node = nullptr;
	ASSERT_EQ(binary_tree_search(root_node, 1), nullptr);
}