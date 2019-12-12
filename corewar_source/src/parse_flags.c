#include "../includes/corewar.h"

int parse_flag_n(int *argc, char ***argv)
{
	int	champion_order;

	champion_order = -1;
	if (*argc > 1 && (champion_order = ft_atoi(*(*argv + 1))))
	{
		if (champion_order < 1)
			print_error_and_exit("Champion id cannot be less than 1", 42);
	}
	else
		print_error_and_exit("Invalid argument with flag 'n'", 41);
	(*argv) += 2;
	(*argc) -= 2;
	return champion_order;
}

void parse_flag_v(t_gstate *gstate, int *argc, char ***argv)
{
    gstate->f_v = 1;
    (*argv)++;
    (*argc)--;
}

void parse_flag_dump(t_gstate *gstate, int *argc, char ***argv)
{
    int f_dump_arg;

    if (*argc > 1 && (f_dump_arg = ft_atoi(*(*argv + 1))))
    {
    	if (f_dump_arg < 0)
    		print_error_and_exit("Dump flag argument cannot be negative number", 44);
        gstate->f_dump = 1;
        gstate->f_dump_arg = f_dump_arg;
        (*argv) += 2;
        (*argc) -= 2;
    }
    else
        print_error_and_exit("Invalid dump flag", 43);
}