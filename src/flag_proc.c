/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_proc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 20:56:27 by dmesseng          #+#    #+#             */
/*   Updated: 2021/10/16 12:57:42 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_flags(const char *start, t_info *info)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (ft_strchr(start, info->flags[i]) == NULL)
			info->flags[i] = 0;
		i++;
	}
}

static int	ft_abs(int d)
{
	if (d < 0)
		return (-d);
	return (d);
}

void	process_flags(t_info *info, char *str)
{
	char	*flags[6];
	char	*start;

	start = str;
	flags[point] = ft_strchr(str, '.');
	if (flags[point])
		info->prc = ft_abs(ft_atoi(flags[point] + 1));
	else
		info->flags[point] = 0;
	while ((flags[point] && start < flags[point]) || (!flags[point] && *start))
	{
		if (*start >= '1' && *start <= '9')
		{
			info->wdt = ft_atoi(start);
			break ;
		}
		start++;
	}
	start = ft_substr(str, 0, start - str);
	if (start)
		init_flags(start, info);
	else
		remove_flags(info);
	free(start);
}
