#include "binary_trees.h"

typedef struct s_btree_print
{
	int depth;
	int is_left;
} btree_print_t;

/**
 * print_tree_helper - Helper function to print binary tree
 * @tree: pointer to the root of the tree
 * @prefix: prefix for current line
 * @is_left: whether this is a left child
 */
static void print_tree_helper(const binary_tree_t *tree, char *prefix, int is_left)
{
	if (tree == NULL)
		return;

	printf("%s", prefix);
	printf(is_left ? "├── " : "└── ");
	printf("%d\n", tree->n);

	if (tree->left || tree->right)
	{
		if (tree->left)
			print_tree_helper(tree->left, prefix, 1);
		else
		{
			printf("%s├── \n", prefix);
		}

		if (tree->right)
			print_tree_helper(tree->right, prefix, 0);
		else
		{
			printf("%s└── \n", prefix);
		}
	}
}

/**
 * binary_tree_print - prints a binary tree in a visual format
 * @tree: pointer to the root of the tree
 */
void binary_tree_print(const binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	printf("%d\n", tree->n);
	print_tree_helper(tree, "", 0);
}
