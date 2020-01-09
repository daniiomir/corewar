/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_prog_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:11:21 by cnikia            #+#    #+#             */
/*   Updated: 2020/01/09 13:11:22 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static int	is_champion_filename(char *filename)
{
	size_t	filename_len;

	if (!filename)
		print_error_and_exit("Champion filename is invalid", 40);
	filename_len = ft_strlen(filename);
	if (ft_strchr(filename, '.'))
	{
		if (filename_len > 4 &&
		ft_strequ(filename + (filename_len - 4), ".cor"))
			return (1);
		print_error_and_exit("Champion filename is invalid", 40);
	}
	return (0);
}

static void	parse_champion_filename(t_gstate *gstate, int *argc, char ***argv)
{
	int	champion_order;

	champion_order = 0;
	if (ft_strequ(**argv, "-n"))
		champion_order = parse_flag_n(argc, argv);
	if (is_champion_filename(**argv))
	{
		gstate->all_players[gstate->players_num] =
				parse_champion_file(champion_order,
						gstate->players_num, **argv);
	}
	else
		print_error_and_exit("After the -n flag should be the name of the champion file", 42);
	(*argv)++;
	(*argc)--;
	gstate->players_num++;
}

void		parse_arguments(t_gstate *gstate, int argc, char **argv)
{
	if (argc == 0)
		print_usage();
	while (argc > 0)
	{
		if (ft_strequ(*argv, "-n") || is_champion_filename(*argv))
			parse_champion_filename(gstate, &argc, &argv);
		else if (ft_strequ(*argv, "-dump"))
			parse_flag_dump(gstate, &argc, &argv);
		else if (ft_strequ(*argv, "-v"))
			parse_flag_v(gstate, &argc, &argv);
		else
			print_usage();
	}
	if (gstate->players_num < 1 || gstate->players_num > MAX_PLAYERS)
	{
		print_error_and_exit(CONCAT_STR_WITH_NBR(
	"Players amount less than 1 or more than ", MAX_PLAYERS), 46);
	}
}
