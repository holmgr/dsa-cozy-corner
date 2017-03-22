#include <vector>

template<typename V>
class GraphNode;

/*
 This is a struct to be used with the GraphNode to define links between the nodes in the graph.
*/

template<typename V>
struct NodeLink {
	GraphNode<V>* node;
	float link_weight = 1;
};

/*
 This class is a node for a graph structure with a value if it is needed.
*/
template <typename V>
class GraphNode {
 private:
  V value;
  std::vector<NodeLink<V>> neighbors;

 public:
  void setValue(V new_value);
  V getValue();
  std::vector<NodeLink<V>> getNeighbors() const;

  /*
   This function will add the gien nod and weight to the NodeLink struct and then
   add it to the list of neighbors.
  */
  void addNeighbor(GraphNode<V>* node, float link_weight);
  /*
  It is expected that the user of this structure will get the child befor
  removing it.
  If the index is above the given size of the childrenvector the nullptr will be
  returned.
  */
  void removeNeighbor(int index);
};

/* --------------------------------------------- ##
 * ---------------------------------------------*/

/*
This is the implementation of a graphnode and will follow the expectaions of the
headerfile,
that is writen for the functions.
*/

template <typename V>
void GraphNode<V>::setValue(V new_value) {
  value = new_value;
}

template <typename V>
V GraphNode<V>::getValue() {
  return value;
}

template <typename V>
std::vector<NodeLink<V>> GraphNode<V>::getNeighbors() const {
  return neighbors;
}

template <typename V>
void GraphNode<V>::addNeighbor(GraphNode<V>* node, float link_weight) {
	// Create the link and set the weigth and node
	NodeLink<V> nl;
	nl.node = node;
	nl.link_weight = link_weight;

	neighbors.push_back(nl);
}

template <typename V>
void GraphNode<V>::removeNeighbor(int index) {
  if (index < neighbors.size() && index >= 0) {
    neighbors.erase(neighbors.begin() + index);
  }
}