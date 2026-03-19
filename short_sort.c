/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helaouta <helaouta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 10:54:45 by helaouta          #+#    #+#             */
/*   Updated: 2026/03/19 12:05:26 by helaouta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_index(t_stack *a)
{
	int	i;
	int	min;
	int	min_i;

	i = 0;
	min = a->arr[0];
	min_i = 0;
	while (i < a->size)
	{
		if (a->arr[i] < min)
		{
			min = a->arr[i];
			min_i = i;
		}
		i++;
	}
	return (min_i);
}

static void	move_min_to_top(t_stack *a)
{
	int	min_i;

	min_i = find_min_index(a);
	if (min_i == 1)
		sa(a);
	else if (min_i == 2)
	{
		ra(a);
		ra(a);
	}
	else if (min_i == 3)
		rra(a);
	else if (min_i == 4)
	{
		rra(a);
		rra(a);
	}
}

void	sort_three(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	x = a->arr[0];
	y = a->arr[1];
	z = a->arr[2];
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z && x > z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && y > z && x > z)
		rra(a);
}

void	sort_five(t_stack *a, t_stack *b)
{
	if (a->size <= 1 || is_sorted(a))
		return ;
	if (a->size == 2)
	{
		if (a->arr[0] > a->arr[1])
			sa(a);
		return ;
	}
	if (a->size == 3)
	{
		sort_three(a);
		return ;
	}
	while (a->size > 3)
	{
		move_min_to_top(a);
		pb(a, b);
	}
	sort_three(a);
	while (b->size > 0)
		pa(b, a);
}
