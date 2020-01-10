/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_double.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <cnikia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 17:19:50 by cnikia            #+#    #+#             */
/*   Updated: 2019/08/26 16:40:27 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		get_sign(t_pf **pf, long double *dub)
{
	if ((*dub) < 0)
	{
		(*pf)->sign = '-';
		(*dub) *= -1;
	}
	else
		(*pf)->sign = '+';
}

static void		dub_str_next(int count, long long drob,
long long num, t_pf **pf)
{
	count = (!count) ? 1 : count;
	if (((*pf)->arg = (char *)malloc(sizeof(char) * (count + (*pf)->prec + 2))))
	{
		(*pf)->malloc = 1;
		((*pf)->arg)[count + (*pf)->prec + 1] = '\0';
		if ((*pf)->prec != -1)
		{
			((*pf)->arg)[count] = '.';
			if (!drob)
				while ((*pf)->prec)
					((*pf)->arg)[count + 1 + --((*pf)->prec)] = '0';
			while (drob)
			{
				((*pf)->arg)[count + 1 + --((*pf)->prec)] = drob % 10 + '0';
				drob /= 10;
			}
		}
		if (!num)
			((*pf)->arg)[--count] = '0';
		while (num)
		{
			((*pf)->arg)[--count] = num % 10 + '0';
			num /= 10;
		}
	}
}

static int		check(t_pf **pf, long long *drob)
{
	int			wst;
	long long	a;

	a = 1;
	wst = (*pf)->prec;
	while (wst-- > 0)
		a *= 10;
	if (*drob >= a)
	{
		*drob = 0;
		return (0);
	}
	return (1);
}

static void		dub_str(long double dub, t_pf **pf)
{
	long long	num;
	long long	drob;
	long long	waste;
	int			count;

	count = 0;
	drob = 0;
	num = 0;
	num = (long long)dub;
	dub -= (double)num;
	waste = (long long)(*pf)->prec;
	while (waste-- > -1)
		dub *= 10;
	drob = (long long)dub;
	(*pf)->prec = (drob == 0 && (*pf)->prec == 0) || ((*pf)->dot == 1 &&
	(*pf)->wst == -1) ? -1 : (*pf)->prec;
	(*pf)->wst = drob == 0 ? 1 : 0;
	drob = (drob % 10 > 4) ? (drob / 10) + 1 : drob / 10;
	num = (check(pf, &drob)) ? num : num + 1;
	waste = num;
	while (waste && ++count)
		waste /= 10;
	dub_str_next(count, drob, num, pf);
}

void			flag_double(va_list ap, t_pf **pf)
{
	long double			dub;
	int					prec;

	prec = (*pf)->prec;
	(*pf)->wst = (*pf)->prec;
	(*pf)->prec = ((*pf)->prec == -1) ? 6 : (*pf)->prec;
	if ((*pf)->mode == 'L')
		dub = va_arg(ap, long double);
	else
		dub = va_arg(ap, double);
	if (dub != dub)
	{
		(*pf)->arg = "nan\0";
		(*pf)->prec = prec;
		return ;
	}
	(*pf)->arg = (dub == dub + dub / .0 && dub > 0) ? "inf\0" : NULL;
	get_sign(pf, &dub);
	if (!(*pf)->arg)
		dub_str(dub, pf);
	(*pf)->prec = prec;
}
