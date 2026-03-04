/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate_log.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helaouta <helaouta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 10:53:20 by helaouta          #+#    #+#             */
/*   Updated: 2026/02/25 10:53:30 by helaouta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate_a(t_stack *a)
{
	rra(a);
	write(1, "rra\n", 4);
}

void	rrotate_b(t_stack *b)
{
	rrb(b);
	write(1, "rrb\n", 4);
}

void	rrotate_ab(t_stack *a, t_stack *b)
{
	rrr(a, b);
	write(1, "rrr\n", 4);
}