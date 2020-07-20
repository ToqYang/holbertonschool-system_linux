#ifndef MY_FUNC
#define MY_FUNC


/* System Calls */
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

/* To get Group and User Structs */
#include <pwd.h>
#include <grp.h>

/* Standard Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int arguc;
char **arguv;
char **envip;
int dirs;
int files;


/**
 * struct all_flags - Contain flags
 * @colnum: -1
 * @all: -a
 * @almostall: -A
 * @longformat: -l
 * @rev: -r
 * @sort: -S
 * @stime: -t
 * @recursive: -r
 *
 * Description: Flags of the program
 */
struct all_flags
{
	int colnum;
	int all;
	int almostall;
	int longformat;
	int rev;
	int sort;
	int stime;
	int recursive;
};

/**
 * flags - Typedef for allflags
 */
typedef struct all_flags flags;
/**
 * flagsPtr - Typedef for flags *
 */
typedef flags * flagsPtr;


/**
 * struct cfile - Info Files
 * @path: Pointer at the path
 * @namefile: Name of the file
 * @user: User characters
 * @group: Group characters
 * @permissions: Permissions character
 * @dayw: Day of the week EX Sun Mon
 * @month: Month of the week
 * @dayn: Number of the day
 * @year: 2020-1998
 * @hour: 10
 * @min: 20
 * @sec: 10
 * @num_file: # of the file
 * @type_file: EX -d directory
 * @size_file: Measure of the file
 * @id_folder: Id of the folder
 * @prev: Before pointer
 * @next: Next pointer
 *
 * Description: Feature of a file
 */
struct cfile
{
	char *path;
	char *namefile;
	char user[32];
	char group[32];
	char permissions[11];

	/* Time of the file */
	char dayw[4];
	char month[4];
	char dayn[4];
	char year[5];

	char hour[3];
	char min[3];
	char sec[3];

	int num_file;
	int type_file;
	long long size_file;

	int id_folder;

	struct cfile *prev;
	struct cfile *next;
};

/**
 * file - Typedef of a cfile to file
 */
typedef struct cfile file;
/**
 * dir_files - Typedef of a cfile to dir
 */
typedef struct cfile dir_files;


/**
 * filesPtr - Typedef of file to a filesPtr
 */
typedef file * filesPtr;

/**
 * dirfilesPtr - Typedef of dir_files to a dirfilesPtr
 */
typedef dir_files * dirfilesPtr;

/**
 * p_files - Typedef of file to p_files *
 */
typedef file * p_files;
/**
 * f_files - Typedef of file to f_files *
 */
typedef file * f_files;


/**
 * struct name_directory - Name dir
 * @name_folder: Name of the folder
 * @next: After ptr at the same struct
 *
 * Description: Contain the names of the directory
 */
struct name_directory
{
	char *name_folder;
	struct name_directory *next;
};

/**
 * name_dir - Typedef of name_directory of the name_dir
 */
typedef struct name_directory name_dir;
/**
 * namedirPtr - Typedef of name_dir of the namedirPtr
 */
typedef name_dir * namedirPtr;


/**
 * struct message_errors - Name of the errors
 * @message_error: Name of the message error
 * @next: After ptr at the same struct
 *
 * Description: Contain of the print of the message errors
 */
struct message_errors
{
	char *message_error;
	struct message_errors *next;
};

/**
 * m_errors - Typedef of message errors
 */
typedef struct message_errors m_errors;
/**
 * errorPtr - Typedef of message errors ptr
 */
typedef m_errors * errorPtr;


/* Functionalities */
int command_ls(void);
int print_name(char *filename, int mode);
int is_flags(void);


/* Functionalities System */
char *file_perms(mode_t filemode);
int type_file(mode_t filemode);
int status_stream(errorPtr *err_h, char *path_name_s, struct stat *buff);

/* Files Functionality */
int is_flags(void);
int opt_flags(flagsPtr cflags);
int _getopt(const char *optstring);


/* 1-Strings Standard */
int _strlen(char *s);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
char *_memset(char *s, char b, unsigned int n);
int _putchar(char c);

/* 2-Strings Standard */
int _strcmp(char *s1, char *s2);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_strncpyn(char *dest, char *src, int start, int end);

/* 1-My strings */
char *strcopyfrom(char *dest, const char *src, size_t n);
char *concatenate_path(char *dirpath, char *filename);
int found_char(char *src, char cmp);
char *cut_string_after(char *src, char cmp);
char *cut_string_before(char *src, char cmp);

/* Errors Nodes */
errorPtr add_error(errorPtr *head, char *name_stream);

/* Directory Nodes dir_functions */
dirfilesPtr add_node_files(dirfilesPtr *head, char *path, int *id_folder,
			   struct stat *inf, struct dirent *rd);
void cpy_files_dirs(dirfilesPtr c_node, char *path, int *id_fol,
		    struct stat *status, struct dirent *r_files);
namedirPtr insert_node_dir(namedirPtr *head, char *dir);

/* file_functions Files nodes */
filesPtr add_nfiles(filesPtr *head, char *path, int *id_folder,
		    struct stat *inf, struct dirent *rd);
void cpy_fil(filesPtr c_node, char *path, int *id_fol, struct stat *status,
	     struct dirent *r_files);


/* Files handling and cut code */
int files_stream(filesPtr *files_h, dirfilesPtr *dir_files_h,
		 namedirPtr *dir_names_h, errorPtr *errors_h);
int files_str(filesPtr *f_head, errorPtr *e_head, char *file);
void curr_dir_files(DIR *directory, dirfilesPtr *dir_files_head,
		    char *name_fold, errorPtr *error_head);
void files_cut(DIR *my_files, char *name_f, char *name_fd,
	       filesPtr *files_head, errorPtr *e_hd);


/* Free Nodes */
int free_all(f_files *h_f, dirfilesPtr *h_df, namedirPtr *h_d, errorPtr *h_er);
void freen_files(f_files head);
void freen_dirs(namedirPtr head);
int freen_errs(errorPtr head);

/* Print */
int print_dirs(p_files h, int mode, int filter, char delim);
int print_files(p_files h, int mode, int filter, char delim);
int print_error(errorPtr h);

#endif
