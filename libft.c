/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helaouta <helaouta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:59:14 by helaouta          #+#    #+#             */
/*   Updated: 2026/03/19 11:17:44 by helaouta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**free_all(char **arr, int i)
{
	while (i > 0)
		free(arr[--i]);
	free(arr);
	return (0);
}

static int	count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
		{
			s++;
		}
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static int	next_word_len(char const *s, char c)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
		l++;
	}
	return (l);
}

static int	init_vals(const char *s, char c, int *wc, char ***arr)
{
	*wc = count_words(s, c);
	*arr = malloc((*wc + 1) * sizeof(char *));
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		wc;
	int		len;

	i = init_vals(s, c, &wc, &arr);
	if (!arr)
		return (0);
	while (i < wc)
	{
		while (*s == c)
			s++;
		len = next_word_len(s, c);
		arr[i] = malloc(len + 1);
		if (!(arr[i]))
			return (free_all(arr, i));
		j = -1;
		while (++j < len)
			arr[i][j] = s[j];
		arr[i++][len] = '\0';
		s += len;
	}
	arr[i] = 0;
	return (arr);
}
