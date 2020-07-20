#include "headers/principal.h"


/**
 * _strcmp - Compare two strings
 * @s1: (char *) First s1
 * @s2: (char *) Second s2
 *
 * Return: Integers diference
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	for (i = 0; s1[i] && s2[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return (s1[i] - s2[i]);
}


/**
 * _realloc - Store a new chunk to allocate
 * @ptr: (void *) Store the pointer
 * @old_size: Store the old value
 * @new_size: Store the new size
 * Return: Pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *a;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr != 0)
	{
		free(ptr);
		return (NULL);
	}

	free(ptr);
	a = malloc(new_size);

	return (a);
}


/**
 * _strncpyn - Copy string [START:END]
 * @dest: (char *) Destine
 * @src: (char *) Source
 * @start: (int) Start of the arr
 * @end: (int) Limit of the arr
 *
 * Return: (char *) Destine
 */
char *_strncpyn(char *dest, char *src, int start, int end)
{
	for (int i = 0; start < end; ++i, ++start)
		dest[i] = src[start];

	dest[end] = '\0';

	return (dest);
}
