/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helaouta <helaouta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:58:24 by helaouta          #+#    #+#             */
/*   Updated: 2026/03/19 11:45:38 by helaouta         ###   ########.fr       */
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

static void	sort_controller(t_stack *a, t_stack *b)
{
	if (a->size <= 3)
	{
		sort_three(a);
	}
	else if (a->size <= 5)
	{
		sort_five(a, b);
	}
	else
	{
		stack_radix(a, b);
	}
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
		sort_controller(&a, &b);
	destroy(a.arr, b.arr);
	return (0);
}
