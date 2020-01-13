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

int		switch_label_go_back(t_code *ptr, char *label)
{
	int		offset;
	int		check;
	t_code	*tmp;

	offset = 0;
	check = 0;
	tmp = ptr;
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
	return (0);
}

void	init_switch_label(t_code *ptr, char **label, int *offset, int arg)
{
	*offset = 0;
	if (arg == 1)
		*label = ptr->arg1;
	else if (arg == 2)
		*label = ptr->arg2;
	else if (arg == 3)
		*label = ptr->arg3;
}

int		switch_label(t_pasm *pasm, t_code *ptr, int arg)
{
	int		offset;
	char	*label;
	t_code	*tmp;

	init_switch_label(ptr, &label, &offset, arg);
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
		offset = switch_label_go_back(ptr, label);
		if (offset)
			return (offset);
	}
	error_exit_line(pasm, NULL, "wrong label in argument.", ptr->line);
	return (0);
}

void	switch_labels_to_adress_helper(t_pasm *pasm, t_code *ptr, int nb_arg)
{
	int		offset;

	offset = switch_label(pasm, ptr, nb_arg);
	if (nb_arg == 1)
	{
		free(ptr->arg1);
		ptr->arg1 = ft_itoa(offset);
	}
	if (nb_arg == 2)
	{
		free(ptr->arg2);
		ptr->arg2 = ft_itoa(offset);
	}
	if (nb_arg == 3)
	{
		free(ptr->arg3);
		ptr->arg3 = ft_itoa(offset);
	}
}

void	switch_labels_to_adress(t_pasm *pasm, t_code *code)
{
	t_code	*ptr;

	ptr = code;
	while (ptr)
	{
		if (check_is_label(ptr->arg1))
			switch_labels_to_adress_helper(pasm, ptr, 1);
		if (check_is_label(ptr->arg2))
			switch_labels_to_adress_helper(pasm, ptr, 2);
		if (check_is_label(ptr->arg3))
			switch_labels_to_adress_helper(pasm, ptr, 3);
		ptr = ptr->next;
	}
}
