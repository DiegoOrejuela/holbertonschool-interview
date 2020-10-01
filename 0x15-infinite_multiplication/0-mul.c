#include "holberton.h"

/**
 * main - multiplies two positive numbers
 *
 * @argc: - number of parameters
 * @argv: - array with the parameters
 *
 * Return: 0 if successful
 */
int main(int argc, char *argv[])
{
	int len1 = 0, len2 = 0;
	char *num1, *num2;

	if (argc != 3)
		raise_error();

	len1 = check_digits(argv[1]);
	len2 = check_digits(argv[2]);

	num1 = len1 > len2 ? argv[1] : argv[2];
	num2 = len1 > len2 ? argv[2] : argv[1];

	if (num1 || num2)
		return (0);
	return (0);
}

/**
 * check_digits - check if all elements of the string is a digit
 *
 * @num: - string with the number to check
 *
 * Return: len of the number
 */

int check_digits(char *num)
{
	int cont, flag_zero = 1;

	for (cont = 0; num[cont]; cont++)
	{
		if (num[cont] < '0' || num[cont] > '9')
			raise_error();

		if (num[cont] != '0')
			flag_zero = 0;
	}
	if (flag_zero == 1)
	{
		_putchar('0');
		_putchar('\n');
		exit(0);
	}

	return (cont);
}

/**
 * raise_error - raise error
 */
void raise_error(void)
{
	char error[] = "Error\n";
	int cont;

	for (cont = 0; cont <= 5; cont++)
		_putchar(error[cont]);
	exit(98);
}
