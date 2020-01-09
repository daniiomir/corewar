/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroberts <hroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 14:31:14 by cnikia            #+#    #+#             */
/*   Updated: 2019/07/12 15:46:01 by hroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	add_flag(t_pf **pf, const char *str)
{
	char flag;

	flag = str[0];
	if (flag == '-')
		(*pf)->flag = (*pf)->flag | 1;
	if (flag == '+')
		(*pf)->flag = (*pf)->flag | 2;
	if (flag == ' ')
		(*pf)->flag = (*pf)->flag | 4;
	if (flag == '#')
		(*pf)->flag = (*pf)->flag | 8;
	if (flag == '0')
		(*pf)->flag = (*pf)->flag | 16;
}

void	add_wide(va_list ap, t_pf **pf, const char *str, int *a)
{
	int count;
	int temp;

	count = 0;
	if (str[count] >= '0' && str[count] <= '9')
	{
		(*pf)->wide = ft_atoi(str);
		while (str[count] >= '0' && str[count] <= '9')
		{
			count++;
		}
		(*a) = (*a) + count - 1;
	}
	if (str[0] == '*')
	{
		temp = va_arg(ap, int);
		if (temp < 0)
		{
			(*pf)->flag = (*pf)->flag | 1;
			temp = temp * (-1);
		}
		(*pf)->wide = temp;
	}
}

int		add_prec(va_list ap, t_pf **pf, const char *str, int *a)
{
	int count;
	int temp;

	(*pf)->dot = 1;
	count = 0;
	if (str[count] >= '0' && str[count] <= '9')
	{
		(*pf)->prec = ft_atoi(str);
		while (str[count] >= '0' && str[count] <= '9')
			count++;
		(*a) = (*a) + count - 1;
	}
	else if (str[0] == '*')
	{
		temp = va_arg(ap, int);
		temp = (temp < 0) ? -2 : temp;
		(*pf)->prec = temp;
	}
	else
		return (0);
	return (1);
}

void	add_mode(t_pf **pf, const char *str, int *a)
{
	if ((str[0] == 'h' && str[1] == 'h') ||
	(str[0] == 'l' && str[1] == 'l'))
	{
		(*pf)->mode = str[0] - 1;
		(*a)++;
	}
	else if (str[0] == 'j')
		(*pf)->mode = 'm';
	else
		(*pf)->mode = str[0];
}
