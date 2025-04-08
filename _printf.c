#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    const char *ptr = format;

    if (!format)
        return (-1);

    va_start(args, format);

    while (*ptr)
    {
        if (*ptr == '%')
        {
            ptr++;
            if (!*ptr)
                break;

            if (*ptr == 'c')
            {
                char c = va_arg(args, int);
                count += _putchar(c);
            }
            else if (*ptr == 's')
            {
                char *str = va_arg(args, char *);
                if (!str)
                    str = "(null)";
                while (*str)
                    count += _putchar(*str++);
            }
            else if (*ptr == '%')
            {
                count += _putchar('%');
            }
            else
            {
                count += _putchar('%');
                count += _putchar(*ptr);
            }
        }
        else
        {
            count += _putchar(*ptr);
        }
        ptr++;
    }

    va_end(args);
    return count;
}
