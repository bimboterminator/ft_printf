/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 11:24:59 by dmesseng          #+#    #+#             */
/*   Updated: 2021/10/16 14:45:55 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_digits(size_t hex, char *base, int *cnt)
{
	if (hex == 0)
		return ;
	print_digits(hex / 16, base, cnt);
	ft_putchar_fd(base[hex % 16], 1);
	*cnt = *cnt + 1;
}

int	putnbr_hex(size_t hex, int conversion)
{
	char	*base16;
	int		total;

	total = 0;
	if (!hex)
	{
		ft_putchar_fd('0', 1);
		total++;
		return (total);
	}
	if (conversion == 'X')
		base16 = "0123456789ABCDEF";
	else
		base16 = "0123456789abcdef" ;
	print_digits(hex, base16, &total);
	return (total);
}

void	print_hex(t_info *info)
{
	unsigned int	hex;

	hex = va_arg(info->args, unsigned int);
	info->tl += putnbr_hex((size_t)hex, *info->format);
}
