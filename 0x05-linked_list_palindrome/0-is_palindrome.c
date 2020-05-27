#include <stddef.h>
#include "lists.h"


/**
 * is_palindrome - Check if linked list is palindrome
 * @head: double pointer to head of list
 * Return: 0 if False, 1 if True
 */
int is_palindrome(listint_t **head)
{
    listint_t *copy = *head, *end, *prev, *hold;
    int size, i;

    if (!head)
        return (0);
    if (!*head)
        return (1);

    for (size = 0; copy; size++)
        copy = copy->next;

    copy = *head;
    
    for (i = 0; i < size; i++)
    {
        hold = copy->next;
        if (i > size / 2)
            copy->next = prev; 
        prev = copy;
        if (hold)
            copy = hold;
    }
    end = copy;
    copy = *head;
    prev = NULL;
    for (i = 0; i < size / 2; i++)
    {
        if (copy->n != end->n)
            return (0);
        hold = end->next;
        end->next = prev;
        prev = end;
        end = hold;

        copy = copy->next;
    }
    return (1);
}
