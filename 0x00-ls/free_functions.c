#include "headers/principal.h"


/**
 * free_all - Take all the structs and give a free
 * @h_f: (f_files *) Head node
 * @h_df: (dirfilesPtr *) Head node
 * @h_d: (namedirPtr *) Head node
 * @h_er: (errorPtr *) Head node
 *
 * Return: (int) # Of the errors
 */
int free_all(f_files *h_f, dirfilesPtr *h_df, namedirPtr *h_d, errorPtr *h_er)
{
	int errors = 0;

	freen_files(*h_f);
	freen_files(*h_df);
	freen_dirs(*h_d);
	errors = freen_errs(*h_er);

	return (errors);
}


/**
 * freen_files - Free node od the file
 * @head: (f_files) Head node
 *
 */
void freen_files(f_files head)
{
	f_files del_Node = NULL;

	while (head != NULL)
	{
		del_Node = head->next;

		free(head->path);
		free(head->namefile);
		free(head);
		head = del_Node;
	}
}


/**
 * freen_dirs - Free names and node
 * @head: (namedirPtr) Head node
 *
 */
void freen_dirs(namedirPtr head)
{
	namedirPtr del_Node = NULL;

	while (head != NULL)
	{
		del_Node = head->next;
		free(head->name_folder);
		free(head);
		head = del_Node;
	}
}


/**
 * freen_errs - Free names and node
 * @head: (errorPtr) Head node
 *
 * Return: (int) Quantity of errors
 */
int freen_errs(errorPtr head)
{
	int err = 0;
	errorPtr del_Node = NULL;

	while (head != NULL)
	{
		del_Node = head->next;
		free(head->message_error);
		free(head);
		head = del_Node;
	}

	return (err);
}
