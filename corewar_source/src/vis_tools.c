#include "corewar_vis.h"

static void check_has_color() {
	if (has_colors() == 0) {
		endwin();
		print_error_and_exit("Terminal does not support color", 91);
	}
}

void init_color_palette() {
	check_has_color();
	init_pair(COLOR_ERROR, COLOR_WHITE, COLOR_RED);
	init_pair(GRAY, COLOR_GRAY, 0);
	init_pair(GREEN, COLOR_GREEN, 0);
	init_pair(PURPLE, COLOR_INDIGO, 0);
	init_pair(RED, COLOR_RED, 0);
	init_pair(CYAN, COLOR_CYAN, 0);
	init_pair(MAGENTA, COLOR_MAGENTA, 0);
	init_pair(YELLOW, COLOR_YELLOW, 0);
	init_pair(GRAY_CUR, COLOR_BLACK, COLOR_GRAY);
	init_pair(GREEN_CUR, COLOR_BLACK, COLOR_GREEN);
	init_pair(PURPLE_CUR, COLOR_BLACK, COLOR_INDIGO);
	init_pair(RED_CUR, COLOR_BLACK, COLOR_RED);
	init_pair(CYAN_CUR, COLOR_BLACK, COLOR_CYAN);
	init_pair(MAGENTA_CUR, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(YELLOW_CUR, COLOR_BLACK, COLOR_YELLOW);
}

void	check_window_size(t_vis *vis)
{
	WINDOW	*error_win;
	int		len;
	int		indent;
	int		box_width;

	if (vis->width < (COL_WIDTH * 4 + 5) || vis->height < MAP_HEIGHT + USAGE_HEIGHT + 2)
	{
		len = strlen("Make the window bigger");
		box_width = vis->width / 2;
		indent = (box_width - len) / 2;
		error_win = newwin(5, box_width, (vis->height / 2) - 3, box_width / 2);
		box(error_win, 0, 0);
		wbkgd(error_win, COLOR_PAIR(COLOR_ERROR));
		wattron(error_win, A_BOLD);
		mvwprintw(error_win, 2, indent, "Make the window bigger");
		wattroff(error_win, A_BOLD);
		wrefresh(error_win);
		napms(4000);
		endwin();
		print_error_and_exit("The window is smaller than necessary", 90);
	}
}
