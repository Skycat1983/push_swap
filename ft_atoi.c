/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helaouta <helaouta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 13:45:46 by helaouta          #+#    #+#             */
/*   Updated: 2026/03/18 13:45:43 by helaouta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	is_whitespace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_atoi(const char *nptr, int *error)
{
	int		i;
	long	sum;
	int		sign;
	long	max;
	long 	min;

	max = 2147483647;
	min = -2147483648;
	i = 0;
	while (is_whitespace((int)nptr[i]))
		i++;
	sign = 1;
	if (nptr[i] == '-')
		sign *= -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	sum = 0;
	while (ft_isdigit((int)nptr[i]))
	{
		sum = (nptr[i] - '0') + (sum * 10);
		i++;
	}
	if ((sum * sign) > max || (sum * sign) < min)
		(*error)++;
	return ((int)sum * sign);
}
