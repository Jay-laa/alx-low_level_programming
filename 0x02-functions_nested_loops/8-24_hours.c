#include "main.h"
/**
 * jack_bauer - prints every minute of the day of Jack Bauer,
 * starting from 00:00 to 23:59
 */
void jack_bauer(void)
{
	int i = 0, j = 23, i2 = 0, j2 = 59;

	while (i <= j)
	{
		while (i2 <= j2)
		{
			_putchar(i < 9 ? 0 + '0' : i / 10 + '0');
			_putchar(i < 9 ? i + '0' : i % 10 + '0');
			_putchar(':');
			_putchar(i2 < 9 ? 0 + '0' : i2 / 10 + '0');
			_putchar(i2 < 9 ? i2 + '0' : i2 % 10 + '0');
			_putchar('\n');
			i2++;
		}
		i2 = 0;
		i++;
	}
}
