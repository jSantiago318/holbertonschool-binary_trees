#include "binary_trees.h"

/**
 * binary_tree_height_helper - Helper to measure the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree. If tree is NULL, return 0
 */
static size_t binary_tree_height_helper(const binary_tree_t *tree)
{
	size_t left_height;
	size_t right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height_helper(tree->left);
	right_height = binary_tree_height_helper(tree->right);

	if (tree->left != NULL)
		left_height += 1;
	if (tree->right != NULL)
		right_height += 1;

	return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure the balance factor
 *
 * Return: Balance factor of the tree. If tree is NULL, return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left_height;
	size_t right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height_helper(tree->left);
	right_height = binary_tree_height_helper(tree->right);

	return ((int)left_height - (int)right_height);
}
