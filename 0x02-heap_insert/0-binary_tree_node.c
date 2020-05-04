#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree
 *
 *
 * @parent: parent of tree
 * @value: value for tree
 * Return: Always 0 (Success)
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	new->parent = NULL;
	new->left = NULL;
	new->right = NULL;
	new->n = value;


	if (!parent)
		return (new);

	new->parent = parent;
	return (new);
}
