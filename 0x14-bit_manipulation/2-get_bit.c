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
	unsigned long int bit_mask;
	int bit_value;

	if (index > 63)
		return (-1);
	bit_mask = 1UL << index;
	bit_value = (n & bit_mask) ? 1 : 0;
	return (bit_value);
}
