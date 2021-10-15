#include "ft_printf.h"

void	init(t_info *new, char const * format)
{
	new->format = format;
	new->wdt = 0;
	new->prc = 0;
	new->tl = 0;
	new->sign = 0;
	new->flags[zero] = '0';
	new->flags[dash] = '-';
	new->flags[hash] = '#';
	new->flags[space] = ' ';
	new->flags[plus] = '+';
	new->flags[point] = '.';
}