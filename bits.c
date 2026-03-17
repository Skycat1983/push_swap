/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helaouta <helaouta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 13:52:51 by helaouta          #+#    #+#             */
/*   Updated: 2026/03/17 13:53:12 by helaouta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Returns 1 if `bit` is set in `number`, else 0.
*/
size_t	is_bit_set(unsigned long long number, size_t bit)
{
	unsigned long long	mask;

	mask = 1ULL << bit;
	if ((number & mask) != 0ULL)
		return (1);
	return (0);
}

/*
** How many bit passes are needed to represent max rank value.
** If values are normalized to [0..size-1], max rank is size-1.
*/
int	calc_bit_passes(t_stack *stack_a)
{
	int	max_rank_value;
	int	total_bit_passes;

	max_rank_value = stack_a->size - 1;
	total_bit_passes = 1;
	while (max_rank_value > 1)
	{
		max_rank_value = max_rank_value >> 1;
		total_bit_passes++;
	}
	return (total_bit_passes);
}
