#include "main.h"

int (*specific_format(const char *fm))(va_list li, char *string, int j)
{
	fun function[] =
	{
		{"s", get_s},
		{"c", get_c},
		{"i", get_d},
		{"d", get_d},
		{NULL, NULL}
	};

	int i = 0;

	while (function[i].type)
	{
		if (*fm == *function[i].type)
		{
			return(function[i].op);
		}
		i++;
	}
return(0);
}