#include "headers/principal.h"


/**
 * print_name - Show name of a file
 * @filename: (char *) Name of file
 * @mode: (int) Decide of skip . and .. or not
 *
 * Return: (int) Success or Failure
 */
int print_name(char *filename, int mode)
{
	if (mode == 0)
	{
		if (filename[0] != '.')
		{
			fprintf(stdout, "%s", filename);
			return (EXIT_SUCCESS);
		}
	}
	if (mode == 1)
	{
		fprintf(stdout, "%s", filename);
		return (EXIT_SUCCESS);
	}

	return (EXIT_FAILURE);
}


/**
 * is_flags - Look if in the arguments there files
 *
 * Return: (int) Success or Failure
 */
int is_flags(void)
{
	for (int i = 0; i < arguc; ++i)
	{
		if (arguv[i][0] == '-')
			return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}


/**
 * opt_flags - Get and Choose the flags to set
 * @cflags: (flagsPtr) Struct with the flags
 *
 * Return: Exit Success or Failure
 */
int opt_flags(flagsPtr cflags)
{
	int opt = 1;

	while ((opt = _getopt("1aAlrStR")) != -1)
	{
		if (opt == -2)
			return (opt);
		if (opt != 4)
		{
			switch (opt)
			{
				case '1':
					cflags->colnum = 1;
					break;
				case 'a':
					cflags->all = 1;
					break;
				case 'A':
					cflags->almostall = 1;
					break;
				case 'l':
					cflags->longformat = 1;
					break;
				case 'r':
					cflags->rev = 1;
					break;
				case 'S':
					cflags->sort = 1;
					break;
				case 't':
					cflags->stime = 1;
					break;
				case 'R':
					cflags->recursive = 1;
					break;
				case '?':
					fprintf(stderr,
						"Unknown option `-%c'\n", opt);
					break;
			}
		}
	}

	return (EXIT_SUCCESS);
}


/**
 * _getopt - Get the flags of the arguv
 * @optstring: (char *) String with the option to compare
 *
 * Return: (int) If it find coincidences then return the char.
 *         If it can't find coincidences proceed to the next char of the arguv.
 *         If already parsed all argv with opstring
 *         or fail the function return -1
 */
int _getopt(const char *optstring)
{
	static int travel = 1, findstr = 0;
	static char *flags = NULL;
	static int n = 1;

	/* Find the first string with "-" */
	if (findstr == 0)
	{
		while (n < arguc)
		{
			if (arguv[n][0] == '-')
			{
				flags = arguv[n];
				findstr = 1;
				++n;
				break;
			}
			++n;
		}
		if (!findstr)
			return (-2);
	}
	printf("%d %d\n", n, arguc);

	/* Compare coincidences optstring with the flags */
	for (int i = 0; flags[travel] != '\0' && optstring[i]; ++i)
	{
		if (flags[travel] == optstring[i])
		{
			++travel;
			return (optstring[i]);
		}
	}

	/* If parsed all the flags */
	if (flags[travel] == '\0')
	{
		if (n == arguc)
			return (-1);

		findstr = 0;
		travel = 1;
		return (2);
	}

	/* If the flags not are NULLS print ? not find equals */
	++travel;
	return ('?');
}
