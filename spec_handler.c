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
    switch (specifier)
    {
        case 'c':
        {
            char c = va_arg(list, int);
            putchar(c);
            return 1; // Return the number of characters printed
        }

        case 's':
        {
            char *str = va_arg(list, char *);
            if (str != NULL)
            {
                int printed_chars = 0;
                while (*str)
                {
                    putchar(*str);
                    str++;
                    printed_chars++;
                }
                return printed_chars; // Return the number of characters printed
            }
            return 0; // Return 0 if the string is NULL;
        }

        default:
            // Unsupported format specifier, just print it as is
            putchar('%');
            putchar(specifier);
            return 2; // Return 2 characters printed
    }
}

