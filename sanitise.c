/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitise.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helaouta <helaouta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 09:54:07 by helaouta          #+#    #+#             */
/*   Updated: 2026/02/26 12:54:59 by helaouta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_ranks(t_stack *a, int *ranks)
{
	int	i;
	int	j;
	int	rank;

	i = 0;
	while (i < a->size)
	{
		rank = 0;
		j = 0;
		while (j < a->size)
		{
			if (a->arr[j] < a->arr[i])
				rank++;
			j++;
		}
		ranks[i] = rank;
		i++;
	}
}

int	normalize_rank(t_stack *a)
{
	int	i;
	int	*ranks;

	if (!a || !a->arr || a->size <= 0)
		return (0);
	ranks = malloc(sizeof(int) * a->size);
	if (!ranks)
		return (0);
	init_ranks(a, ranks);
	i = 0;
	while (i < a->size)
	{
		a->arr[i] = ranks[i];
		i++;
	}
	free(ranks);
	return (1);
}
