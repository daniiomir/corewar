#include "corewar.h"

int byte_shift(unsigned char *buff, int byte)
{
	int				sign;
	unsigned int	i;
	int				j;

	i = 0;
	j = 0;
	sign = (buff[0] >> 7) & 0x1;
	while (byte > 0)
	{
		if (sign)
			i += ((buff[--byte] ^ 0xff) << (j++ * 8));
		else
			i += (buff[--byte] << (j++ * 8));
	}
	if (sign)
		i = ~(i);
	return (i);
}
