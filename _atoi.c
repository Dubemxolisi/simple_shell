#include "shell.h"

/**
 * interactive - it returns true if shell is interactive mode
 * @info: struct address
 * Return: 1 if interactive mode, 0 otherwise
 */

int interactive(info_t *info)

{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - it checks if the character is a delimeter
 * @c: the char to check
 * @delim: the delimeter string
 * Return: 1 if it is true and 0 if its false
 */

int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
					return (0);
}

/**
 * _isalpha - it checks for alphabetic character
 * @c: The character to be input
 * Return: 1 if c is an alphabetic, otherwise 0
 */

int _isalpha(int c)

{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}

/**
 * _atoi - it converts a sting into a integer
 * @s: is the string to be converted
 * Retern: 0 if the is no number in the string, otherwise converted the number
 */

int _atoi(char *s)

{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
