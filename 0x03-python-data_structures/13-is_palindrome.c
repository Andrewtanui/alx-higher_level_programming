#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

void reverse_list(listint_t **head);
int compare_lists(listint_t *list1, listint_t *list2);

int is_palindrome(listint_t **head)
{
    listint_t *slow_ptr, *fast_ptr, *prev_slow_ptr;
    listint_t *mid_ptr, *second_half;
    int is_palindrome = 1;

    if (*head == NULL || (*head)->next == NULL)
        return 1;

    slow_ptr = *head;
    fast_ptr = *head;
    prev_slow_ptr = *head;

    while (fast_ptr != NULL && fast_ptr->next != NULL)
    {
        fast_ptr = fast_ptr->next->next;
        prev_slow_ptr = slow_ptr;
        slow_ptr = slow_ptr->next;
    }

    if (fast_ptr != NULL)
    {
        mid_ptr = slow_ptr;
        slow_ptr = slow_ptr->next;
    }

    second_half = slow_ptr;
    prev_slow_ptr->next = NULL;
    reverse_list(&second_half);
    is_palindrome = compare_lists(*head, second_half);
    reverse_list(&second_half);

    if (mid_ptr != NULL)
    {
        prev_slow_ptr->next = mid_ptr;
        mid_ptr->next = second_half;
    }
    else
        prev_slow_ptr->next = second_half;

    return is_palindrome;
}

void reverse_list(listint_t **head)
{
    listint_t *prev = NULL;
    listint_t *current = *head;
    listint_t *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

int compare_lists(listint_t *list1, listint_t *list2)
{
    while (list1 && list2)
    {
        if (list1->n != list2->n)
            return 0;

        list1 = list1->next;
        list2 = list2->next;
    }

    if (list1 == NULL && list2 == NULL)
        return 1;

    return 0;
}
