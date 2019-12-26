#include <corewar_vis.h>

t_vis			*init_vis()
{
	t_vis	*vis;

	vis = (t_vis *)malloc(sizeof(t_vis));
	if (vis == NULL)
		print_error_and_exit("Memory does not allocated", 3);
	vis->w_map = NULL;
	vis->w_usage = NULL;
	vis->w_info = NULL;
	vis->width = 0;
	vis->height = 0;
	vis->is_running = 0;
	vis->speed = 1;
	vis->btn = 0;
	return (vis);
}
