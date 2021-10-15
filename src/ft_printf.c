#include "ft_printf.h"

void	inc(t_info * info, int total)
{
	info->format++;
	if (total)
		info->tl++;
}

int	ft_printf(const char *format, ...)
{
	int		tl;
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (0);
	init(info, format);
	va_start(info->args, format);
	while (*info->format != '\0')
	{
		if (*info->format == '%')
		{
			print_format(info);
			info->format++;
		}
		else
		{
			ft_putchar_fd(*info->format, 1);
			inc(info, 1);
		}
	}
	va_end(info->args);
	tl = info->tl;
	free(info);
	return tl;
}

