#include <stdio.h>
#include <stdlib.h>
#include "lists.h"


/**
 * is_palindrome - Check if linked list is palindrome
 * @head: double pointer to head of list
 * Return: 0 if False, 1 if True
 */
int is_palindrome(listint_t **head)
{
    listint_t *rev, *prev = NULL, *copy = *head, *hold;
    int size;

    if (!head)
        return (0);
    if (!*head)
        return (1);

    for (size = 0; copy; size++)
    {
        rev = malloc(sizeof(listint_t));
        if (!rev)
            return (0);
        rev->n = copy->n;
        rev->next = prev;
        prev = rev;
        copy = copy->next;
    }

    hold = rev;
    copy = *head;
    size /= 2;

    for (; size; size--)
    {
        if (rev && copy && rev->n != copy->n)
        {
            free_listint(hold);
            return (0);
        }
        else
        {
            rev = rev->next;
            copy = copy->next;
        }
    }
    free_listint(hold);
    return (1);
}
