/*
 * File: 0-print_list.c
 * Auth: Joy Emojorho
 */

#include "lists.h"
#include <stdio.h>

/**
 * print_list - Prints all the elements of a list_t list.
 * @h: The list_t list.
 *
 * Return: The number of nodes in h.
 */
size_t print_list(const list_t *h)
{
	size_t nodes = 0;

	if (h == NULL) /* Check for a NULL input pointer */
	{
		printf("Error: NULL pointer passed as argument\n");
		return (nodes);
	}

	while (h)
	{
	if (h->str == NULL)
		printf("[0] (nil)\n");
	else
		printf("[%d] %s\n", h->len, h->str);

	nodes++;
	h = h->next;
	}

	return (nodes);
}
