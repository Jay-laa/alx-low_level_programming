#include "main.h"

/**
 * get_bit - gets the value of a bit at a given index
 * @n: the number to get the bit from
 * @index: the index of the bit to get, starting from 0
 *
 * Return: the value of the bit at the given index, or -1 if an error occurs
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index > 63)
		return (-1);

	unsigned long int mask = 1UL << index;

	if (n & mask)
		return (1);
	else
		return (0);
}
