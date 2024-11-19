#include "RedBlack_tree.h"

Node* Red_Black_tree::find_grand_father(Node* n) {
	if (n->parent_node == nullptr || n->parent_node->parent_node == nullptr) return nullptr;
	return n->parent_node->parent_node;
}

Node* Red_Black_tree::find_uncle(Node* n) {
	Node* Grand(find_grand_father(n));
	if (Grand == nullptr) return nullptr;
	if (Grand->left_node == n->parent_node)return Grand->right_node;
	else return Grand->left_node;
}

void Red_Black_tree::left_rotate(Node* n) {
	Node* t = n->right_node;

	n->right_node = t->left_node;
	if (t->left_node != nil) t->left_node->parent_node = n;

	t->parent_node = n->parent_node;

	if (n->parent_node == nil) nil->right_node = t;
	else if (n->parent_node->left_node == n) n->parent_node->left_node = t;
	else n->parent_node->right_node == t;

	t->left_node = n;

	n->parent_node = t;
}

void Red_Black_tree::right_rotate(Node* n) {
	Node* t = n->left_node;

	n->left_node = t->right_node;
	if (t->right_node != nil) t->right_node->parent_node = n;

	t->parent_node = n->parent_node;

	if (n->parent_node == nil) nil->left_node = t;
	else if (n->parent_node->right_node == n) n->parent_node->right_node = t;
	else n->parent_node->left_node == t;

	t->right_node = n;

	n->parent_node = t;
}

void Red_Black_tree::insert_fix(Node* n) {//이때 nil의 오른쪽은 루트
	while (n->parent_node->Node_color == Color::Red) {
		Node* Grand(find_grand_father(n));
		Node* uncle(find_uncle(n));
		if (n->parent_node == Grand->left_node) {
			if (uncle->Node_color == Color::Red) {
				n->parent_node->Node_color = uncle->Node_color = Color::Black;
				Grand->Node_color = Color::Red;
				n = Grand;
			}
			else {
				if (n->parent_node->right_node == n) {
					n = n->parent_node;
					left_rotate(n);
				}
				n->parent_node->Node_color = !n->parent_node->Node_color;
				Grand->Node_color = !Grand->Node_color;
				right_rotate(Grand);
			}
		}
		else {
			if (uncle->Node_color == Color::Red) {
				n->parent_node->Node_color = uncle->Node_color = Color::Black;
				Grand->Node_color = Color::Red;
				n = Grand;
			}
			else {
				if (n->parent_node->left_node == n) {
					n = n->parent_node;
					right_rotate(n);
				}
				n->parent_node->Node_color = !n->parent_node->Node_color;
				Grand->Node_color = !Grand->Node_color;
				left_rotate(Grand);
			}
		}
	}
	nil->right_node->Node_color = Color::Black;
}

void Red_Black_tree::insert_node(const int& in_data,Node* n) {
	Node* parent, * tail;
	parent = nil;
	tail = nil->right_node;
	while (tail != nil) {
		parent = tail;
		if (in_data == tail->data) {
			printf("data in this tree\n");
			return;
		}
		else if (tail->data > in_data)tail = tail->left_node;
		else tail = tail->right_node;
	}
	tail = new Node(in_data, Color::Red, parent, nil, nil);
	if (parent == nil) {
		parent->right_node = tail;
		tail->Node_color = Color::Black;
	}
	else if (in_data < parent->data)parent->left_node = tail;
	else parent->right_node = tail;
	insert_fix(tail);
}

void Red_Black_tree::delete_node(const int& delete_data, Node* n) {
	Node* target = n;
	while (target != nil && target->data != delete_data) {
		if (delete_data < target->data) target = target->left_node;
		else target = target->right_node;
	}

	if (target == nil) {
		printf("Node not found\n");
		return;
	}

	Node* replacement = target;
	if (target->left_node != nil && target->right_node != nil) {
		replacement = target->right_node;
		while (replacement->left_node != nil)
			replacement = replacement->left_node;
		target->data = replacement->data;
		target = replacement;
	}

	Node* child = (target->left_node != nil) ? target->left_node : target->right_node;
	if (child != nil) child->parent_node = target->parent_node;

	if (target->parent_node == nil) nil->right_node = child;
	else if (target == target->parent_node->left_node) target->parent_node->left_node = child;
	else target->parent_node->right_node = child;

	if (target->Node_color == Color::Black)
		delete_fix(child);

	delete target;
}
void Red_Black_tree::delete_fix(Node* n) {
	while (n != nil->right_node && n->Node_color == Color::Black) {
		if (n->parent_node->left_node == n) {
			Node* sibling = n->parent_node->right_node;
			if (sibling->Node_color == Color::Red) {
				sibling->Node_color = Color::Black;
				n->parent_node->Node_color = Color::Red;
				left_rotate(n->parent_node);
				sibling = n->parent_node->right_node;
			}
			if (sibling->left_node->Node_color == Color::Black && sibling->right_node->Node_color == Color::Black) {
				sibling->Node_color = Color::Red;
				n = n->parent_node;
			}
			else {
				if (sibling->right_node->Node_color == Color::Black) {
					sibling->Node_color = Color::Red;
					sibling->left_node->Node_color = Color::Black;
					right_rotate(sibling);
					sibling = n->parent_node->right_node;
				}
				sibling->Node_color = n->parent_node->Node_color;
				n->parent_node->Node_color = sibling->right_node->Node_color = Color::Black;
				left_rotate(n->parent_node);
				n = nil->right_node;
			}
		}
		else {
			Node* sibling = n->parent_node->left_node;
			if (sibling->Node_color == Color::Red) {
				sibling->Node_color = Color::Black;
				n->parent_node->Node_color = Color::Red;
				right_rotate(n->parent_node);
				sibling = n->parent_node->left_node;
			}
			if (sibling->left_node->Node_color == Color::Black && sibling->right_node->Node_color == Color::Black) {
				sibling->Node_color = Color::Red;
				n = n->parent_node;
			}
			else {
				if (sibling->left_node->Node_color == Color::Black) {
					sibling->Node_color = Color::Red;
					sibling->right_node->Node_color = Color::Black;
					left_rotate(sibling);
					sibling = n->parent_node->left_node;
				}
				sibling->Node_color = n->parent_node->Node_color;
				n->parent_node->Node_color = sibling->left_node->Node_color = Color::Black;
				right_rotate(n->parent_node);
				n = nil->right_node;
			}
		}
	}
}

Node* Red_Black_tree::root() {
	return nil->right_node;
}

void Red_Black_tree::in_order_traversal(Node* root) {
	if (root == nil) return; 
	in_order_traversal(root->left_node);

	std::cout << root->data << " (" << (root->Node_color == Color::Red ? "R" : "B") << ") ";

	in_order_traversal(root->right_node);
}

void Red_Black_tree::in_order_traversal() {
	in_order_traversal(nil->right_node); 
}

void Red_Black_tree::print_root() {
	std::cout << "\nroot : " << nil->right_node->data <<" ("  << (nil->right_node->Node_color == Color::Red ? "R" : "B" )<< ")\n";
}