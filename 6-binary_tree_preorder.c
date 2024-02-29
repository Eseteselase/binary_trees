#include "binary_trees.h"
/**
 * @tree:  is a pointer to the root node
 * @func: pointer to func
*/
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree && func)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
