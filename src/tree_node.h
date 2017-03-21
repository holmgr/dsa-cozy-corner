#include <vector>

/*
This class is a node for a tree structure with a parentpointer and
unlimited number of children so it is not limited to a binary-tree.
*/
template<typename V>
class TreeNode {
private:
	V value;
	TreeNode<V>* parent;
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