#include "headers/principal.h"


/**
 * add_error - Add node errors at the end
 * @head: (errorPtr *) Head node
 * @name_stream: (char *) Name of the file
 * 
 * Return: (errorPtr *) Node with the modification
 */ 
errorPtr add_error(errorPtr *head, char *name_stream)
{
    char buff_err[512];
    /* Set values to Null */
    _memset(buff_err, '\0', 512);
    /* Read Name Program and NameFile */
    sscanf(buff_err, "hls: cannot access '%s': No such file or directory", name_stream);

    errorPtr error = malloc(sizeof(m_errors));
    error->message_error = (char *)malloc((_strlen(buff_err) + 1) * sizeof(char));

    if (!(error->message_error))
        return (NULL);

    _strcpy(error->message_error, buff_err);
    error->next = NULL;

    errorPtr last = *head;

    /* If the Head is None */
    if (!*head)
    {
        *head = error;
        return (error);
    }
    /* 
        Position in the Last Valid Position
        and Paste the New Node
    */
    while (last->next != NULL)
        last = last->next; 

    last->next = error;

    return (error);
}