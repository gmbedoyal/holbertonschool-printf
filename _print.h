#include <stdarg.h>
#ifndef _PRINT_H
#define _PRINT_H

typedef struct funtions
{
	char *tipe;
	int (*op)(va_list);
} fun;
int (*specific_format(const char *fm))(va_list);
int _printf(const char *format, ...);
int get_c(va_list ch);
int get_s(va_list s);

#endif