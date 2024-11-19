#ifndef RedBlack_tree_H_
# define RedBlack_tree_H_
#include <iostream>

namespace Color {
	const enum Node_color : bool { Red = true, Black = false };
}

class Node {
private:
	bool Node_color;
	int data;
	Node* left_node;
	Node* right_node;
	Node* parent_node;
	friend class Red_Black_tree;
public:
	explicit Node(const int& paramKey = NULL, const bool paramColor = Color::Black, Node* paramParent = nullptr, Node* paramLeft = nullptr, Node* paramRight = nullptr) : data(paramKey), Node_color(paramColor), parent_node(paramParent), left_node(paramLeft), right_node(paramRight) {}
};

class Red_Black_tree {
private:
	int num_of_node;
	Node* nil;

private:
	Node* find_grand_father(Node* n);
	Node* find_uncle(Node* n);
	void left_rotate(Node* n);
	void right_rotate(Node* n);
	void insert_fix(Node* n);
	void delete_fix(Node* n);
	void in_order_traversal(Node* root);
public:
	void insert_node(const int& in_data, Node* n);
	void delete_node(const int& delete_data, Node* n);
	void in_order_traversal();
	Node* root();
	void print_root();
	explicit Red_Black_tree() : num_of_node(0), nil(new Node(-1, Color::Black)) {
		nil->left_node = nil->right_node = nil->parent_node = nil;
	}
};
#endif 