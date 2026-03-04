/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_log.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helaouta <helaouta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 10:17:15 by helaouta          #+#    #+#             */
/*   Updated: 2026/02/25 10:50:09 by helaouta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *a)
{
	sa(a);
	write(1, "sa\n", 3);
}

void	swap_b(t_stack *b)
{
	sb(b);
	write(1, "sb\n", 3);
}

void	swap_ab(t_stack *a, t_stack *b)
{
	ss(a, b);
	write(1, "ss\n", 3);
}