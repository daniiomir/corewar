/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:55:15 by cnikia            #+#    #+#             */
/*   Updated: 2019/12/09 16:55:16 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_H
# define ARENA_H

#include "corewar.h"

t_arena				*init_arena();
void				fill_champions_code(t_arena *arena, t_gstate *gstate);
void				print_arena(t_arena *arena, t_cursor *cursor);
void				free_all(t_arena *arena);
t_cursor			*fill_cursors(t_gstate *gstate, t_arena *arena);
void 				dead_cursor(t_cursor **cursor, t_cursor **start);
void				main_alg(t_gstate *gstate);
t_op    			op_tab[17];

#endif