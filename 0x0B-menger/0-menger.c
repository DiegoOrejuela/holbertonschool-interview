#include "menger.h"

/**
 * menger - function that draws a 2D Menger Sponge
 *
 * @level: is the level of the Menger Sponge to draw
 */

void menger(int level)
{
	int size, height = 0, width, aux1, aux2;
	char str;

	size = pow(3, level);

	while (height < size)
	{
		width = 0;
		while (width < size)
		{
			aux1 = height;
			aux2 = width;
			str = 35;

			while (aux1 > 0 || aux2 > 0)
			{
				if (aux1 % 3 == 1 && aux2 % 3 == 1)
					str = 32;
				aux1 = aux1 / 3;
				aux2 = aux2 / 3;
			}
			printf("%c", str);
			width++;
		}
		printf("\n");
		height++;
	}
}
