/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:03:34 by dmesseng          #+#    #+#             */
/*   Updated: 2021/10/16 14:37:23 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flags(t_info *info)
{
	info->flags[zero] = '0';
	info->flags[dash] = '-';
	info->flags[hash] = '#';
	info->flags[space] = ' ';
	info->flags[plus] = '+';
	info->flags[point] = '.';
}
void	init(t_info *new, char const *format)
{
	new->format = format;
	new->wdt = 0;
	new->prc = 0;
	new->tl = 0;
	new->sign = 0;
	init_flags(new);
}

void	clear_params(t_info *info)
{
	info->wdt = 0;
	info->prc = 0;
	info->sign = 0;
}

void	remove_flags(t_info *info)
{
	info->flags[zero] = 0;
	info->flags[dash] = 0;
	info->flags[hash] = 0;
	info->flags[space] = 0;
	info->flags[plus] = 0;
	info->flags[point] = 0;
}
