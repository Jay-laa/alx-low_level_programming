#include "main.h"

/**
 * clear_bit - sets a bit at a given index to 0
 * @n: pointer to the number to change
 * @index: index of the bit to set to 0
 *
 * Return: 1 for success, -1 for failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);
	unsigned long int bit_mask = 1UL << index;
	*n = (*n & ~bit_mask);
	return (1);
}
