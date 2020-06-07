#include "lists.h"
#include <stddef.h>
#include <stdio.h>

/**
 * check_cycle - Check if linked list has a cycle
 * @list: list to check
 * 
 * Return: 1 if it does have a cycle or 0 if not
 */
int check_cycle(listint_t *list)
{
    listint_t *hare, *turtle = list;

    if (list == NULL)
        return (0);
    hare = list->next;

    while (hare != NULL)
    {
        if (hare == turtle)
            return (1);
        if (hare->next)
            hare = hare->next->next;
        else
            hare = hare->next;
        turtle = turtle->next;
    }
    return (0);
}
