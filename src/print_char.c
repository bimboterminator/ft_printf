/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:22:17 by dmesseng          #+#    #+#             */
/*   Updated: 2021/10/15 21:41:45 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(t_info *info)
{
	int	c;
	int	total;

	c = va_arg(info->args, int);
	total = 0;
	if (!info->flags[dash])
	{
		while (info->wdt-- - 1 > 0)
			putchar_and_inc(' ', &total);
		putchar_and_inc(c, &total);
	}
	else
	{
		putchar_and_inc(c, &total);
		while (info->wdt-- - 1 > 0)
			putchar_and_inc(' ', &total);
	}
	info->tl += total;
}
