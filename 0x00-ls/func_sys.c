#include "headers/principal.h"


/**
 * file_perms - Get file permissions
 * @filemode: (mode_t) File mode of the file
 *
 * Return: (char *) String with the permissions
 */
char *file_perms(mode_t filemode)
{
	static char permissions[11];

	sprintf(permissions, "%c%c%c%c%c%c%c%c%c",/* User */
		(filemode & S_IRUSR) ? 'r' : '-',
		(filemode & S_IWUSR) ? 'w' : '-',
		(filemode & S_IXUSR) ? 'x' : '-',
		/* Group Perms --> */
		(filemode & S_IRGRP) ? 'r' : '-',
		(filemode & S_IWGRP) ? 'w' : '-',
		(filemode & S_IXGRP) ? 'x' : '-',
		/* Other Perms --> */
		(filemode & S_IROTH) ? 'r' : '-',
		(filemode & S_IWOTH) ? 'w' : '-',
		(filemode & S_IXOTH) ? 'x' : '-');

	return (permissions);
}


/**
 * type_file - Find mode and permissions of a file
 * @filemode: (mode_t) File mode of the file
 *
 * Return: (int) Letter of the type of file or ?
 *         or ? if not is none
 */
int type_file(mode_t filemode)
{
	int letter = 63;
	/* Detect File-type */
	if (S_ISREG(filemode))
		letter = 45;
	if (S_ISDIR(filemode))
		letter = 100;
	if (S_ISCHR(filemode))
		letter = 99;
	if (S_ISBLK(filemode))
		letter = 98;
	if (S_ISFIFO(filemode))
		letter = 112;
	if (S_ISSOCK(filemode))
		letter = 115;

	return (letter);
}



/**
 * status_stream - Take the info of the file
 * @err_h: (errorPtr *) Head node of the errors
 * @path_name_s: (char *) Name of the path associate at the error
 * @buff: (struct stat *) Store the info of the file
 *
 * Return: (int) Success or Failure
 */
int status_stream(errorPtr *err_h, char *path_name_s, struct stat *buff)
{
	/* Read Info About the File  */
	if (lstat(path_name_s, buff) == -1)
	{
		/* Add error at the current name */
		/* EX: [FOLDER]/[FILE] --> not exist */
		/*	    ---------------          */
		add_error(err_h, path_name_s);
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);

}
