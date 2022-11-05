#include "sort.h"

/**
 * swap - swap nodes
 * @a: first node
 * @b: second node
 * Return: nothing
 */

void swap(listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}

/**
 * cocktail_sort_list - function that sorts a doubly
 * linked list of integers in ascending order
 * @list: List of integers to be sorted
 * Return: Void
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *curr;
	int swapped = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = *list;
	while (swapped)
	{
		swapped = 0;
		while (curr && curr->next)
		{
			if (curr->n > curr->next->n)
			{
				swap(curr, curr->next);
				if (curr->prev->prev == NULL)
					*list = curr->prev;
				print_list(*list);
				swapped = 1;
			}
			else
				curr = curr->next;
		}
		if (!swapped)
			break;
		swapeed = 0;
		while (curr && curr->prev)
		{
			if (curr->n < curr->prev->n)
			{
				swap(curr->prev, curr);
				if (curr->prev == NULL)
					*list = curr;
				print_list(*list);
				swapped = 1;
			}
			else
				curr = curr->prev;
		}
	}
}
