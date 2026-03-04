/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helaouta <helaouta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:59:14 by helaouta          #+#    #+#             */
/*   Updated: 2026/02/26 12:36:49 by helaouta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n--)
		*p++ = 0;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;

	arr = malloc(nmemb * size);
	if (!arr)
		return (0);
	ft_bzero(arr, nmemb * size);
	return (arr);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// ! atoi


static int	is_whitespace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	long	sum;
	int		sign;

	i = 0;
	while (is_whitespace((int)nptr[i]))
		i++;
	sign = 1;
	if (nptr[i] == '-')
		sign *= -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	sum = 0;
	while (ft_isdigit((int)nptr[i]))
	{
		sum = (nptr[i] - '0') + (sum * 10);
		i++;
	}
	return ((int)sum * sign);
}

// ! ftsplit



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

int	next_word_len(char const *s, char c)
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
