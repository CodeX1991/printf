#include "main.h"

/**
 * print_int_octal - Prints a int converted to octal
 * @args: A list of variadic arguments
 *
 * Return: The number of printed digits
 */
int print_int_octal(va_list args)
{
	unsigned int n = 0, num;
	int num_digit = 0;

	num = va_arg(args, unsigned int);
	n = num;

	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);

	num_digit = base_len(n, 8);
	_recursion_int_base(num, 8);

	return (num_digit);
}

/**
 * print_int_hex - Prints a int converted to lowercase hex
 * @args: A list of variadic arguments
 *
 * Return: The number of printed digits
 */
int print_int_hex(va_list args)
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
	_recursion_int_base(num, 16);

	return (num_digit);
}

/**
 * _recursion_int_base - Prints a binary
 * @a:integer to print
 * @base: the given base to convert to
 */
void _recursion_int_base(unsigned int a, int base)
{
	unsigned int t, rem;

	t = a;
	if (t / base)
		_recursion_int_base(t / base, base);

	rem = t % base;

	if (rem > 9)
		_putchar(check_hex(rem, 'x'));
	else
		_putchar(rem + '0');
}

/**
 * check_hex - check which hex function is called
 * @num: number to convert into letter
 * @x: inform the hex function called
 * Return: the ASCII value for a letter
 */

int check_hex(unsigned int num, char x)
{
	char *hex = "abcdef";
	char *Hex = "ABCDEF";

	num = num - 10;
	if (x == 'x')
		return (hex[num]);
	else
		return (Hex[num]);
	return (0);
}

/**
 * base_len - count the length of a base number
 * @num: the number to calculate its count
 * @base: the given base
 *
 * Return: the length of the base
 */
int base_len(unsigned int num, int base)
{
	int i;

	for (i = 0; num > 0; i++)
		num = num / base;
	return (i);
}
