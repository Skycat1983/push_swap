/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_log.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helaouta <helaouta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 10:22:40 by helaouta          #+#    #+#             */
/*   Updated: 2026/02/25 11:07:29 by helaouta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack *b, t_stack *a)
{
	pa(b, a);
	write(1, "pa\n", 3);
}

void	push_b(t_stack *a, t_stack *b)
{
	pb(a, b);
	write(1, "pb\n", 3);
}