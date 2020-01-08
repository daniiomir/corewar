#include <corewar_vis.h>

void	draw_is_running(t_vis *vis, int *row)
{
	int		color;
	char 	*status;

	color = vis->is_running ? GREEN : RED;
	status = vis->is_running ? "RUNNING" : "STOPPED";
	wattron(vis->w_info, A_BOLD | COLOR_PAIR(color));
	wprintw(vis->w_info, "===== %s =====", status);
	wattroff(vis->w_info, A_BOLD | COLOR_PAIR(color));
	(*row) += 3;
}

void draw_players(t_gstate *gstate, t_vis *vis, int *row, int col)
{
	int		i;
	int		color;
	t_champ	*player;

	i = 0;
	while (i < gstate->players_num)
	{
		player = gstate->all_players[i];
		color = g_colors[player->id];
		wprintw(vis->w_info, "Player %d : ", player->id);
		wattron(vis->w_info, color);
		wprintw(vis->w_info, "%.45s", player->name);
		ft_strlen(player->name) > 45 ? waddstr(vis->w_info, "...") : 0;
		wattroff(vis->w_info, color);
		wmove(vis->w_info, (*row) += 1, col + 5);
		wprintw(vis->w_info, "Last live : %30s", "no information");
		wmove(vis->w_info, (*row) += 1, col + 5);
		wprintw(vis->w_info, "Lives in current period : %16s", "no information");

		wmove(vis->w_info, (*row) += 2, col);
		i++;
	}
}

void	draw_info(t_gstate *gstate, t_arena *arena)
{
	t_vis	*vis;
	int 	row;
	int 	col;

	row = 1;
	col = 3;
	vis = gstate->vis;
	wmove(vis->w_info, row, col);
	draw_is_running(vis, &row);
	wmove(vis->w_info, row, col);
	wattron(vis->w_info, A_BOLD);
	wprintw(vis->w_info, "Cycle : %d", arena->all_cycles);
	wmove(vis->w_info, row += 2, col);
	wprintw(vis->w_info, "Processes : no information");
	wmove(vis->w_info, row += 2, col);
    draw_players(gstate, vis, &row, col);
    wmove(vis->w_info, row += 1, col);
    wprintw(vis->w_info, "Cycles to die : %10d", arena->cycles_to_die);
    wmove(vis->w_info, row += 2, col);
    wprintw(vis->w_info, "Cycle delta : %10d", CYCLE_DELTA);
    wmove(vis->w_info, row += 2, col);
    wprintw(vis->w_info, "Max checks : %10d/10", arena->checks);
    wmove(vis->w_info, row += 2, col);
    wprintw(vis->w_info, "Nbr of lives : %8d/21", arena->lives_nbr);
	wattroff(vis->w_info, A_BOLD);
}

void refresh_window(t_gstate *gstate, t_arena *arena)
{
	t_vis	*vis;

	vis = gstate->vis;
	werase(vis->w_map);
	werase(vis->w_usage);
	werase(vis->w_info);
	draw_map(vis, arena);
	draw_usage(vis);
	draw_info(gstate, arena);
	box(vis->w_info, 0, 0);
	wrefresh(vis->w_map);
	wrefresh(vis->w_info);
	wrefresh(vis->w_usage);
}

void btn_handler(t_vis *vis)
{
	if (vis->btn == RUN)
		vis->is_running = !vis->is_running;
}

void visualisation(t_gstate *gstate, t_arena *arena)
{
	prepare_map(gstate);

	while ((gstate->vis->btn = getch()) != EXIT)
	{
		btn_handler(gstate->vis);
		if (gstate->vis->btn == ONE_CYCLE)
			one_cycle(gstate);
		else if (gstate->vis->is_running)
		{
			one_cycle(gstate);
		}
		refresh_window(gstate, arena);
	}

    endwin();
}
