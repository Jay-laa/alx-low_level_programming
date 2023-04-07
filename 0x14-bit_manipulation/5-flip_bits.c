#include "main.h"

/**
 * flip_bits - returns the number of bits you would need to flip
 * to get from one number to another
 * @n: first number
 * @m: second number
 *
 * Return: number of bits you would need to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int flip = n ^ m;
	unsigned int bit_diff = 0;

	while (flip != 0)
	{
		bit_diff += flip & 1;
		flip >>= 1;
	}

	return (bit_diff);
}
