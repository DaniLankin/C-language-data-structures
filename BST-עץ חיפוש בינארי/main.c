#include<stdio.h>
#include "tree.h"

void print_preorder(tree* root)
{
	if (root)
	{
		printf("%d ", root->data);
		print_preorder(root->left);
		print_preorder(root->right);
	}
}

void print_inorder(tree* root)
{
	if (root)
	{
		print_inorder(root->left);
		printf("%d ", root->data);
		print_inorder(root->right);
	}
}

void print_postorder(tree* root)
{
	if (root)
	{
		print_postorder(root->left);
		print_postorder(root->right);
		printf("%d ", root->data);
	}
}

void main()
{
	int num;
	tree* temp = NULL;
	tree* root = NULL;

	/* Inserting nodes into tree */
	insert_iterative(&root, 9);		//insert_recursive(&root, NULL , 9);
	insert_iterative(&root, 4);		//insert_recursive(&root, NULL , 4);
	insert_iterative(&root, 15);	//insert_recursive(&root, NULL, 15);
	insert_iterative(&root, 6);		//insert_recursive(&root, NULL, 6);
	insert_iterative(&root, 12);	//insert_recursive(&root, NULL, 12);
	insert_iterative(&root, 17);	//insert_recursive(&root, NULL, 17);
	insert_iterative(&root, 2);		//insert_recursive(&root, NULL, 2);

	/* Printing nodes of tree */
	printf("Pre Order Display:  ");	print_preorder(root);	printf("\n\n");
	printf("In Order Display:   ");	print_inorder(root);	printf("\n\n");
	printf("Post Order Display: ");	print_postorder(root);	printf("\n\n");

	/* Delete node in tree */
	printf("Value to delete in tree: ");
	scanf_s("%d", &num);
	printf("\n");

	root = delete_node(root, num);

	/* Search node into tree */
	printf("Value to search in tree: ");
	scanf_s("%d", &num);
	printf("\n");

	temp = search(root, num);
	if (temp)
	{
		printf("Data found in tree: \n");
		printf("Node: %d\n", temp->data);

		if (temp->parent) { printf("Parent: %d\n", temp->parent->data); }
		else { printf("Parent: NULL\n"); }
		if (temp->left) { printf("Left Son: %d\n", temp->left->data); }
		else { printf("Left Son: NULL\n"); }
		if (temp->right) { printf("Right Son: %d\n", temp->right->data); }
		else { printf("Right Son: NULL\n"); }
	}
	else
	{
		printf("Data Not found in tree.\n");
	}

	/* Deleting all nodes of tree */
	deltree(&root);
}
