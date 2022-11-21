#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "_print.h"

int (*specific_format(const char *fm))(va_list)
{
	fun funtion[] =
	{
		{"s", get_s},
		{"c", get_c},
		/*{"i", get_i},*/
		{"d", get_d},
		{NULL, NULL}
	};

	int i = 0;

	while (funtion[i].tipe)
	{
		if (*fm == *(funtion[i].tipe))
		{
			return(funtion[i].op);
		}
		i++;
	}
}
/**
  * comentario
  * comentario2
  *
  *
 */
int _printf(const char *format, ...)
{
	int i = 0, count = 0;
	char *buff;
	va_list li;

	va_start(li, format);

	if (!format)
		exit (1);

	buff = malloc(1024);

	while (format[i])
	{
		if (format[i] != '%')
		{
			count++;
			buff[i] = format[i];
		}
		else
			count += write(1,specific_format(format), 1);/*specific_format(*format[i + 1])(va_list li);*/	
		i++;
	}
	write(1, buff, count);
	free(buff);
	va_end(li);
	return(count);
}
int main()
{
	char *p = "hola";
	char f = 'h';
	int i = 10;
	_printf("Hola mundo%s\n", *p);
	_printf("%c", f);
	_printf("%i", i);
	return(0);
}
