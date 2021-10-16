/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 12:11:26 by dmesseng          #+#    #+#             */
/*   Updated: 2021/10/16 12:22:09 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_digit(unsigned int n, int *cnt)
{
	if (n == 0)
		return ;
	put_digit(n / 10, cnt);
	ft_putchar_fd(n % 10 + '0', 1);
	*cnt = *cnt + 1;
}

static	int	putnbr_unsigned(unsigned int n)
{
	int	total;

	total = 0;
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		total++;
		return (total);
	}
	put_digit(n, &total);
	return (total);
}

void	print_unsigned(t_info *info)
{
	unsigned int	uint;

	uint = va_arg(info->args, unsigned int);
	info->tl += putnbr_unsigned(uint);
}
