/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helaouta <helaouta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 11:16:06 by helaouta          #+#    #+#             */
/*   Updated: 2026/02/26 12:35:56 by helaouta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
duplicates in the array break the sorting algorithm
creates count_arr
value at each index is the frequency that number has occured
uses calloc to ensure all zeros which we can increment

sort_arr = the array we want to sort
rank = is the value/rank in the normalised sort_array
count_arr = temp array to track frequency of each value in sort_arr

as soon as we encounter a value > 1 in the count_arr we have a dupe
*/

int	has_dupes(t_stack *a)
{
	int	*count_arr;
	int	*sort_arr;
	int	rank;
	int	i;

	count_arr = calloc(a->size, sizeof(int));
	if (!count_arr)
		return (1);
	i = 0;
	sort_arr = a->arr;
	while (i < a->size)
	{
		rank = sort_arr[i];
		count_arr[rank]++;
		if (count_arr[rank] > 1)
		{
			free(count_arr);
			return (1);
		}
		i++;
	}
	free(count_arr);
	return (0);
}

int	is_sorted(t_stack *a)
{
	int *arr;
	int size;
	int i;
	int left;
	int right;

	i = 0;
	arr = a->arr;
	size = a->size;
	if (!arr)
		return (0);
	while (i <= size)
	{
		if (i + 1 >= size)
		{
			return (1);
		}
		left = arr[i];
		right = arr[i + 1];
		if (left < right)
			i++;
		else
			return (0);
	}
	return (1);
}