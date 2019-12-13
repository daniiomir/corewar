#include "../includes/corewar.h"

unsigned int	byte_shift(unsigned char *buff, int byte, int sign)
{
	unsigned int	i;
	int				j;

	i = 0;
	j = 0;
	while (byte > 0)
	{
		if (sign)
			i += ((buff[--byte] ^ 0xff) << (j++ * 8));
		else
			i += (buff[--byte] << (j++ * 8));
	}
	return (i);
/*    if (sign)
        i = ((buff[0] ^ 0xff) << 24) | ((buff[1] ^ 0xff) << 16) | ((buff[2] ^ 0xff) << 8) | (buff[3] ^ 0xff);
    else
        i = (buff[0] << 24) | (buff[1] << 16) | (buff[2] << 8) | (buff[3]);*/
}

// TODO: сделать функцию на нахождение отрицательных чисел х2
// доделать функцию
