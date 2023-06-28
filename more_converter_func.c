#include "main.h"

/**
 * print_int_heX - Prints a int converted to uppercase hex
 * @args: A list of variadic arguments
 *
 * Return: The number of printed digits
 */
int print_int_heX(va_list args)
{
	unsigned int n = 0, num;
	int num_digit = 0;

	num = va_arg(args, unsigned int);
	n = num;

	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);

	num_digit = base_len(n, 16);
	_recursion_int_heX(num, 16);

	return (num_digit);
}

/**
 * _recursion_int_heX - Prints a heX
 * @a:integer to print
 * @base: the given base to convert to
 */
void _recursion_int_heX(unsigned int a, unsigned int base)
{
	unsigned int t, rem;

	t = a;
	if (t / base)
		_recursion_int_heX(t / base, base);
	rem = t % base;

	if (rem > 9)
		_putchar(check_hex(rem, 'X'));
	else
		_putchar(rem + '0');
}
