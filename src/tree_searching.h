#ifndef TREE_SEARCHING_H
#define TREE_SEARCHING_H
#include "tree_node.h"
#include <stack>

/*
 This function will search trough a tree-structure, with the given node as the start, for the given value
 and expect that the tree is sorted.
 If the value is found the node containing the value will be returned. If the value is not found then a
 nullptr will be returned.

 The complexity is in the worst-case O(n), the tree is just a long sequence of children, and O(log(n)) in
 the best-case, then the tree is a complete binary tree with depth log(n).
*/
template<typename V>
TreeNode<V>* binary_tree_search(TreeNode<V>* start_node, V value) {
	TreeNode<V>* current_node = start_node;
	bool found_node = false;
	while (!found_node) {
		// The value was found
		if (current_node->value == value) {
			found_node = true;
		}
		else if (value < current_node->value) {
			// If the value is smaller then the current node go to the left childe.
			// If there exist a left child.
			if (current_node->getChildren().size() > 0) {
				current_node = current_node->getChildren()[0];
			}
			else {
				current_node = nullptr;
				found_node = false;
			}
		}
		else {
			// If the value is larger then the current node go to the left childe.
			// If there exist a right child.
			if (current_node->getChildren().size() > 1) {
				current_node = current_node->getChildren()[1];
			}
			else {
				current_node = nullptr;
				found_node = false;
			}
		}
	}
	return current_node;
}

#endif