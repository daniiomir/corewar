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

int		setbit(const int value, const int position)
{
    return (value | (1 << position));
}

char 	*code_get_hex_op(char *op_code)
{
	int		i;

	i = 0;
	while (op_tab[i])
	{
		if (ft_strequ(op_code, op_tab[i].op_name))
			return (ft_itoa_base(op_tab[i].op_code, 16));
	}
	return (NULL);
}

char 	*code_get_hex_addcode(t_code *code_line)
{
	int		addcode;

	if (!check_for_code_arg_type(code_line))
		return (ft_strnew(0));
	addcode = 0;
	if (code_line->arg1_type == T_REG)
		addcode = setbit(addcode, 2);
	if (code_line->arg1_type == T_DIR)
		addcode = setbit(addcode, 1);
	if (code_line->arg1_type == T_IND)
	{
		addcode = setbit(addcode, 1);
		addcode = setbit(addcode, 2);
	}

	if (code_line->arg2_type == T_REG)
		addcode = setbit(addcode, 4);
	if (code_line->arg2_type == T_DIR)
		addcode = setbit(addcode, 3);
	if (code_line->arg2_type == T_IND)
	{
		addcode = setbit(addcode, 3);
		addcode = setbit(addcode, 4);
	}

	if (code_line->arg3_type == T_REG)
		addcode = setbit(addcode, 6);
	if (code_line->arg3_type == T_DIR)
		addcode = setbit(addcode, 5);
	if (code_line->arg3_type == T_IND)
	{
		addcode = setbit(addcode, 5);
		addcode = setbit(addcode, 6);
	}
	return (ft_itoa_base(addcode, 16));
}

char 	*code_get_hex_arg1(t_code *code_line)
{
	int		len;
	int		dir_size;
	char 	*arg_one;

	arg_one = ft_itoa_base(code_line->arg1, 16);
	len = (int)ft_strlen(arg_one);
	dir_size = check_dir_size(code_line) * 2;
	if (len < 2 && code_line->arg1_type == T_REG)
		arg_one = ft_strjoin_free2("0", arg_one);
	else if (len < 4 && code_line->arg1_type == T_IND)
		arg_one = ft_strjoin_free_all(get_nulls(4 - len), arg_one);
	else if (len < dir_size && code_line->arg1_type == T_DIR)
		arg_one = ft_strjoin_free_all(get_nulls(dir_size - len), arg_one);
	return (arg_one);
}

char 	*code_get_hex_arg2(t_code *code_line)
{}

char 	*code_get_hex_arg3(t_code *code_line)
{}

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
			code_get_hex_arg1(code_line));
		hex_code_line = ft_strjoin_free_all(hex_code_line,
			code_get_hex_arg2(code_line));
		hex_code_line = ft_strjoin_free_all(hex_code_line,
			code_get_hex_arg3(code_line));
		code_line->hex = hex_code_line;
		code_line = code_line->next;
	}
}