#include "main.h"
#include <stdio.h>

/**
 * handle_integer - Handle %d and %i specifiers
 * @specifier: The format specifier character ('d' or 'i')
 * @list: The va_list containing the integer argument
 *
 * Return: Number of characters printed.
 */
int handle_integer(char specifier, va_list list)
{
	int printed_chars = 0;
	int value;
	char buffer[20];
	int chars_written;

	if (specifier != 'd' && specifier != 'i')
	{
		/* Not a valid specifier */
		return (0);
	}

	value = va_arg(list, int);
	/* Handle integer formatting and printing */
	/* You can use snprintf for formatting */
	chars_written = snprintf(buffer, sizeof(buffer), "%d", value);
	if (chars_written >= 0)
	{
		int i;

		for (i = 0; i < chars_written; i++)
		{
			_putchar(buffer[i]);
			printed_chars++;
		}
	}
	return (printed_chars);
}

