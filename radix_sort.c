/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helaouta <helaouta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 11:20:41 by helaouta          #+#    #+#             */
/*   Updated: 2026/03/19 12:04:31 by helaouta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Process the current top value of A for a given bit:
** - if bit is 1: rotate A
** - if bit is 0: push to B
*/
static void	process_top_of_a(t_stack *a, t_stack *b, int bit)
{
	int	top;

	top = a->arr[0];
	if (is_bit_set((unsigned long long)top, (size_t)bit))
		ra(a);
	else
		pb(a, b);
}

/*
** Do one full scanning pass over A for a given bit.
** We capture the initial size so we scan each original element exactly once,
** even though pb/ra change the stack during the pass.
**
** Returns number of moves performed in this pass.
*/
static int	pass_a_for_bit(t_stack *a, t_stack *b, int bit)
{
	int	i;
	int	n;
	int	moves;

	n = a->size;
	i = 0;
	moves = 0;
	while (i < n)
	{
		process_top_of_a(a, b, bit);
		moves++;
		i++;
	}
	return (moves);
}

/*
** Push everything back from B to A.
** Returns number of moves performed.
*/
static int	drain_b_to_a(t_stack *b, t_stack *a)
{
	int	moves;

	moves = 0;
	while (b->size > 0)
	{
		pa(b, a);
		moves++;
	}
	return (moves);
}

/*
** Radix sort using bit passes.
** Assumes values in A are normalized ranks [0..size-1].
**
** Returns 0 (you can change to return move count if you want).
*/
void	stack_radix(t_stack *a, t_stack *b)
{
	int	bit;
	int	total_bits;

	total_bits = calc_bit_passes(a);
	bit = 0;
	while (bit < total_bits)
	{
		pass_a_for_bit(a, b, bit);
		drain_b_to_a(b, a);
		if (is_sorted(a))
			break ;
		bit++;
	}
}
