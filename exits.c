#include "shell.h"

/**
 * *_strncpy - it copies a string
 * @dest: the destination of a string to be copied to
 * @src: its the source of the string
 * @n: the amount of characters to be copied
 * Return: the concatenated string
 */

char *_strncpy(char *dest, char *src, int n)

{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
	dest[i] = src[i];
i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 * *_strncat - it concatenates two strings
 * @dest: its the first string
 * @src: its the second string
 * @n: its the amount of bytes to be maximally used
 * Return: the concatenated string
 */

char *_strncat(char *dest, char *src, int n)

{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
	{
		dest[i] = '\0';
	}

	return (s);
}

/**
 * *_strchr - it locates a character in a string
 * @s: its the string to be parsed
 * @c: its the character to be look for
 * Retrun: (s) a pointer to the memory area s
 */

char *_strchr(char *s, char c)

{
	do 
	{
		if (*s == c)
			return (s);
	}
	while (*s++ != '\0');

	return (NULL);
}
