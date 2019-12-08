#include "corewar.h"

void parse_flag_v(t_gstate *gstate, int *argc, char ***argv) {
    gstate->f_v = 1;
    (*argv)++;
    (*argc)--;
}

void parse_flag_dump(t_gstate *gstate, int *argc, char ***argv) {
    int f_dump_arg;

    if (*argc > 1  && (f_dump_arg = ft_atoi(*(*argv + 1))) != 0)
    {
        gstate->f_dump = 1;
        gstate->f_dump_arg = f_dump_arg;

        (*argv) += 2;
        (*argc) -= 2;
    }
    else
    {
        print_error_and_exit("Invalid dump flag\n", 1);
    }
}