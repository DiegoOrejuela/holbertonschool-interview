/**
 * is_palindrome - Palindrome unsigned integer
 *
 * @n: is the number to be checked
 *
 * Return: return 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long reverse_n[1000];
	int i, j;

	if (n <= 9)
		return (1);

	for (i = 0; (n / 10) != 0; i++)
	{
		reverse_n[i] = (n % 10);
		n /= 10;
	}
	reverse_n[i] = n;

	for (j = 0; i >= 0; i--)
	{
		if (reverse_n[j] != reverse_n[i])
			return (0);
		j++;
	}
	return (1);
}
