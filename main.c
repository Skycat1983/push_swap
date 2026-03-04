/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helaouta <helaouta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:58:24 by helaouta          #+#    #+#             */
/*   Updated: 2026/02/26 14:28:09 by helaouta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	destroy(int *arr1, int *arr2)
{
	free(arr1);
	free(arr2);
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
	a.arr = values;
	a.size = size;
	b.arr = NULL;
	b.size = 0;
	b.arr = malloc(sizeof(int) * a.size);
	if (!b.arr)
		return (free(a.arr), write(2, "Error\n", 6), 1);
	normalize_rank(&a);
	if (has_dupes(&a))
		return (destroy(a.arr, b.arr), write(2, "Error\n", 6), 1);
	print_stack(&a);
	printf("=========\n");
	stack_radix(&a, &b);
	print_stack(&a);
	printf("=========\n");

	destroy(a.arr, b.arr);
	return (0);
}
