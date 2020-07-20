#include "headers/principal.h"


/**
 * add_node_files - Add node with the features of the file
 * @head: (dirfilesPtr *) Head of the dirs file
 * @path: (char *) Path of the filename
 * @id_folder: (int) Id associated at the folder
 * @inf: (struct stat *) Info associate at the status of the file
 *( stat)*
 * @rd: (struct dirent *) Read Folder
 *
 * Return: (dirfilesPtr) Current node
 */
dirfilesPtr add_node_files(dirfilesPtr *head, char *path, int *id_folder,
			   struct stat *inf, struct dirent *rd)
{
	dirfilesPtr dir_newfiles = malloc(sizeof(dir_files));

	if (!dir_newfiles)
		return (NULL);

	/* Copy Info Curent File */
	cpy_files_dirs(dir_newfiles, path, id_folder, inf, rd);

	dirfilesPtr last = *head;

	/* If the Head is None */
	if (!(*head))
		*head = dir_newfiles;
	else
	{
		/* Position in the Last Valid Position and Paste the New Node */
		while (last->next != NULL)
			last = last->next;

		last->next = dir_newfiles;
		dir_newfiles->prev = last->next;
	}

	return (dir_newfiles);
}


/**
 * cpy_files_dirs - Copy the information found in the directory
 * @c_node: (dirfilesPtr) Current node to pass info
 * @path: Pass the path of the file
 * @id_fol: (int *) Id of the folder
 * @status: (struct stat *) Info associate at the status of the file
 * @r_files: (struct dirent *) Read Folder
 *
 */
void cpy_files_dirs(dirfilesPtr c_node, char *path, int *id_fol,
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


/**
 * insert_node_dir - Insert node at the end
 * @head: (namedirPtr) Head the node
 * @dir: (char *) Name of the folder
 *
 * Return: (namedirPtr) Current Node
 */
namedirPtr insert_node_dir(namedirPtr *head, char *dir)
{
	namedirPtr new_dir_names = malloc(sizeof(name_dir));

	if (!new_dir_names)
		return (NULL);

	/* Assign New Space */
	new_dir_names->name_folder = malloc((_strlen(dir) + 1) * sizeof(char));

	if (!new_dir_names)
		return (NULL);

	_strcpy(new_dir_names->name_folder, dir);
	new_dir_names->next = NULL;

	namedirPtr last = *head;

	/* If the Head is None */
	if (!(*head))
	{
		*head = new_dir_names;
		return (new_dir_names);
	}
	/* Position in the Last Valid Position and Paste the New Node */
	while (last->next != NULL)
		last = last->next;

	last->next = new_dir_names;

	return (new_dir_names);
}
