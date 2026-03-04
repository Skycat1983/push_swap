/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helaouta <helaouta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 10:16:26 by helaouta          #+#    #+#             */
/*   Updated: 2026/02/25 10:16:45 by helaouta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int	tmp;

	if (!a || a->size < 2)
		return ;
	tmp = a->arr[0];
	a->arr[0] = a->arr[1];
	a->arr[1] = tmp;
}

void	sb(t_stack *b)
{
	int	tmp;

	if (!b || b->size < 2)
		return ;
	tmp = b->arr[0];
	b->arr[0] = b->arr[1];
	b->arr[1] = tmp;
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}