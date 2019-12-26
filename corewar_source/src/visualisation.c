#include <corewar_vis.h>

int get_color(t_cell cell) {
	int id;

	id = cell.playerId;
	if (cell.is_cursor)
		id = TO_CURSOR_COLOR(id);
	return (g_colors[id]);
}

void draw_map(t_gstate *gstate, t_arena *arena) {
	t_vis	*vis;
	int 	color;
	int 	row;
	int 	i;

	vis = gstate->vis;
	row = 1;
	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
			wmove(vis->w_map, row++, 2);
		color = get_color(vis->map[i]);
		wattron(vis->w_map, color);
		wprintw(vis->w_map, "%02x", arena->map[i]);
		wattroff(vis->w_map, color);
		waddch(vis->w_map, ' ');
		i++;
	}
	wattron(vis->w_map, COLOR_PAIR(GRAY));
	box(gstate->vis->w_map, 0, 0);
	wattroff(vis->w_map, COLOR_PAIR(GRAY));
}

void refresh_window(t_gstate *gstate, t_arena *arena) {
	t_vis	*vis;

	vis = gstate->vis;
	werase(vis->w_map);
	werase(vis->w_usage);
	werase(vis->w_info);
	draw_map(gstate, arena);
	box(gstate->vis->w_info, 0, 0);
	box(gstate->vis->w_usage, 0, 0);
	wrefresh(gstate->vis->w_map);
	wrefresh(gstate->vis->w_info);
	wrefresh(gstate->vis->w_usage);
}

void visualisation(t_gstate *gstate, t_arena *arena)
{
	prepare_map(gstate);

	while ((gstate->vis->btn = getch()) != QUIT)
	{
		if (gstate->vis->btn)
			printw("%c ", gstate->vis->btn, gstate->vis->btn);
//		handle_buttons(vm);
//		if (vm->vs->button == PASS_ONE_CYCLE)
//			exec_cycle_vs(vm);
//		else if (vm->vs->is_running && (clock() >= calc_time_delay(vm)))
//		{
//			vm->vs->time = clock();
//			exec_cycle_vs(vm);
//		}
		refresh_window(gstate, arena);
	}

    endwin();
}

