#include "main.h"

/**
 * print_a_stringS - print any given string
 * @args: a list of variadic argument
 *
 * Return: length of the string
 */

int print_a_stringS(va_list args)
{
	int i = 0, j = 0;
	char *str = va_arg(args, char *);

	if (str != NULL)
	{
		while (str[i])
		{
			if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
			{
				_putchar('\\');
				_putchar('x');
				if (str[i] == 10 || (str[i] >= 1 && str[i] <= 9))
					_putchar('0');
				_recursion_int_heX(str[i], 16);
				j += 3;
			}
			else
				_putchar(str[i]);
			i++;
		}
		return (i + j);
	}
	_putchar('(');
	_putchar('n');
	_putchar('u');
	_putchar('l');
	_putchar('l');
	_putchar(')');

	return (6);
}

/**
 * print_reverse - prints a string in reverse
 * @args: list of variadic argument
 *
 * Return: the number of character printed in reverse
 */

int print_reverse(va_list args)
{
	int counter = 0, i = 0;
	char *s = va_arg(args, char *);
	char *str = "(nil)";

	if (s == NULL)
	{
		while (str)
			_putchar(*str);
	}

	while (s[i] != 0)
	{
		counter++;
		i++;
	}
	_print_rev_recursion(s);

	return (counter);
}

/**
 * _print_rev_recursion - prints a string in reverse
 * @s: pointer the giving string
 */

void _print_rev_recursion(char *s)
{
	if (*s == 0)
	{
		return;
	}
	_print_rev_recursion(s + 1);
	_putchar(*s);
}
