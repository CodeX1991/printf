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

/**
 * print_an_address - print any given address
 * @args: a list of variadic argument
 *
 * Return: length of the address
 */

int print_an_address(va_list args)
{
	int i = 0, n;
	char *str = "(nil)";
	void *p;
	unsigned long int holder;

	p = va_arg(args, void*);

	if (str == NULL)
	{
		while (str[i])
		{
			_putchar(str[i]);
			i++;
		}
		return (i);
	}

	holder = (unsigned long int)p;
	_putchar('0');
	_putchar('x');
	n = print_hex(holder);

	return (n + 2);
}

/**
 * print_hex - Prints a int converted to lowercase hex
 * @num: A list of variadic arguments
 *
 * Return: The number of printed digits
 */
int print_hex(unsigned long int num)
{
	int num_digit = 0, i;
	long int *array;
	unsigned long int buffer = num;

	while (num / 16 != 0)
	{
		num /= 16;
		num_digit++;
	}

	num_digit++;

	array = malloc(num_digit * sizeof(long int));
	if (array == NULL)
		return (-1);
	for (i = 0; i < num_digit; i++)
	{
		array[i] = buffer % 16;
		buffer /= 16;
	}
	for (i = num_digit - 1; i >= 0; i--)
	{
		if (array[i] > 9)
			array[i] = array[i] + 39;
		_putchar(array[i] + '0');
	}

	free(array);
	return (num_digit);
}
