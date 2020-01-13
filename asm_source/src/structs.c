/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:30:04 by swarner           #+#    #+#             */
/*   Updated: 2019/12/04 17:30:06 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_hcode	*create_hex_struct(void)
{
	t_hcode		*hex_code;

	hex_code = (t_hcode *)malloc(sizeof(t_hcode));
	hex_code->magic_header = NULL;
	hex_code->champion_name = NULL;
	hex_code->null_octet = NULL;
	hex_code->exec_size = NULL;
	hex_code->champion_comment = NULL;
	hex_code->null_octet2 = NULL;
	return (hex_code);
}

void	free_hex_struct(t_hcode *hex_code)
{
	if (hex_code)
	{
		if (hex_code->magic_header)
			free(hex_code->magic_header);
		if (hex_code->champion_name)
			free(hex_code->champion_name);
		if (hex_code->null_octet)
			free(hex_code->null_octet);
		if (hex_code->exec_size)
			free(hex_code->exec_size);
		if (hex_code->champion_comment)
			free(hex_code->champion_comment);
		if (hex_code->null_octet2)
			free(hex_code->null_octet2);
		free(hex_code);
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
	code->hex = NULL;
	code->next = NULL;
	code->prev = NULL;
	return (code);
}

void	add_code_line(t_pasm *pasm, t_code *code_line)
{
	t_code	*prev;
	t_code	*code_ptr;

	if (!pasm->code)
		pasm->code = code_line;
	else
	{
		code_ptr = pasm->code;
		while (code_ptr)
		{
			prev = code_ptr;
			code_ptr = code_ptr->next;
		}
		code_ptr = code_line;
		prev->next = code_line;
		code_ptr->prev = prev;
	}
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
		if (temp->hex)
			free(temp->hex);
		free(temp);
		temp = NULL;
	}
}
