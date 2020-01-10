/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arena.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:16:14 by cnikia            #+#    #+#             */
/*   Updated: 2020/01/09 13:16:15 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			fill_color_cursor(t_cursor *cursors, int a)
{
	t_cursor	*cursor;

	cursor = cursors;
	while (cursor)
	{
		if (cursor->cur_pos == a)
		{
			if (cursor->reg[0] == -1)
				ft_printf("\033[1;31m");
			if (cursor->reg[0] == -2)
				ft_printf("\033[1;32m");
			if (cursor->reg[0] == -3)
				ft_printf("\033[1;34m");
			if (cursor->reg[0] == -4)
				ft_printf("\033[1;35m");
			return (1);
		}
		cursor = cursor->next;
	}
	return (0);
}

void		print_arena(t_arena *arena, t_cursor *cursor)
{
	int		a;
	int		b;

	a = 0;
	ft_printf("\e[1;1H\e[2J");
	while (a < MEM_SIZE)
	{
		b = fill_color_cursor(cursor, a);
		ft_printf("%02x ", arena->map[a++]);
		if (b)
			ft_printf("\033[0m");
		if (a % 64 == 0)
			ft_printf("\n");
	}
//	sleep(1);
}
