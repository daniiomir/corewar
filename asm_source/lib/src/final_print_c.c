/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_print_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroberts <hroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:47:47 by cnikia            #+#    #+#             */
/*   Updated: 2019/07/12 15:53:58 by hroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	wst_one(t_pf **pf, int a)
{
	while (((*pf)->prec >= 0 ? a < (*pf)->prec : 1) &&
	(((*pf)->arg)[a] != 0 || a < (*pf)->len))
	{
		ft_putchar(((*pf)->arg)[a]);
		(*pf)->b++;
		a++;
	}
	if ((*pf)->proc == 'y' && (*pf)->prec == 0)
	{
		ft_putchar('%');
		(*pf)->b++;
	}
	if ((*pf)->wide)
	{
		while (a < (*pf)->wide - ((*pf)->proc == 'y' &&
		(*pf)->prec == 0 ? 1 : 0))
		{
			ft_putchar(' ');
			(*pf)->b++;
			a++;
		}
	}
}

static void	wst_two(t_pf **pf, int len, int a)
{
	if ((*pf)->prec >= 0)
		len = len > (*pf)->prec ? (*pf)->prec : len;
	if ((*pf)->len == 1)
		len = 1;
	while ((a < (*pf)->wide - len -
	((*pf)->proc == 'y' && (*pf)->prec == 0 ? 1 : 0)))
	{
		(*pf)->flag & 16 ? ft_putchar('0') : ft_putchar(' ');
		(*pf)->b++;
		a++;
	}
	a = 0;
	while (((*pf)->prec >= 0 ? a < (*pf)->prec : 1) &&
	(((*pf)->arg)[a] != 0 || a < (*pf)->len))
	{
		ft_putchar(((*pf)->arg)[a]);
		(*pf)->b++;
		a++;
	}
	if ((*pf)->proc == 'y' && (*pf)->prec == 0)
	{
		ft_putchar('%');
		(*pf)->b++;
	}
}

void		final_print_c(t_pf **pf)
{
	int a;
	int	len;

	a = 0;
	if ((*pf)->prec == -1 && (*pf)->dot && (*pf)->type == 's')
		(*pf)->prec = 0;
	len = ft_strlen((*pf)->arg);
	if ((*pf)->flag & 1)
		wst_one(pf, a);
	else
		wst_two(pf, len, a);
}
