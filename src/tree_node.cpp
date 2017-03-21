#include "tree_node.h"

/*
 This is the implementation of a treenode and will follow the expectaions of the headerfile,
 that is writen for the functions.
*/


template<typename V>
void TreeNode<V>::setValue(const V new_value) {
	value = new_value;
}

template<typename V>
V TreeNode<V>::getValue() {
	retrun value;
}

template<typename V>
std::vector<TreeNode<V>*> TreeNode<V>::getChildren() {
	return children;
}

template<typename V>
void TreeNode<V>::addChild(TreeNode<V>* node) {
	children.push_back(node);
}


template<typename V>
void TreeNode<V>::removeChild(int index) {
	// If the index is above the size of the list of children then return nullptr.
	if (index >= children.size()) {
		return nullptr;
	}
	else {
		return children.erase(neighbors.begin() + index);
	}
}

template<typename V>
TreeNode<V>* TreeNode<V>::getParent() {
	return parent;
}

template<typename V>
void TreeNode<V>::setParent(TreeNode<V>* node) {
	parent = node;
}

template<typename V>
void TreeNode<V>::removeParent() {
	parent = nullptr;
}