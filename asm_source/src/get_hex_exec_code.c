/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hex_exec_code.c.                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:30:52 by swarner           #+#    #+#             */
/*   Updated: 2019/12/04 17:30:54 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

unsigned char	setbit(const unsigned char value, const int position)
{
    return (value | (1 << position));
}

char 	*code_get_hex_op(char *op_code)
{
	int		i;

	i = 0;
	while (op_tab[i].op_name)
	{
		if (ft_strequ(op_code, op_tab[i].op_name))
			return (ft_itoa_base(op_tab[i].op_code, 16));
	}
	return (NULL);
}

char 	*code_get_hex_addcode(t_code *code_line)
{
	unsigned char	addcode;

	if (!check_for_code_arg_type(code_line))
		return (ft_strnew(0));
	addcode = 0;
	if (code_line->arg1_type == REG_CODE)
		addcode = setbit(addcode, 2);
	if (code_line->arg1_type == DIR_CODE)
		addcode = setbit(addcode, 1);
	if (code_line->arg1_type == IND_CODE)
	{
		addcode = setbit(addcode, 1);
		addcode = setbit(addcode, 2);
	}

	if (code_line->arg2_type == REG_CODE)
		addcode = setbit(addcode, 4);
	if (code_line->arg2_type == DIR_CODE)
		addcode = setbit(addcode, 3);
	if (code_line->arg2_type == IND_CODE)
	{
		addcode = setbit(addcode, 3);
		addcode = setbit(addcode, 4);
	}

	if (code_line->arg3_type == REG_CODE)
		addcode = setbit(addcode, 6);
	if (code_line->arg3_type == DIR_CODE)
		addcode = setbit(addcode, 5);
	if (code_line->arg3_type == IND_CODE)
	{
		addcode = setbit(addcode, 5);
		addcode = setbit(addcode, 6);
	}
	return (ft_itoa_base((int)addcode, 16));
}

char 	*code_get_hex_arg_positive(t_pasm *pasm, t_code *code_line, char *arg, int arg_type)
{
	int		len;
	int		dir_size;
	char 	*final_arg;

	final_arg = ft_itoa_base(ft_atoi(arg), 16);
	len = (int)ft_strlen(final_arg);
	dir_size = check_dir_size(code_line) * 2;
	if (len < 2 && arg_type == REG_CODE)
		final_arg = ft_strjoin_free2("0", final_arg);
	else if (len < 4 && arg_type == IND_CODE)
		final_arg = ft_strjoin_free_all(get_nulls(4 - len), final_arg);
	else if (len < dir_size && arg_type == DIR_CODE)
		final_arg = ft_strjoin_free_all(get_nulls(dir_size - len), final_arg);
	else
		error_exit_line(pasm, "arguments too big.", code_line->line);
	return (final_arg);
}

// char	*code_get_hex_arg_negative_reg(int arg)
// {
// 	char			*final;
// 	unsigned char	reg;

// 	reg = (unsigned char)arg;
// 	reg = ~reg + 1;
// 	final = ft_itoa_base((int)reg, 16);
// 	return (final);
// }

// char	*code_get_hex_arg_negative_dir_ind(int arg)
// {
// 	char			*final;
// 	int				dir_ind;

// 	dir_ind = ~arg + 1;
// 	final = ft_itoa_base(dir_ind, 16);
// 	return (final);
// }

char 	*code_get_hex_arg_negative(t_code *code_line, char *argument, int arg_type)
{
	int		arg_value;
	int		by;
	char 	*final_arg;
	int		dir_size;

	arg_value = ft_atoi(argument);
	arg_value = -arg_value;
	dir_size = check_dir_size(code_line);
	if (dir_size == 2 || arg_type == IND_CODE)
		by = ~(short)arg_value + 1;
	else
		by = ~arg_value + 1;
	final_arg = ft_itoa_base(by, 16);
	return (final_arg);
}

char 	*code_get_hex_arg(t_pasm *pasm, t_code *code_line, char *argument, int arg_type)
{
	int		arg;
	char 	*final_arg;

	if (!argument || !arg_type)
		return (NULL);
	arg = ft_atoi(argument);
	if (arg >= 0)
		final_arg = code_get_hex_arg_positive(pasm, code_line, argument, arg_type);
	else
		final_arg = code_get_hex_arg_negative(code_line, argument, arg_type);
	return (final_arg);
}

void	code_to_hex(t_pasm *pasm)
{
	t_code	*code_line;
	char	*hex_code_line;

	code_line = pasm->code;
	while (code_line)
	{
		hex_code_line = ft_strjoin_free_all(
			code_get_hex_op(code_line->operation), 
			code_get_hex_addcode(code_line));
		hex_code_line = ft_strjoin_free_all(hex_code_line,
			code_get_hex_arg(pasm, code_line,
			code_line->arg1, code_line->arg1_type));
		hex_code_line = ft_strjoin_free_all(hex_code_line,
			code_get_hex_arg(pasm, code_line,
			code_line->arg2, code_line->arg2_type));
		hex_code_line = ft_strjoin_free_all(hex_code_line,
			code_get_hex_arg(pasm, code_line,
			code_line->arg3, code_line->arg3_type));
		code_line->hex = hex_code_line;
		code_line = code_line->next;
	}
}