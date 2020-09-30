#include "binary_trees.h"
#include <stddef.h>
#include <stdlib.h>

/**
  * binary_tree_height - get height from binary tree
  * @tree: tree to search
  * Return: height
  */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lSize = 0, rSize = 0;

	if (!tree)
		return (0);
	else if (tree->left || tree->right)
	{
		lSize = binary_tree_height(tree->left);
		rSize = binary_tree_height(tree->right);
		if (lSize > rSize)
			return (lSize + 1);
		return (rSize + 1);
	}
	else
		return (0);
}

/**
  * binary_tree_preorder - does function using preorder
  * @tree: binary tree
  * @new: new tree
  * @height: height of tree
  * @lvl: current lvl of tree
  */

void binary_tree_preorder(heap_t *tree, heap_t **new,
						  size_t height, size_t lvl)
{
	if (!tree)
		return;
	if (height == lvl)
		*new = tree;
	binary_tree_preorder(tree->left, new, height, lvl + 1);
	binary_tree_preorder(tree->right, new, height, lvl + 1);
}


/**
 * heap_extract - function that extracts the root new of a Max binary heap
 * @root: double pointer to the root new of the heap
 *
 * Return: the value in root new and rebuild heap, return 0 if fails
 */
int heap_extract(heap_t **root)
{
	int n, value_hold;
	heap_t *new, *hold;

	if (!root || !*root)
		return (0);

	n = (*root)->n;
	if (!(*root)->left && !(*root)->right)
	{
		*root = NULL;
		return (n);
	}
	hold = *root;
	binary_tree_preorder(hold, &new, binary_tree_height(*root), 0);
	while (hold->left || hold->right)
	{
		if (!hold->right || hold->left->n > hold->right->n)
		{
			value_hold = hold->n;
			hold->n = hold->left->n;
			hold->left->n = value_hold;
			hold = hold->left;
		}
		else if (!hold->left || hold->left->n < hold->right->n)
		{
			value_hold = hold->n;
			hold->n = hold->right->n;
			hold->right->n = value_hold;
			hold = hold->right;
		}

	}
	hold->n = new->n;
	if (new->parent->right)
		new->parent->right = NULL;
	else
		new->parent->left = NULL;
	free(new);
	return (n);
}
