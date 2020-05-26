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
    listint_t *rev, *prev = NULL, *copy = *head;
    int size;

    if (!head || !*head)
        return (0);

    for (size = 0; copy; size++)
    {
        rev = malloc(sizeof(listint_t));
        rev->n = copy->n;
        rev->next = prev;
        prev = rev;
        copy = copy->next;
    }
    
    copy = *head;
    size /= 2;

    for (; size; size--)
    {
        if (rev && copy && rev->n != copy->n)
            return (0);
        else
        {
            rev = rev->next;
            copy = copy->next;
        }
    }
    return (1);
}
