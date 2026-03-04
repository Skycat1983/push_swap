/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_log.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helaouta <helaouta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 10:23:46 by helaouta          #+#    #+#             */
/*   Updated: 2026/02/25 10:25:08 by helaouta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *a)
{
	ra(a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack *b)
{
	rb(b);
	write(1, "rb\n", 3);
}

void	rotate_ab(t_stack *a, t_stack *b)
{
	rr(a, b);
	write(1, "rr\n", 3);
}