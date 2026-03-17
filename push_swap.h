/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helaouta <helaouta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:58:46 by helaouta          #+#    #+#             */
/*   Updated: 2026/03/17 14:05:46 by helaouta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*arr;
	int	size;
}		t_stack;

// ! Parse
int		*parse_controller(int argc, char *argv[], int *words);
int		*parse_input(char *argv[], int *words);
int		*parse_inputs(int argc, char *argv[], int *words);

//! Sanitise
void	init_ranks(t_stack *a, int *ranks);
int		normalize_rank(t_stack *a);

//! Validate
int		has_dupes(t_stack *a);
int		is_sorted(t_stack *a);

//! Libft
char	**ft_split(char const *s, char c);

//! atoi
int		ft_atoi(const char *nptr);

//! calloc
void	*ft_calloc(size_t nmemb, size_t size);

//! Sort
size_t	is_bit_set(unsigned long long number, size_t bit);
int		stack_radix(t_stack *stack_a, t_stack *stack_b);

//! bits
size_t	is_bit_set(unsigned long long number, size_t bit);
int		calc_bit_passes(t_stack *stack_a);

// ! Mutations
// swap
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

// push
void	pa(t_stack *b, t_stack *a);
void	pb(t_stack *a, t_stack *b);

// rotate
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

// rev rotate
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

#endif