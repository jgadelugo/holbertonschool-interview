#include "binary_trees.h"


/**
  * binary_tree_height - get height from binary tree
  * @tree: tree to search
  * Return: height
  */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l = 0, r = 0;

	if (tree == NULL)
		return (0);
	l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
	r = tree->right ? 1 + binary_tree_height(tree->right) : 1;
	return ((l > r) ? l : r);
}

/**
 * check_avl_tree - Checks if tree is AVL tree
 * @tree: tree to check
 * @high: higher node
 * @low: lower node
 * Return: 1 if True, 0 if not AVL tree
 */
int check_avl_tree(const binary_tree_t *tree, int low, int high)
{
	size_t height_l, height_r, balancer;

	if (tree)
	{
		if (tree->n > high || tree->n < low)
			return (0);
		height_l = binary_tree_height(tree->left);
		height_r = binary_tree_height(tree->right);
		if (height_l > height_r)
			balancer =  height_l - height_r;
		else
			balancer = height_r - height_l;
		if (balancer > 1)
			return (0);
		return (check_avl_tree(tree->left, low, tree->n - 1) &&
				check_avl_tree(tree->right, tree->n + 1, high));
	}
	return (1);
}

/**
 * binary_tree_is_avl - checks if it is a valid AVL tree
 * @tree: node of binary tree
 * Return: 1 if true, 0 if not avl tree
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (check_avl_tree(tree, INT_MIN, INT_MAX));
}
