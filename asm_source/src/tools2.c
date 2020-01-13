/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:42:07 by swarner           #+#    #+#             */
/*   Updated: 2019/12/07 17:42:09 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*get_nulls(int len)
{
	int		i;
	char	*nulls;

	i = 0;
	nulls = ft_strnew(len);
	while (i < len)
		nulls[i++] = '0';
	return (nulls);
}

int		check_for_arg_type(char *arg)
{
	if (arg[0] == 'r')
		return (REG_CODE);
	else if (arg[0] == DIRECT_CHAR)
		return (DIR_CODE);
	else if (ft_isdigit(arg[0])
		|| (arg[0] == LABEL_CHAR && ft_isalpha(arg[1]))
		|| (arg[0] == '-' && ft_isdigit(arg[1])))
		return (IND_CODE);
	return (0);
}

int		check_for_op_name(char *op)
{
	int		i;

	i = 0;
	while (g_op_tab[i].op_name)
	{
		if (ft_strequ(op, g_op_tab[i].op_name))
			return (1);
		i++;
	}
	return (0);
}

int		check_for_code_arg_type(t_code *code_line)
{
	if (ft_strequ(code_line->operation, "live")
		|| ft_strequ(code_line->operation, "zjmp")
		|| ft_strequ(code_line->operation, "fork")
		|| ft_strequ(code_line->operation, "lfork"))
		return (0);
	return (1);
}

int		check_dir_size(t_code *code_line)
{
	if (ft_strequ(code_line->operation, "zjmp")
		|| ft_strequ(code_line->operation, "ldi")
		|| ft_strequ(code_line->operation, "sti")
		|| ft_strequ(code_line->operation, "fork")
		|| ft_strequ(code_line->operation, "lldi")
		|| ft_strequ(code_line->operation, "lfork"))
		return (2);
	return (4);
}
