#include "menger.h"

/**
 * menger - function that draws a 2D Menger Sponge
 *
 * @level: is the level of the Menger Sponge to draw
 */

void menger(int level)
{
	int _size, _height = 0, _width, _aux1, _aux2;
	char _str;

	_size = pow(3, level);

	while (_height < _size)
	{
		width = 0;
		while (_width < _size)
		{
			_aux1 = _height;
			_aux2 = _width;
			_str = 35;

			while (_aux1 > 0 || _aux2 > 0)
			{
				if (_aux1 % 3 == 1 && _aux2 % 3 == 1)
					_str = 32;
				_aux1 = _aux1 / 3;
				_aux2 = _aux2 / 3;
			}
			printf("%c", _str);
			_width++;
		}
		printf("\n");
		_height++;
	}
}
