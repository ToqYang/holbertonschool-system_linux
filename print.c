
#include "headers/principal.h"


/**
 * print_list - Print list linked
 * @h: Const list of a pointer
 * Return: Size_t
 */
int print_files(p_files h, int mode, int filter, char delim)
{
        int count = 0;
        (void)mode;
        (void)delim;

        for (int i = 0; h != NULL; ++i, (h = h->next))
        {
            if (filter == 0)
            {
                if (h->next != NULL)
                    fprintf(stdout, "%s ", h->namefile);
                else
                    fprintf(stdout, "%s\n", h->namefile);
            }
            ++count;
        }

        return (count);
}


/**
 * print_list - Print list linked
 * @h: Const list of a pointer
 * Return: Size_t
 */
int print_dirs(p_files h, int mode, int filter, char delim)
{
        int count = 0;
        (void)mode;
        (void)delim;

        for (int i = 0; h != NULL; ++i, (h = h->next))
        {
            if (filter == 0)
            {
                if (h->next != NULL)
                    fprintf(stdout, "%s ", h->namefile);
                else
                    fprintf(stdout, "%s\n", h->namefile);
            }
            ++count;
        }

        return (count);
}


/**
 * print_list - Print list linked
 * @h: (errorPtr) Head of the ptr
 * 
 * Return: (size_t) Count
 */
int print_error(errorPtr h)
{
        int count = 0;

	    while (h != NULL)
	    {
		    fprintf(stderr, "%s\n", h->message_error);
		    h = h->next;
		    ++count;
	    }

	    return (count);
}