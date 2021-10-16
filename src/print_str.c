/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:43:28 by dmesseng          #+#    #+#             */
/*   Updated: 2021/10/16 13:21:37 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_str(t_info *info)
{
	char	*str;
	size_t	len;

	str = va_arg(info->args, char *);
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		info->tl += 6;
		return ;
	}
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	info->tl += len;
}
