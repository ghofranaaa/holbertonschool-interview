#include "wildcmp.h"

/**
* wildcmp - compares two strings with
* support for the wildcard '*'
* @s1: first string
* @s2: second string (may contain '*')
*
* Return: 1 if the strings can be considered identical,
* otherwise 0
*/

int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s2 == '*')
	{
		/* skip consecutive '*' recursively */
		if (*(s2 + 1) == '*')
			return (wildcmp(s1, s2 + 1));

		/* '*' can match zero or more characters */
		if (wildcmp(s1, s2 + 1))
			return (1);
		if (*s1 && wildcmp(s1 + 1, s2))
			return (1);
	}

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	return (0);
}
