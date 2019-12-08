#include "corewar.h"

t_gstate *init_global_state() {
    t_gstate *gstate;

    gstate = (t_gstate *)malloc(sizeof(t_gstate));
    gstate->players_num = 0;
    gstate->f_dump = 0;
    gstate->f_dump_arg = 0;
    gstate->f_v = 0;
    return gstate;
}