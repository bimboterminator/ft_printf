#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
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
	int			numzeros;
	const char	*format;
}				t_info;

void 	init(t_info *, char const *);
void	process_flags(t_info *, char *);
void	print_decimal(t_info *);
void	print_char(t_info *);
void	print_str(t_info *);
void	print_format(t_info *);
int		ft_printf(const char *, ...);
void	inc(t_info *, int);
char	*ft_strchr(const char *, int);
void	ft_putchar_fd(char, int);
void	ft_putnbr_fd(int, int);
int		ft_isdigit(int);
int		ft_atoi(const char *);
size_t	ft_strlen(const char *);
size_t	ft_strlcpy(char *, const char *, size_t);
void	putchar_and_inc(char, int *);
char	*ft_substr(const char*, unsigned int, size_t);
#endif
