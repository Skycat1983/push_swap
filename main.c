/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helaouta <helaouta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:58:24 by helaouta          #+#    #+#             */
/*   Updated: 2026/03/18 16:56:59 by helaouta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	destroy(int *arr1, int *arr2)
{
	free(arr1);
	free(arr2);
}

static int	init(t_stack *a, t_stack *b, int size, int *values)
{
	a->arr = values;
	a->size = size;
	b->size = 0;
	b->arr = malloc(sizeof(int) * size);
	if (!b->arr)
		return (0);
	return (1);
}

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

static void	sort_three(t_stack *a)
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

	// size 4 or 5
	while (a->size > 3)
	{
		move_min_to_top(a);
		pb(a, b);
	}

	sort_three(a);

	while (b->size > 0)
		pa(b, a);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	int		size;
	int		*values;

	if (argc == 1)
		return (0);
	values = parse_controller(argc, argv, &size);
	if (!values)
		return (write(2, "Error\n", 6), 1);
	if (!init(&a, &b, size, values))
		return (free(values), write(2, "Error\n", 6), 1);
	if (size <= 1)
		return (destroy(a.arr, b.arr), 0);
	normalize_rank(&a);
	if (has_dupes(&a))
		return (destroy(a.arr, b.arr), write(2, "Error\n", 6), 1);
	if (!is_sorted(&a))
	{
		if (a.size <= 3)
		{
			sort_three(&a);
		}
		else if (a.size <= 5)
		{
			sort_five(&a, &b);
		}
		else
		{
			stack_radix(&a, &b);
		}
	}
	destroy(a.arr, b.arr);
	return (0);
}