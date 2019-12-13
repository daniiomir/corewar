/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_alg.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 21:50:03 by cnikia            #+#    #+#             */
/*   Updated: 2019/12/12 21:50:04 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_ALG_H
# define MAIN_ALG_H

#include "corewar.h"

t_arena				*init_arena();
void				fill_champions_code(t_arena *arena, t_gstate *gstate);
void				print_arena(t_arena *arena, t_cursor *cursor);
void				free_all(t_arena *arena);
t_cursor			*fill_cursors(t_gstate *gstate);
void 				dead_cursor(t_cursor **cursor, t_cursor **start);
void				main_alg(t_gstate *gstate);
int 				next_operation_steps_calculation(t_cursor *next, unsigned char arg_type);
void 				dead_cursor(t_cursor **cursor, t_cursor **start);
void				cursor_operations_exec(t_cursor **cursor, t_arena *arena);
void				do_operations(t_cursor *wst, t_arena *arena);

#endif
