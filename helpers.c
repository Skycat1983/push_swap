/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helaouta <helaouta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:59:22 by helaouta          #+#    #+#             */
/*   Updated: 2026/02/26 12:55:14 by helaouta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *a)
{
	int *arr;
	int i;
	int size;
	arr = a->arr;
	size = a->size;
	i = 0;
	while (i < size)
	{
		printf("index = %d, value = %d\n", i, arr[i]);
		i++;
	}
}
