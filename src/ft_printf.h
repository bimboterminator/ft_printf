#ifndef PRINTF_H
# define PRINTF_H
#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"
typedef enum flags
{
	zero,
	dash,
	hash,
	space,
	plus,
	point
}			t_flags;

typedef struct s_info
{
	va_list		args;
	int			wdt;
	int			prc;
	char		flags[6];
	int			tl;
	int			sign;
	const char	*format;
}				t_info;

void 	init(t_info *, char const *);
void	process_flags(t_info *, char *, size_t);
void	print_decimal(t_info *);
void	print_conversion(t_info *);
void	print_format(t_info *);
int		ft_printf(const char *, ...);
void	inc(t_info *, int);
void	putchar_and_inc(char, int *);
#endif	PRINTF_H
