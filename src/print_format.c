#include "ft_printf.h"

void	print_conversion(t_info *info)
{
	if (*info->format == 'd')
		print_decimal(info);
//	else if (*info->format == 'c')
}

void	print_format(t_info *info)
{
	size_t	i;
	char *flags;

	info->format++;
	if (*info->format == '%')
	{
		ft_putchar_fd('%', 1);
		inc(info, 1);
		return ;
	}
	i = 0;
	while(info->format[i] != 'c' && info->format[i] != 's' && info->format[i] != 'p'
		  && info->format[i] != 'd' && info->format[i] != 'i' && info->format[i] != 'u'
		  && info->format[i] != 'x'&& info->format[i] != 'X')
		i++;
	flags = ft_substr(info->format, 0, i);
	process_flags(info, flags, i);
	free(flags);
	info->format += i;
	print_conversion(info);
}

void	putchar_and_inc(char c, int *cnt)
{
	ft_putchar_fd(c, 1);
	*cnt++;
}
