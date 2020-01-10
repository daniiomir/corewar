/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_champ.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:04:53 by rrika             #+#    #+#             */
/*   Updated: 2019/12/10 14:04:53 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

t_champ		*parse_champion_file(int n_arg, int id, char *filename)
{
	int		fd;
	t_champ	*player;

	player = init_champion(n_arg, id);
	if ((fd = open(filename, O_RDONLY)) <= 0)
		print_error_and_exit(ft_strjoin("Cannot open file ", filename), 50);	// утечка
	check_header(fd);
	player->name = get_name_and_comment(fd, PROG_NAME_LENGTH);
	miss_nulls(fd);
	player->size = get_exec_code_size(fd);
	player->comment = get_name_and_comment(fd, COMMENT_LENGTH);
	miss_nulls(fd);
	player->code = get_exec_code(fd, player->size);
	close(fd);
	return (player);
}
