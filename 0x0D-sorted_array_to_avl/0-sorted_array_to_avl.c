#include "binary_trees.h"
#include <stdlib.h>

/**
  * create_node - creates node with base values
  * @value: value for new node
  *
  * Return: new node
  */
binary_tree_t *create_node(int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);
	new->n = value;
	new->left = NULL;
	new->right = NULL;
	return (new);
}


/**
  * insert_to_avl - insert to avl tree
  * @array: array to convert to AVL tree
  * @low: low index
  * @high: high index
  *
  * Return: root node or NULL if fails
  */

avl_t *insert_to_avl(int *array, int low, int high)
{
	int half = (low + high) / 2;
	avl_t *left_node, *right_node, *parent;

	if (low > high)
		return (NULL);

	left_node = insert_to_avl(array, low, half - 1);
	right_node = insert_to_avl(array, half + 1, high);

	parent = create_node(array[half]);
	if (!parent)
		return (NULL);

	parent->left = left_node;
	parent->right = right_node;

	if (left_node)
		left_node->parent = parent;
	if (right_node)
		right_node->parent = parent;
	return (parent);
}

/**
 * sorted_array_to_avl - Sorts an array to avl
 * @array: array to sort
 * @size: size of array
 *
 * Return: AVL tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;


	if (!(array) || !(size))
		return (NULL);

	root = insert_to_avl(array, 0, size - 1);
	return (root);
}
