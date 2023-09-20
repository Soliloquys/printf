#include "main.h"

/**
 * handle_specifier - Handle format specifiers in printf
 * @specifier: The format specifier character
 * @list: The va_list containing the arguments
 *
 * Return: Number of characters printed (excluding null terminator).
 */
int handle_specifier(char specifier, va_list list)
{
	int printed_chars = 0;

	switch (specifier)
	{
		case 'c':
		{
			char c = va_arg(list, int);

			_putchar(c);
			return (1);
		}

		case 's':
		{
			char *str = va_arg(list, char *);

			if (str != NULL)
			{
				while (*str)
				{
					_putchar(*str);
					str++;
					printed_chars++;
				}
				return (printed_chars);
			}
			return (0);
		}

		default:
			_putchar('%');
			_putchar(specifier);
			return (2);
	}
}

