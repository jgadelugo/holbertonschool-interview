#include <stddef.h>
#include "lists.h"


/**
 * is_palindrome - Check if linked list is palindrome
 * @head: double pointer to head of list
 * Return: 0 if False, 1 if True
 */
int is_palindrome(listint_t **head)
{
    listint_t *copy = *head, *end = *head, *prev, *hold;
    int size, i, is_pali = 1;

    if (!head)
        return (0);

    /* get size */
    for (size = 0; copy; size++)
        copy = copy->next;

    if (!*head || size == 1)
        return (1);

    copy = *head;

    /* Flip half */
    for (i = 0; i < size; i++)
    {
        hold = end->next;
        if (i > size / 2)
            end->next = prev; 
        prev = end;
        if (hold)
            end = hold;
    }

    prev = NULL;

    /* Check if palindrome and flip half back*/
    for (i = 0; i < size / 2; i++)
    {
        if (copy->n != end->n)
            is_pali = 0;

        hold = end->next;
        end->next = prev;
        prev = end;
        end = hold;

        copy = copy->next;
    }
    return (is_pali);
}
