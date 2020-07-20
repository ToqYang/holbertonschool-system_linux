#include "headers/principal.h"


/**
 * strcopyfrom - Copy a string from a determined char
 * @dest: (char *) Destine to copy directory
 * @src: (char *) Source of the string to be copied
 * @n: (size_t) Number from where it should copied
 *
 * Return: (char *) Final ptr
 */
char *strcopyfrom(char *dest, const char *src, size_t n)
{
	size_t i = 0;

	for (; i < n && src[n] != '\0'; ++i, ++n)
		dest[i] = src[n];

	dest[i] = '\0';
	return (dest);
}


/**
 * concatenate_path - Concatenate Path Directory/Filename
 * @dirpath: (char *) Name of the directory path
 * @filename: (char *) Name of the file to access
 *
 * Return: (char *) Pathnanme of the file
 */
char *concatenate_path(char *dirpath, char *filename)
{
	size_t len1 = 0;
	size_t len2 = 0;
	size_t size = 0;

	len1 = _strlen(dirpath);
	len2 = _strlen(filename);
	size = (len1 + len2 + 1) * sizeof(char);

	char *pathname = malloc(size);

	if (!pathname)
		return (NULL);

	pathname[0] = '\0';
	_strcpy(pathname, dirpath);
	if (dirpath[len1 - 1] != '/')
	{
		_strcat(pathname, "/");
		pathname = _realloc(pathname, size, size + (1 * sizeof(char)));
		if (!pathname)
			return (NULL);
	}
	_strcat(pathname, filename);

	return (pathname);
}


/**
 * found_char - Find if there coincidences with a char
 * @src: (char *) Source to compare
 * @cmp: (char) To compare if there
 *
 * Return: 1 if it found coincidences and
 *         0 if it isn't the found
 */
int found_char(char *src, char cmp)
{
	int len = _strlen(src);

	for (int i = 0; i <= len; ++i)
	{
		if (cmp == src[i])
			return (1);
	}

	return (0);
}


/**
 * cut_string_after - Cut string [HERE]/STRING
 * @src: (char *) Source to compare
 * @cmp: (char) To compare if there
 *
 * Return: 1 if it found coincidences and
 *         0 if it isn't the found
 */
char *cut_string_after(char *src, char cmp)
{
	int len_src = _strlen(src), k = 0, j = 0;
	int len_folder = 0, len_file = 0;

	/* Find idx of the Last Occurrence */
	for (int i = 0; i < len_src; ++i)
	{
		if (cmp == src[i])
			len_folder = i + 1;
	}

	/* Get Len of the File */
	for (int i = len_folder; src[i] != '\0' ; ++i, ++len_file)
		;

	/* Cut string */
	char *new = (char *)malloc((len_file + 1) * sizeof(char));

	if (!new)
		return (NULL);


	/* Copy the File From of the Path */
	for (k = 0, j = len_folder; src[j] != '\0'; ++k, ++j)
		new[k] = src[j];

	new[k] = '\0';

	return (new);
}


/**
 * cut_string_before - Cut string [HERE]/STRING
 * @src: (char *) Source to compare
 * @cmp: (char) To compare if there
 *
 * Return: 1 if it found coincidences and
 *         0 if it isn't the found
 */
char *cut_string_before(char *src, char cmp)
{
	int len_src = _strlen(src);
	int len_folder = 0, j = 0;

	/* Find idx of the Last Occurrence */
	for (int i = 0; i <= len_src; ++i)
	{
		if (cmp == src[i])
			len_folder = i;
	}

	char *new = (char *)malloc((len_folder + 1) * sizeof(char));

	if (!new)
		return (NULL);

	/* Copy Folder Name */
	for (int i = 0; i <= len_folder; ++i, ++j)
		new[i] = src[j];

	new[j] = '\0';

	return (new);
}
