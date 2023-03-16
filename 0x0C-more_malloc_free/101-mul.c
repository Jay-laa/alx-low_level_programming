#include "main.h"
#include <stdio.h>
#include <stdlib.h>

#define ERR_MSG "Error"

/**
 * _isdigit - checks for a digit (0 through 9)
 * @c: character to be checked
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: string to be measured
 *
 * Return: length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*(s + i))
		i++;

	return (i);
}

/**
 * print_error - prints Error, followed by a new line, to standard error
 *
 * Return: void
 */
void print_error(void)
{
	int i = 0;
	char *error = "Error\n";

	while (*(error + i))
	{
		_putchar(*(error + i));
		i++;
	}
}

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments passed to the program
 * @argv: array of arguments
 *
 * Return: 0 if successful, 98 if an error occurs
 */
int main(int argc, char **argv)
{
	int i, j, len1, len2, len_res, num1, num2, res_num;
	int *result;

	if (argc != 3)
	{
		print_error();
		exit(98);
	}
	for (i = 1; i < argc; i++)
		for (j = 0; *(*(argv + i) + j); j++)
			if (!_isdigit(*(*(argv + i) + j)))
			{
				print_error();
				exit(98);
			}
	len1 = _strlen(*(argv + 1)), len2 = _strlen(*(argv + 2));
	len_res = len1 + len2;
	result = calloc(len_res, sizeof(int));
	if (!result)
		return (1);
	for (i = len1 - 1; i >= 0; i--)
	{
		num1 = *(*(argv + 1) + i) - '0';
		res_num = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			num2 = *(*(argv + 2) + j) - '0';
			res_num = *(result + i + j + 1) + (num1 * num2);
			*(result + i + j + 1) = res_num % 10;
			*(result + i + j) += res_num / 10;
		}
	}
	for (i = 0; i < len_res - 1 && !*(result + i); i++)
		;
	for (; i < len_res; i++)
		_putchar(*(result + i) + '0');
	_putchar('\n');
	free(result);
	return (0);
}
