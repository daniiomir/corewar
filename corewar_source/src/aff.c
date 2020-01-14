/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:41:59 by cnikia            #+#    #+#             */
/*   Updated: 2020/01/09 13:42:00 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_aff(t_gstate *gstate, t_cursor *cursor)
{
	int	reg;
	int	value;

	cursor->steps += 2;
	reg = get_cur_pos_byte(gstate->arena, cursor);
	value = cursor->reg[INDEX(reg)];
	if (gstate->f_a && !gstate->f_v)
		ft_printf("Aff: %c\n", (char)value);
}
