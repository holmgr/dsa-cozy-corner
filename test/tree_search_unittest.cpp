#include "tree_searching.h"
#include "gtest/gtest.h"

/*
 This file will include all the files to test the binary_tree_search.
*/


// Tests so that no value will be found if a value not in the tree is given
TEST(TreeSearchTest, NoValue) {
	TreeNode<int> root_node;
	TreeNode<int> child1;
	TreeNode<int> child2;
	TreeNode<int> child3;
	TreeNode<int> child4;
	TreeNode<int> child5;
	TreeNode<int> child6;

	root_node.setValue(5);
	child1.setValue(3);
	child2.setValue(9);
	child3.setValue(8);
	child4.setValue(4);
	child5.setValue(2);
	child6.setValue(1);

	root_node.addChild(&child1);
	root_node.addChild(&child2);
	child1.addChild(&child5);
	child1.addChild(&child4);
	child5.addChild(&child6);
	child2.addChild(&child3);

	ASSERT_EQ(binary_tree_search(&root_node, 0), nullptr);
}


// This test will check so that the root-value can be found in the givent tree.
TEST(TreeSearchTest, FoundRoot) {
	TreeNode<int> root_node;
	TreeNode<int> child1;
	TreeNode<int> child2;
	TreeNode<int> child3;
	TreeNode<int> child4;
	TreeNode<int> child5;
	TreeNode<int> child6;

	root_node.setValue(5);
	child1.setValue(3);
	child2.setValue(9);
	child3.setValue(8);
	child4.setValue(4);
	child5.setValue(2);
	child6.setValue(1);

	root_node.addChild(&child1);
	root_node.addChild(&child2);
	child1.addChild(&child5);
	child1.addChild(&child4);
	child5.addChild(&child6);
	child2.addChild(&child3);

	ASSERT_EQ(binary_tree_search(&root_node, 5), &root_node);
}


// This test will check so that leaf values can be found.
TEST(TreeSearchTest, LeefValue) {
	TreeNode<int> root_node;
	TreeNode<int> child1;
	TreeNode<int> child2;
	TreeNode<int> child3;
	TreeNode<int> child4;
	TreeNode<int> child5;
	TreeNode<int> child6;

	root_node.setValue(5);
	child1.setValue(3);
	child2.setValue(9);
	child3.setValue(8);
	child4.setValue(4);
	child5.setValue(2);
	child6.setValue(1);

	root_node.addChild(&child1);
	root_node.addChild(&child2);
	child1.addChild(&child5);
	child1.addChild(&child4);
	child5.addChild(&child6);
	child2.addChild(&child3);

	ASSERT_EQ(binary_tree_search(&root_node, 1), &child6);
	ASSERT_EQ(binary_tree_search(&root_node, 8), &child3);
}


// This test will check so that a value inside the tree can be found.
TEST(TreeSearchTest, FoundValue) {
	TreeNode<int> root_node;
	TreeNode<int> child1;
	TreeNode<int> child2;
	TreeNode<int> child3;
	TreeNode<int> child4;
	TreeNode<int> child5;
	TreeNode<int> child6;

	root_node.setValue(5);
	child1.setValue(3);
	child2.setValue(9);
	child3.setValue(8);
	child4.setValue(4);
	child5.setValue(2);
	child6.setValue(1);

	root_node.addChild(&child1);
	root_node.addChild(&child2);
	child1.addChild(&child5);
	child1.addChild(&child4);
	child5.addChild(&child6);
	child2.addChild(&child3);

	ASSERT_EQ(binary_tree_search(&root_node, 3), &child1);
}


// This test checks so that an empty tree will return just an empty tree.
TEST(TreeSearchTest, NullTree) {
	TreeNode<int>* root_node = nullptr;


	ASSERT_EQ(binary_tree_search(root_node, 3), nullptr);
}