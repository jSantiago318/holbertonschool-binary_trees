#include "binary_trees.h"

/**
 * binary_tree_is_perfect_helper - Helper to check if tree is perfect and get height
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of tree if perfect, -1 if not perfect
 */
static int binary_tree_is_perfect_helper(const binary_tree_t *tree)
{
	int left_height;
	int right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_is_perfect_helper(tree->left);
	right_height = binary_tree_is_perfect_helper(tree->right);

	if (left_height == -1 || right_height == -1)
		return (-1);

	if (left_height != right_height)
		return (-1);

	if ((tree->left == NULL && tree->right != NULL) ||
		(tree->left != NULL && tree->right == NULL))
		return (-1);

	return (left_height + 1);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is perfect, 0 otherwise. Returns 0 if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_is_perfect_helper(tree) != -1 ? 1 : 0);
}
