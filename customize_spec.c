#include "main.h"

/**
 * print_a_stringS - print any given string
 * @args: a list of variadic argument
 *
 * Return: length of the string
 */

int print_a_stringS(va_list args)
{
	int i = 0;
	char *str = va_arg(args, char *);

	if (str != NULL)
	{
		while (str[i])
		{
			if (str[i] > 0 && str[i] < 32)
			{
				_putchar('\\');
				_putchar('x');
				_putchar('0');
				_recursion_int_heX(str[i], 16);
			}
			else
				_putchar(str[i]);
			i++;
		}
		return (i);
	}
	_putchar('(');
	_putchar('n');
	_putchar('u');
	_putchar('l');
	_putchar('l');
	_putchar(')');

	return (6);
}
