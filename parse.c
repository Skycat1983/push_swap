/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helaouta <helaouta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 11:24:49 by helaouta          #+#    #+#             */
/*   Updated: 2026/03/17 13:57:05 by helaouta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

int	*parse_input(char *argv[], int *size)
{
	int		*values;
	char	**str;
	int		i;
	int		words;

	str = ft_split(argv[1], ' ');
	words = 0;
	while (str && str[words])
		words++;
	values = malloc(sizeof(int) * words);
	if (!values)
	{
		free_split(str);
		return (NULL);
	}
	i = 0;
	while (i < words)
	{
		values[i] = ft_atoi(str[i]);
		i++;
	}
	free_split(str);
	*size = words;
	return (values);
}

int	*parse_inputs(int argc, char *argv[], int *size)
{
	int		*values;
	int		i;
	int		words;

	words = 1;
	while (words < argc - 1)
		words++;
	values = malloc(sizeof(int) * words);
	if (!values)
		return (NULL);
	i = 0;
	while (i < words)
	{
		values[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	*size = words;
	return (values);
}

int	*parse_controller(int argc, char *argv[], int *size)
{
	if (argc > 2)
		return (parse_inputs(argc, argv, size));
	return (parse_input(argv, size));
}
