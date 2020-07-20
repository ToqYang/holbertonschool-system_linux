#include "headers/principal.h"


/**
 * files_stream - Link the procceses
 * @files_h: (filesPtr *) Head of the node
 * @dir_files_h: (dirfilesPtr *) Head of the node
 * @dir_names_h: (namedirPtr *) Head of the node
 * @errors_h: (errorPtr *) Head of the node
 *
 * Return: Exit or Failure
 */
int files_stream(filesPtr *files_h, dirfilesPtr *dir_files_h,
		 namedirPtr *dir_names_h, errorPtr *errors_h)
{
	dirs = 0, files = 0;
	int i = 0;
	char is_dir[256];

	/* Look If Is ./hls or ./hls [FILE] OR [FOLDER] */
	if (arguc == 1)
		arguv[i] = "./";
	else
		i = 1;

	for (; i < arguc; ++i)
	{
		/* Define Name and Open Folder and it not has / the do */
		char *n_folder = arguv[i];

		_strcpy(is_dir, n_folder);
		_strcat(is_dir, "/");
		DIR *dir = opendir(is_dir);

		if (!dir)
		{
			files_str(files_h, errors_h, n_folder);
			continue;
		}
		else
			n_folder = is_dir;

		/* Insert Name of the Folder */
		insert_node_dir(dir_names_h, n_folder);
		/* Look and Insert Files of Folder */
		curr_dir_files(dir, dir_files_h, n_folder, errors_h);

		if (closedir(dir) == -1)
			return (EXIT_FAILURE);

		++dirs;
		_memset(is_dir, '\0', 256);
	}

	return (EXIT_SUCCESS);
}


/**
 * files_str - Look if is a file
 * @f_head: (filesPtr *) Head of the files
 * @e_head: (errorPtr *) Head of the errors
 * @file: (char *) Name of the file
 *
 * Return: Exit or Failure
 */
int files_str(filesPtr *f_head, errorPtr *e_head, char *file)
{
	char *filename = file, *filefolder = "./";
	DIR *m_file = NULL;
	int initial_files = files, f_slash = 0;

	/* EX: [FILE]: [FOLDER]/[FILE] or ../[FOLDER]/[FILE] */
	f_slash = found_char(file, '/');
	if (f_slash)
	{
		filefolder = cut_string_before(file, '/');
		filename = cut_string_after(file, '/');
		m_file = opendir(filefolder);

		if (!m_file)
			add_error(e_head, file);
	}
	else  /* EX: [FILE] */
	{
		m_file = opendir(filefolder);

		if (!m_file)
			add_error(e_head, file);
	}
	files_cut(m_file, filename, filefolder, f_head, e_head);

	if (f_slash)
	{
		free(filefolder);
		free(filename);
	}
	if (closedir(m_file) == -1)
		return (EXIT_FAILURE);
	/* If not found Coincidences the file doesn't exist */
	if (initial_files == files)
	{
		add_error(e_head, file);
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}


/**
 * curr_dir_files - Look the files in the current dir
 * @directory: (DIR *) Directory current
 * @dir_files_head: (dirfilesPtr *) Head of the directory files
 * @name_fold: (char *) Name of the folder
 * @error_head: (errorPtr *) Head of the errors
 *
 */
void curr_dir_files(DIR *directory, dirfilesPtr *dir_files_head,
		    char *name_fold, errorPtr *error_head)
{
	struct stat buf;
	struct dirent *read;

	while ((read = readdir(directory)) != NULL)
	{
		char *folder_name = concatenate_path(name_fold, read->d_name);

		/* Read Info About the File */
		if ((status_stream(error_head, folder_name, &buf)))
		{
			free(folder_name);
			continue;
		}
		/* Take Information of the File and Add Dir */
		add_node_files(dir_files_head, folder_name, &dirs, &buf, read);
		free(folder_name);
	}
}


/**
 * files_cut - Cut the file
 * @my_files: (DIR) Directory
 * @name_f: (char *) Name file
 * @name_fd: (char *) Name folder
 * @files_head: (char *) Files head
 * @e_hd: (errorPtr *) Head of ther error
 *
 */
void files_cut(DIR *my_files, char *name_f, char *name_fd,
	       filesPtr *files_head, errorPtr *e_hd)
{
	struct dirent *readfiles;
	struct stat info;

	/* Read Directory Default: ./ or filefolder */
	while ((readfiles = readdir(my_files)) != NULL)
	{
		/* Compare with the files of the directory */
		if (!(_strcmp(name_f, readfiles->d_name)))
		{
			char *filepath = concatenate_path(name_fd, name_f);
			/* Look status of the file */
			if ((status_stream(e_hd, filepath, &info)))
			{
				free(filepath);
				continue;
			}
			/* Take Information of the File and Add Dir*/
			add_nfiles(files_head, filepath,
				   &files, &info, readfiles);
			free(filepath);
			++files;
		}
	}
}
