#include <vector>

/*
This class is a node for a tree structure with a parentpointer and
unlimited number of children so it is not limited to a binary-tree.
*/
template<class V>
class TreeNode {
private:
	V value;
	TreeNode<V>* parent = nullptr;
	std::vector<TreeNode<V>*> children;
public:
	void setValue(const V new_value);
	V getValue();

	TreeNode<V>* getParent();
	std::vector<TreeNode<V>*> getChildren();

	void setParent(TreeNode<V>* node);
	void addChild(TreeNode<V>* node);

	// It is expected that the user of this structure will get the parent befor removing it.
	void removeParent();
	/*
	It is expected that the user of this structure will get the child befor removing it.
	 If the index is above the given size of the childrenvector the nullptr will be returned.
	*/
	void removeChild(int index);
};

/* --------------------------------------------- ## ---------------------------------------------*/

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
	return value;
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
	if (index < children.size() && index >= 0) {
		children.erase(children.begin() + index);
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