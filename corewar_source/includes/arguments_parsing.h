#ifndef COREWAR_SOURCE_ARGUMENTS_PARSING_H
# define COREWAR_SOURCE_ARGUMENTS_PARSING_H

# include "corewar.h"

void        print_usage();
void        print_error_and_exit(char *errstr, int errno);
t_gstate    *init_global_state();
void        parse_arguments(t_gstate *gstate, int argc, char **argv);
void        parse_flag_dump(t_gstate *gstate, int *argc, char ***argv);
void        parse_flag_v(t_gstate *gstate, int *argc, char ***argv);
int			parse_flag_n(int *argc, char ***argv);
int         is_champion_filename(char *filename);
void        parse_champion_file(t_gstate *gstate, int *argc, char ***argv);

#endif
