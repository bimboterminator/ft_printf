#include "ft_printf.h"

static void	init_flags(const char *start, t_info *info)
{
	int	i;

	i = 0;
	while (i < 5) {
		if (ft_strchr(start, info->flags[i]) == NULL)
			info->flags[i] = 0;
		i++;
	}
}
void process_flags(t_info *info, char *str, size_t len)
{
	char	*flags[6];
	char	*start;

	start = str;
	flags[point] = ft_strchr(str, '.');
	if (flags[point])
		info->prc = ft_atoi(flags[point] + 1);
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
	init_flags(start, info);
	free(start);
}