#include "lists.h"

/**
 * print_listint - prints all the elements of a struct list type listint_t
 *
 * @h: pointer to the head/first member of a singly linked list of structs
 * of type listint_s
 *
 * Return: amount of nodes in the list
 */

size_t print_listint(const listint_t *h)
{
	size_t count = 1;

	if (h)
	{
		printf("%i\n", h->n);

		if (h->next)
			count += print_listint(h->next);

		return (count);
	}
	else
		return (0);
}
