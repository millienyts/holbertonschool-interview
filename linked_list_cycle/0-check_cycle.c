#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it.
 * @list: ptr head of list
 * Return: 0 if no cycle, 1 if cycle
 */
int check_cycle(listint_t *list)
{

	listint_t *head, *tails = list;

	if (!list)
		return (0);

	head = list->next;

	while (head)
	{
		if (head->next)
			head = head->next->next;
		else
			head = head->next;

		tails = tails->next;

		if (head == tails)
			return (1);
	}
	return (0);
}
