#include "corewar_vis.h"

void fill_vis_arena(t_vis *vis, t_champ *champ, int first_pos) {
	int	size;
	int i;

	size = champ->size;
	vis->map[first_pos].is_cursor = 1;
	i = first_pos;
	while (i < first_pos + size)
	{
		vis->map[i].playerId = champ->id;
		i++;
	}
}

void init_vis_arena(t_gstate *gstate)
{
	int		step;
	int 	first_pos;
	int 	i;

	step = MEM_SIZE / gstate->players_num;
	first_pos = 0;
	i = 0;
	while (i < gstate->players_num)
	{
		fill_vis_arena(gstate->vis, gstate->all_players[i], first_pos);
		first_pos += step;
		i++;
	}
}

void prepare_map(t_gstate *gstate)
{
	initscr();
    nodelay(stdscr, 1);
	keypad(stdscr, 1);
	curs_set(0);
	noecho();
	cbreak();
	use_default_colors();
	start_color();
	refresh();
	getmaxyx(stdscr, gstate->vis->height, gstate->vis->width);
	init_color_palette();
	check_window_size(gstate->vis);
	init_vis_arena(gstate);
	gstate->vis->w_map = newwin(MAP_HEIGHT, MAP_WIDTH, 1, 2);
	gstate->vis->w_info = newwin(MAP_HEIGHT, COL_WIDTH, 1, MAP_WIDTH + 3);
	gstate->vis->w_usage = newwin(USAGE_HEIGHT, MAP_WIDTH, MAP_HEIGHT + 1, 2);
}