#include "main.h"
#include <stdio.h>

/**
 * print_binary - prints the binary representation of a number
 * @n: unsigned long int to convert to binary
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
	int i;
	int printed = 0; /* flag to track if 1 bit has been printed */
	unsigned long int mask = 1;

	/* Find the most significant bit position */
	for (i = 63; i >= 0; i--)
	{
		if ((n >> i) & mask)
		{
			_putchar('1');
			printed = 1; /* Set flag to indicate 1 bit has been printed */
		}

		else if (printed)
		{
			_putchar('0');
		}
	}

	/* If no 1 bits were printed, print a single 0 */
	if (!printed)
	{
		_putchar('0');
	}
}
