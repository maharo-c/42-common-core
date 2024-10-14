/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margarita <margarita@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:40:16 by margarita         #+#    #+#             */
/*   Updated: 2024/10/14 23:58:57 by margarita        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Chooses which move to make to get the stack B element to the correct
	position in stack A.
	If the costs of moving stack A and B into position match,
	both will be rotated or reverse rotated at the same time.
	They might also be rotated separately, before finally pushing
	the top element of B to the top element of A. */

void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		reverse_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rotate_both(a, b, &cost_a, &cost_b);
	rotate_a(a, &cost_a);
	rotate_b(b, &cost_b);
	do_pa(a, b);
}

/*	Rotates stack B until it is in position. If the cost is negative,
	the stack will be reverse rotated, if it is positive, it will be 
	rotated. */

static void	rotate_b(t_stack **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_rb(b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_rrb(b);
			(*cost)++;
		}
	}
}

/*	Rotates stack A until it is in position. If the cost is negative,
	the stack will be reverse rotated, if it is positive, it will be 
	rotated. */

static void	rotate_a(t_stack **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_ra(a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_rra(a);
			(*cost)++;
		}
	}
}

/*	Rotates both stacks until one of them is in position.
	The given cost is positive since both positions are in the top half
	of their stacks. The cost is decreased as the stacks are rotated,
	when one reaches 0, the stack has been rotated as far as possible
	and the top position is correct. */

static void	rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		do_rr(a, b);
	}
}

/*	Reverse rotates both stacks until one of them is in position.
	The gievn cost is negative since both positions are ni the bottom half
	of their stacks. The cost is increased as the stacks are rotated, when
	one reaches 0, the stack has been rotataed as far as possible and the top
	position is correct. */

static void	reverse_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		do_rrr(a, b);
	}
}
