/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:54:57 by dmesseng          #+#    #+#             */
/*   Updated: 2021/10/15 21:06:46 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_digit(int n, int fd)
{
	if (n == 0)
		return ;
	if (n < 0)
	{
		put_digit(-(n / 10), fd);
		ft_putchar_fd(-(n % 10) + '0', fd);
	}
	else
	{
		put_digit(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (n < 0)
		ft_putchar_fd('-', fd);
	put_digit(n, fd);
}
