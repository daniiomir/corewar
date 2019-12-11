/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:22:53 by cnikia            #+#    #+#             */
/*   Updated: 2019/12/11 20:26:44 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			fill_color_cursor(t_cursor *cursors, int a)
{
	t_cursor	*cursor;

	cursor = cursors;
	while (cursor)
	{
		if (cursor->current_position == a)
		{
			if (cursor->reg[0] == -1)
				printf("\033[1;31m");
			if (cursor->reg[0] == -2)
				printf("\033[1;32m");
			if (cursor->reg[0] == -1)
				printf("\033[1;34m");
			if (cursor->reg[0] == -1)
				printf("\033[1;35m");
			return (1);
		}
		cursor = cursor->next;
	}
	return (0);
}

void		print_arena(t_arena *arena, t_cursor *cursor)
{
	int 	a;
	int 	b;

	a = 0;
	printf("\e[1;1H\e[2J");
	while (a < MEM_SIZE)
	{
		b = fill_color_cursor(cursor, a);
		printf("%02x ", arena->memory[a++]);
		if (b)
			printf("\033[0m");
		if (a % 64 == 0)
			printf("\n");
	}
	sleep(1);
}
