/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 12:10:34 by dmesseng          #+#    #+#             */
/*   Updated: 2021/10/16 13:01:16 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

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
void	init(t_info *info, char const *str);
void	process_flags(t_info *info, char *str);
void	print_decimal(t_info *info);
void	print_char(t_info *info);
void	print_str(t_info *info);
void	print_format(t_info *info);
void	print_pointer(t_info *info);
int		ft_printf(const char *str, ...);
void	inc(t_info *info, int val);
char	*ft_strchr(const char *str, int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
void	remove_flags(t_info *info);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
void	putchar_and_inc(char c, int *val);
char	*ft_substr(const char *str, unsigned int start, size_t len);
int		putnbr_hex(size_t hex, int conversion);
void	print_hex(t_info *info);
void	ft_putstr_fd(char *str, int fd);
void	print_unsigned(t_info *info);
#endif
