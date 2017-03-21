#include <vector>


/*
 This class is a node for a graph structure with a value if it is needed.
*/
template<typename V>
class GraphNode {
private:
	V value;
	std::vector<GraphNode<V>*> neighbors;
public:
	void setValue(V new_value);
	V getValue();
	std::vector<GraphNode<V>*> getNeighbors() const;

	void addNeighbor(GraphNode<V>* node);
	/*
	It is expected that the user of this structure will get the child befor removing it.
	If the index is above the given size of the childrenvector the nullptr will be returned.
	*/
	void removeNeighbor(int index);
};

/* --------------------------------------------- ## ---------------------------------------------*/

/*
This is the implementation of a graphnode and will follow the expectaions of the headerfile,
that is writen for the functions.
*/

template<typename V>
void GraphNode<V>::setValue(V new_value) {
	value = new_value;
}

template<typename V>
V GraphNode<V>::getValue() {
	return value;
}

template<typename V>
std::vector<GraphNode<V>*> GraphNode<V>::getNeighbors() const {
	return neighbors;
}

template<typename V>
void GraphNode<V>::addNeighbor(GraphNode* node) {
	neighbors.push_back(node);
}


template<typename V>
void GraphNode<V>::removeNeighbor(int index) {
	if (index < neighbors.size() && index >= 0) {
		neighbors.erase(neighbors.begin() + index);
	}
}