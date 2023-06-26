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
