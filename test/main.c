#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len, len2;

	len = _printf("%u", 1024);
	len2 = printf("%u", 1024);
	printf("\n");
	printf("%d %d\n", len, len2);
	fflush(stdout);
	if (len != len2)
	{
		printf("lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}
