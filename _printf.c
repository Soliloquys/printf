#include "main.h"

/**
 * _printf - Printf function
 * @format: format string.
 * Return: Number of characters printed (excluding null terminator).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			printed_chars++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == '%')
			{
				/* Handle "%%" case */
				_putchar('%');
				printed_chars++;
			}
			else if (*format == 'c' || *format == 's')
			{
				printed_chars += handle_specifier(*format, args);
			}
			else if (*format == 'd' || *format == 'i')
			{
				printed_chars += handle_integer(*format, args);
			}
			else
			{
				_putchar('%');
				_putchar(*format);
				printed_chars += 2;
			}
		}

		format++;
	}

	va_end(args);

	return (printed_chars);
}


