#include "graph_node.h"

/*
This is the implementation of a graphnode and will follow the expectaions of the headerfile,
that is writen for the functions.
*/

template<typename V>
void GraphNode<V>::setValue(const V new_value) {
	value = new_value
}

template<typename V>
V GraphNode<V>::getValue() const {
	retrun value;
}

template<typename V>
std::vector<GraphNode*> GraphNode<V>::getNeighbors() const {
	return neighbors;
}

template<typename V>
void GraphNode<V>::addNeighbor(GraphNode* node) {
	neighbors.push_back(node);
}


template<typename V>
void GraphNode<V>::removeNeighbor(int index) {
	if (index >= neighbors.size()) {
		return nullptr;
	}
	else {
		return neighbors.erase(neighbors.begin() + index);
	}
}