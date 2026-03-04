/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helaouta <helaouta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 10:30:46 by helaouta          #+#    #+#             */
/*   Updated: 2026/02/25 10:30:57 by helaouta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	int	tmp;
	int	i;

	if (!a || a->size < 2)
		return ;
	tmp = a->arr[a->size - 1];
	i = a->size - 1;
	while (i > 0)
	{
		a->arr[i] = a->arr[i - 1];
		i--;
	}
	a->arr[0] = tmp;
}

void	rrb(t_stack *b)
{
	int	tmp;
	int	i;

	if (!b || b->size < 2)
		return ;
	tmp = b->arr[b->size - 1];
	i = b->size - 1;
	while (i > 0)
	{
		b->arr[i] = b->arr[i - 1];
		i--;
	}
	b->arr[0] = tmp;
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}