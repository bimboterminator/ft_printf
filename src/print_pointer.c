/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 11:45:20 by dmesseng          #+#    #+#             */
/*   Updated: 2021/10/16 12:32:44 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_pointer(t_info *info)
{
	size_t	ptr;

	ptr = (size_t)va_arg(info->args, void *);
	ft_putstr_fd("0x", 1);
	info->tl += putnbr_hex(ptr, 'x') + 2;
}
