#include "main.h"

/**
 * get_endianness - checks the endianness
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	unsigned int value = 1;
	char *endian = (char *)&value;

	if (*endian == 1)
		return (1);
	return (0);
}
