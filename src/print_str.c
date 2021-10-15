/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:43:28 by dmesseng          #+#    #+#             */
/*   Updated: 2021/10/15 21:53:19 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	print_str(t_info *info)
{
	char	*str;
	int		total;
	int		len;

	total = 0;
	str = va_arg(info->args, char *);
	len = ft_strlen(str);
//	if (t_info->prc > 0 && t_info->)
//		len
}
