#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: pointer to the parent node of new created node
 * @value: value of the node
 *
 * Return: pointer to new created node on success and NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode, *tmp;

	if (!parent)
	{
		return (NULL);
	}
	newnode = malloc(sizeof(binary_tree_t));
	if (!newnode)
		return (NULL);
	newnode->n = value;
	newnode->parent = parent;
	newnode->left = NULL;
	newnode->right = NULL;
	if (!parent->left)
	{
		parent->left = newnode;
	}
	else
	{
		tmp = parent->left;
		parent->left = newnode;
		tmp->parent = newnode;
		newnode->left = tmp;
	}
	return (newnode);
}
