#include "main.h"

/**
 * _printf - Printf function
 * @format: format string.
 * Return: Number of characters printed (excluding null terminator).
 */
int _printf(const char *format, ...)
{
	va_list list;
	int printed_chars = 0;

	if (format == NULL)
		return (-1);

	va_start(list, format);

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
			else
			{
				printed_chars += handle_specifier(*format, list);
			}
		}

		format++;
	}

	va_end(list);

	return (printed_chars);
}

