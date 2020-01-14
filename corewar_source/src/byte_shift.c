/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_shift.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:04:31 by cnikia            #+#    #+#             */
/*   Updated: 2020/01/09 14:04:32 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		byte_to_int(unsigned char *code, int byte_len)
{
	int				sign;
	unsigned int	i;
	int				j;

	i = 0;
	j = 0;
	sign = (code[0] >> 7) & 0x1;
	while (byte_len > 0)
	{
		if (sign)
			i += ((code[--byte_len] ^ 0xff) << (j * 8));
		else
			i += (code[--byte_len] << (j * 8));
		j++;
	}
	if (sign)
		i = ~(i);
	return (i);
}

int		get_map_ind(int current_position, int shift)
{
	int sum;

	sum = (current_position + shift) % MEM_SIZE;
	if (sum < 0)
		return (sum + MEM_SIZE);
	return (sum);
}

int		get_map_int(t_arena *arena, int first_pos, int size)
{
	unsigned char	new_arr[size];
	int				i;

	i = 0;
	while (i < size)
	{
		new_arr[i] = arena->map[get_map_ind(first_pos, i)];
		i++;
	}
	return (byte_to_int(new_arr, size));
}

int		get_cur_pos_byte(t_arena *arena, t_cursor *cursor)
{
	int reg_ind;

	reg_ind = get_map_ind(cursor->cur_pos, cursor->next_op_steps);
	cursor->next_op_steps += 1;
	return (arena->map[reg_ind]);
}
