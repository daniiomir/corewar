/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <cnikia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 14:31:14 by cnikia            #+#    #+#             */
/*   Updated: 2019/06/30 19:37:56 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	flag_str(va_list ap, t_pf **pf)
{
	int a;

	if ((*pf)->type == 'c')
	{
		a = va_arg(ap, int);
		if (a == 0)
			(*pf)->len = 1;
		if (((*pf)->arg = (char *)malloc(sizeof(char) * 2)))
		{
			(*pf)->malloc = 1;
			(*pf)->arg[1] = '\0';
			(*pf)->arg[0] = a;
		}
	}
	if ((*pf)->type == 's')
	{
		(*pf)->arg = va_arg(ap, char *);
		if (!((*pf)->arg))
			(*pf)->arg = "(null)";
	}
}

void	flag_percent(t_pf **pf)
{
	if (((*pf)->arg = (char *)malloc(sizeof(char) * 2)))
	{
		(*pf)->malloc = 1;
		((*pf)->arg)[1] = '\0';
		((*pf)->arg)[0] = '%';
		(*pf)->type = 's';
		(*pf)->proc = 'y';
	}
}
