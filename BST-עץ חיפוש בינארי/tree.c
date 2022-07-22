/************************************************************************
*	C Binary-Search-Tree (or BST in short)								*
*	with left, right & parent pointers									*
*																		*
*   Implemention include:												*
*		a. Insert (iterative & recursive)								*
*		b. Search														*
*		c. Get min & max value											*
*		d. Delete node (with best successor selection)					*
*		e. Delete tree													*
*																		*
*	The code was written by Shimon Aviram,								*
*	Based on the following references:									*
*	https://www.thegeekstuff.com/2013/02/c-binary-tree/					*
*	http://www.zentut.com/c-tutorial/c-binary-search-tree/				*
************************************************************************/

#include<stdlib.h>
#include<stdio.h>
#include "tree.h"

/*create a new node*/
tree* create_node(tree *parent, tree_type data)
{
    tree* node = (tree*)malloc(sizeof(tree));
	if (!node)
		return NULL;

    node->data = data;
	node->parent = parent;
    node->left = node->right = NULL;
    return node;
}

/*insert a new node into the BST using iterative method*/
void insert_iterative(tree **root, tree_type data)
{
	if (!(*root))
    {
		*root = create_node(NULL, data);
		return;
    }

    tree* cursor = *root;
 
    while(1)
	{      
		if(data < cursor->data)
        {
            if (cursor->left)
				cursor = cursor->left;
			else
			{
				cursor->left = create_node(cursor, data);
				return;
			}
        }
        else if(data > cursor->data)
        {
            if (cursor->right)
				cursor = cursor->right;
			else
			{
				cursor->right = create_node(cursor, data);
				return;
			}
		}
		else //(data == cursor->data)
		{
			return;
		}
    }
}

/*insert a new node into the BST using recursive method*/
void insert_recursive(tree **root, tree *parent, tree_type data)
{
	if (!(*root))
	{
		*root = create_node(parent, data);
		return;
	}

	if (data < (*root)->data)
	{
		insert_recursive(&(*root)->left, *root , data);
	}
	else if (data >(*root)->data)
	{
		insert_recursive(&(*root)->right, *root, data);
	}
}

void deltree(tree **root)
{
	if (*root)
	{
		deltree(&((*root)->left));
		deltree(&((*root)->right));
		free(*root);
		*root = NULL;
	}
}

tree* search(tree *root, tree_type data)
{
	if (!root)
		return NULL;

	if (data < root->data)
	{
		search(root->left, data);
	}
	else if (data > root->data)
	{
		search(root->right, data);
	}
	else if (data == root->data)
	{
		return root;
	}
}

tree* min_value(tree* node, int* height) 
{
	*height = 0;
	
	/* loop down to find the leftmost leaf */
	while (node->left != NULL) 
	{
		node = node->left;
		(*height)++;
	}
	
	return node;
}

tree* max_value(tree* node, int* height) 
{
	*height = 0;
	
	/* loop down to find the rightmost leaf */
	while (node->right != NULL) 
	{
		node = node->right;
		(*height)++;
	}
	
	return node;
}

/*delete a node in the BST*/
tree* delete_node(tree* root, tree_type data)
{
	if(!root)
        return NULL;

    if(data < root->data)
        root->left = delete_node(root->left, data);
    else if(data > root->data)
        root->right = delete_node(root->right, data);
    else
    {       		
		tree* cursor = NULL;

		if ((root->left) && (root->right)) //2 children
		{
			int left, right;
			tree *parent = NULL;
			tree* cursorLeft = min_value(root->right, &left);
			tree* cursorRight = max_value(root->left, &right);

			cursor = (left > right)?cursorLeft:cursorRight;
			parent = cursor->parent;
			root->data = cursor->data;

			if (parent->left == cursor)
				parent->left = delete_node(parent->left, cursor->data);
			else
				parent->right = delete_node(parent->right, cursor->data);
		}
		else
		{
			if (root->left)	//only left child
			{
				cursor = root->left;
				cursor->parent = root->parent;
			}
			else if (root->right) //only right child
			{
				cursor = root->right;
				cursor->parent = root->parent;
			}
			free(root);
			root = cursor;
		}
	}
    return root;
}