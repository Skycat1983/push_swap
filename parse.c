/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helaouta <helaouta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 11:24:49 by helaouta          #+#    #+#             */
/*   Updated: 2026/03/19 12:04:15 by helaouta         ###   ########.fr       */
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
	int		error;

	error = 0;
	str = ft_split(argv[1], ' ');
	*size = 0;
	while (str && str[*size])
		(*size)++;
	values = malloc(sizeof(int) * (*size));
	if (!values)
		return (free_split(str), NULL);
	i = 0;
	while (i < *size)
	{
		values[i] = ft_atoi(str[i], &error);
		i++;
	}
	free_split(str);
	if (error > 0)
		return (free(values), NULL);
	return (values);
}

int	*parse_inputs(int argc, char *argv[], int *size)
{
	int		*values;
	int		i;
	int		error;

	error = 0;
	*size = argc - 1;
	values = malloc(sizeof(int) * (*size));
	if (!values)
		return (NULL);
	i = 0;
	while (i < *size)
	{
		values[i] = ft_atoi(argv[i + 1], &error);
		i++;
	}
	if (error > 0)
		return (free(values), NULL);
	return (values);
}

int	*parse_controller(int argc, char *argv[], int *size)
{
	if (argc > 2)
		return (parse_inputs(argc, argv, size));
	return (parse_input(argv, size));
}
