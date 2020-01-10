#include <corewar_vis.h>

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
		if (gstate->processes_num == 0)			// конец игры
		{
			gstate->vis->is_running = 0;
		}
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

void visualisation_debug(t_gstate *gstate, t_arena *arena)
{
//	init_vis_arena(gstate);

	while (gstate->vis->is_running)
	{
		if (gstate->processes_num == 0)			// конец игры
		{
			gstate->vis->is_running = 0;
			break;
		}
		one_cycle(gstate);
	}
}
