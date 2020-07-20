#include "headers/principal.h"


/**
 * add_nfiles - Add node with the features of the file
 * @head: (filesPtr *) Head of the dirs file
 * @path: (char *) Path of the filename
 * @id_folder: (int) Id associated at the folder
 * @inf: (struct stat *) Info associate at the status of the file
 * @rd: (struct dirent *) Read Folder
 *
 * Return: (filesPtr) Current node
 */
filesPtr add_nfiles(filesPtr *head, char *path, int *id_folder,
		    struct stat *inf, struct dirent *rd)
{
	filesPtr new_file = malloc(sizeof(file));

	if (!new_file)
		return (NULL);

	/* Copy Info Curent File */
	cpy_files_dirs(new_file, path, id_folder, inf, rd);

	filesPtr last = *head;

	/* If the Head is None */
	if (!(*head))
		*head = new_file;
	else
	{
		/* Position in the Last Valid Position and Paste the New Node */
		while (last->next != NULL)
			last = last->next;

		last->next = new_file;
		new_file->prev = last->next;
	}

	return (new_file);
}


/**
 * cpy_fil - Copy the information found in the directory
 * @c_node: (dirfilesPtr) Current node to pass info
 * @path: Pass the path of the file
 * @id_fol: (int *) Id of the folder
 * @status: (struct stat *) Info associate at the status of the file
 * @r_files: (struct dirent *) Read Folder
 *
 */
void cpy_fil(filesPtr c_node, char *path, int *id_fol,
	     struct stat *status, struct dirent *r_files)
{
	char *time = ctime(&(status->st_mtime));
	/* Assign New Space */
	c_node->path = malloc((_strlen(path) + 1) * sizeof(char));
	c_node->namefile = malloc((_strlen(r_files->d_name) + 1) * sizeof(char));

	if ((c_node->path) && (c_node->namefile))
	{
		struct passwd *users;
		struct group *groups;

		users = getpwuid(status->st_uid);
		groups = getgrgid(status->st_gid);
		/* Update Node With the Info */
		_strcpy(c_node->path, path);
		_strcpy(c_node->namefile, r_files->d_name);
		_strcpy(c_node->user, users->pw_name);

		/* Time */
		_strncpyn(c_node->dayw, time, 0, 3);
		_strncpyn(c_node->month, time, 4, 7);
		_strncpyn(c_node->dayn, time, 8, 10);
		_strncpyn(c_node->hour, time, 11, 13);
		_strncpyn(c_node->min, time, 14, 16);
		_strncpyn(c_node->sec, time, 17, 19);
		_strncpyn(c_node->year, time, 20, 24);


		_strcpy(c_node->group, groups->gr_name);
		_strcpy(c_node->permissions, file_perms(status->st_mode));
		c_node->type_file = type_file(status->st_mode);
		c_node->size_file = (long long)status->st_size;
		c_node->id_folder = *id_fol;
		c_node->prev = NULL;
		c_node->next = NULL;
	}
}
