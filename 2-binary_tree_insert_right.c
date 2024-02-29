#include "binary_trees.h"
/**
 * binary_tree_insert_right- inserts a node as the right-child
 * @parent: is a pointer to the node to insert the right-child
 * @value: is the value to store
 * Return: pointer to the created node, or NULL
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *addr;

	if (parent == NULL)
		return (NULL);
	addr = binary_tree_node(parent, value);
	if (addr == NULL)
		return (NULL);
	if (parent->right != NULL)
	{
		addr->right = parent->right;
		parent->right->parent = addr;
	}
	parent->right = addr;

	return (addr);
}
