#include "main.h"

/**
 * unsigned_integer - prints unsigned integers
 * @args: list of the variadic arguments
 *
 * Return: a count of the number printed
 */

int unsigned_integer(va_list args)
{
	unsigned int num;

	num = va_arg(args, unsigned int);

	if (num == 0)
		return (print_unsigned_integer(num));
	if (num < 1)
		return (-1);
	return (print_unsigned_integer(num));
}


/**
 * print_unsigned_integer - print any given integer
 * @n: number to be printed
 *
 * Return: the number the length of digits printed
 */

int print_unsigned_integer(unsigned int n)
{
	unsigned int num;
	int count = 1;

	num = n;

	while (num > 9)
	{
		num = num / 10;
		count++;
	}

	_recursion_integer(n);
	return (count);
}

/**
 * _print_int_binary - Prints a int converted to binary
 * @args: A list of variadic arguments
 *
 * Return: The number of printed digits
 */
int _print_int_binary(va_list args)
{
	unsigned int n = 0, num;
	int num_digit = 0;

	num = va_arg(args, unsigned int);
	n = num;

	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);

	while (n > 0)
	{
		n = n / 2;
		num_digit++;
	}
	_recursion_int_binary(num);
	return (num_digit);
}

/**
 * _recursion_int_binary - Prints a binary
 * @a:integer to print
 */
void _recursion_int_binary(unsigned int a)
{
	unsigned int t;

	t = a;
	if (t / 2)
		_recursion_int_binary(t / 2);
	_putchar(t % 2 + '0');
}
