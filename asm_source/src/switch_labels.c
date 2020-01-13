/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_labels.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:39:32 by swarner           #+#    #+#             */
/*   Updated: 2019/12/07 17:39:33 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		switch_label(t_pasm *pasm, t_code *ptr, int arg)
{
	int		offset;
	int		check;
	char	*label;
	t_code	*tmp;

	offset = 0;
	if (arg == 1)
		label = ptr->arg1;
	else if (arg == 2)
		label = ptr->arg2;
	else if (arg == 3)
		label = ptr->arg3;
	if (ptr->next)
	{
		tmp = ptr;
		while (tmp)
		{
			if (ft_strequ(tmp->label_name, label))
				return (offset);
            offset += tmp->size;
			tmp = tmp->next;
		}
	}
	if (ptr->prev)
	{
		offset = 0;
		check = 0;
		tmp = ptr;
//		offset -= tmp->size - check_for_code_arg_type(tmp); // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		while (tmp)
		{
			if (check)
            	offset -= tmp->size;
			if (!check)
				check++;
			if (ft_strequ(tmp->label_name, label))
				return (offset);
			tmp = tmp->prev;
		}
	}
	error_exit_line(pasm, NULL, "wrong label in argument.", ptr->line);
	return (0);
}

void	switch_labels_to_adress(t_pasm *pasm, t_code *code)
{
	int		offset;
	t_code	*ptr;

	ptr = code;
	while (ptr)
	{
		if (check_is_label(ptr->arg1))
		{
			offset = switch_label(pasm, ptr, 1);
			free(ptr->arg1);
			ptr->arg1 = ft_itoa(offset);
		}
		if (check_is_label(ptr->arg2))
		{
			offset = switch_label(pasm, ptr, 2);
			free(ptr->arg2);
			ptr->arg2 = ft_itoa(offset);
		}
		if (check_is_label(ptr->arg3))
		{
			offset = switch_label(pasm, ptr, 3);
			free(ptr->arg3);
			ptr->arg3 = ft_itoa(offset);
		}
		ptr = ptr->next;
	}
}

