/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 12:56:03 by cnikia            #+#    #+#             */
/*   Updated: 2020/01/09 12:57:34 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vis.h>

void	refresh_window(t_gstate *gstate, t_arena *arena)
{
	t_vis	*vis;

	vis = gstate->vis;
	werase(vis->w_map);
	werase(vis->w_usage);
	werase(vis->w_info);
	draw_map(vis, arena);
	draw_usage(vis);
	draw_info(gstate, arena);
	wrefresh(vis->w_map);
	wrefresh(vis->w_info);
	wrefresh(vis->w_usage);
}

void	btn_handler(t_vis *vis)
{
	if (vis->btn == RUN)
		vis->is_running = !vis->is_running;
	if (vis->btn == SLOW_DOWN10)
		vis->speed += 1000;
	if (vis->btn == SLOW_DOWN100)
		vis->speed += 10000;
	if (vis->btn == SPEED_UP10)
		vis->speed -= 1000;
	if (vis->btn == SPEED_UP100)
		vis->speed -= 10000;
	if (vis->speed < MIN_SPEED)
		vis->speed = MIN_SPEED;
	if (vis->speed >= MAX_SPEED)
		vis->speed = MAX_SPEED - 1000;
}

void	visualisation(t_gstate *gstate, t_arena *arena)
{
	prepare_map(gstate);
	system("say -v Alex -r 200 'Welcome to the battle' &");
	while ((gstate->vis->btn = getch()) != EXIT)
	{
		gstate->vis->btn = (char)ft_tolower(gstate->vis->btn);
		btn_handler(gstate->vis);
		if (gstate->processes_num == 0)
			gstate->vis->is_running = 0;
		if (gstate->vis->btn == ONE_CYCLE)
			one_cycle(gstate);
		if (gstate->vis->is_running)
		{
			one_cycle(gstate);
			usleep(gstate->vis->speed);
		}
		refresh_window(gstate, arena);
	}
	endwin();
}
