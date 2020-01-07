#include "corewar.h"

void	op_aff(t_arena *arena, t_cursor *cursor)
{
	int32_t	reg;
	int32_t	value;

	cursor->cur_pos = get_map_ind(cursor->cur_pos, 2);
	reg = get_arg(arena, cursor, cursor->args[0], 0);		// TODO: эта запись неверна, так как, надо доставать именно индекс регистра, а не его значение
	value = cursor->reg[INDEX(reg)];
//	if (gstate->f_a)						// нужен gstate
//		printf("Aff: %c\n", (char)value);
}