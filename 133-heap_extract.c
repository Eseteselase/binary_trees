#include "binary_trees.h"

/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 *
 * Return: Value stored in the root node.
 */

int heap_extract(heap_t **root) {
    if (!root || !*root) {
	    return 0;
    }

    heap_t *last_node = *root;
    int last_level = 0;

    while (last_node->left || last_node->right) {
        last_level++;
        if (!last_node->left) {
            last_node = last_node->right;
        } else {
            last_node = last_node->left;
        }
    }

    int value = (*root)->n;
    free(*root);

    *root = last_node;

    heapify(*root, last_level, 0);

    return value;
}
