#include <stddef.h> /* for NULL */
#include "regex.h"

/**
* regex_match - check whether a given pattern matches a given string
* @s: the string to scan
* @p: the regular expression (supports '.' and '*')
*
* Return: 1 if the pattern matches the string, 0 otherwise.
*
* Rules:
* - '.' matches any single character.
* - '*' matches zero or more of the preceding element.
*/


int regex_match(char const *s, char const *p)
{
	if (*p == '\0')
		return (*s == '\0');

	if (*(p + 1) == '*')
	{
		/* '*' case: zero or more of preceding char */
		if ((*s && (*p == '.' || *p == *s)) && regex_match(s + 1, p))
			return (1);
		return (regex_match(s, p + 2));
	}
	else if (*s && (*p == '.' || *p == *s))
	{
		/* match single char */
		return (regex_match(s + 1, p + 1));
	}
	else
		return (0);
}
