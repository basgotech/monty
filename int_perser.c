#include "monty_header.h"

/**
 *_atoi - converts a string to an integers
 *@str: the string to be converted
 *Return: 0 if no numbers in string
 */

int _atoi(char *str)
{
	int x, si = 1, fl = 0, dis;
	unsigned int result = 0;

	for (x = 0;  str[x] != '\0' && fl != 2; x++)
	{
		if (str[x] == '-')
			si *= -1;

		if (str[x] >= '0' && str[x] <= '9')
		{
			fl = 1;
			result *= 10;
			result += (str[x] - '0');
		}
		else if (fl == 1)
			fl = 2;
	}

	if (si == -1)
		dis = -result;
	else
		dis = result;

	return (dis);
}
