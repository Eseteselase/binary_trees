#ifndef BINARY_TR_H
#define BINARY_TR_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
void binary_tree_print(const binary_tree_t *);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
void binary_tree_delete(binary_tree_t *tree);
int binary_tree_is_root(const binary_tree_t *node);
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
size_t binary_tree_nodes(const binary_tree_t *tree);
int is_full_recursive(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
void btlo_helper(const binary_tree_t *tree, void (*func)(int), size_t level);
size_t binary_tree_height(const binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
bst_t *bst_insert(bst_t **tree, int value);
bst_t *bst_search(const bst_t *tree, int value);
size_t height(const binary_tree_t *tree);
int balance(const binary_tree_t *tree);
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent, avl_t **new, int value);
avl_t *avl_insert(avl_t **tree, int value);
avl_t *avl_remove(avl_t *root, int value);
heap_t *heap_insert(heap_t **root, int value);
size_t binary_tree_size(const binary_tree_t *tree);
int heap_extract(heap_t **root);
#endif
