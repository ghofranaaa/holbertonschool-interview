#include "holberton.h"
#include <stdlib.h>

/**
 * is_digit - checks if a string contains only digits
 * @s: string
 * Return: 1 if all digits, 0 otherwise
 */
int is_digit(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * _strlen - returns string length
 * @s: string
 * Return: length
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

/**
 * errors - prints error and exits with 98
 */
void errors(void)
{
	char *err = "Error\n";
	int i;

	for (i = 0; err[i]; i++)
		_putchar(err[i]);
	exit(98);
}

/**
 * multiply - performs multiplication of two numbers as strings
 * @s1: first number string
 * @s2: second number string
 */
void multiply(char *s1, char *s2)
{
	int len1, len2, len, i, carry, n1, n2, *res, a = 0;

	len1 = _strlen(s1);
	len2 = _strlen(s2);
	len = len1 + len2;
	res = malloc(sizeof(int) * len);
	if (!res)
		exit(98);
	for (i = 0; i < len; i++)
		res[i] = 0;

	for (len1 = len1 - 1; len1 >= 0; len1--)
	{
		n1 = s1[len1] - '0';
		carry = 0;
		for (len2 = _strlen(s2) - 1; len2 >= 0; len2--)
		{
			n2 = s2[len2] - '0';
			carry += res[len1 + len2 + 1] + (n1 * n2);
			res[len1 + len2 + 1] = carry % 10;
			carry /= 10;
		}
		if (carry > 0)
			res[len1 + len2 + 1] += carry;
	}

	for (i = 0; i < len; i++)
	{
		if (!(res[i] == 0 && a == 0))
		{
			_putchar(res[i] + '0');
			a = 1;
		}
	}
	if (a == 0)
		_putchar('0');
	_putchar('\n');
	free(res);
}

/**
 * main - multiplies two positive numbers
 * @argc: number of args
 * @argv: array of args
 * Return: 0 always
 */
int main(int argc, char *argv[])
{
	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
		errors();

	multiply(argv[1], argv[2]);
	return (0);
}
