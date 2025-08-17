#include <stdio.h>
#include <math.h>
#include "menger.h"

/**
* print_char - decide whether to print '#' or ' ' at (x, y)
* @x: column index
* @y: row index
*/
void print_char(int x, int y)
{
	while (x > 0 && y > 0)
	{
		if (x % 3 == 1 && y % 3 == 1)
		{
			putchar(' ');
			return;
		}
		x /= 3;
		y /= 3;
	}
	putchar('#');
}

/**
* menger - draws a 2D Menger Sponge
* @level: level of the sponge
*/
void menger(int level)
{
	int size, row, col;

	if (level < 0)
		return;

	size = (int)pow(3, level);

	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
			print_char(col, row);
		putchar('\n');
	}
}
