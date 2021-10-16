/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:43:28 by dmesseng          #+#    #+#             */
/*   Updated: 2021/10/16 14:33:57 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_str_fixed_size(char *str, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->prc)
	{
		ft_putchar_fd(str[i], 1);
		i++;
		info->tl++;
	}
}

void	print_str(t_info *info)
{
	char	*str;
	size_t	len;
		
	str = va_arg(info->args, char *);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (info->prc == 0)
		info->prc = (int)len;
	if (info->flags[dash])
	{
		print_str_fixed_size(str, info);
		while (info->wdt-- > info->prc)
			putchar_and_inc(' ', &info->tl);
	}
	else
	{
		while (info->wdt-- > info->prc)
			putchar_and_inc(' ', &info->tl);
		print_str_fixed_size(str, info);
	}
}
