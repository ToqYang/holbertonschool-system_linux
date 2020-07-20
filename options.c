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

	while (dir_files != NULL)
	{
		if (dir_files->namefile[0] != '.')
		{
			if (flag_current.colnum == 1)
			{
				fprintf(stdout, "%s\n", dir_files->namefile);
			}
			else
			{
				fprintf(stdout, "%s ", dir_files->namefile);
			}
		}
		
		dir_files = dir_files->next;
	}
	printf("\n");

	free_all(&files, &dir_files, &dir_names, &errors);

	return (EXIT_SUCCESS);
}