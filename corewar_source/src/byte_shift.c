#include "corewar.h"

int byte_to_int(unsigned char *code, int byte_len)
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
			i += ((code[--byte_len] ^ 0xff) << (j++ * 8));
		else
			i += (code[--byte_len] << (j++ * 8));
	}
	if (sign)
		i = ~(i);
	return (i);
}

int	get_map_ind(int current_position, int shift)
{
	int sum;

	sum = current_position + shift;
	if (sum < 0)
		return (MEM_SIZE + sum);
	return (sum % MEM_SIZE);
}
