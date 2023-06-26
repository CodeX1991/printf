#include "main.h"

/**
 * _printf - customize printf function
 * @format: the character string
 *
 * Return: the length of what is printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int len = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	len = _print_format(format, args);

	va_end(args);

	return (len);
}
