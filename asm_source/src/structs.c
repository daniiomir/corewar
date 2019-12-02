#include "asm.h"

t_pasm	*init_pasm(void)
{
	t_pasm	*pasm;

	pasm = (t_pasm *)malloc(sizeof(t_pasm));
	pasm->champion_name = NULL;
	pasm->comment = NULL;
	pasm->code = NULL;
	pasm->final_code = NULL;
	return (pasm);
}

void	free_pasm(t_pasm *pasm)
{
	if (pasm)
	{
		if (pasm->champion_name)
			free(pasm->champion_name);
		if (pasm->comment)
			free(pasm->comment);
		if (pasm->code)
			free_code_lines(pasm->code);
		if (pasm->final_code)
			free(pasm->final_code);
		free(pasm);
	}
}

t_code	*create_code_line(void)
{
	t_code	*code;

	code = (t_code *)malloc(sizeof(t_code));
	if (!code)
		return (NULL);
	code->operation = NULL;
	code->arg1 = NULL;
	code->arg1_type = 0;
	code->arg2 = NULL;
	code->arg2_type = 0;
	code->arg3 = NULL;
	code->arg3_type = 0;
	code->label_name = NULL;
	code->size = 0;
	code->line = 0;
	code->next = NULL;
	code->prev = NULL;
	return (code);
}

void	free_code_lines(t_code *code_lines)
{
	t_code	*temp;

	while (code_lines)
	{
		temp = code_lines;
		code_lines = code_lines->next;
		if (temp->operation)
			free(temp->operation);
		if (temp->arg1)
			free(temp->arg1);
		if (temp->arg2)
			free(temp->arg2);
		if (temp->arg3)
			free(temp->arg3);
		if (temp->label_name)
			free(temp->label_name);
		free(temp);
		temp = NULL;
	}
}