#include "lists.h"
#include <stdlib.h>

/**
  * insert_node - Inserts a node into a sorted linked list
  *
  * @head: head of sorted linked list
  * @number: new value for node
  * Return: new node of linked list
  */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new, *copy;


	/* check if head exists at all */
	if (!head)
		return (NULL);

	/* Create new node to insert into linked list */
	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);
	new->n = number;

	/* insert at beginning */
	if (!(*head) || number < (*head)->n)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	/* create copy of head to not move it */
	copy = *head;

	/*insert in the middle */
	for (; copy->next; copy = copy->next)
		if (number < copy->next->n)
		{
			new->next = copy->next;
			copy->next = new;
			return (new);
		}

	/* add at end */
	copy->next = new;
	new->next = NULL;
	return  (new);
}
