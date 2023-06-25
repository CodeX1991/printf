#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct format_type - a format type structure
 * @spec: pointer to the specifier character
 * @f: a pointer function
 *
 * Description: creating the structure of the format type
 * and the corresponding pointer function
 */

typedef struct format_type
{
	char *spec;
	int (*f)(va_list args);
} spc_dt;

int _validate_format(char format);
int _putchar(char c);
int _print_invalid_spec(char prev_format, char format, int count);
int _print_spec(char format, va_list args);
int _print_format(const char *format, va_list args);
int print_a_char(va_list args);
int print_an_integer(va_list args);
int print_a_string(va_list args);
int print_int_binary(va_list args);
int _printf(const char *format, ...);
void _recursion_integer(int num);

#endif /* MAIN_H isdef */
