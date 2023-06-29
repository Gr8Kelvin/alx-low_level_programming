#include "main.h"

/**
 *leet - funtion
 *letters a and A replaced by 4
 *letters e and E replaced by 3
 *letters o and O replaced by 0
 *letters t and T replaced by 7
 *letters l and L replaced by 1
 *@s: pointer
 *Return: pointer to s
 */

char *leet(char *s)
{
	int sl, lc;
	char ll[] = "aAeEoOtTlL";
	char ln[] = "4433007711";

	sl = 0;
	while (s[sl] != '\0')
	{
		lc = 0;
		while (lc < 10)
		{
			if (ll[lc] == s[sl])
			{
				s[sl] = ln[lc];
			}
			lc++;
		}
		sl++;
	}
	return (s);
}

