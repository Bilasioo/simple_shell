#include "Header.h"

/**
 * show_prompt - function used to show prompts
 *
 **/

void show_prompt(void)
{
	char *prompt = "$ ";

	write(STDOUT_FILENO, prompt, 2);
}
