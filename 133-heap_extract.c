#include "binary_trees.h"

/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 *
 * Return: Value stored in the root node.
 */
int heap_extract(heap_t **root)
{
    int extracted_value;

    if (root == NULL || *root == NULL)
        return 0;

    /* Extract value from the root node */
    extracted_value = (*root)->n;

    /* Find the last level-order node */
    while ((*root)->left || (*root)->right)
    {
        if ((*root)->right == NULL || (*root)->left->n > (*root)->right->n)
        {
            (*root)->n = (*root)->left->n;
            *root = (*root)->left;
        }
        else
        {
            (*root)->n = (*root)->right->n;
            *root = (*root)->right;
        }
    }

    /* Free the last level-order node */
    if (*root)
    {
        if ((*root)->parent)
        {
            if ((*root)->parent->left == *root)
                (*root)->parent->left = NULL;
            else
                (*root)->parent->right = NULL;
            free(*root);
        }
        else
        {
            /* If the last node is the root itself */
            free(*root);
            *root = NULL;
        }
    }

    /* Rebuild the heap */
    if (*root)
        heapify_down(*root);

    return extracted_value;
}

/**
 * heapify_down - Rebuilds the Max Binary Heap after extracting the root.
 * @node: Pointer to the root node of the heap.
 */
void heapify_down(heap_t *node)
{
    heap_t *largest = node;
    heap_t *left = node->left;
    heap_t *right = node->right;

    if (left && left->n > largest->n)
        largest = left;

    if (right && right->n > largest->n)
        largest = right;

    if (largest != node)
    {
        swap_values(node, largest);
        heapify_down(largest);
    }
}

/**
 * swap_values - Swaps the values of two heap nodes.
 * @node1: First heap node.
 * @node2: Second heap node.
 */
void swap_values(heap_t *node1, heap_t *node2)
{
    int temp = node1->n;
    node1->n = node2->n;
    node2->n = temp;
}
