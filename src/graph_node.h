#include <vector>


/*
 This class is a node for a graph structure with a value if it is needed.
*/
template<typename V>
class GraphNode {
private:
	V value;
	std::vector<GraphNode*> neighbors;
public:
	void setValue(const V new_value);
	V getValue() const;
	std::vector<GraphNode*> getNeighbors() const;

	void addNeighbor(GraphNode* node);
	/*
	It is expected that the user of this structure will get the child befor removing it.
	If the index is above the given size of the childrenvector the nullptr will be returned.
	*/
	void removeNeighbor(int index);
};