#include "slide_line.h"
#include <unistd.h>

/**
* merge_line_left - Merge and slide line to the left
* @line: Pointer to the array
* @size: Size of the array
*/
void merge_line_left(int *line, size_t size)
{
	size_t i;
	int last = 0;

	/* First pass: move non-zero elements to the left */
	for (i = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			line[last++] = line[i];
		}
	}
	for (i = last; i < size; i++)
		line[i] = 0;

	/* Second pass: merge equal elements */
	for (i = 0; i < size - 1; i++)
	{
		if (line[i] != 0 && line[i] == line[i + 1])
		{
			line[i] *= 2;
			line[i + 1] = 0;
		}
	}

	/* Final pass: move again after merge */
	last = 0;
	for (i = 0; i < size; i++)
	{
		if (line[i] != 0)
			line[last++] = line[i];
	}
	for (i = last; i < size; i++)
		line[i] = 0;
}


/**
* merge_line_right - Merge and slide line to the right
* @line: Pointer to the array
* @size: Size of the array
*/
void merge_line_right(int *line, size_t size)
{
	ssize_t i;
	ssize_t last = size - 1;

	/* First pass: move non-zero elements to the right */
	for (i = size - 1; i >= 0; i--)
	{
		if (line[i] != 0)
		{
			line[last--] = line[i];
		}
	}
	for (i = last; i >= 0; i--)
		line[i] = 0;

	/* Second pass: merge equal elements */
	for (i = size - 1; i > 0; i--)
	{
		if (line[i] != 0 && line[i] == line[i - 1])
		{
			line[i] *= 2;
			line[i - 1] = 0;
		}
	}

	/* Final pass: move again after merge */
	last = size - 1;
	for (i = size - 1; i >= 0; i--)
	{
		if (line[i] != 0)
			line[last--] = line[i];
	}
	for (i = last; i >= 0; i--)
		line[i] = 0;
}


/**
* slide_line - Slide and merge an array of integers like 2048
* @line: Pointer to the array
* @size: Size of the array
* @direction: SLIDE_LEFT or SLIDE_RIGHT
*
* Return: 1 on success, 0 on failure
*/
int slide_line(int *line, size_t size, int direction)
{
	if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);

	if (direction == SLIDE_LEFT)
		merge_line_left(line, size);
	else
		merge_line_right(line, size);

	return (1);
}
