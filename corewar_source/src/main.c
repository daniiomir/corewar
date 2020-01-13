/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:44:25 by swarner           #+#    #+#             */
/*   Updated: 2019/11/13 15:44:27 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_vis.h"

int	main(int argc, char **argv)
{
	t_gstate	*gstate;

	gstate = init_global_state();
	parse_arguments(gstate, argc - 1, argv + 1);
	order_of_champs(gstate);
	gstate->arena = init_arena(gstate);
	fill_arena_and_init_cursors(gstate->arena, gstate);
	if (gstate->f_v)
		visualisation(gstate, gstate->arena);
	else
		main_alg(gstate);
	free_all(gstate);
}

/*
    make corewar; ./corewar -v ../examples/champs/Car.cor -n 3 ../examples/champs/ex.cor ../examples/champs/Gagnant.cor ../examples/champs/Car.cor
*/

//	------------ BASIC FUNCTIONS ------------

//	initscr();				- initializes the screen
//	cbreak();				- ends the program by pressing ctrl+c (default)
//	raw();					- doesn't end the program by pressing ctrl+c
//	noecho();				- doesn't print user input
//  keypad(win, true);      - enables special keystrokes
//	endwin();				- deallocates memory and ends ncurses
//	refresh();				- refreshes the screen to match whats in memory
//	clear();				- clears the screen

//	move(x, y);				- moves the cursor to the specified location
//	mvprintw(x, y, "", %d);	- moves the cursor and prints string

//  getyx(win, y, x);       - puts current x and y into variables
//  getbegyx(win, y, x);    - puts window's beginning x and y into variables
//  getmaxyx(win, y, x);    - puts window's width and height into variables


//	------------ INPUT AND OUPUT ------------
//	getch();				- waits for user input, returns int value of that key
//	printw();				- prints a string to a window
//  addch(c);               - prints char
//  mvaddch(x, y, c)        - moves cursor and prints char

//	------------ NEW WINDOW ------------

//	newwin(h, w, s_y, s_x)	- creates the window. Takes 4 parameters:
//								h	- height
//								w	- width
//								s_y	- start_y
//								s_x	- start_x
//	wrefresh();				- refreshes the specific window
//	box(win, 0, 0);			- puts a basic border around the window
//								second_arg	- left and right border symbol
//								third_arg	- top and bottom border symbol
//	wborder(win, l, r...	- fully customize window border
//  wgetch(win);            - gets char in window
//	wprintw(win, "", %d);	- prints string in window
//	wmove(win, x, y);		- moves the cursor in window
//	mvwprintw(win, x, y, "", %d);	- moves the cursor and prints string in window

//	------------ COLOR ------------
//	has_colors();			- true if terminal has colors
//	start_color();			- after func will be color
//	init_pair(ID, c1, c2);	- initializes pair of color
//								ID	- unique id we gave
//								c1	- text color
//								c2	- background color
//  init_color(C, r, g, b); - changes existing color
//  can_change_color();     - returns true if terminal can change color

//	------------ ATTRIBUTES ------------
//	attron()				- enables attribute
//	attroff()				- disables attribute
//  wattron()				- enables attribute for specific window
//	wattroff()				- disables attribute for specific window
//								A_REVERSE		- reverses the color
//								A_STANDOUT		- reverses the color (same as  reverse)
//								A_BOLD			- makes font bold
//								A_UNDERLINE		- underline
//								COLOR_PAIR(ID)	-
