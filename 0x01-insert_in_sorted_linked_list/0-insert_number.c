#include "lists.h"
#include <stdlib.h>

/**
  * insert_node - Inserts a node into a sorted linked list
  *
  * @head: head of sorted linked list
  * @number: new value for node
  * Return: head of linked list
  */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new, *copy = *head;


	new = malloc(sizeof(listint_t));
	new->n = number;
	if (!(copy) or number < copy->n)
	{
		new->next = copy;
		*head = new;
		return (*head);
	}

	for (; copy->next; copy = copy->next)
		if (number < copy->next->n)
		{
			new->next = copy->next;
			copy->next = new;
			return (*head);
		}
	copy->next = new;
	new->next = NULL;
	return  (*head);
}
