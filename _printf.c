#include "main.h"

/**
 * _printf - Printf function
 * @format: format string.
 * Return: Number of characters printed (excluding null terminator).
 */
int _printf(const char *format, ...)
{
    if (format == NULL)
        return (-1);

    va_list list;
    int printed_chars = 0;

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
                break; // End of string, exit loop

            printed_chars += handle_specifier(*format, list); // Use the function from the external file
        }

        format++; // Move to the next character in the format string
    }

    va_end(list);

    return (printed_chars);
}

