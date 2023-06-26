#include "main.h"

/**
 * print_a_char - print a character
 * @args: list of variadic argument
 *
 * Return: 1 on success
 */

int print_a_char(va_list args)
{
	_putchar(va_arg(args, int));

	return (1);
}

/**
 * print_an_integer - print any given integer
 * @args: list of variadic argument
 *
 * Return: the number the length of digits printed
 */

int print_an_integer(va_list args)
{
	unsigned int n;
	int num, count = 1;

	n = va_arg(args, int);
	num = n;

	if (num < 0)
	{
		_putchar('-');
		num = -num;
		n = num;
		count++;
	}

	while (n > 9)
	{
		n = n / 10;
		count++;
	}

	_recursion_integer(num);
	return (count);
}

/**
 * _recursion_integer - prints a given integer
 * @num: the given number
 */

void _recursion_integer(int num)
{
	unsigned int t;

	t = num;
	if (t / 10)
		_recursion_integer(t / 10);
	_putchar((t % 10) + '0');
}
/**
 * print_a_string - print any given string
 * @args: a list of variadic argument
 *
 * Return: length of the string
 */

int print_a_string(va_list args)
{
	int i = 0;
	char *str = va_arg(args, char *);

	if (str != NULL)
	{
		while (str[i])
		{
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
