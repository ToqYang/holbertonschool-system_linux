#include "headers/principal.h"

/**
 * main - Copy command ls
 * @argc: (int) Length of the arguments
 * @argv: (char **) String of each argument
 * @envp: (char **) Get the environment
 *
 * Return: Exit Success or Failure
 */
int main(int argc, char *argv[], char *envp[])
{
	arguc = argc;
	arguv = argv;
	envip = envp;

	int success = 1;

	success = command_ls();

	if (success)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}
