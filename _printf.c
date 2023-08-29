#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - produces out put according to a format
 * @format: is a character string
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	int count = 0;
	char *s;
	va_list args;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					putchar(va_arg(args, int));
					count++;
					break;
				case 's':
					s = va_arg(args, char *);

					while (*s != '\0')
					{
						putchar(*s);
						s++;
						count++;
					} break;
				case '%':
						putchar('%');
						count++;
						break;
				default:
				break;
			}
		} else
		{
			putchar(*format);
			count++;
		} format++;
	}
va_end(args);
	return (count);
}
