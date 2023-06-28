#include "main.h"

/**
 * _print_format - prints the format
 * @format: pointer to the format to be printed
 * @args: a list of variadic argument
 *
 * Return: count of the character supplied
 */

int _print_format(const char *format, va_list args)
{
	int count = 0;
	int i = 0;

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			i++;

			while (format[i] == ' ')
				i++;

			if (format[i] == '%')
				count += _putchar(format[i]);

			if (_validate_format(format[i]) == 0)
				count = _print_invalid_spec(format[i - 1], format[i], count);
			else
				count += _print_spec(format[i], args);
		}
		else
			count += _putchar(format[i]);
		i++;
	}
	return (count);
}


/**
 * _validate_format - check for specifier
 * @format_type: the format to be checked
 *
 * Return: 1 if format corresponds otherwise 0
 */

int _validate_format(char format_type)
{
	int i = 0;
	char spec_type[] = {'c', 'i', 'd', 'b', '%', 's', 'u', 'x', 'X', 'o', 'S'};

	while (spec_type[i])
	{
		if (format_type == spec_type[i])
			return (1);
		i++;
	}

	return (0);
}

/**
 * _print_invalid_spec - handle the print if _validate_format fails
 * @prev_format: the previous format value
 * @format: current format value
 * @count: the count of the format value to be printed
 *
 * Return: the current count after print
 */

int _print_invalid_spec(char prev_format, char format, int count)
{
	count += _putchar('%');

	if (prev_format == ' ')
	{
		count += _putchar(' ');
		count += _putchar(format);
	}
	else
		count += _putchar(format);
	return (count);
}

/**
 * _print_spec - handle print if _validate_format passed
 * @format: the specifier to print in place
 * @args: a list of variadic argument
 *
 * Return: length of the argument place in the place of the format
 */

int _print_spec(char format, va_list args)
{
	int i = 0, len = 0;

	spc_dt _types[] = {
		{"c", print_a_char},
		{"i", print_an_integer},
		{"d", print_an_integer},
		{"b", _print_int_binary},
		{"s", print_a_string},
		{"u", unsigned_integer},
		{"x", print_int_hex},
		{"X", print_int_heX},
		{"o", print_int_octal},
		{"S", print_a_stringS},
		{NULL, NULL}
	};

	while (_types[i].spec)
	{
		if (*_types[i].spec == format)
			len = _types[i].f(args);
		i++;
	}
	return (len);
}
