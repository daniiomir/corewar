/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <cnikia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 18:17:02 by cnikia            #+#    #+#             */
/*   Updated: 2019/07/12 16:10:21 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_pf	*pf_new(void)
{
	t_pf	*new;

	if ((new = (t_pf *)malloc(sizeof(t_pf))))
	{
		new->flag = 0;
		new->wide = 0;
		new->prec = -1;
		new->mode = 0;
		new->type = 0;
		new->sign = 0;
		new->arg = NULL;
		new->dot = 0;
		new->b = 0;
		new->len = 0;
		new->malloc = 0;
		new->proc = 0;
		new->wst = 0;
	}
	return (new);
}
