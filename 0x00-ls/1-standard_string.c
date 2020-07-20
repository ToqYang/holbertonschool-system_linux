#include "headers/principal.h"


/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * _memset - Print the fields of memory with a constant
 * @s: (char *) Array to set
 * @b: (char *) Constant b
 * @n: bytes of the memory area pointed to by s
 *
 * Return: pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	for (unsigned int i = 0; i < n; i++)
		s[i] = b;

	return (s);
}


/**
 * _strcat - Concatenate two strings
 * @dest: (char *) Destination char
 * @src: (char *) Source char
 *
 * Return: (char *) Destine concatenate
 */
char *_strcat(char *dest, const char *src)
{
	size_t i = 0, j = 0;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0'; j++)
		dest[i + j] = src[j];

	dest[i + j] = '\0';

	return (dest);
}


/**
 * _strlen - Retrieve the length
 * @s: (char *) String to count
 *
 * Return: (int) Length of the array
 */
int _strlen(char *s)
{
	int i = 0;

	for (; s[i] != '\0'; i++)
		;

	return (i);
}


/**
 * _strcpy - Copy string to other
 * @dest: (char *) Destine string
 * @src: (char *) Source string
 *
 * Return: (char *) Pinter copied
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (*(src + i))
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';

	return (dest);
}
