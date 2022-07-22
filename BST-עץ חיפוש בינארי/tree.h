#pragma once

typedef int tree_type;

typedef struct tree {
	tree_type data;
	struct tree* right, * left, * parent;
}tree;

tree* create_node(tree* parent, tree_type data);

/*insert a new node into the BST using iterative method*/
void insert_iterative(tree** root, tree_type data);

/*insert a new node into the BST using recursive method*/
void insert_recursive(tree** root, tree* parent, tree_type data);

tree* search(tree* root, tree_type data);

tree* min_value(tree* node, int* height);

tree* max_value(tree* node, int* height);

tree* delete_node(tree* root, tree_type data);

void deltree(tree** root);
