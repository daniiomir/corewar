/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <cnikia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 14:31:14 by cnikia            #+#    #+#             */
/*   Updated: 2019/08/26 17:44:41 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		plus_print(t_pf **pf)
{
	if (ft_strchr("dif", (*pf)->type))
	{
		if ((*pf)->flag & 2)
			ft_putstr_printf("+", pf);
		else if ((*pf)->flag & 4)
			ft_putstr_printf(" ", pf);
	}
	if (ft_strchr("xXop", (*pf)->type) && (*pf)->flag & 8)
	{
		if ((*pf)->type == 'x' && !(((*pf)->arg)[1] == '\0'
		&& ((*pf)->arg)[0] == '0'))
			ft_putstr_printf("0x", pf);
		if ((*pf)->type == 'X' && !(((*pf)->arg)[1] == '\0'
		&& ((*pf)->arg)[0] == '0'))
			ft_putstr_printf("0X", pf);
		if ((*pf)->type == 'o' && !(((*pf)->arg)[1] == '\0'
		&& ((*pf)->arg)[0] == '0'))
			ft_putstr_printf("0", pf);
		if ((*pf)->type == 'p')
			ft_putstr_printf("0x", pf);
	}
}

static void	wst_one(t_pf **pf, int len, int a, int plus)
{
	(*pf)->sign == '-' ? ft_putstr_printf("-", pf) : plus_print(pf);
	while (++a < ((*pf)->prec >= 0 ? ((*pf)->prec - len) : 0))
		ft_putstr_printf("0", pf);
	len += a + plus;
	a = 0;
	ft_putstr_printf((*pf)->arg, pf);
	if ((*pf)->flag & 8 && (*pf)->type == 'f' && (*pf)->prec == 0)
		ft_putstr_printf(".", pf);
	while (a++ < ((*pf)->wide - len))
		ft_putstr_printf(" ", pf);
}

static void	wst_two(t_pf **pf, int len, int a, int plus)
{
	if (!((*pf)->flag & 16) || ((*pf)->prec >= 0 && (*pf)->flag & 16 &&
	(*pf)->type != 'f') || ((*pf)->type == 'f' && !((*pf)->flag & 16)) ||
	((*pf)->dot && (*pf)->prec >= 0))
		while (++a < ((*pf)->wide - ((*pf)->prec > len ? (*pf)->prec : len)
		- plus))
			ft_putstr_printf(" ", pf);
	if (((*pf)->prec == 0 || (*pf)->prec < 0) && (*pf)->arg[0] == '0' &&
	((*pf)->type == 'x' || (*pf)->type == 'o') && (*pf)->wide)
		ft_putstr_printf(" ", pf);
	a = -1;
	(*pf)->sign == '-' ? ft_putstr_printf("-", pf) : plus_print(pf);
	while (++a < ((*pf)->prec >= 0 ? ((*pf)->prec - len) : 0) &&
	(*pf)->prec >= 0)
		ft_putstr_printf("0", pf);
	while (a++ < ((*pf)->wide - len - plus) && (*pf)->flag & 16 &&
	((*pf)->prec < 0 || (*pf)->type == 'f'))
		ft_putstr_printf("0", pf);
	if ((!((*pf)->dot && (*pf)->arg[0] == '0') || (*pf)->prec > 0) ||
	((((*pf)->dot && (*pf)->arg[0] == '0') || (*pf)->prec > 0) && (*pf)->type
	== 'o' && (*pf)->flag & 8) || ((*pf)->dot && (*pf)->type == 'f'))
		ft_putstr_printf((*pf)->arg, pf);
	else if ((*pf)->arg[0] == '0' && (*pf)->wide > 0 && (*pf)->type == 'd')
		ft_putstr_printf(" ", pf);
	if ((*pf)->flag & 8 && (*pf)->type == 'f' && (*pf)->prec == 0)
		ft_putstr_printf(".", pf);
}

void		final_print(t_pf **pf)
{
	int a;
	int	len;
	int	plus;

	a = -1;
	len = ft_strlen((*pf)->arg);
	plus = (((*pf)->sign == '-' || (*pf)->flag & 2 || (*pf)->flag & 4) ? 1 : 0);
	plus += ((((*pf)->type == 'x' || (*pf)->type == 'X') &&
	!(((*pf)->arg)[1] == '\0' && ((*pf)->arg)[0] == '0'))
	|| (*pf)->type == 'p') && ((*pf)->flag & 8) ? 2 : 0;
	len += ((*pf)->type == 'o') && (*pf)->flag & 8 && !(((*pf)->arg)[1] == '\0'
	&& ((*pf)->arg)[0] == '0') ? 1 : 0;
	plus += (*pf)->flag & 8 && (*pf)->type == 'f' && (*pf)->prec == 0 ? 1 : 0;
	if ((*pf)->flag & 1)
		wst_one(pf, len, a, plus);
	else
		wst_two(pf, len, a, plus);
}
