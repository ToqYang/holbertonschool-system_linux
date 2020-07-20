#include "headers/principal.h"


/**
 * command_ls - main of the command
 *
 * Return: Succes or Failure
 */
int command_ls(void)
{
	filesPtr files = NULL;
	dirfilesPtr dir_files = NULL;
	namedirPtr dir_names = NULL;
	errorPtr errors = NULL;
	flags flag_current;

	int thereflags = is_flags();

	if (thereflags != 1)
	{
		opt_flags(&flag_current);
		printf("There flags");
	}

	files_stream(&files, &dir_files, &dir_names, &errors);
	print_error(errors);
	print_files(files, 0, 0, '\n');
	_putchar('\n');
	print_dirs(dir_files, 0, 0, '\n');
	free_all(&files, &dir_files, &dir_names, &errors);

	return (EXIT_SUCCESS);
}