#include "ft_printf.h"

int ft_dlen(long d)
{
	int len = 0;
	if (d == 0)
		return (1);
	while (d!=0)
	{
		len++;
		d /= 10;
	}
	return (len);
}

static void	print_left_padding(int d, int len, char pad, t_info *info)
{
	int	cnt;

	cnt = 0;
	if (info->flags[plus] && d > 0)
		putchar_and_inc('+', &cnt);
	else if (info->flags[space] && !info->flags[plus] && d>0)
		putchar_and_inc(' ', &cnt);
	if (d < 0)
		cnt++;
	while (info->prc > len)
	{
		ft_putchar_fd('0', 1);
		info->prc--;
		cnt++;
	}
	if ((d && info->flags[point] && info->prc >= 0) || !info->flags[point]) {
		ft_putnbr_fd(d, 1);
		cnt += len;
	}
	while(info->wdt > cnt)
	{
		ft_putchar_fd(pad, 1);
		cnt++;
	}
	info->tl += cnt;
}

static void print_right(int d, t_info *info, int total, char pad)
{
	if (info->sign && pad == '0')
	{
		if (d > 0 && info->flags[plus])
			ft_putchar_fd('+', 1);
		else if (d > 0 && info->flags[space] )
			ft_putchar_fd(' ',1);
	}
	while (info->wdt > total)
	{
		ft_putchar_fd(pad,1);
		info->wdt--;
	}
	if (info->sign && pad == ' ')
	{
		if (d > 0 && info->flags[plus])
			ft_putchar_fd('+', 1);
		else if (d > 0 && info->flags[space])
			ft_putchar_fd(' ',1);
	}
	while(numzeros--)
		ft_putchar_fd('0', 1);
	if ((d && info->flags[point] && info->prc >= 0) || !info->flags[point])
		ft_putnbr_fd(d, 1);
}

static void	print_right_padding(int d, int len, char pad, t_info* info)
{
	int total;
	int numzeros;
	int sign;
	int cnt;

	numzeros = 0;
	sign = 0;
	total = 0;
	cnt = 0;

	if (d < 0 || info->flags[plus] || info->flags[space])
	{
		sign = 1;
		info->sign = 1;
	}
	if (info->prc > len)
		numzeros = info->prc - len;
	total += sign + numzeros + len;
	print_right(d, info, total, pad);
	info->tl += total;
}
void print_decimal(t_info * info)
{
	int d;
	int len;
	char pad;
	int cnt = 0;
	d = va_arg(info->args, int);
	len = ft_dlen(d);
	pad = ' ';
	if (info->flags[zero])
		pad ='0';
	if (info->flags[dash] || info->prc)
		pad = ' ';
	if (info->flags[dash])
		print_left_padding(d, len, pad, info);
	else
		print_right_padding(d, len, pad, info);
}