/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:35:32 by dmesseng          #+#    #+#             */
/*   Updated: 2021/10/08 18:32:57 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	size_t	cnt;
	size_t	i;
	size_t	wl;
	size_t	length;

	cnt = 0;
	i = 0;
	wl = 0;
	length = ft_strlen(s);
	while (i <= length)
	{
		if (s[i] == c || s[i] == '\0')
		{
			if (wl != 0)
				cnt++;
			wl = 0;
		}
		else
			wl++;
		i++;
	}
	return (cnt);
}

static size_t	ft_str_len(const char *s, size_t *wl)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	*wl = 0;
	return (len);
}

static char	**alloc_mas(char const *s, char c, size_t *tmp1, size_t *tmp2)
{
	char	**result;

	result = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	*tmp1 = 0;
	*tmp2 = 0;
	if (result == NULL)
		return (NULL);
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	wl;
	size_t	len;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	len = ft_str_len(s, &wl);
	split = alloc_mas(s, c, &i, &j);
	while (split && i <= len)
	{
		if (s[i] == c || s[i] == '\0')
		{
			if (wl != 0)
				split[j++] = ft_substr(s, i - wl, wl);
			wl = 0;
		}
		else
			wl++;
		i++;
	}
	if (split)
		split[j] = NULL;
	return (split);
}
