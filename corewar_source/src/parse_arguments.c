#include "corewar.h"

int is_champion_filename(char *filename) {
    size_t filename_len;

    filename_len = ft_strlen(filename);
    if (ft_strchr(filename, '.'))
    {
        if (filename_len > 4 && ft_strcmp(filename + (filename_len - 4), ".cor") == 0)
            return (1);
        print_error_and_exit("Champion filename is invalid\n", 2);
    }
    return (0);
}

void    parse_arguments(t_gstate *gstate, int argc, char **argv) {
    if (argc == 0)
        print_usage();

    while (argc > 0)
    {
        if (ft_strcmp(*argv, "-n") == 0 || is_champion_filename(*argv))
        {
            argc--;
            argv++;
            gstate->players_num++;
            //  parse_champion_file(gstate);
        }
        else if (ft_strcmp(*argv, "-dump") == 0)
            parse_flag_dump(gstate, &argc, &argv);
        else if (ft_strcmp(*argv, "-v") == 0)
            parse_flag_v(gstate, &argc, &argv);
        else
            print_usage();
    }

    if (gstate->players_num < 1 || gstate->players_num > 4)
    {
        print_error_and_exit("Players amount less than 1 or more than 4", 1);
    }
}

void print_usage() {
    printf("Usage: ./corewar [-v][-d <num> | -n <num> ] <champion1.cor> <...>");
    exit(1);
}
